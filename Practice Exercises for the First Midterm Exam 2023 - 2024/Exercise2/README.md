## Exercise 2 - List and List Container

Implement a class `List` that stores information about:

- Numbers that are part of the list (a dynamically allocated array of integers).
- The number of elements in the list.

The following methods should be defined for the class:

- Constructor (with arguments), copy constructor, destructor, assignment operator `=`.
- `void print()` method that prints the information about the list in the following format: `[number of elements in the list]: x1 x2 .. xn sum: [sum] average: [average]`
- `int sum()` method that returns the sum of the elements in the list.
- `double average()` method that returns the average of the numbers in the list.

Additionally, create a class `ListContainer` that stores information about:

- An array of lists (a dynamically allocated array of objects of the `List` class).
- The number of elements in the array of lists (an integer).
- The number of attempts to add a list to the container (an integer initially set to zero).

The following methods should be defined for the class:

- Default constructor, copy constructor, destructor, assignment operator `=`.
- `void print()` method that prints the information about the container in the following format: `List number: [list ordinal number] List info: [information printed using the List::print() method] \n sum: [sum] average: [average]`
  - If the container is empty, only the message `The list is empty` should be printed.
- `void addNewList(List l)` method that adds a list to the container.
  - **Note:** A list is added to the container if and only if its sum is different from the sums of all lists that have already been added to the container.
- `int sum()` method that returns the sum of all elements in all lists.
- `double average()` method that returns the average of all elements in all lists in the container.

---

## Задача 2 - Листа и контејнер од листи

Да се имплементира класа `List` во којашто ќе се чуваат информации за:

- Броеви што се дел од листата (динамички алоцирана низа од цели броеви).
- Бројот на броеви што се дел од листата.

За класата да се дефинираат следните методи:

- Конструктор (со аргументи), copy-конструктор, деструктор, оператор `=`.
- `void pecati()` метод што ќе ги печати информациите за листата во форматот: `[број на елементи во листата]: x1 x2 .. xn sum: [сума] average: [просек]`
- `int sum()` метод што ја враќа сумата на елементите во листата.
- `double average()` метод што ќе го враќа просекот на броевите во листата.

Дополнително, креирајте ја класата `ListContainer`, во којашто ќе се чуваат информации за:

- Низа од листи (динамички алоцирана низа од објекти од класата `List`).
- Број на елементи во низата од листи (цел број).
- Број на обиди за додавање на листа во контејнерот (цел број првично поставен на нула).

За класата потребно е да ги дефинирате следните методи:

- Конструктор (default), copy-конструктор, деструктор, оператор `=`.
- `void pecati()` метод што ќе ги печати информациите за контејнерот во форматот: `List number: [реден број на листата] List info: [испечатени информации за листата со методот List::pecati()] \n sum: [сума] average: [просек]`
  - Доколку контејнерот е празен, се печати само пораката `The list is empty`.
- `void addNewList(List l)` метод со којшто се додава листа во контејнерот.
  - **Напомена:** Една листа се додава во контејнерот ако и само ако има различна сума од сите листи што се веќе додадени во контејнерот.
- `int sum()` метод што ја враќа сумата на сите елементи во сите листи.
- `double average()` метод што го враќа просекот на сите елементи во сите листи во контејнерот.







 ## Test Cases


### Test Case 1

**Input:**
```text
2
1
1
2
0 1
0
```
**Expected output:**

```text
List number: 1 List info: 1: 1 sum: 1 average: 1
Sum: 1 Average: 1
Successful attempts: 1 Failed attempts: 1
```




### Test Case 2

**Input:**
```text
5
5
1 2 3 4 5
2
10 5
3
1 2 3
6
1 4 5 6 7 10
3
10 10 13
0
```
**Expected output:**

```text
List number: 1 List info: 5: 1 2 3 4 5 sum: 15 average: 3
List number: 2 List info: 3: 1 2 3 sum: 6 average: 2
List number: 3 List info: 6: 1 4 5 6 7 10 sum: 33 average: 5.5
Sum: 54 Average: 3.85714
Successful attempts: 3 Failed attempts: 2
```



### Test Case 3

**Input:**
```text
3
2
1 2
1
3
3
1 1 1
0
```
**Expected output:**

```text
List number: 1 List info: 2: 1 2 sum: 3 average: 1.5
Sum: 3 Average: 1.5
Successful attempts: 1 Failed attempts: 2
```




### Test Case 4

**Input:**
```text
6
5
1 2 3 4 5
2
1 2
3
1 1 1
4
1 1 1 1
3
1 1 2
5
10 10 10 10 10
0
```
**Expected output:**

```text
List number: 1 List info: 5: 1 2 3 4 5 sum: 15 average: 3
List number: 2 List info: 2: 1 2 sum: 3 average: 1.5
List number: 3 List info: 4: 1 1 1 1 sum: 4 average: 1
List number: 4 List info: 5: 10 10 10 10 10 sum: 50 average: 10
Sum: 72 Average: 4.5
Successful attempts: 4 Failed attempts: 2
```




### Test Case 5

**Input:**
```text
5
5
1 2 3 4 5
2
10 5
3
1 2 3
6
1 4 5 6 7 10
3
10 10 13
1
```
**Expected output:**

```text
Test case for operator =
The list is empty
0 54
List number: 1 List info: 5: 1 2 3 4 5 sum: 15 average: 3
List number: 2 List info: 3: 1 2 3 sum: 6 average: 2
List number: 3 List info: 6: 1 4 5 6 7 10 sum: 33 average: 5.5
Sum: 54 Average: 3.85714
Successful attempts: 3 Failed attempts: 2
54 54
```
