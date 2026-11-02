## Exercise 1 - OnlineCourse Class with Bonus Credits

Given a class `Course` that stores the code and credits of a course, along with an appropriate constructor and a printing method.

Define a class `OnlineCourse` that inherits from the `Course` class and includes an integer variable for bonus credits. The number of bonus credits must be greater than `0` and less than `3`; otherwise, the bonus should be set to `1`.

For the `OnlineCourse` class, define:

- An appropriate constructor.
- A method `int calculateMaxCourseCredits()` that calculates the maximum number of credits for the course (course credits + bonus credits).
- A printing method `void display()` that prints the course code, number of credits, and number of bonus credits.


## Задача 1 - Класа OnlineCourse со бонус кредити

Дадена е класа `Course` во која се чува кодот и бројот на кредити на курсот, соодветен конструктор и метода за печатење.

Да се дефинира класа `OnlineCourse` која наследува од класата `Course` и која вклучува целобројна променлива за бонус кредити. Бројот на бонус кредити мора да биде вредност поголема од `0` и помала од `3`, во спротивно бонусот да се постави на `1`.

За класата `OnlineCourse` да се дефинираат:

- Соодветен конструктор.
- Методата `int calculateMaxCourseCredits()` со којашто се пресметува бројот на максимални кредити од курсот (кредити на курсот + бонус кредити).
- Метода за печатење `void display()`, којашто го печати кодот на курсот, бројот на кредити и бројот на бонус кредити.






## Test Cases


### Test Case 1

**Input:**
```text
1
```
**Expected output:**

```text
CS101 6 1
```



### Test Case 2

**Input:**
```text
2
```
**Expected output:**

```text
CS101 6 1
CS102 4 2
```




### Test Case 3

**Input:**
```text
3
```
**Expected output:**

```text
CS101 5 1
CS102 6 1
```




### Test Case 4

**Input:**
```text
4
```
**Expected output:**

```text
9
```





### Test Case 5

**Input:**
```text
5
3
CS101 4 2
CS102 5 1
CS103 6 2
```
**Expected output:**

```text
CS101 4 2
CS102 5 1
CS103 6 2
```





### Test Case 6

**Input:**
```text
5
3
CS101 6 3
CS102 7 -1
CS103 8 2
```
**Expected output:**

```text
CS101 6 1
CS102 7 1
CS103 8 2
```





### Test Case 7

**Input:**
```text
6
3
CS101 4 2
CS102 5 1
CS103 6 2
```
**Expected output:**

```text
CS101 4 2
CS102 5 1
CS103 6 2
6
6
8
```




### Test Case 8

**Input:**
```text
6
3
CS101 6 3
CS102 7 -1
CS103 8 2
```
**Expected output:**

```text
CS101 6 1
CS102 7 1
CS103 8 2
7
8
10
```
