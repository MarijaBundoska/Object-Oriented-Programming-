## Exercise 4 - Temperature Class with Changeable Value

Define a class `Temperature` that holds a floating-point variable `temp`. Implement the following for the class:

- A setter method.
- A `changeTemp` method that increments `temp` by one if its value is negative, and decrements it by one if its value is positive.
- A `print` method for printing the value of `temp`.

**Do not change the `main` function.**


## Задача 4 - Класа Temperature со промена на вредноста

Да се дефинира класа `Temperature` во која се чува реална променлива `temp`. За класата да се дефинираат:

- `set` метода.
- `changeTemp` метода со којашто, доколку вредноста на `temp` е негативна, ќе се зголеми за еден, а доколку е позитивна, ќе се намали за еден.
- `print` метода за печатење на вредноста на `temp`.

**Забранети се промени во `main` функцијата.**



## Test Cases


### Test Case 

**Input:**
```text
4
1
2.0
2
3
-10.5
4
```
**Expected output:**

```text
2
1
-9.5
1
```


### Test Case 

**Input:**
```text
10
1
23
2
3
2.6
4
3
28
1
-3.3
2
3
-4.4
2
4
```
**Expected output:**

```text
23
22
1.6
22
27
-3.3
-2.3
-3.4
-1.3
-1.3
```
