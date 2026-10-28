## Exercise 3 - Number Class with a Lower Limit of 0

Define a class `Number` that holds an integer variable `num`. Implement the following for the class:

- A setter method.
- A `decreaseNumber` method that decrements the value of `num` by a given integer value. If the difference is less than `0`, set the value of `num` to `0` and print the message `"Difference is less than 0"`.
- A `print` method for printing the value of `num`.

**Changes to the `main` function are forbidden.**


## Задача 3 - Класа Number со долна граница од 0

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
11.5
2
3
-10.1
4
```
**Expected output:**

```text
11.5
1
-11.1
1
```



### Test Case 2

**Input:**
```text
10
1
3.3
2
3
-2.0
4
3
-18.3
1
23
2
3
24
2
4
```
**Expected output:**

```text
3.3
1
-3
1
-19.3
23
2
25
3
3
```
