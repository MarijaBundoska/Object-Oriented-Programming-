## Exercise 2 - Drivers and Earnings per Race

Define a class `Vozac` that stores the following information:

- Name (a string of up to 100 characters)
- Age (an integer)
- Number of races (an integer)
- Whether the driver is a veteran (yes/no)

Overload the following operators:

- Operator `<<` for printing the driver's name, age, number of races, and whether the driver is a veteran (print `VETERAN`).
- Operator `==` for comparing two drivers according to their earnings per race.

Derive two new classes from this class: `Avtomobilist` and `Motociklist`.

For the car driver, additionally store:

- Car price (a decimal number).

For the motorcycle driver, additionally store:

- Engine power (an integer).

The earnings per race are calculated as follows:

- For a car driver, the earnings per race are \(\frac{CENA\_AVTOMOBIL}{5}\).
- For a motorcycle driver, the earnings per race are \(MOKJNOST\_NA\_MOTOR \times 20\).

Every car driver pays tax on their earnings. Implement appropriate methods for calculating the tax:

- For car drivers: if the number of races is greater than 10, the tax rate is 15% of the earnings; otherwise, the tax rate is 10% of the earnings.
- For motorcycle drivers: if the driver is a veteran, the tax rate is 25% of the earnings; otherwise, the tax rate is 20% of the earnings.

Write an external function `soIstaZarabotuvachka` that receives an array of pointers to objects of class `Vozac`, the number of drivers, and a pointer to a driver object. The function should return the number of drivers who have the same earnings per race as the given driver.


## Задача 2 - Возачи и заработувачка по трка

Да се дефинира класа `Vozac` во која се чуваат информации за:

- Име (низа од максимум 100 знаци)
- Возраст (цел број)
- Број на трки (цел број)
- Дали е ветеран (да/не)

Да се преоптоварат:

- Операторот `<<` за печатење на името, возраста, бројот на трки и дали возачот е ветеран (се печати `VETERAN`).
- Операторот `==` за споредување на двајца возачи според заработувачката по трка.

Од оваа класа да се изведат две нови класи `Avtomobilist` и `Motociklist`.

За автомобилистот дополнително се чува:

- Цена на автомобилот (децимален број).

За мотоциклистот дополнително се чува:

- Моќност на моторот (цел број).

Заработувачката по трка на возачите се пресметува како:

- За автомобилистот, заработувачката по трка е \(\frac{CENA\_AVTOMOBIL}{5}\).
- За мотоциклистот, заработувачката по трка е `MOKJNOST_NA_MOTOR * 20`.

Секој возач плаќа данок на заработка. Да се напишат соодветни методи за пресметување данок:

- За автомобилисти: ако бројот на трки е поголем од 10, стапката на данок е 15% од заработката, инаку 10% од заработката.
- За мотоциклисти: ако возачот е ветеран, стапката на данок е 25% од заработката, инаку 20% од заработката.

Да се напише надворешна функција `soIstaZarabotuvachka` која како аргументи прима низа од покажувачи од класата `Vozac`, нивниот број, како и покажувач кон објект од класата `Vozac`, и враќа како резултат бројот на возачи кои имаат иста заработувачка по трка со проследениот возач.




## Test Cases


### Test Case 1

**Input:**
```text
5
1
Hamilton 30 95 0 55000
Vetel 26 88 1 800
Barrichello 38 198 0 810
Rossi 32 130 1 800
Lorenzo 24 45 0 900
VozacX 38 198 1 800
```
**Expected output:**

```text
=== DANOK ===
Hamilton
30
95
1650
Vetel
26
88
VETERAN
4000
Barrichello
38
198
3240
Rossi
32
130
VETERAN
4000
Lorenzo
24
45
3600
=== VOZAC X ===
VozacX
38
198
VETERAN
=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===
2
```




### Test Case 2

**Input:**
```text
5
4
Hamilton 30 95 0 55000
Vetel 26 88 1 8000
Barrichello 38 198 0 8100
Rossi 32 130 1 8000
Lorenzo 24 45 0 9000
VozacX 38 198 1 800
```
**Expected output:**

```text
=== DANOK ===
Hamilton
30
95
1650
Vetel
26
88
VETERAN
240
Barrichello
38
198
243
Rossi
32
130
VETERAN
240
Lorenzo
24
45
36000
=== VOZAC X ===
VozacX
38
198
VETERAN
=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===
0
```




### Test Case 3
**Input:**
```text
5
3
Hamilton 30 95 0 55000
Vetel 26 88 0 14000
Barrichello 38 198 1 30000
Rossi 32 130 1 850
Lorenzo 24 45 0 900
VozacX 38 198 1 850
```
**Expected output:**

```text
=== DANOK ===
Hamilton
30
95
1650
Vetel
26
88
420
Barrichello
38
198
VETERAN
900
Rossi
32
130
VETERAN
4250
Lorenzo
24
45
3600
=== VOZAC X ===
VozacX
38
198
VETERAN
=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===
1
```

