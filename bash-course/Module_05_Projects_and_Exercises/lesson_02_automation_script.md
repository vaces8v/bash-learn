# Lesson 02: Automation Script

## Introduction

In this lesson, we will explore how to create automation scripts using Bash. Automation scripts are powerful tools that can help you streamline repetitive tasks, manage system processes, and improve efficiency in your workflow. By the end of this lesson, you will be able to write your own automation scripts to perform common tasks automatically.

## What is an Automation Script?

An automation script is a program written in a scripting language (in this case, Bash) that automates a series of commands or tasks. These scripts can be used for various purposes, such as:

- Backing up files
- Monitoring system performance
- Automating software installations
- Performing routine maintenance tasks

## Key Concepts

### 1. Shebang

Every Bash script starts with a shebang (`#!`) followed by the path to the Bash interpreter. This line tells the system which interpreter to use to execute the script.

Example:
```bash
#!/bin/bash
```

### 2. Making a Script Executable

Before running a script, you need to make it executable using the `chmod` command.

Example:
```bash
chmod +x my_script.sh
```

### 3. Writing Your First Automation Script

Let's create a simple automation script that backs up a directory.

1. Open your terminal.
2. Create a new file named `backup.sh`:
   ```bash
   touch backup.sh
   ```
3. Open the file in your favorite text editor and add the following code:

   ```bash
   #!/bin/bash

   # Directory to back up
   SOURCE_DIR="/path/to/source"
   # Backup destination
   BACKUP_DIR="/path/to/backup"

   # Create a backup
   cp -r "$SOURCE_DIR" "$BACKUP_DIR"

   echo "Backup of $SOURCE_DIR completed successfully to $BACKUP_DIR."
   ```

4. Save the file and make it executable:
   ```bash
   chmod +x backup.sh
   ```

5. Run the script:
   ```bash
   ./backup.sh
   ```

### 4. Scheduling Automation Scripts

You can schedule your automation scripts to run at specific times using `cron`. To edit your crontab, use the following command:

```bash
crontab -e
```

Add a line to schedule your script. For example, to run the backup script every day at 2 AM:

```bash
0 2 * * * /path/to/backup.sh
```

## Conclusion

In this lesson, you learned how to create automation scripts in Bash, make them executable, and schedule them using `cron`. Automation scripts can save you time and effort by handling repetitive tasks automatically. In the next lesson, we will explore more advanced topics related to scripting and automation.

## Assignment

1. Create an automation script that cleans up temporary files from a specified directory.
2. Schedule your cleanup script to run weekly using `cron`.