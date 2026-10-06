# Exercise 9 - Student and PhD Student Management

## Problem Description

Implement a class `Work` that stores information about: **(5 points)**

- **Work type** — one character:
  - `C` for a conference paper
  - `J` for a journal paper
- **Publication year** — an integer

Implement a class `Student` that stores: **(5 points)**

- **Student name** — an array of at most 30 characters
- **Index** — an integer
- **Enrollment year** — an integer
- **List of grades from passed courses** — an array of integers
- **Number of passed courses** — an integer

For this class, implement the following methods:

- `rank()` — calculates the average grade of the student's passed exams. **(5 points)**
- `operator<<` — prints the student in the following format: **(5 points)**

```text
Index Name Enrollment Year Rank
```
Implement a class PhDStudent that, in addition to the basic student information, stores: (5 points)
- List of published works — a dynamically allocated array of objects of the `Work` class
- Number of works — an integer

- In this class, appropriately override the `rank()` function so that, in addition to the average grade from the passed exams, the total points earned from the published works of the PhD student are also added.

- Depending on the type of work, each university has a specific way of awarding points for publications. The scoring system is the same for all PhD students.

Initially, a conference paper is worth 1 point, while a journal paper is worth 3 points.
The university has the ability to change these point values. **(5 points + 5 points)**
For this class, provide:

- `operator+=` — adds a new Work object to the list of published works. **(5 points)**
If an attempt is made to add a work that was published before the student's enrollment year, an exception (an object of the Exception class) should be thrown.
Exception handling should be implemented in the main function where necessary, and also in the constructor if needed.

If an exception is generated, the following error message should be printed:

```text
Ne moze da se vnese dadeniot trud
```

The new work must not be added to the student's list of works. **(10 points)**
Note: All class variables must be declared as private.

Provide all necessary functions required for the correct functioning of the program. **(5 points)**




# Вежба 9 - Управување со студенти и PhD студенти

## Опис на задачата

Да се имплементира класа `Trud` во која се чуваат информации за: **(5 поени)**

- **Вид на труд** — еден знак:
  - `C` за конференциски труд
  - `J` за труд во списание
- **Година на издавање** — цел број

Да се имплементира класа `Student` во која се чува: **(5 поени)**

- **Името на студентот** — низа од најмногу 30 карактери
- **Индекс** — цел број
- **Година на упис** — цел број
- **Листа на оцени од положени предмети** — низа од цели броеви
- **Број на положени предмети** — цел број

За оваа класа да се имплементираат следните методи:

- `rang()` — што пресметува просек од положените испити на студентот. **(5 поени)**
- `оператор <<` за печатење на студентот во формат: **(5 поени)**
```text
Индекс Име Година на упис Ранг
```
Да се имплементира класа PhDStudent во која покрај основните информации за студентот дополнително се чува: **(5 поени)**
- Листа од објавени трудови — динамички резервирана низа од објекти од класата Trud
- бројот на трудови — цел број

- Во оваа класа да се препокрие соодветно функцијата rang() така што на просекот од положените испити ќе се додаде и збирот од поените од објавените трудови на PhD студентот.

- Во зависност од видот на трудот, секој универзитет има посебен начин на бодување на трудовите. Начинот на бодување е ист за сите PhD студенти.

Иницијално да се смета дека конференциски труд се бодува со 1 поен, а труд во списание со 3 поени.
Универзитетот има можност да ги менува вредностите на бодовите. **(5 поени + 5 поени)**

За оваа класа да се обезбеди:

- `оператор +=` — за додавање нов објект од класата Trud во листата. **(5 поени)**
Ако се направи обид да се внесе труд што е издаден порано од годината на упис на студентот, да се фрли исклучок (објект од класата `Exception`).
Справувањето со исклучокот треба да се реализира во главната функција main каде што е потребно, но и во конструктор ако е потребно.

Ако бил генериран исклучок, треба да се отпечати соодветна порака за грешка:

```text
Ne moze da se vnese dadeniot trud
```

Новиот труд нема да се внесе во листата на трудови од студентот. **(10 поени)**
Напомена: Сите променливи на класите се чуваат како приватни.

Да се обезбедат сите потребни функции за правилно функционирање на програмата. **(5 поени)**


## Test Cases


### Test Case 1

**Input:**
```text
2
3
1
PhDStudent_1
111222
2012
5
10 10 10 9 10
1
j
2015
1
PhDStudent_2
123456
2003
5
10 9 10 8 10
3
c
2003
j
2003
j
2005
0
Student
12234
2010
3
10 10 10
123456
C
2004
```
**Expected output:**

```text
===== Testiranje na operatorot += ======

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 16.4
12234 Student 2010 10

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 17.4
12234 Student 2010 10
```



### Test Case 2

**Input:**
```text
4
PhDStudent
123456
2003
5
10 9 10 8 10
3
c
2003
j
2001
J
2005
```
**Expected output:**

```text
===== Testiranje na isklucoci ======
Ne moze da se vnese dadeniot trud
123456 PhDStudent 2003 13.4
```



### Test Case 3

**Input:**
```text
	
6
3
1
PhDStudent_1
111222
2012
5
10 10 10 9 10
1
j
2015
1
PhDStudent_2
123456
2003
5
10 9 10 8 10
3
c
2003
j
2003
j
2005
0
Student
12234
2010
3
10 10 10
2
5
```
**Expected output:**

```text
===== Testiranje na static clenovi ======

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 16.4
12234 Student 2010 10

Lista na site studenti:
111222 PhDStudent_1 2012 14.8
123456 PhDStudent_2 2003 21.4
12234 Student 2010 10
```



### Test Case 4

**Input:**
```text
1
Student
12234
2010
3
10 10 10
PhDStudent
123456
2003
5
10 9 10 8 10
3
c
2003
j
2008
j
2005
```
**Expected output:**

```text
===== Testiranje na klasite ======
12234 Student 2010 10
123456 PhDStudent 2003 16.4
```




### Test Case 5

**Input:**
```text	
2
3
1
PhDStudent_1
111222
2012
5
10 10 10 9 10
1
j
2015
1
PhDStudent_2
123456
2003
5
10 9 10 8 10
3
c
2003
j
2003
j
2005
0
Student
12234
2010
3
10 10 10
12234
C
2004
```
**Expected output:**

```text
===== Testiranje na operatorot += ======

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 16.4
12234 Student 2010 10
Ne postoi PhD student so indeks 12234

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 16.4
12234 Student 2010 10
```



### Test Case 6

**Input:**
```text
5
3
1
PhDStudent_1
111222
2012
5
10 10 10 9 10
1
j
2015
1
PhDStudent_2
123456
2003
5
10 9 10 8 10
3
c
2003
j
2003
j
2005
0
Student
12234
2010
3
10 10 10
111222
C
2010
```
**Expected output:**

```text
===== Testiranje na isklucoci ======

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 16.4
12234 Student 2010 10
Ne moze da se vnese dadeniot trud

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 16.4
12234 Student 2010 10
```
