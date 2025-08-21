# 1. Introduction

Infix expressions are the normal mathematical expressions we write (like A + B * C).
But computers find it easier to evaluate expressions written in Postfix (Reverse Polish Notation) form (like A B C * +).<br>

So, Infix to Postfix conversion is the process of changing human-readable expressions into a format suitable for machines to evaluate.<br>

# 2. What is this?

Infix Expression: Operator is written between operands. Example: A + B.

Postfix Expression: Operator is written after operands. Example: A B +.

Conversion means taking an expression like A + B * C and rewriting it as A B C * +.

# 3. Process for Constructing It

We use a stack for operators. Rules:

1. Scan the expression from left to right.

2. If operand (A, B, numbers) → directly put in the result.

3. If operator → push into stack (consider precedence and associativity).

4. Higher precedence operators are pushed before lower precedence ones.

5. If same precedence, use associativity rule (e.g., left-to-right for +, -, *, /).

If ( → push it into stack.

If ) → pop operators until ( is found.

At end → pop all remaining operators to the result.

Example:
Infix: A + B * C
Steps:

Output: A

Push +

Output: B

Push * (higher precedence than +)

Output: C

Pop * → +
Postfix: A B C * +

# 4. Why We Use It?

Computers cannot directly evaluate infix because of precedence and brackets.

Postfix is unambiguous – order of operations is clear, no need for brackets.

Makes expression evaluation using stacks faster and simpler.

# 5. Applications

Compilers: Convert infix (human code) into postfix for easy evaluation.

Expression Evaluation: Used in calculators and interpreters.

Parsing Algorithms: Used in parsing mathematical and logical expressions.

Stack-based Machines (like JVM): Work with postfix form for execution.

# Bonus Point
in file there are two funtion<br>
## 1. infixtopostfix<br>
which takes expression and convert it into postfix.<br>
## 2. postfixtoinfix<br>
takes postfix expression and evaluate the output.<br>
## Example
infix = "2+4-6*7+(2^5-7)";<br>
After conversion into postfix-
postfix = 24+67*-25^7-+;<br>

Evaluating the expression-<br>
output: -11
