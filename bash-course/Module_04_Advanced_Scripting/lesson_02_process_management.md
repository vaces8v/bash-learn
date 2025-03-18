# Process Management in Bash

## Introduction to Process Management

In this lesson, we will explore process management in Bash, which is essential for controlling and monitoring the execution of processes in a Unix-like operating system. Understanding how to manage processes will allow you to write more efficient and effective scripts.

## What is a Process?

A process is an instance of a running program. Each process has its own memory space and system resources. In Bash, you can manage processes using various commands and techniques.

## Key Concepts

1. **Foreground and Background Processes**:
   - **Foreground Process**: A process that is currently running and interacting with the user.
   - **Background Process**: A process that runs in the background, allowing the user to continue using the terminal.

2. **Job Control**:
   - You can control jobs in Bash using commands like `bg`, `fg`, and `jobs`.
   - `jobs`: Lists all current jobs.
   - `fg %job_number`: Brings a background job to the foreground.
   - `bg %job_number`: Sends a job to the background.

3. **Process IDs (PIDs)**:
   - Each process is assigned a unique Process ID (PID).
   - You can find the PID of a process using the `ps` command.

4. **Killing Processes**:
   - You can terminate a process using the `kill` command followed by the PID.
   - Example: `kill 1234` (where 1234 is the PID).

## Common Commands

- `ps`: Displays the currently running processes.
- `top`: Provides a dynamic view of running processes.
- `htop`: An enhanced version of `top` (may need to be installed).
- `kill`: Sends a signal to terminate a process.
- `pkill`: Kills processes by name.

## Example Usage

### Running a Process in the Background

To run a command in the background, append an ampersand (`&`) to the command:

```bash
sleep 60 &
```

### Listing Jobs

To see the jobs you have running:

```bash
jobs
```

### Bringing a Job to the Foreground

To bring a job back to the foreground:

```bash
fg %1
```

### Killing a Process

To kill a process with a specific PID:

```bash
kill 1234
```

## Conclusion

Process management is a crucial aspect of Bash scripting that allows you to control how your scripts and commands run. By mastering these commands and concepts, you will be able to create more robust and efficient scripts.

## Assignment

1. Create a script that runs a command in the background and then lists all running jobs.
2. Write a script that checks for a specific process and kills it if it is running.