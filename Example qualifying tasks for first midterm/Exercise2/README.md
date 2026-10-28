## Exercise 2 - Number Class with a Lower Limit of 0

Define a class `Number` that holds an integer variable `num`. Implement the following for the class:

- A setter method.
- A `decreaseNumber` method that decrements the value of `num` by a given integer value. If the difference is less than `0`, set the value of `num` to `0` and print the message `"Difference is less than 0"`.
- A `print` method for printing the value of `num`.

**Changes to the `main` function are forbidden.**


## Задача 2 - Класа Number со долна граница од 0

Да се дефинира класа `Number` во која се чува целобројна променлива `num`. За класата да се дефинираат:

- `set` метода.
- `decreaseNumber` метода со којашто ќе се намалува вредноста на `num` за дадена целобројна вредност. Доколку разликата е помала од `0`, вредноста на `num` да се постави на `0` и да се испечати пораката `"Difference is less than 0"`.
- `print` метода за печатење на вредноста на `num`.

**Забранети се промени во `main` функцијата.**



## Test Cases


### Test Case 1

**Input:**
```text
4
1
100
2
10
3
100
1000
4
```
**Expected output:**

```text
100
90
Difference is less than 0
0
90
```



### Test Case 2

**Input:**
```text	
7
1
4
3
3
1
2
2
3
5
7
1
10
2
8
4
```
**Expected output:**

```text
4
2
2
Difference is less than 0
0
10
2
2
```
