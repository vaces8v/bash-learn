# Functions in Bash

## Introduction to Functions

Functions are a fundamental aspect of Bash scripting that allow you to group commands and reuse them throughout your script. By defining functions, you can make your scripts more organized, modular, and easier to maintain.

## Defining a Function

To define a function in Bash, you can use the following syntax:

```bash
function_name() {
    # commands
}
```

Alternatively, you can define a function using the `function` keyword:

```bash
function function_name {
    # commands
}
```

### Example

Here’s a simple example of a function that prints a greeting:

```bash
greet() {
    echo "Hello, $1!"
}
```

In this example, `$1` refers to the first argument passed to the function.

## Calling a Function

Once you have defined a function, you can call it by simply using its name followed by any required arguments:

```bash
greet "World"  # Output: Hello, World!
```

## Returning Values from Functions

Bash functions can return values using the `return` statement. However, this only returns an exit status (0 for success, non-zero for failure). To return a value, you can use `echo`:

```bash
add() {
    local sum=$(( $1 + $2 ))
    echo $sum
}

result=$(add 5 3)
echo "The sum is: $result"  # Output: The sum is: 8
```

## Local Variables

You can define local variables within a function using the `local` keyword. This ensures that the variable is only accessible within the function:

```bash
my_function() {
    local var="I am local"
    echo $var
}

my_function  # Output: I am local
echo $var    # Output: (no output, var is not accessible here)
```

## Function Parameters

Functions can accept parameters, which can be accessed using `$1`, `$2`, etc. You can also use `$@` to refer to all arguments passed to the function:

```bash
print_all() {
    for arg in "$@"; do
        echo $arg
    done
}

print_all "Hello" "World" "from" "Bash"
```

## Conclusion

Functions are a powerful feature in Bash scripting that help you write cleaner and more efficient scripts. By using functions, you can encapsulate logic, reuse code, and manage complexity in your scripts. In the next lesson, we will explore control structures in more detail. 

## Assignment

1. Create a function that takes two numbers as arguments and prints their product.
2. Define a function that checks if a number is even or odd and prints the result.
3. Write a script that uses functions to perform basic arithmetic operations (addition, subtraction, multiplication, division) based on user input.