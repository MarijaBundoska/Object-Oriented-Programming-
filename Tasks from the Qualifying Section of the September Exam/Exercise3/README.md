## Exercise 3 - Team Project

Given a class `Project` that stores the project code and duration (in months), along with an appropriate constructor and a method for printing.

Define a class `TeamProject` that inherits from the class `Project` and includes an integer variable for the team size. The team size must be a value greater than 0 and less than 10; otherwise, set the team size to 5.

For the class `TeamProject`, define:

- An appropriate constructor.
- A method `int calculateTotalTeamHours()` that calculates the number of team hours based on the project duration and team size (`duration + team_size * 160`).
- A method `void showInfo()` that prints the project code and the team size.


## Задача 3 - Тимски проект

Дадена е класата `Project`, во која се чуваат кодот на проектот и времетраењето (во месеци), со соодветен конструктор и метода за печатење.

Да се дефинира класа `TeamProject` која наследува од класата `Project` и која вклучува целобројна променлива за големината на тимот. Големината на тимот мора да биде вредност поголема од 0 и помала од 10; во спротивно, големината да се постави на 5.

За класата `TeamProject` да се дефинира:

- Соодветен конструктор.
- Метод `int calculateTotalTeamHours()` со којшто се пресметува бројот на тимски часови врз основа на времетраењето на проектот и големината на тимот (`duration + team_size * 160`).
- Метод `void showInfo()`, којшто го печати кодот на проектот и големината на тимот.




## Test Cases


### Test Case 1

**Input:**
```text
1
```
**Expected output:**

```text
Project1 2 5
```



### Test Case 2

**Input:**
```text
2
```
**Expected output:**

```text
CS101 5 3
CS102 7 2
```




### Test Case 3

**Input:**
```text
3
```
**Expected output:**

```text
CS101 5 5
CS102 7 5
```



### Test Case 4

**Input:**
```text
4
```
**Expected output:**

```text
164
```



### Test Case 5

**Input:**
```text
5
3
Project1 1 3
Project2 2 6
Project3 3 9
```
**Expected output:**

```text
Project1 1 3
Project2 2 6
Project3 3 9
```



### Test Case 6

**Input:**
```text
5
3
Project1 1 13
Project2 2 -6
Project3 3 9
```
**Expected output:**

```text
Project1 1 5
Project2 2 5
Project3 3 9
```



### Test Case 7

**Input:**
```text
6
3
Project1 10 3
Project2 12 6
Project3 9 9
```
**Expected output:**

```text
Project1 10 3
Project2 12 6
Project3 9 9
490
972
1449
```



### Test Case 8

**Input:**
```text
6
3
Project1 10 -3
Project2 12 16
Project3 9 9
```
**Expected output:**

```text
Project1 10 5
Project2 12 5
Project3 9 9
810
812
1449
```
