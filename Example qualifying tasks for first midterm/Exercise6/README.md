## Exercise 6 - Letter Class with Lowercase Conversion

Define a class `Letter` that holds a character variable `ch`. Implement the following for the class:

- A setter method.
- A `lowerLetter` method that converts the letter to lowercase. If the character is not a letter, print the error message `"Character is not a letter"`. Use the `isalpha` and `tolower` functions.
- A `print` method for printing the value of `ch`.

**Do not change the `main` function.**

---

## Задача 6 - Класа Letter со претворање во мала буква

Да се дефинира класа `Letter` во која се чува еден знак `ch`. За класата да се дефинираат:

- `set` метода.
- `lowerLetter` метода со којашто буквата ќе се претвори во мала буква. Доколку знакот не е буква, да се испечати пораката за грешка `"Character is not a letter"`. Да се користат методите `isalpha` и `tolower`.
- `print` метода за печатење на вредноста на `ch`.

**Забранети се промени во `main` функцијата.**



## Test Cases


### Test Case 1

**Input:**
```text
4
1
A
4
3
2
2
```
**Expected output:**

```text
A
A
Character is not a letter
2
a
```




### Test Case 2

**Input:**
```text
10
1
Q
2
3
C
4
3
A
1
T
2
3
3
1
N
2
```
**Expected output:**

```text
Q
q
c
q
a
T
t
Character is not a letter
3
N
n
```
