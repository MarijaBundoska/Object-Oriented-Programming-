# Exercise 8 - Concert Management System

## Problem Description

Create a class for describing concerts. For one concert, the following information is stored **(5 points)**:

- name (an array of at most 20 characters)
- location (an array of at most 20 characters)
- seasonal discount (real number)
- ticket price in denars (decimal number)

All data in the class should be private. The seasonal discount is the same for all concerts and can be changed by the managers depending on the season. For that purpose, a function for changing the seasonal discount should be provided. The seasonal discount is expressed in percentages and its initial value is 20 percent. (5 points)

The basic price of one concert ticket is calculated using the method:

- `price()` – which returns the price with the seasonal discount **(5 points)**

For the purposes of a summer festival, a special type of entertainment concerts should be provided, electronic concerts. For each electronic concert, additional information is stored about the DJ's name (dynamically allocated array of characters), the duration of the performance in hours (real number), and a boolean variable indicating whether it is a daytime or nighttime event (daytime-true/nighttime-false). **(5 points)**

For each electronic concert, a method for calculating the ticket price should be available **(5 points)**:

- `price()` – the basic price is increased depending on the duration of the electronic concert. If the duration of the concert is longer than 5 hours, the basic price is increased by 150 denars. If the duration is longer than 7 hours, the price is increased by 360 denars. If it is a daytime event, the price is reduced by 50, and if it is a nighttime event, the price is increased by 100 denars.

The following functions should be implemented:

- `void mostExpensiveConcert(Concert **concerts, int n)` – prints the name and price of the most expensive concert in the array. Additionally, it should print how many of the concerts are electronic and how many are not in the following format:

```text
[Electronic concerts: X out of total Y.]

```
**(10 points)**
- `bool searchConcert(Concert **concerts, int n, char *name, bool electronic)` – searches for a concert that has the same name as the variable name. If the variable electronic is true, only electronic concerts should be searched; otherwise, all concerts are searched. If the concert is found, its name and price are printed and the function returns true. If the concert is not found, the function returns false. There may be multiple concerts with the same name.
**(10 points)**



# Задача 8 - Управување со концерти

## Опис на задачата

Да се креира класа за опишување на концерти. За еден концерт се чуваат информации за **(5 поени)**:

- назив (низа од најмногу 20 знаци)
- локација (низа од најмногу 20 знаци)
- сезонски попуст (реален број)
- цена на билет во денари (децимален број)

Сите податоци во класата треба да се приватни. Сезонскиот попуст е ист за сите концерти и може да се менува од страна на менаџерите во зависност од сезоната. За таа цел да се обезбеди функција за менување на сезонскиот попуст. Сезонскиот попуст е изразен во проценти и почетната вредност е 20 проценти. **(5 поени)**

Основната цена на еден билет за концерт се пресметува со методот:

- `cena()` – која ја враќа цената со сезонскиот попуст **(5 поени)**

За потребите на еден летен фестивал, треба да се обезбедат посебен вид на забавни концерти, електронски концерти. За секој eлектронски концерт дополнително се чуваат инфромации за името на DJ-от (динамички алоцирана низа од знаци), времетраење на настапот во часови (реален број) и логичка променлива за дали се работи за дневна или ноќна забава (дневна-true/ноќна-false). **(5 поени)**

За секој електронски концерт треба да биде на располагање метод за пресметување на цената за билет **(5 поени)**:

- `cena()` – основната цена се зголемува во зависност од времетраењето на електронскиот концерт. Ако времетраењето на концертот е подолго од 5 часа, основната цена се зголемува за 150 денари. Ако времетраењето е подолго од 7 часа, цената се зголемува за 360 денари. Доколку се работи за дневна забава, цената се намалува за 50, а доколку се работи за ноќна забава цената се зголемува за 100 денари.

Да се имплементираат следните функции:

- `void najskapKoncert(Koncert **koncerti, int n)` –  во која ќе се испечати називот и цената на најскапиот концерт во низата. Дополнително, да се испечати и колку од концертите се електронски, а колку не во формат:

```text
[Electronic concerts: X out of total Y.]

```
**(10 поени)**
- `bool prebarajKoncert(Koncert **koncerti, int n, char *naziv, bool elektronski)` –  во која ќе се прабарува концерт кој имаат ист назив како променливата naziv. Доколку променливата elektronski е true, треба да се пребарува само низ електронските концерти, во спротивно се пребаруваат сите концерти. Доколку е пронајден концертот, се печати неговиот назив и цена и функцијата враќа true. Доколку не е пронајден концертот, функцијата враќа false. Можно е да има повеќе концерти со ист назив.
**(10 поени)**


## Test Cases


### Test Case 1

**Input:**
```text
6
```
**Expected output:**
```text
Najskap koncert: SeaDance 7230
Elektronski koncerti: 3 od vkupno 5
```



### Test Case 2

**Input:**
```text
3
TomorrowLand
Belgium
8432.2
Axwell
5.6
0
```
**Expected output:**
```text
Kreiran e elektronski koncert so naziv TomorrowLand i sezonskiPopust 0.2
```




### Test Case 3

**Input:**
```text
4
TomorrowLand
Belgium
8432.2
Axwell
5.6
0

```
**Expected output:**
```text
Cenata na elektronskiot koncert so naziv TomorrowLand e: 6995.76
```



### Test Case 4

**Input:**
```text
2
MkcKoncert
Skopje
333.3
```
**Expected output:**
```text
Osnovna cena na koncertot so naziv MkcKoncert e: 266.64
```




### Test Case 5

**Input:**
```text
7
1
```
**Expected output:**
```text
Ne e pronajden
Area 280
Pronajden
```




### Test Case 6

**Input:**
```text
8
```
**Expected output:**
```text
Najskap koncert: TomorrowLand 1260
Elektronski koncerti: 2 od vkupno 4
```




### Test Case 7

**Input:**
```text
1
Axwell
Skopje
450
```
**Expected output:**
```text
Kreiran e koncert so naziv: Axwell
```
