## Exercise 2 - Student Exam Results

Define a class `Student` to store information about a student who has taken an exam for a subject, including the index (string), first name (string), last name (string), and points earned on the exam (integer).

For the class, define:

- The necessary constructors.
- The print operator `<<`.
- A method `int grade()` that returns the grade for the subject based on the following scale:
  - 0–49 points: 5
  - 50–59 points: 6
  - 60–69 points: 7
  - 70–79 points: 8
  - 80–89 points: 9
  - 90–100 points: 10

**(10 points)**

Define a class `Results` to store a list of students who have passed the exam for the subject (a dynamically allocated array of objects from the `Student` class and an integer indicating the size of the list).

For the class, implement:

- The necessary constructors.
- The operator `+=` for adding a student (`Student`) to the results. **(5 points)**
  - If the student being added has less than 50 points, meaning they did not pass the exam, throw an exception of the class `StudentFailedException`. **(5 points)**
  - Handling the exception should print the message: `Student with id {ID} failed the course`. **(5 points)**
- The print operator `<<`. **(5 points)**
- A method `Results withGrade(int grade)` that takes a grade (integer) as an argument and returns a new object of the `Results` class containing only the students with the specified grade. **(5 points)**

Complete the `main` function with the following requirements:

- Read information about all students who have taken the exam from the file `input.txt` in the following format:
  - The information for each student is given in one line, in the order of index, first name, last name, and points, separated by a space.
  - After reading the information for each student, add the student to the `results` object.
- Print the results for all students to the file `output1.txt`.
- Print the results for all students with the grade `grade`, read in the initial code, to the file `output2.txt`.

**(15 points)**

---

## Задача 2 - Резултати од испит на студенти

Да се дефинира класа `Student` во која ќе се чуваат информации за студент кој полагал испит по некој предмет, и тоа индекс (стринг), име (стринг), презиме (стринг) и поени освоени на испитот (цел број).

За класата да се дефинираат:

- Потребните конструктори.
- Оператор за печатење `<<`.
- Метод `int grade()` кој ја враќа оценката по предметот според следната скала:
  - 0–49 поени: 5
  - 50–59 поени: 6
  - 60–69 поени: 7
  - 70–79 поени: 8
  - 80–89 поени: 9
  - 90–100 поени: 10

**(10 поени)**

Да се дефинира класа `Results` во која ќе се чува листа на студенти кои го положиле испитот по предметот (динамички алоцирана низа од објекти од класата `Student` и цел број кој ја означува големината на листата).

За класата да се имплементираат:

- Потребните конструктори.
- Оператор `+=` за додавање на студент (`Student`) во резултатите. **(5 поени)**
  - Доколку студентот кој се додава има помалку од 50 поени, односно не го положил испитот, да се фрли исклучок од класата `StudentFailedException`. **(5 поени)**
  - Справувањето со исклучокот треба да ја испечати пораката: `Student with id {ID} failed the course`. **(5 поени)**
- Оператор за печатење `<<`. **(5 поени)**
- Метод `Results withGrade(int grade)` кој прима како аргумент оценка (цел број), а враќа нов објект од класата `Results` во кој се содржат само студентите со оценка `grade`. **(5 поени)**

Да се дополни функцијата `main` со следните барања:

- Од датотеката `input.txt` да се прочитаат информациите за сите студенти кои го полагале испитот, во следниот формат:
  - Информациите за секој студент се дадени во еден ред, по редослед индекс, име, презиме и поени, одделени со празно место.
  - По читањето на информациите за секој студент, студентот да се додаде во објектот `results`.
- Резултатите за сите студенти да се испечатат во датотеката `output1.txt`.
- Резултатите за сите студенти со оценка `grade`, вчитана во почетниот код, да се испечатат во датотеката `output2.txt`.

**(15 поени)**





## Test Cases


### Test Case 1

**Input:**
```text
151020 Stefan Andonov 89
151021 Vlatko Spasev 55
----
9
```
**Expected output:**

```text
All students:
151020 Stefan Andonov 89 Grade: 9
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 9:
151020 Stefan Andonov 89 Grade: 9
```




### Test Case 2

**Input:**
```text
151020 Stefan Andonov 89
151021 Vlatko Spasev 55
----
6
```
**Expected output:**

```text
All students:
151020 Stefan Andonov 89 Grade: 9
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 6:
151021 Vlatko Spasev 55 Grade: 6
```




### Test Case 3

**Input:**
```text
151020 Stefan Andonov 89
151021 Vlatko Spasev 55
----
7
```
**Expected output:**

```text
All students:
151020 Stefan Andonov 89 Grade: 9
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 7:
None
```




### Test Case 4

**Input:**
```text
151020 Stefan Andonov 39
151021 Vlatko Spasev 55
----
6
```
**Expected output:**

```text
Student with id 151020 failed the course
All students:
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 6:
151021 Vlatko Spasev 55 Grade: 6
```




### Test Case 5

**Input:**
```text
123 John Doe 95
124 Jane Smith 85
125 Jim Brown 75
126 Jake White 65
127 Judy Green 45
128 Jack Black 55
129 Jill Blue 82
----
9
```
**Expected output:**

