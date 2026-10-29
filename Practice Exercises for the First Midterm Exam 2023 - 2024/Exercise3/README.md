## Exercise 3 - Stock Records and Client Portfolios

For the needs of a private banker who trades stocks, a module for managing client portfolios needs to be developed.

For this purpose, a class `StockRecord` should be created. The class should contain:

- ID, which identifies the stock being traded (a string of 12 characters).
- Name of the company that issued the stock (a string of 50 characters).
- Purchase price of the stock (a real number).
- Current price of the stock (a real number).
- Number of purchased shares (an integer).

The necessary constructors and a `set` method for the current price with the signature `void setNewPrice(double c)` should be defined for the class (**10 points**). In addition, the methods `double value()` and `double profit()` should be implemented. The first should calculate the value of the shares, while the second should calculate the current profit from the shares. The calculations are performed as follows (**5 points**):

```text
Value = number of shares * current price
Profit = number of shares * (current price - purchase price)
```

Additionally, the `<<` operator should be overloaded to print the object in the following format (**5 points**):

`Company NumberOfShares PurchasePrice CurrentPrice Profit`

A class `Client` should be created, containing:

- Client's first and last name (a string of 60 characters).
- Account ID (an integer).
- An array of companies owned by the client (a dynamically allocated array of objects of the `StockRecord` class).
- Number of objects in the array (an integer).

The necessary constructors, destructor, and the method `double totalValue()` should be defined for the `Client` class. This method calculates the current value of the shares owned by the client. It is calculated as the sum of the values of all shares from every company included in the client's portfolio (**15 points**).

Additionally, the following operators should be overloaded for the class:

- `+=` for purchasing a new company in the portfolio (adding a new object of the `StockRecord` class to the array of companies) (**10 points**).
- `<<` for printing information about the client's portfolio. The first line should display the account ID and the current portfolio value, separated by a space. Each subsequent line should display one of the companies included in the portfolio (**5 points**).

Complete functionality (**5 points**).

---

## Задача 3 - Акции и клиентски портфолија

За потребите на еден приватен банкар кој тргува со акции, потребно е да се направи модул за менаџирање со клиентски портфолија.

За таа цел, треба да се креира класа `StockRecord`. Класата треба да содржи:

- ID, кој означува која е акцијата која се тргува (низа од 12 знаци).
- Име на компанијата која ја издала акцијата (низа од 50 знаци).
- Цена според која се купени акциите (реален број).
- Моментална цена на акцијата (реален број).
- Број на акции кои се купени (цел број).

За класата да се дефинираат потребните конструктори и `set` метода за моменталната цена со потпис `void setNewPrice(double c)` (**10 поени**). Исто така, да се имплементираат методи `double value()` и `double profit()`. Првата треба да ја пресметува вредноста на акциите, а втората треба да го пресметува моменталниот профит од акциите. Пресметката се врши на следниот начин (**5 поени**):

```text
Вредност = број на акции * моментална цена
Профит = број на акции * (моментална цена - цена по која се купени)
```

Дополнително, да се преоптовари операторот `<<` за печатење на објектот во следниот формат (**5 поени**):

`Компанија БројНаАкции КуповнаЦена МоменталнаЦена Профит`

Да се креира класа `Client` која содржи:

- Име и презиме на клиентот (низа од 60 знаци).
- ID на сметка (цел број).
- Низа од компании кои ги поседува клиентот (динамичка низа од објекти од класата `StockRecord`).
- Број на објекти во низата (цел број).

За класата `Client` да се дефинираат потребните конструктори, деструктор и метода `double totalValue()` која ќе ја пресметува моменталната вредност на акциите кои ги поседува клиентот. Таа се пресметува како збир од вредноста на сите акции од секоја компанија од кои е составено клиентското портфолио (**15 поени**).

Дополнително, за класата да се преоптоварат операторите:

- `+=` за купување на нова компанија во портфолиото (додавање на нов објект од класата `StockRecord` во низата со компании) (**10 поени**).
- `<<` за печатење на информации за портфолиото на клиентот така што во првиот ред ќе бидат прикажани ID на сметката и моменталната вредност на портфолиото одделени со празно место, а во секој нареден ред ќе бидат прикажани компаниите од кои е составено портфолиото, секоја во посебен ред (**5 поени**).

Комплетна функционалност (**5 поени**).





 ## Test Cases


### Test Case 1

**Input:**
```text
3
Aleksandar
240992
3
CH0038863350
Nestle
100
90
100
DE000BAY0017
Bayer
60
70
500
DE0007164600
SAP
110
115
200
```
**Expected output:**

```text
=====TEST NA KLASATA Client=====
Konstruktor OK
Operator += OK
240992 67000
Nestle 100 100 90 -1000
Bayer 500 60 70 5000
SAP 200 110 115 1000
Operator << OK
```


### Test Case 2

**Input:**
```text
2
2
DE0008404005
Allianz
120
100
100
US5949181045
Microsoft
60
90
100
```
**Expected output:**

```text
=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====
10000
Allianz 100 120 100 -2000
9000
Microsoft 100 60 90 3000
```




### Test Case 3

**Input:**
```text
1
90
```
**Expected output:**

```text
=====TEST NA KLASATA StockRecord=====
Konstruktor OK
SET metoda OK
```
