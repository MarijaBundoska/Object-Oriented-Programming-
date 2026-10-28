## Exercise 5 - Letter Class with Uppercase Conversion

Define a class `Letter` that holds a character variable `ch`. Implement the following for the class:

- The necessary constructors (the default value of `ch` is the letter **`a`**).
- An `upperLetter` method that converts the letter to uppercase. If the character is not a letter, print the error message `"Character is not a letter"`. Use the `isalpha` and `toupper` functions.
- A getter method for `ch`.

**Do not change the `main` function.**



## Задача 5 - Класа Letter со претворање во голема буква

Да се дефинира класа `Letter` во која се чува еден знак `ch`. За класата да се дефинираат:

- Потребните конструктори (подразбирлива вредност за `ch` е буквата **`a`**).
- `upperLetter` метода со којашто буквата ќе се претвори во голема буква. Доколку знакот не е буква, да се испечати пораката за грешка `"Character is not a letter"`. Да се користат методите `isalpha` и `toupper`.
- `get` метода за пристап до вредноста на `ch`.

**Забранети се промени во `main` функцијата.**


## Test Cases


### Test Case 1

**Input:**
```text
4
1
b
4
3
2
2
```
**Expected output:**

```text
b
b
Character is not a letter
2
B
```


### Test Case 2

**Input:**
```text
10
1
p
2
3
y
4
3
1
1
t
2
3
a
1
w
2
```
**Expected output:**

```text
p
P
Y
P
Character is not a letter
1
t
T
A
w
W
```
