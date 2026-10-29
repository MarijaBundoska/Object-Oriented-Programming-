## Exercise 5 - Guitar Inventory Management

For the needs of a guitar store, a program for managing the inventory is required.

For this purpose, a class `Gitara` should be created (**5 points**). The class should contain:

- Serial number (a string of 25 characters).
- Purchase price (a real number).
- Year of manufacture (an integer).
- Type (a string of 40 characters).

A method `daliIsti` should be defined, which takes an object of type `Gitara` as an argument and compares the two guitars based on their serial numbers (**5 points**).

Additionally, a function `pecati()` should be implemented for this class to print the object in the following format (**5 points**):

> `[SerialNumber] [Type] [Price]`

A class `Magacin` should be created (**5 points**) containing:

- Name of the warehouse (a string of 30 characters).
- Location of the warehouse (a string of 60 characters).
- An array of guitars owned by the warehouse (a dynamically allocated array of objects of the `Gitara` class).
- Number of objects in the array (an integer).
- Year of opening (an integer).

For the `Magacin` class, a method `double vrednost()` should be defined to calculate the current value of the guitars stored in the warehouse. It is calculated as the sum of the values of all guitars in the warehouse (**5 points**).

Additionally, the following functions should be defined for the class:

- `void dodadi(Gitara d)` to store a new guitar in the warehouse (adding a new object of the `Gitara` class to the dynamically allocated array of guitars) (**10 points**).
- `void prodadi(Gitara p)` to remove a given guitar from the warehouse (deleting all objects that are identical to the argument passed to the function) (**10 points**).
- `void pecati(bool daliNovi)` to print information about the warehouse. The first line should display the name and location of the warehouse, followed by the guitars stored in the warehouse, each on a separate line. If the passed variable has the value `true`, only guitars manufactured after the year the warehouse was opened should be printed. Otherwise, all guitars should be printed (**5 points**).

The necessary constructors, destructor, and all other methods required for the correct functioning of the program should be defined for both classes (**5 points**). All data members in the classes must be private.

---

## Задача 5 - Менаџирање магацин со гитари

За потребите на една продавница за гитари, потребно е да се направи програма за менаџирање на магацинот.

За таа цел, треба да се креира класа `Gitara` **(5 поени)**. Класата треба да содржи:

- Сериски број (низа од 25 знаци).
- Набавна цена (реален број).
- Година на производство (цел број).
- Тип (низа од 40 знаци).

Да се дефинира метод `daliIsti` кој како аргумент ќе добие објект од тип `Gitara` и ќе ги спореди двете гитари според нивниот сериски број **(5 поени)**.

Дополнително, за оваа класа да се направи функција `pecati()` за печатење на објектот во следниот формат **(5 поени)**:

> `[СерискиБрој] [Тип] [Цена]`

Да се креира класа `Magacin` **(5 поени)** која содржи:

- Име на магацинот (низа од 30 знаци).
- Локација на магацинот (низа од 60 знаци).
- Низа од гитари кои ги поседува магацинот (динамички алоцирана низа од објекти од класата `Gitara`).
- Број на објекти во низата (цел број).
- Година на отворање (цел број).

За класата `Magacin` да се дефинира метод `double vrednost()` што ќе ја пресметува моменталната вредност на гитарите кои се наоѓаат во магацинот. Таа се пресметува како збир од вредноста на сите гитари од кои е составен магацинот **(5 поени)**.

Дополнително, за класата да се дефинираат функциите:

- `void dodadi(Gitara d)` за сместување на нова гитара во магацин (додавање на нов објект од класата `Gitara` во динамички алоцираната низа со гитари) **(10 поени)**.
- `void prodadi(Gitara p)` за бришење на дадена гитара од магацинот (бришење на сите објекти кои се исти како аргументот проследен во функцијата) **(10 поени)**.
- `void pecati(bool daliNovi)` за печатење на информации за магацинот така што во првиот ред ќе биде прикажано името и локацијата на магацинот, а потоа во секој нареден ред ќе бидат прикажани гитарите кои се наоѓаат во магацинот. Доколку пратената променлива има вредност `true`, ќе се печатат само гитарите кои имаат година на производство понова од годината на отворање на магацинот. Во спротивно, се печатат сите гитари **(5 поени)**.

За класите да се дефинираат потребните конструктори, деструктор и сите останати методи за правилно функционирање на програмата **(5 поени)**. Сите податочни членови во класите се приватни.






 ## Test Cases


### Test Case 1

**Input:**
```text
2
```
**Expected output:**

```text
===== Testiranje na klasata Magacin so metodot print() ======
Magacin1 Lokacija1
```





### Test Case 2

**Input:**
```text
1
Acoustic
55333
2012
33212.40
```
**Expected output:**

```text
===== Testiranje na klasata Gitara ======
Acoustic
55333
2012
33212.4
```






### Test Case 3

**Input:**
```text
5
5
Acoustic1
55113
2016
35212.9
Electrical
111111
2015
11212.8
Acoustic2
55113
2015
35212.9
Acoustic3
55113
2010
35212.9
Electrical2
333333
2010
11212.8
```
**Expected output:**

```text
===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======
gitara dodadi
gitara dodadi
gitara dodadi
gitara dodadi
gitara dodadi
Magacin1 Lokacija1
55113 Acoustic1 35212.9
111111 Electrical 11212.8
55113 Acoustic2 35212.9
Po brisenje:
Magacin1 Lokacija1
111111 Electrical 11212.8
```





### Test Case 4

**Input:**
```text
6
5
Acoustic1
55113
2016
35212.9
Electrical
111111
2015
11212.8
Acoustic2
55113
2015
35212.9
Acoustic3
55113
2010
35212.9
Electrical2
333333
2010
11212.8
```
**Expected output:**

```text
===== Testiranje na klasata Magacin so metodot vrednost()======
128064
Po brisenje:
22425.6
```





### Test Case 5

**Input:**
```text
4
5
Acoustic1
55113
2010
35212.9
Electrical
111111
2012
11212.8
Acoustic2
55113
2010
35212.9
Acoustic3
55113
2010
35212.9
Electrical2
333333
2015
11212.8
```
**Expected output:**

```text
===== Testiranje na klasata Magacin so metodot prodadi() ======
gitara dodadi
gitara dodadi
gitara dodadi
gitara dodadi
gitara dodadi
Magacin1 Lokacija1
55113 Acoustic1 35212.9
111111 Electrical 11212.8
55113 Acoustic2 35212.9
55113 Acoustic3 35212.9
333333 Electrical2 11212.8
Magacin1 Lokacija1
111111 Electrical 11212.8
333333 Electrical2 11212.8
```





### Test Case 6

**Input:**
```text
3
2
Acoustic
55113
2010
35212.9
Electrical
33113
2011
11212.8
```
**Expected output:**

```text
===== Testiranje na klasata Magacin so metodot dodadi() ======
gitara dodadi
gitara dodadi
Magacin1 Lokacija1
55113 Acoustic 35212.9
33113 Electrical 11212.8
```
