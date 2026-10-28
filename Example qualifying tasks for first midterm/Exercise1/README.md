## Exercise 1 - Number Class with an Upper Limit of 100

Define a class `Number` that holds an integer variable `num`. Implement the following for the class:

- The necessary constructors.
- An `increaseNumber` method that increments the value of `num` by a given integer value. If the sum is greater than `100`, set the value of `num` to `100` and print the message `"Sum is greater than 100"`.
- A getter method for `num`.

**Do not change the `main` function.**


## Задача 1 - Класа Number со горна граница од 100

Да се дефинира класа `Number` во која се чува целобројна променлива `num`. За класата да се дефинираат:

- Потребните конструктори.
- Методата `increaseNumber`, со којашто ќе се зголеми вредноста на `num` за дадена целобројна вредност. Доколку збирот е поголем од `100`, вредноста на `num` да се постави на `100` и да се испечати пораката `"Sum is greater than 100"`.
- Методата `get` за пристап до вредноста на `num`.

**Забранети се промени во `main` функцијата.**





## Test Cases


### Test Case 1

**Input:**
```text
4
1
100
2
1000
3
10
10
4
```
**Expected output:**

```text
100
Sum is greater than 100
100
20
100
```



### Test Case 2

**Input:**
```text
7
1
5
3
98
3
2
2
3
7
2
1
1
2
100
4
```
**Expected output:**

```text
5
Sum is greater than 100
100
2
9
1
Sum is greater than 100
100
100
```
