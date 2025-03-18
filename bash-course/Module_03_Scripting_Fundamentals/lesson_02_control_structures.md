# Control Structures in Bash

In this lesson, we will explore control structures in Bash scripting, which are essential for making decisions and controlling the flow of execution in your scripts. Control structures include conditionals and loops, allowing you to execute different code based on certain conditions or to repeat code multiple times.

## 1. Conditionals

Conditionals allow you to execute different commands based on whether a condition is true or false. The most common conditional statements in Bash are `if`, `else`, and `elif`.

### Syntax

```bash
if [ condition ]; then
    # commands to execute if condition is true
elif [ another_condition ]; then
    # commands to execute if another_condition is true
else
    # commands to execute if none of the above conditions are true
fi
```

### Example

```bash
#!/bin/bash

read -p "Enter a number: " number

if [ $number -gt 0 ]; then
    echo "The number is positive."
elif [ $number -lt 0 ]; then
    echo "The number is negative."
else
    echo "The number is zero."
fi
```

## 2. Loops

Loops allow you to execute a block of code multiple times. Bash supports several types of loops, including `for`, `while`, and `until`.

### For Loop

The `for` loop iterates over a list of items.

#### Syntax

```bash
for item in list; do
    # commands to execute for each item
done
```

#### Example

```bash
#!/bin/bash

for i in {1..5}; do
    echo "Iteration number: $i"
done
```

### While Loop

The `while` loop continues to execute as long as a specified condition is true.

#### Syntax

```bash
while [ condition ]; do
    # commands to execute while condition is true
done
```

#### Example

```bash
#!/bin/bash

count=1
while [ $count -le 5 ]; do
    echo "Count is: $count"
    ((count++))
done
```

### Until Loop

The `until` loop continues to execute until a specified condition becomes true.

#### Syntax

```bash
until [ condition ]; do
    # commands to execute until condition is true
done
```

#### Example

```bash
#!/bin/bash

count=1
until [ $count -gt 5 ]; do
    echo "Count is: $count"
    ((count++))
done
```

## 3. Summary

In this lesson, we covered the basics of control structures in Bash scripting, including conditionals and loops. Understanding these concepts is crucial for writing effective scripts that can make decisions and repeat tasks as needed.

## 4. Assignment

Create a Bash script that uses both conditionals and loops. The script should prompt the user for a number and print whether it is even or odd for numbers from 1 to that number.