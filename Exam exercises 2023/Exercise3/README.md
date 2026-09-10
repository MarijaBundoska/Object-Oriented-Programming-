# Exercise 3 - Student and Demonstrator Management System

### Problem Description
A class `Kurs` (Course) is defined to store information about:
* `ime` (array of characters - course name)
* `krediti` (integer - ECTS credits)

A class `Student` is defined to store information about:
* `indeks` (integer - student ID index)
* `ocenki` (dynamically allocated array of integers representing grades from 5 to 10)
* `brojOcenki` (integer - total number of grades)

A class `Predavach` (Lecturer) is defined to store information about:
* `ime` (dynamically allocated array of characters - lecturer name)
* `kursevi` (array of `Kurs` objects - list of courses taught)
* `brojKursevi` (integer - number of courses)

Create a class `Demonstrator` that inherits from both `Student` and `Predavach` (multiple inheritance) to represent students who lead lab exercises. Objects of this class store:
* Student index, grades array, number of grades
* Demonstrator name, list of courses taught, number of courses
* `brojChasovi` (integer - weekly lab hours taught)

**Member Functions:**
* `getBodovi()`: Returns an integer representing total points.
  * For regular students: Percentage of passing grades (grade > 5). Example: Grades `5, 6, 7` yield `66` points (66.66% truncated to integer).
  * For demonstrators: Base grade points plus lab points calculated as:
    $$\frac{20 \times C}{N}$$
    Where $C$ is weekly hours (`brojChasovi`) and $N$ is total courses (`brojKursevi`).
  * If a demonstrator teaches 0 courses ($N = 0$), throw a custom exception `NoCourseException`. Handle it appropriately by printing:
    `Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi` (where `XXXX` is the student index).
* `pecati()`: 
  * For regular students: Prints only the student index.
  * For demonstrators: Prints in the format:
    `Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)`

**Global Functions:**
* `Student& vratiNajdobroRangiran(Student **studenti, int n)`: Returns a reference to the student with the highest points among `n` students. Demonstrators with 0 courses are considered to have 0 points.
* `void pecatiDemonstratoriKurs(char* kurs, Student** studenti, int n)`: Prints all demonstrators who lead lab exercises for the specified `kurs`.

---


### Опис на задачата
Дадена е класа `Kurs` во која се чуваат информации за:
* `ime` (низа од знаци)
* `krediti` (цел број - кредити)

Дадена е класа `Student` која содржи информации за:
* `indeks` (цел број)
* `ocenki` (динамички алоцирана низа од оценки од 5 до 10)
* `brojOcenki` (цел број)

Дадена е класа `Predavach` која содржи информации за:
* `ime` (динамички алоцирана низа од знаци)
* `kursevi` (низа од објекти од `Kurs`)
* `brojKursevi` (цел број)

Да се креира класа `Demonstrator` преку повеќекратно наследување од `Student` и `Predavach`, која ги претставува студентите што држат лабораториски вежби. Дополнително чува:
* `brojChasovi` (цел број - број на часови во неделата кога држи лабораториски вежби)

**Методи:**
* `getBodovi()`: Враќа цел број на бодови за дадениот студент.
  * За обични студенти: Процент на преодни оценки (оценки > 5). На пример, за оценки `5, 6, 7` враќа `66` бодови (цел дел од 66.66%).
  * За демонстратори: На бодовите од оценките се додаваат бодови од вежбите по формулата:
    $$\frac{20 \times C}{N}$$
    Каде $C$ е бројот на часови во неделата, а $N$ е бројот на курсеви.
  * Доколку демонстраторот не држи ниту еден курс ($N = 0$), се фрла исклучок `NoCourseException`. При фаќање на исклучокот се печати:
    `Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi` (каде `XXXX` е индексот на демонстраторот).
* `pecati()`:
  * За обични студенти: Го печати само индексот на студентот.
  * За демонстратори: Печати во форматот:
    `Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)`

**Глобални функции:**
* `Student& vratiNajdobroRangiran(Student **studenti, int n)`: Враќа референца кон студентот со најмногу бодови. Демонстраторите без курсеви се земаат со 0 бодови.
* `void pecatiDemonstratoriKurs(char* kurs, Student** studenti, int n)`: Ги печати сите демонстратори кои држат лабораториски вежби за дадениот `kurs`.

---

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
