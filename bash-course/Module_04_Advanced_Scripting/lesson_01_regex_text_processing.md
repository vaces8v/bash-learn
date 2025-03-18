# Regular Expressions and Text Processing in Bash

## Introduction to Regular Expressions

Regular expressions (regex) are powerful tools for searching and manipulating text. In Bash, they are commonly used with commands like `grep`, `sed`, and `awk` to process text data efficiently. Understanding regex will enable you to perform complex text processing tasks with ease.

## Basic Syntax of Regular Expressions

1. **Literal Characters**: Matches the exact characters. For example, `cat` matches the string "cat".
2. **Metacharacters**: Special characters that have specific meanings:
   - `.`: Matches any single character.
   - `^`: Matches the start of a line.
   - `$`: Matches the end of a line.
   - `*`: Matches zero or more occurrences of the preceding element.
   - `+`: Matches one or more occurrences of the preceding element.
   - `?`: Matches zero or one occurrence of the preceding element.
   - `[]`: Matches any one of the enclosed characters (e.g., `[abc]` matches "a", "b", or "c").
   - `|`: Acts as a logical OR (e.g., `cat|dog` matches either "cat" or "dog").

## Using Regular Expressions in Bash

### 1. Using `grep`

The `grep` command is used to search for patterns in files. Here are some examples:

- **Basic Search**:
  ```bash
  grep "pattern" filename
  ```

- **Using Regex**:
  ```bash
  grep "^start" filename  # Matches lines that start with "start"
  grep "end$" filename    # Matches lines that end with "end"
  grep "a.*b" filename    # Matches lines containing "a" followed by "b"
  ```

### 2. Using `sed`

The `sed` command is a stream editor that can perform basic text transformations on an input stream (a file or input from a pipeline).

- **Substitution**:
  ```bash
  sed 's/old/new/g' filename  # Replaces all occurrences of "old" with "new"
  ```

- **Using Regex**:
  ```bash
  sed -n '/^start/p' filename  # Prints lines that start with "start"
  ```

### 3. Using `awk`

The `awk` command is a programming language designed for text processing. It is particularly useful for extracting and manipulating data from structured text files.

- **Basic Usage**:
  ```bash
  awk '/pattern/ {print $0}' filename  # Prints lines matching the pattern
  ```

- **Using Regex**:
  ```bash
  awk '/^start/ {print $1}' filename  # Prints the first field of lines starting with "start"
  ```

## Practical Examples

### Example 1: Extracting Email Addresses

You can use regex to extract email addresses from a text file:

```bash
grep -E "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}" file.txt
```

### Example 2: Replacing Text

Using `sed` to replace all occurrences of "foo" with "bar":

```bash
sed -i 's/foo/bar/g' file.txt
```

## Conclusion

Regular expressions are an essential skill for anyone working with text in Bash. They allow for powerful text processing capabilities that can save time and effort. Practice using regex with different commands to become proficient in text manipulation.

## Assignment

1. Write a script that uses `grep` to find all lines in a file that contain a specific word.
2. Create a `sed` command that replaces all instances of a specific string in a file.
3. Use `awk` to print the second column of a CSV file where the first column matches a specific pattern.