# Exercise 3 - Student and Demonstrator Management System

## Problem Description

A class `Kurs` is given, which stores information about the course name (an array of characters) and the number of credits (an integer).

A class `Student` is given, which contains information about: the student's index (an integer), an array of the student's grades (a dynamically allocated array of grades represented by numbers from 5 to 10), and the number of grades.

A class `Predavach` is given, which contains information about: the lecturer's name (a dynamically allocated array of characters), a list of courses taught by the lecturer (an array of objects of the class `Kurs`), and the number of courses (an integer).

Create a class `Demonstrator`, which represents students who teach laboratory exercises for some courses. The objects of this class should contain information about: the student's index, the student's grades, the number of grades, the demonstrator's name, the list of courses, the number of courses whose laboratory exercises the student teaches, and the number of hours per week during which the student teaches laboratory exercises (an integer).

**(5 points)**

## Functions

For each student, the following functions should be provided:

- `getBodovi()` – returns an integer representing the number of points for a given student. Students who are not demonstrators have points representing the percentage of passing grades of the student. (For example, a student with grades: `5 6 7` will have `66` points (the integer part of `66.666...`) because 66% of the grades are greater than 5). For each demonstrator, the points obtained from the grades are increased by the points from the laboratory exercises: `(20 * C) / N`, where `N` is the number of courses taught by the demonstrator, and `C` is the number of hours per week during which the student teaches laboratory exercises. If a demonstrator does not teach any courses, the `NoCourseException` exception is thrown. The exception should be handled where necessary, and an appropriate error message should be printed: `"Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi"`, where `XXXX` is the demonstrator's index.

**(15 points)**

- `pecati()` – prints only the student's index if the student is not a demonstrator, and in the case when the student is a demonstrator, information about the courses whose laboratory exercises the demonstrator teaches is also printed.

**(10 points)**

The printing format is:

```text
Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)
```

## Global Functions

The following global functions should be implemented:

- `Student& vratiNajdobroRangiran(Student ** studenti, int n )` – returns a reference to the student who has the highest number of points from the list of the given `n` students (`studenti`). Note that demonstrators who do not teach laboratory exercises are considered to have 0 points. Note also that in the examples there is always exactly one student who has the highest number of points.

**(15 points)**

- `void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n)` – from a given list of students, prints only those who teach laboratory exercises for the course `kurs`.

**(10 points)**

Complete functionality of the program.

**(5 points)**

Note that the already existing classes `Kurs`, `Student`, and `Predavach` can be supplemented and modified. Refer to the given classes. In addition to the constructors, other functions are also provided in them which can be used.

---

## Опис на задачата

Дадена е класа `Kurs` во која се чуваат информации за име на курс (низа од знаци) и број на кредити (цел број).

Дадена е класа `Student` што содржи инфомрации за: индекс на студентот (цел број), низа од оценки на студентот (динамички алоцирана низа на оценките кои претставуваат `броеви` од 5 до 10) и број на оценки.

Дадена е класа `Predavach` што содржи инфомрации за: име на предавачот (динамички алоцирана низа од знаци), листа од курсеви кои ги предава предавачот (низа од објекти од класата `Kurs`) и број на курсеви (цел број).

Да се креира класа `Demonstrator`, со која се претставуваат студентите држат лабораториските вежби на некои курсеви. Објектите од оваа класа треба да содржат инфомрации за: индекс на студентот, оценки на студентот, број на оценки, име на демонстраторот, листа од курсеви, број на курсеви чии лабораторисски вежби ги држи студентот и број на часови во неделата кога студентот држи лабораториски вежби (цел број). **(5 поени)**

За секој студент да се овозможат следните функции:

- `getBodovi()` - која враќа цел број кој го претставува број на бодови за даден студент. Студентите кои не се демонстратори имаат бодови кои го претставуваат процентот на преодни оценки на студентот. (На пример студент со оценки: 5 6 7 ќе има 66 бодови (цел дел од 66.666...) затоа што во 66% од оценките има оценка поголема од 5 ). Кај секој демонстратор на овие бодовите од оценките се додаваат бодовите од лабораториските вежби: (20*C)/N, каде N e бројот на курсеви кои ги држи, C бројот на часови во неделата кога студентот држи лабораториски вежби. Во случај кога некој демонстратор не држи ниту еден курс се фрла исклучокот **NoCourseException**. Справување со исклучокот треба да реализира онаму каде што е потребно и притоа да се испечати соодветна порака за грешка "Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi", каде XXXX е индексот на демонстраторот. **(15 поени)**

- `pecati()`- во која се печати само индексот на студентот ако студентот не е демонстратор, а во случај кога студентот е демонстратор во продолжение се печатат информации за курсевите чии лабораториски вежби ги држи демонстраторот. **(10 поени)**

Форматот за печатење е:

```text
Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)
```

Да се имплементираат следните глобални функции:

