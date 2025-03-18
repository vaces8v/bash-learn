# Lesson 01: Project Setup

## Introduction

In this lesson, we will guide you through the process of setting up a Bash project. This foundational step is crucial for organizing your scripts and ensuring that your development environment is efficient and effective.

## Objectives

By the end of this lesson, you will be able to:

1. Create a project directory structure.
2. Initialize a Git repository for version control.
3. Set up a basic README file to document your project.
4. Understand the importance of organizing scripts and resources.

## Step 1: Create a Project Directory

Start by creating a new directory for your project. Open your terminal and run the following command:

```bash
mkdir my_bash_project
cd my_bash_project
```

## Step 2: Initialize a Git Repository

To keep track of changes in your project, initialize a Git repository:

```bash
git init
```

This command creates a new `.git` directory in your project folder, allowing you to use Git for version control.

## Step 3: Create a README File

A README file is essential for documenting your project. Create a README file using the following command:

```bash
touch README.md
```

Open the README.md file in your favorite text editor and add a brief description of your project, its purpose, and how to use it.

## Step 4: Organize Your Scripts

It's important to keep your scripts organized. Consider creating subdirectories for different types of scripts or resources. For example:

```bash
mkdir scripts
mkdir resources
```

You can place your Bash scripts in the `scripts` directory and any additional resources (like configuration files or data) in the `resources` directory.

## Conclusion

Setting up a project correctly from the beginning can save you a lot of time and effort later on. In this lesson, you learned how to create a project directory, initialize a Git repository, create a README file, and organize your scripts. 

In the next lesson, we will dive into creating an automation script for common tasks.