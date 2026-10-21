## Exercise 3 - Students, Courses, and Demonstrators

A class `Kurs` is given, which stores information about the course name (a character string) and the number of credits (an integer).

A class `Student` is given, which stores information about the student's index number (an integer), an array of the student's grades (a dynamically allocated array of grades represented by numbers from 5 to 10), and the number of grades.

A class `Predavach` is given, which stores information about the lecturer's name (a dynamically allocated character array), a list of courses taught by the lecturer (an array of objects of class `Kurs`), and the number of courses (an integer).

Create a class `Demonstrator`, representing students who conduct laboratory exercises for certain courses. Objects of this class should store the following information: the student's index number, grades, number of grades, demonstrator's name, list of courses, number of courses for which the student conducts laboratory exercises, and the number of hours per week during which the student conducts laboratory exercises (an integer). **(5 points)**

The following functions must be provided for each student:

- `getBodovi()` – returns an integer representing the student's points. Students who are not demonstrators receive points equal to the percentage of passing grades. For example, a student with grades `5 6 7` receives 66 points (the integer part of 66.666...) because 66% of the grades are greater than 5. For each demonstrator, points from laboratory exercises are added to the points from grades, according to the formula `(20 * C) / N`, where `N` is the number of courses the student teaches and `C` is the number of hours per week during which the student conducts laboratory exercises. If a demonstrator does not teach any courses, the exception `NoCourseException` must be thrown. The exception must be handled where appropriate, and the following error message must be printed: `"Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi"`, where `XXXX` is the demonstrator's index number. **(15 points)**
- `pecati()` – prints only the student's index number if the student is not a demonstrator. If the student is a demonstrator, information about the courses for which the demonstrator conducts laboratory exercises must also be printed. **(10 points)**

The output format is:

```text
Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)
```

Implement the following global functions:

- `Student& vratiNajdobroRangiran(Student** studenti, int n)` – returns a reference to the student with the highest number of points from the given list of `n` students (`studenti`). Demonstrators who do not conduct laboratory exercises are considered to have 0 points. The examples always contain exactly one student with the highest number of points. **(15 points)**
- `void pecatiDemonstratoriKurs(char* kurs, Student** studenti, int n)` – prints only those students from the given list who conduct laboratory exercises for the specified course `kurs`. **(10 points)**

Implement the complete functionality of the program. **(5 points)**

Note that the existing classes `Kurs`, `Student`, and `Predavach` may be extended or modified. Refer to the provided classes, which include additional functions that can be used besides the constructors.

## Задача 3 - Студенти, курсеви и демонстратори

Дадена е класа `Kurs` во која се чуваат информации за името на курсот (низа од знаци) и бројот на кредити (цел број).

Дадена е класа `Student` што содржи информации за индексот на студентот (цел број), низа од оценки на студентот (динамички алоцирана низа од оценки кои претставуваат броеви од 5 до 10) и бројот на оценки.

Дадена е класа `Predavach` што содржи информации за името на предавачот (динамички алоцирана низа од знаци), листа од курсеви кои ги предава предавачот (низа од објекти од класата `Kurs`) и бројот на курсеви (цел број).

Да се креира класа `Demonstrator`, со која се претставуваат студентите кои држат лабораториски вежби на некои курсеви. Објектите од оваа класа треба да содржат информации за индексот на студентот, оценките на студентот, бројот на оценки, името на демонстраторот, листата од курсеви, бројот на курсеви чии лабораториски вежби ги држи студентот и бројот на часови во неделата кога студентот држи лабораториски вежби (цел број). **(5 поени)**

За секој студент да се овозможат следните функции:

- `getBodovi()` – која враќа цел број што го претставува бројот на бодови за даден студент. Студентите кои не се демонстратори имаат бодови што го претставуваат процентот на преодни оценки на студентот. На пример, студент со оценки `5 6 7` ќе има 66 бодови (цел дел од 66.666...), затоа што во 66% од оценките има оценка поголема од 5. Кај секој демонстратор, на овие бодови од оценките им се додаваат бодовите од лабораториските вежби според формулата `(20 * C) / N`, каде што `N` е бројот на курсеви што ги држи, а `C` е бројот на часови во неделата кога студентот држи лабораториски вежби. Во случај кога некој демонстратор не држи ниту еден курс, се фрла исклучокот `NoCourseException`. Исклучокот треба да се обработи онаму каде што е потребно, при што треба да се испечати пораката за грешка `"Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi"`, каде што `XXXX` е индексот на демонстраторот. **(15 поени)**
- `pecati()` – во која се печати само индексот на студентот ако студентот не е демонстратор, а во случај кога студентот е демонстратор, во продолжение се печатат информации за курсевите чии лабораториски вежби ги држи демонстраторот. **(10 поени)**

Форматот за печатење е:

```text
Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)
```

Да се имплементираат следните глобални функции:

- `Student& vratiNajdobroRangiran(Student** studenti, int n)` – што враќа референца кон студентот кој има најмногу бодови од листата на дадените `n` студенти (`studenti`). Демонстраторите кои не држат лабораториски вежби се смета дека имаат 0 бодови. Во примерите секогаш има точно еден студент кој има најголем број на бодови. **(15 поени)**
- `void pecatiDemonstratoriKurs(char* kurs, Student** studenti, int n)` – која од дадена листа на студенти ќе ги испечати само оние кои држат лабораториски вежби на курсот `kurs`. **(10 поени)**

Да се имплементира целосната функционалност на програмата. **(5 поени)**

Да забележиме дека веќе постоечките класи `Kurs`, `Student` и `Predavach` може да се дополнуваат и менуваат. Погледнете ги дадените класи. Во нив, покрај конструкторите, дадени се и други функции што можат да се користат.






## Test Cases


### Test Case 1

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




### Test Case 2

**Input:**
```text
4
11020 5 5 6 7 5 8
A.Angelovski 2 OOP 6 Angliski 2
10
```
**Expected output:**

```text
-----TEST getVkupnaOcenka-----
Broj na bodovi: 160
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
-----TEST pecati -----
11020: A.Angelovski (OOP 6ECTS, Angliski 2ECTS, Kalkulus 6ECTS, DMatematika 6ECTS, Infromatika 3ECTS)
```




### Test Case 9

**Input:**
```text
1
11020 5 5 6 7 5 8
A.Angelovski 2 OOP 6 Angliski 2
10
```
**Expected output:**

```text
-----TEST Demonstrator-----
Objekt od klasata Demonstrator e kreiran
```



### Test Case 10

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