- `Student& vratiNajdobroRangiran(Student ** studenti, int n )` што враќа референца кон студентот кој има најмногу бодови од листата на дадените n студенти (studenti). Да забележиме дека оние демонстратори кои не држат лабораториски вежби ќе земеме дека имаат 0 бодови. Да забележиме и дека во примерите секогаш има точно еден студент кој има најголем број на бодови. **(15 поени)**

- `void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n)` - која од дадена листа на студенти, ќе ги испечати само оние кои држат лабораториски вежби на курсот kurs. **(10 поени)**

Комплетна функционалност на програмата. **(5 поени)**

Да забележиме дека веќе постоечките класи `Kurs`, `Student` и `Predavach` може да се дополнуваат и менуваат. Погледнете ги дадените класи. Во нив покрај конструкторите дадени се и други функциите кои можат да се користат.

## Test Cases

### Test Case 1

**Input:**
```text
2
11133 3 10 5 9
```
**Expected output:**
```text
-----TEST pecati-----
11133
```

### Test Case 2

**Input:**
```text
2
11133 3 10 5 9
```
**Expected output:**
```text
11133 3 10 5 9
-----TEST pecati-----
11133
```

### Test Case 3

**Input:**
```text
7
4
1 11111 3 10 5 8
2 11444 4 5 6 6 6 P.Petkovski 0 0
1 22222 3 10 9 8
2 33333 5 5 6 5 5 5 A.Angelovski 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3 10
```
**Expected output:**
```text
-----TEST vratiNajdobroRangiran-----
Demonstratorot so indeks 11444 ne drzi laboratoriski vezbi
Maksimalniot broj na bodovi e:100
Najdobro rangiran:22222
```


### Test Case 4

**Input:**
```text
3
11133 3 10 5 9

```
**Expected output:**
```text
-----TEST getVkupnaOcenka-----
Broj na bodovi: 66
```

### Test Case 5

**Input:**
```text
6
11020 5 10 6 7 10 10
A.Angelovski 4 OOP 6 Angliski 2 Kalkulus 6 Dmatematika 6
12
```
**Expected output:**
```text
-----TEST Student i Demonstrator-----
11020: A.Angelovski (OOP 6ECTS, Angliski 2ECTS, Kalkulus 6ECTS, Dmatematika 6ECTS)
Broj na bodovi: 160
```


### Test Case 6

**Input:**
```text	
8
5
2 55555 5 5 6 9 7 10 B.Boskovska 3 OOP 6 Angliski 2 DMatematika 6 10
2 44444 3 5 7 9 V.Velkovski 3 Informatika 3  OOP 6 Angliski 2 12
1 11111 3 10 5 8
1 22222 3 10 9 8
2 33333 5 5 6 10 10 10 A.Angelovski 4 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3 10
OOP
```
**Expected output:**
```text
-----TEST pecatiDemonstratoriKurs-----
Demonstratori na OOP se:
55555: B.Boskovska (OOP 6ECTS, Angliski 2ECTS, DMatematika 6ECTS)
44444: V.Velkovski (Informatika 3ECTS, OOP 6ECTS, Angliski 2ECTS)
```


### Test Case 7

**Input:**
```text	
4
11020 5 5 6 5 5 5
A.Angelovski 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10
```
**Expected output:**
```text
-----TEST getVkupnaOcenka-----
Broj na bodovi: 60
```

### Test Case 8

**Input:**
```text
5
11020 5 10 6 7 5 8
A.Angelovski 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10
```
**Expected output:**
```text
-----TEST getVkupnaOcenka-----
Broj na bodovi: 60
```

### Test Case 9

**Input:**
```text	
5
11020 5 10 6 7 5 8
A.Angelovski 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10
```
**Expected output:**
```text
11020 5 10 6 7 5 8
A.Angelovski 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10
-----TEST pecati -----
11020: A.Angelovski (OOP 6ECTS, Angliski 2ECTS, Kalkulus 6ECTS, DMatematika 6ECTS, Infromatika 3ECTS)
```

### Test Case 10

**Input:**
```text
1
11020 5 5 6 7 5 8
A.Angelovski 2 OOP 6 Angliski 2
10
```
**Expected output:**
```text
11020 5 5 6 7 5 8
A.Angelovski 2 OOP 6 Angliski 2
10
-----TEST Demonstrator-----
Objekt od klasata Demonstrator e kreiran
```

### Test Case 11

**Input:**
```text
7
3
1 11111 3 10 5 8
1 22222 3 10 9 8
2 33333 5 5 6 10 10 10
A.Angelovski 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10
```
**Expected output:**
```text
-----TEST vratiNajdobroRangiran-----
Maksimalniot broj na bodovi e:120
Najdobro rangiran:33333: A.Angelovski (OOP 6ECTS, Angliski 2ECTS, Kalkulus 6ECTS, DMatematika 6ECTS, Infromatika 3ECTS)
```
