# Lesson 02: Files and Directories

## Introduction
In this lesson, we will explore how to manage files and directories in Bash. Understanding how to navigate and manipulate the filesystem is crucial for effective use of the command line.

## Navigating the Filesystem
- **pwd**: Print Working Directory
  - Displays the current directory you are in.
  - Example: 
    ```
    pwd
    ```

- **ls**: List Directory Contents
  - Lists files and directories in the current directory.
  - Options:
    - `-l`: Long format, shows detailed information.
    - `-a`: Includes hidden files.
  - Example:
    ```
    ls -la
    ```

- **cd**: Change Directory
  - Used to navigate between directories.
  - Example:
    ```
    cd /path/to/directory
    ```

## Creating and Removing Files and Directories
- **mkdir**: Make Directory
  - Creates a new directory.
  - Example:
    ```
    mkdir new_directory
    ```

- **touch**: Create Empty File
  - Creates a new empty file or updates the timestamp of an existing file.
  - Example:
    ```
    touch new_file.txt
    ```

- **rm**: Remove Files
  - Deletes files.
  - Use with caution, as this action is irreversible.
  - Example:
    ```
    rm file_to_delete.txt
    ```

- **rmdir**: Remove Directory
  - Deletes an empty directory.
  - Example:
    ```
    rmdir empty_directory
    ```

## Moving and Copying Files
- **mv**: Move or Rename Files
  - Moves files or directories from one location to another or renames them.
  - Example:
    ```
    mv old_name.txt new_name.txt
    mv file.txt /path/to/destination/
    ```

- **cp**: Copy Files
  - Copies files or directories.
  - Options:
    - `-r`: Recursively copy directories.
  - Example:
    ```
    cp file.txt /path/to/destination/
    cp -r directory/ /path/to/destination/
    ```

## Conclusion
In this lesson, we covered the essential commands for managing files and directories in Bash. Mastering these commands will enhance your ability to navigate and manipulate the filesystem efficiently.

## Assignment
- Create a directory structure for a project.
- Create several files within that structure.
- Move, rename, and delete files as per the instructions provided in the assignment file.