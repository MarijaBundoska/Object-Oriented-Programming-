## Exercise 3 - Library Membership System

Define an abstract class `Library` with the following specifications **(5 points)**:

- Name of the library (string with a maximum of 50 characters).
- City where the library is located (string with a maximum of 50 characters).
- Base monthly membership fee (floating-point number).
- Information on whether it operates on weekends (Boolean variable).

Additionally, the class should contain two pure virtual member functions:

- `void printDetail()` - function that prints the object's information.
- `double calculateMembershipCardCost()` - function that returns the membership fee for the library.

Define two classes, `AcademicLibrary` and `NationalLibrary`, which inherit from the class `Library` **(5 points)**.

For the class `AcademicLibrary`, additionally store information about:

- Open research opportunities (Boolean variable).
- Number of specialized journal collections within the library (integer variable).

The membership fee (function `double calculateMembershipCardCost()`) for `AcademicLibrary` is calculated as follows:

- If the library offers open research opportunities, the fee increases by 24%.
- Additionally, each specialized journal collection increases the fee by $6.

The function `void printDetail()` prints the characteristics of the library in the following format:

`[Library Name] - (Academic) [City] [Number of specialized collections] [Membership fee]`

**(10 points)**

For the class `NationalLibrary`, additionally store information about:

- Whether the library offers educational programs on cultural heritage (Boolean variable).
- Number of preserved original manuscripts of national significance (integer variable).

The membership fee (function `double calculateMembershipCardCost()`) for `NationalLibrary` is calculated as follows:

- If the library offers educational programs, the fee decreases by 7%.
- Additionally, each preserved original manuscript increases the fee by $15.

The function `void printDetail()` prints the characteristics of the library in the following format:

`[Library Name] - (National) [City] [Number of manuscripts] [Membership fee]`

**(10 points)**

Define the following global function:

`int findMostExpensiveNationalLibrary(Library **l, int n)`

The function takes as arguments an array of pointers to libraries and the size of the array, and returns the index in the array of the national library (`NationalLibrary`) with the highest membership fee.

- If no such object exists in the array, the function returns `-1`.
- If multiple national libraries have the same membership fee, the one that operates on weekends is chosen (the last one found).

**(20 points)**

---

## Задача 3 - Систем за членарина во библиотеки

Да се дефинира апстрактна класа `Library` со следниве спецификации **(5 поени)**:

- Име на библиотеката (стринг со максимум 50 знаци).
- Град во кој се наоѓа библиотеката (стринг со максимум 50 знаци).
- Основна цена на месечна членарина (реален број).
- Информација дали библиотеката работи за викенд (Boolean променлива).

Дополнително, класата треба да содржи две чисто виртуелни функции-членки:

- `void printDetail()` - функција која ги печати информациите за објектот.
- `double calculateMembershipCardCost()` - функција која ја враќа цената на членарината во библиотеката.

Да се дефинираат две класи, `AcademicLibrary` и `NationalLibrary`, кои наследуваат од класата `Library` **(5 поени)**.

За класата `AcademicLibrary` дополнително се чува информација за:

- Отворени можности за истражување (Boolean променлива).
- Број на специјализирани колекции од списанија во рамки на библиотеката (целобројна променлива).

Цената на членарина (функција `double calculateMembershipCardCost()`) за `AcademicLibrary` се пресметува на следниот начин:

- Ако библиотеката нуди отворени можности за истражување, цената се зголемува за 24%.
- Дополнително, секоја специјализирана колекција од списанија ја зголемува цената за $6.

Функцијата `void printDetail()` ги печати карактеристиките на библиотеката во следниот формат:

`[Име на библиотеката] - (Academic) [Град] [Број на специјализирани колекции] [Цена на членарина]`

**(10 поени)**

За класата `NationalLibrary` дополнително се чува информација за:

- Дали библиотеката нуди едукативни програми за културното наследство (Boolean променлива).
- Број на сочувани оригинални ракописи од национално значење (цел број).

Цената на членарина (функција `double calculateMembershipCardCost()`) за `NationalLibrary` се пресметува на следниот начин:

- Ако библиотеката нуди едукативни програми, цената се намалува за 7%.
- Дополнително, секој сочуван оригинален ракопис ја зголемува цената за $15.

Функцијата `void printDetail()` ги печати карактеристиките на библиотеката во следниот формат:

`[Име на библиотеката] - (National) [Град] [Број на ракописи] [Цена на членарина]`

**(10 поени)**

Да се дефинира следната глобална функција:

`int findMostExpensiveNationalLibrary(Library **l, int n)`

Функцијата како аргумент прима низа од покажувачи кон библиотеки и големина на низата, а како резултат го враќа индексот во низата на националната библиотека (`NationalLibrary`) која има најскапа членарина.

- Доколку не постои таков објект во низата, функцијата враќа `-1`.
- Ако повеќе национални библиотеки имаат иста цена на членарина, се избира таа која работи за викенд (последниот најден).

**(20 поени)**








## Test Cases


### Test Case 1

**Input:**
```text
1
2
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12
```
**Expected output:**

```text
Abstract and child classes OK
```



### Test Case 2

**Input:**
```text
2
4
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12
1
Stanford Library
Stanford
20.0
1
0
120
2
British Library
London
28.0
0
0
17
```
**Expected output:**

```text
259
207.9
740
283
calculateMembershipCardCost method OK
```



### Test Case 3

**Input:**
```text
3
2
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12
```
**Expected output:**

```text
Harvard Library - (Academic) Cambridge 38 259
Library of Congress - (National) Washington D.C. 12 207.9
printDetail method OK
```




### Test Case 4

**Input:**
```text
4
2
1
Harvard Library
Cambridge
25.0
1
1
38
1
Stanford Library
Stanford
20.0
1
0
120
```
**Expected output:**

```text
National Library not found in the array!
findMostExpensiveNationalLibrary method OK
```



### Test Case 5

**Input:**
```text
4
4
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12
1
Stanford Library
Stanford
20.0
1
0
120
2
British Library
London
28.0
0
0
20
```
**Expected output:**

```text
British Library - (National) London 20 328
findMostExpensiveNationalLibrary method OK
```



### Test Case 6

**Input:**
```text
	
4
4
2
Library of Congress
Washington D.C.
30.0
0
1
12
2
Library of Congress 2
Washington D.C.
30.0
1
1
12
2
British Library
London
28.0
0
0
10
1
Stanford Library
Stanford
20.0
1
0
120
```
**Expected output:**

```text
Library of Congress 2 - (National) Washington D.C. 12 207.9
findMostExpensiveNationalLibrary method OK
```
