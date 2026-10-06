# Exercise 11 - Performance and Ticket Sales

## Problem Description

It is necessary to model the sale of tickets for performances in a cultural center. For this purpose, a class `DELO` should be created. The class stores the following attributes:

- Name of the work (an array of 50 characters)
- Year when it was written (integer)
- Country of origin (an array of 50 characters)

For the class, the necessary constructor, `get` and `set` methods should be implemented. The `==` operator should be overloaded for the class `DELO` to compare whether two works are the same (two works are considered the same if they have the same name). **(5 points)**

A class `PRETSTAVA` should be defined. The class stores information about:

- The work being performed (an object of class `DELO`)
- Number of tickets sold (integer)
- Date of the performance (an array of 15 characters)

The necessary constructor, `set` and `get` methods should be defined for the class. Additionally, a `cena` method should be implemented for the class `PRETSTAVA`, which should return the price of one ticket. **(5 points)**

The price depends on the age of the work and its country of origin and is calculated according to the following formula:

**Price = N + M**

- `M = 50` denars if the work was written in the 20th or 21st century
- `M = 75` denars if the work was written in the 19th century
- `M = 100` denars if the work was written before the 19th century
- `N = 100` denars if the work is from Italy
- `N = 150` denars if the work is from Russia
- Works from other countries have `N = 80` denars

The performances can be `opera` and `ballet`. For ballet performances, an additional attribute for the ballet price is stored. This price is added to the original ticket price, and its value is the same for all ballet performances. Initially, it is 150 denars, with the possibility of changing it if the management of the cultural center decides to do so. **(10 points)**

An external function `prihod` should be defined. It receives as arguments an array of pointers to performances that were shown during one month and the size of the array, and as a result it should calculate and return the total revenue of the cultural center. **(10 points)**

An external function `brojPretstaviNaDelo` should be defined. It receives as arguments an array of pointers to performances that were shown during one month, the size of the array, and one work. This function calculates how many of the given performances displayed the given work. **(5 points)**

**Note:** In the array of performances passed as an argument to the functions `prihod` and `brojPretstaviNaDelo`, there may be multiple performances for the same work.

Complete functionality of the task **(5 points)**


# Exercise 11 - Продажба на карти за претстави

## Опис на задачата

Потребно е да се моделира продажба на карти за прикажување на претстави во некој културен центар. За таа цел, да се направи класа `DELO`. За класата се чуваат следните атрибути:

- Име на делото (низа од 50 знаци)
- Година кога е напишано (цел број)
- Земја на потекло (низа од 50 знаци)

За класата да се направат потребниот конструктор, `get` и `set` методи. За класата `DELO` да се преоптовари операторот `==` кој ќе споредува дали две дела се исти (две дела се исти ако имаат исто име) **(5 поени)**.

Да се дефинира класа `PRETSTAVA`. За класата се чуваат информации за:

- Делото кое се прикажува (објект од класата `DELO`)
- Број на продадени карти (цел број)
- Дата на прикажување (низа од 15 знаци)

За класата да се дефинира потребниот конструктор, `set` и `get` методите. Дополнително, за класата `PRETSTAVA` да се напише метода `cena` која треба да ја врати цената на една карта. **(5 поени)**

Цената зависи од староста на делото и од земјата на потекло и се пресметува по следната формула: **Цена = N + М**, каде:

- `М = 50` денари ако делото е напишано во 20 или 21 век
- `М = 75` денари ако делото е напишано во 19 век
- `М = 100` денари ако делото е напишано пред 19 век
- `N = 100` денари ако делото е од Италија
- `N = 150` денари ако делото е од Русија
- Делата од останатите земји имаат `N = 80` денари

Претставите можат да бидат `опера` и `балет`. За балетите се чува дополнителен атрибут за цената на балетот која се додава на оригиналната цена на картата и таа вредност е иста за сите балетски претстави. На почеток изнесува 150 денари, со можност да се променува ако така одлучи менаџментот на културниот центар. **(10 поени)**

Да се дефинира надворешна функција `prihod` која како аргумент прима низа од покажувачи кон претстави кои се прикажале во еден месец и големина на низата, а како резултат треба да го пресмета и врати вкупниот приход на културниот центар. **(10 поени)**

Да се дефинира надворешна функција `brojPretstaviNaDelo` која како аргумент прима низа од покажувачи кон претстави кои се прикажале во еден месец, големина на низата и едно дело. Оваа функција пресметува на колку од дадените претстави е прикажано даденото дело. **(5 поени)**

*(Напомена: Во низата од претстави која се проследува како аргумент во функциите `prihod` и `brojPretstaviNaDelo` може да имаме повеќе претстави за едно исто дело)*

Целосна функционалност на задачата **(5 поени)**




## Test Cases


### Test Case 1

**Input:**
```text
4
4
0 Anastasia 1967 Rusija 250 10.05.2016
1 Rigoletto 1851 Italija 120 11.05.2016
0 Anastasia 1967 Rusija 100 12.05.2016
1 Beggar 1728 Anglija 60 13.05.2016
```
**Expected output:**

```text
======TEST CASE 4=======
154300
```



### Test Case 2

**Input:**
```text
2
0 Anastasia 1967 Rusija 250 10.05.2016
1 Rigoletto 1851 Italija 120 11.05.2016
```
**Expected output:**

```text
======TEST CASE 2=======
350
175
```




### Test Case 3

**Input:**
```text
6
5
0 Anastasia 1967 Rusija 250 10.05.2016
1 Rigoletto 1851 Italija 120 11.05.2016
0 Anastasia 1967 Rusija 100 12.05.2016
1 Beggar 1728 Anglija 60 13.05.2016
1 Rigoletto 1851 Italija 150 16.05.2016
Rigoletto 1851 Italija
```
**Expected output:**

```text
======TEST CASE 6=======
2
```




### Test Case 4

**Input:**
```text
3
Anastasia 1967 Rusija
Anastasia 1967 Rusija
Rigoletto 1851 Italija
```
**Expected output:**

```text
======TEST CASE 3=======
Isti se
Ne se isti
```



### Test Case 5

**Input:**
```text
1
0 Anastasia 1967 Rusija 250 10.05.2016
1 Rigoletto 1851 Italija 120 11.05.2016
```
**Expected output:**

```text
======TEST CASE 1=======
Anastasia
Rigoletto
```



### Test Case 6

**Input:**
```text
5
200
4
0 Anastasia 1967 Rusija 250 10.05.2016
1 Rigoletto 1851 Italija 120 11.05.2016
0 Anastasia 1967 Rusija 100 12.05.2016
1 Beggar 1728 Anglija 60 13.05.2016
```
**Expected output:**

```text
======TEST CASE 5=======
171800
```
