# Exercise 7 - Bank Card Management System

## Problem Description

A partial definition of the `Card` class is given. For each card, information is stored about the **transaction account** (an array of 15 characters), **PIN code** (an integer), and whether it has **multiple PIN codes** (a boolean variable).

For each card, the **breaking difficulty** can be calculated. The breaking difficulty is the number of digits in the PIN code.

Special cards, in addition to one mandatory PIN code, have several additional PIN codes. For these users, an appropriate class `SpecialCard` should be modeled, which, in addition to the **additional PIN codes** (a dynamically allocated array of integers), also stores the **number of PIN codes** (an integer). The additional PIN codes also affect the breaking difficulty of the card, increasing it by the number of additional PIN codes.

The maximum number of additional PIN codes that any card can have is `P`. `P` has a fixed value of 4 for all cards and this value cannot be changed.

In the `Card` and `SpecialCard` classes, implement the necessary constructors, setter and getter functions, and destructor. **(5 points)**

For all objects of the classes, the following functions should be provided:

- **overloaded `<<` operator** which prints information about the card in the format: `account: difficulty` **(5 points)**
- `breakingDifficulty()` – calculates the breaking difficulty of the card **(5 points)**

In the `SpecialCard` class, define the following function:

- **overloaded `+=` operator** for adding a new PIN code **(5 points)**

If an attempt is made to enter more than the allowed number of PIN codes, an exception (an object of the `OutOfBoundException` class) should be thrown in the security code. Catch the exception in the main function where necessary. After catching it, print the appropriate error message (*Brojot na pin kodovi ne moze da go nadmine dozvolenoto*) and handle the exception so that the added PIN code is not taken into consideration. **(10 points)**

A partial definition of the `Bank` class is given, which stores information about the bank's name (an array of 30 characters), the cards issued by the bank (an array of 20 pointers to the `Card` class), and the number of such cards.

We say that a card issued by the bank can be broken if its breaking difficulty is at most `LIMIT`. The value `LIMIT` is a member of the `Bank` class, has an initial value of 7, and can be changed using the `setLimit()` function. This value is the same for all banks. **(5 points)**

In the `Bank` class, implement the following functions:

- `printCards()` function which prints all cards that can be broken, each on a separate line. Before that, the following should be printed on the first line: *Vo bankata XXXXX moze da se probijat kartickite:* **(5 points)**.
- `addAdditionalPin(char* account, int newPin)` function which adds a new additional PIN code to the card with the given transaction account. If this is not possible, the function does nothing **(15 points)**.

Complete functionality **(5 points)**


# Exercise 7 - Управување со банкарски картички

## Опис на задачата

Дадена е дел од дефиницијата на класата `Karticka`. За секоја картичка се чуваат информации за **трансакциска сметка** (низа од 15 знаци), **пин код** (цел број) и дали има **повеќе пин кодови** (булова променлива).

За секоја картичка може да се пресмета тежината за пробивање на картичката. Тежината на пробивање е бројот на цифрите на пин кодот.

Специјалните картички покрај еден задолжителен имаат уште неколку пин кодови. За овие корисници да се моделира соодветна класа `SpecijalnaKarticka` во која покрај **дополнителните пин кодови** (динамичко алоцирана низа од цели броеви) се чува и **бројот на пин кодовите** (цел број). Со дополнителните пин кодови се менува и тежината на пробивање на картичката и таа се зголемува за бројот на дополнителни пин кодови.

Максималниот број на дополнителни пин кодови кој може да има било која картичка е `P`. P има фиксна вредност 4 за сите картички и оваа вредност не може да се промени.

Во класите `Karticka` и `SpecijalnaKarticka` треба да се имплементираат потребните конструктори, функции за поставување и преземање и деструктор. **(5 поени)**

За сите објекти од класите треба да се обезбедат следните функции:

- **преоптоварен оператор <<** во кој се печатат информации за картичката во формат: smetka: tezina **(5 поени)**
- `tezinaProbivanje`() – ја пресметува тежината за пробивање на картичката **(5 поени)**

Во класата `SpecijalnaKarticka` дефинирај ја функцијата:

- **преоптоварен оператор +=** за додавање на нов пин код **(5 поени)**

Ако се направи обид да се внесат повеќе од дозволениот број на пин кодови во безбедносниот код да се фрли исклучок (објект од класата `OutOfBoundException`). Фатете го исклучокот во главната функција каде што е потребно. Откако ќе го фатите отпечатете соодветна порака за грешка (*Brojot na pin kodovi ne moze da go nadmine dozvolenoto*) и справете се со исклучокот така да додадениот пин код не се зема предвид **(10 поени)**

Дадена е дел од дефиницијата на класата `Banka` во која се чуваат информаци за името на банката (низа од 30 знаци) и за картичките издадени од банката (низа од 20 покажувачи кон класата `Karticka`) како и бројот на такви картички.

Велиме дека картичката издадена од банката може да се пробие ако тежината за пробивање е најмногу`LIMIT`. Вредноста `LIMIT` е членка на класата `Banka`, има почетна вредност 7 и истата може да се промени со функцијата `setLimit`(). За сите банки оваа вредност е иста. **(5 поени)**

Во класата `Banka` имплементирај ги функциите:

- функција `pecatiKarticki`() во која се печатат сите картички кои можат да се пробијат, секој во посебен ред. Претходно во првиот ред се печати: *Vo bankata XXXXX moze da se probijat kartickite:* **(5 поени)**.
- функција `dodadiDopolnitelenPin`(`char` \* smetka, `int` novPin) во која на картичката со дадена трансакциона сметка се додава нов дополнителен пин код. Ако тоа не е можно функцијата не прави ништо **(15 поени)**.

Комплетна функционалност **(5 поени)


## Test Cases


### Test Case 1

**Input:**
```text
2
ab1232432 345 0
bh4555432 876 1
4
ab1232432 2
ab1112432 100
ab1232432 56
ab1211111 88

```
**Expected output:**

```text
Vo bankata Komercijalna moze da se probijat kartickite:
ab1232432: 3
bh4555432: 3
```



### Test Case 2

**Input:**
```text
2
ab1232432 345 1
bh4555432 876 1
4
ab1232432 2
ab1112432 100
ab1232432 56
ab1211111 88

```
**Expected output:**

```text
Vo bankata Komercijalna moze da se probijat kartickite:
ab1232432: 5
bh4555432: 3
```



### Test Case 3

**Input:**
```text
2
ab1232432 345 0
bh4555432 876576 0
0

```
**Expected output:**

```text
Vo bankata Komercijalna moze da se probijat kartickite:
ab1232432: 3
```



### Test Case 4

**Input:**
```text
	2
ab1232432 345 0
bh4555432 8766 0
0

```
**Expected output:**

```text
Vo bankata Komercijalna moze da se probijat kartickite:
ab1232432: 3
bh4555432: 4
```



### Test Case 5

**Input:**
```text
	2
ab1232432 345 1
bh4555432 8766 1
2
ab1232432 2
ab1232432 34

```
**Expected output:**

```text
Vo bankata Komercijalna moze da se probijat kartickite:
ab1232432: 5
bh4555432: 4
```




### Test Case 6

**Input:**
```text

2
ab1232432 345 1
bh4555432 8766 1
4
ab1232432 2
ab1232432 34
ab1232432 56
ab1232432 67

```
**Expected output:**

```text
Vo bankata Komercijalna moze da se probijat kartickite:
bh4555432: 4
```

