## Exercise 14 - File and Folder Classes

## Задача 14 - Класи за датотека и директориум

Потребно е да се имплементираат класи `File` (датотека) и `Folder` (директориум) за работа со едноставен податочен систем.

### Class `File`

Во класата `File` треба да се чуваат следниве податоци:

- Име на датотеката (динамички алоцирана низа од знаци)
- Екстензија на датотеката (енумерација со можни вредности: `txt`, `pdf`, `exe`)
- Име на сопственикот на датотеката (динамички алоцирана низа од знаци)
- Големина на датотеката (цел број на мегабајти)

Дополнително, во класата потребно е да се напишат и:

- Конструктор без параметри
- Конструктор со параметри
- Конструктор за копирање
- Деструктор
- Преоптоварување на операторот `=`
- Метод за печатење на информациите за една датотека (видете го излезот од тест примерите за структурата на печатење) - `print()`
- Метод за проверка на еднаквост помеѓу две датотеки со потпис `bool equals(const File & that)` кој ќе враќа `true` ако датотеките имаат исто име, екстензија и сопственик
- Метод за споредба на типот помеѓу две датотеки со потпис `bool equalsType(const File & that)` кој ќе враќа `true` ако датотеките се од ист тип, т.е. имаат исто име и екстензија

### Class `Folder`

Во класата `Folder` треба да се чуваат следниве податоци:

- Име на директориумот (динамички алоцирана низа од знаци)
- Број на датотеки во него (на почеток директориумот е празен)
- Динамички алоцирана низа од датотеки, објекти од класата `File`

Дополнително, во класата потребно е да се напишат и:

- Конструктор со потпис `Folder(const char* name)`
- Деструктор
- Метод за печатење на информациите за еден директориум (видете го излезот од тест примерите за структурата на печатење) - `print()`
- Метод за бришење на датотека од директориумот со потпис `void remove(const File & file)` кој ќе ја избрише првата датотека од директориумот која е еднаква според `equals` методот
- Метод за додавање на датотека во директориумот со потпис `void add(const File & file)` кој ќе додава датотеката во директориумот

**Не го менувајте почетниот код.**


 ## Test Cases


### Test Case 1

**Input:**
```text
2
rezultati_oop
FINKI
2
0
rezultati_oop
FINKI
3
0
rezultati_oop
FINKI
1
1
```
**Expected output:**

```text
======= FILE EQUALS & EQUALS TYPE =======
File name: rezultati_oop.pdf
File owner: FINKI
File size: 2
File name: rezultati_oop.pdf
File owner: FINKI
File size: 3
File name: rezultati_oop.txt
File owner: FINKI
File size: 1
FIRST EQUALS SECOND: TRUE
FIRST EQUALS THIRD: FALSE
FIRST EQUALS TYPE SECOND: TRUE
SECOND EQUALS TYPE THIRD: FALSE
```




### Test Case 2

**Input:**
```text
1
rezultati_oop
FINKI
2
0
```
**Expected output:**

```text
======= FILE CONSTRUCTORS AND = OPERATOR =======
======= CREATED =======
File name: rezultati_oop.pdf
File owner: FINKI
File size: 2

======= COPIED =======
File name: rezultati_oop.pdf
File owner: FINKI
File size: 2

======= ASSIGNED =======
File name: rezultati_oop.pdf
File owner: FINKI
File size: 2
```





### Test Case 3

**Input:**
```text
3
results
```
**Expected output:**

```text
======= FOLDER CONSTRUCTOR =======
Folder name: results
```






### Test Case 4

**Input:**
```text
4
results
3
rezultati_oop
FINKI
2
0
rezultati_oop
Ministerot
2
0
rezultati_oop
Ministerot
2
1
```
**Expected output:**

```text
======= ADD FILE IN FOLDER =======
Folder name: results
File name: rezultati_oop.pdf
File owner: FINKI
File size: 2
File name: rezultati_oop.pdf
File owner: Ministerot
File size: 2
File name: rezultati_oop.txt
File owner: Ministerot
File size: 2
```






### Test Case 5

**Input:**
```text
5
results
3
rezultati_oop
FINKI
1
2
rezultati_aok
FINKI
2
1
rezultati_dm
FINKI
3
1
rezultati_dm
FINKI
2
1
```
**Expected output:**

```text
======= REMOVE FILE FROM FOLDER =======
Folder name: results
File name: rezultati_oop.exe
File owner: FINKI
File size: 1
File name: rezultati_aok.txt
File owner: FINKI
File size: 2
```

