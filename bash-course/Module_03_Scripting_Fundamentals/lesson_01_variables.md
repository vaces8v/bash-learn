# Variables in Bash Scripting

## Introduction to Variables

In Bash scripting, a variable is a way to store data that can be referenced and manipulated throughout your script. Variables can hold different types of data, such as strings, numbers, and arrays. Understanding how to use variables is fundamental to writing effective Bash scripts.

## Declaring Variables

To declare a variable in Bash, you simply assign a value to a name without any spaces around the equal sign. For example:

```bash
my_variable="Hello, World!"
```

In this example, `my_variable` is the name of the variable, and it holds the string value "Hello, World!".

## Accessing Variables

To access the value of a variable, you prefix the variable name with a dollar sign (`$`). For example:

```bash
echo $my_variable
```

This command will output:

```
Hello, World!
```

## Variable Types

1. **String Variables**: These hold text data.
   ```bash
   greeting="Hello"
   ```

2. **Numeric Variables**: These hold numerical values.
   ```bash
   number=42
   ```

3. **Array Variables**: These hold multiple values.
   ```bash
   fruits=("apple" "banana" "cherry")
   ```

## Modifying Variables

You can change the value of a variable at any time by reassigning it:

```bash
my_variable="New Value"
```

## Special Variables

Bash also has several special variables that are predefined:

- `$0`: The name of the script.
- `$1`, `$2`, ...: The positional parameters (arguments passed to the script).
- `$#`: The number of arguments passed to the script.
- `$@`: All the arguments passed to the script.

## Example Script

Here’s a simple example of a Bash script that uses variables:

```bash
#!/bin/bash

name="Alice"
age=30

echo "My name is $name and I am $age years old."
```

## Conclusion

Variables are a powerful feature in Bash scripting that allow you to store and manipulate data. Mastering variables will enable you to create more dynamic and flexible scripts. In the next lesson, we will explore control structures that allow you to control the flow of your scripts based on conditions. 

## Assignment

1. Create a Bash script that declares three variables: your name, your favorite color, and your age. Print a sentence using these variables.
2. Modify the script to change the value of your favorite color and print the updated sentence.