```text
Student with id 127 failed the course
All students:
123 John Doe 95 Grade: 10
124 Jane Smith 85 Grade: 9
125 Jim Brown 75 Grade: 8
126 Jake White 65 Grade: 7
128 Jack Black 55 Grade: 6
129 Jill Blue 82 Grade: 9
Grade report for grade 9:
124 Jane Smith 85 Grade: 9
129 Jill Blue 82 Grade: 9
```



### Test Case 6

**Input:**
```text
201 Alice Johnson 92
202 Bob Miller 87
203 Charlie Davis 60
204 David Wilson 78
205 Emma Harris 50
206 Frank Clark 49
207 Grace Lewis 85
----
10
```
**Expected output:**

```text
Student with id 206 failed the course
All students:
201 Alice Johnson 92 Grade: 10
202 Bob Miller 87 Grade: 9
203 Charlie Davis 60 Grade: 7
204 David Wilson 78 Grade: 8
205 Emma Harris 50 Grade: 6
207 Grace Lewis 85 Grade: 9
Grade report for grade 10:
201 Alice Johnson 92 Grade: 10
```




### Test Case 7

**Input:**
```text
301 Henry King 50
302 Irene Wright 67
303 Jack Turner 72
304 Karen Phillips 81
305 Larry Scott 53
306 Molly Adams 90
307 Nancy Baker 88
----
8
```
**Expected output:**

```text
All students:
301 Henry King 50 Grade: 6
302 Irene Wright 67 Grade: 7
303 Jack Turner 72 Grade: 8
304 Karen Phillips 81 Grade: 9
305 Larry Scott 53 Grade: 6
306 Molly Adams 90 Grade: 10
307 Nancy Baker 88 Grade: 9
Grade report for grade 8:
303 Jack Turner 72 Grade: 8
```



### Test Case 8

**Input:**
```text
401 Olivia Hall 79
402 Paul Allen 95
403 Quincy Young 84
404 Rachel Hernandez 56
405 Samuel Martinez 50
406 Teresa Roberts 73
407 Ursula Moore 62
----
7
```
**Expected output:**

```text
All students:
401 Olivia Hall 79 Grade: 8
402 Paul Allen 95 Grade: 10
403 Quincy Young 84 Grade: 9
404 Rachel Hernandez 56 Grade: 6
405 Samuel Martinez 50 Grade: 6
406 Teresa Roberts 73 Grade: 8
407 Ursula Moore 62 Grade: 7
Grade report for grade 7:
407 Ursula Moore 62 Grade: 7
```




### Test Case 9

**Input:**
```text
701 Jack Kelly 55
702 Laura Bennett 75
703 Michael Russell 87
704 Nora Watson 70
705 Owen Patterson 89
706 Piper Richardson 83
707 Quinn Cox 88
----
9
```
**Expected output:**

```text
All students:
701 Jack Kelly 55 Grade: 6
702 Laura Bennett 75 Grade: 8
703 Michael Russell 87 Grade: 9
704 Nora Watson 70 Grade: 8
705 Owen Patterson 89 Grade: 9
706 Piper Richardson 83 Grade: 9
707 Quinn Cox 88 Grade: 9
Grade report for grade 9:
703 Michael Russell 87 Grade: 9
705 Owen Patterson 89 Grade: 9
706 Piper Richardson 83 Grade: 9
707 Quinn Cox 88 Grade: 9
```




### Test Case 10

**Input:**
```text
1001 Alice Johnson 92
1002 Bob Miller 87
1003 Charlie Davis 60
1004 David Wilson 78
1005 Emma Harris 50
1006 Frank Clark 49
1007 Grace Lewis 85
1008 Henry King 45
1009 Irene Wright 67
1010 Jack Turner 72
1011 Karen Phillips 81
1012 Larry Scott 53
1013 Molly Adams 90
1014 Nancy Baker 88
1015 Olivia Hall 79
1016 Paul Allen 95
1017 Quincy Young 84
1018 Rachel Hernandez 56
1019 Samuel Martinez 49
1020 Teresa Roberts 73
----
8
```
**Expected output:**

```text
Student with id 1006 failed the course
Student with id 1008 failed the course
Student with id 1019 failed the course
All students:
1001 Alice Johnson 92 Grade: 10
1002 Bob Miller 87 Grade: 9
1003 Charlie Davis 60 Grade: 7
1004 David Wilson 78 Grade: 8
1005 Emma Harris 50 Grade: 6
1007 Grace Lewis 85 Grade: 9
1009 Irene Wright 67 Grade: 7
1010 Jack Turner 72 Grade: 8
1011 Karen Phillips 81 Grade: 9
1012 Larry Scott 53 Grade: 6
1013 Molly Adams 90 Grade: 10
1014 Nancy Baker 88 Grade: 9
1015 Olivia Hall 79 Grade: 8
1016 Paul Allen 95 Grade: 10
1017 Quincy Young 84 Grade: 9
1018 Rachel Hernandez 56 Grade: 6
1020 Teresa Roberts 73 Grade: 8
Grade report for grade 8:
1004 David Wilson 78 Grade: 8
1010 Jack Turner 72 Grade: 8
1015 Olivia Hall 79 Grade: 8
1020 Teresa Roberts 73 Grade: 8
```
