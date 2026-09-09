# Exercise 2 - Drivers Tax & Earnings Management

### Problem Description
Define an abstract class `Vozac` (Driver) that stores the following information:
* `ime` (array of max 100 characters - driver's name)
* `vozrast` (integer - age)
* `trki` (integer - total number of races)
* `veteran` (boolean - status indicator)

Overload the following operators:
* **Operator `<<`**: prints the name, age, number of races, and if the driver is a veteran, prints `VETERAN` on a new line.
* **Operator `==`**: compares two drivers based on their earnings per race.

Derive two classes from `Vozac`: `Avtomobilist` (Car Driver) and `Motociklist` (Motorcyclist).

Additional attribute for `Avtomobilist`:
* `cena` (double - price of the car)

Additional attribute for `Motociklist`:
* `mokjnost` (integer - engine power)

**Earnings per race calculation:**
* For `Avtomobilist`: `CAR_PRICE / 5`
* For `Motociklist`: `ENGINE_POWER * 20`

**Tax calculation:**
* For `Avtomobilist`: If the number of races is greater than 10, the tax rate is 15% of earnings; otherwise, it is 10%.
* For `Motociklist`: If the driver is a veteran, the tax rate is 25% of earnings; otherwise, it is 20%.

**Global Function:**
Implement a global function `soIstaZarabotuvachka(Vozac **vozaci, int n, Vozac *v)` that takes an array of pointers to `Vozac`, the total number `n`, and a pointer to a driver `v`. The function returns the total count of drivers from the array who have identical earnings to driver `v`.

---

### Опис на задачата
Да се дефинира апстрактна класа `Vozac` во која се чуваат информации за:
* `ime` (низа од максимум 100 знаци)
* `vozrast` (цел број)
* `trki` (цел број на одиграни трки)
* `veteran` (булова вредност: `true`/`false`)

За класата да се овозможат следните преоптоварувања:
* **Оператор `<<`**: ги печати името, возраста, бројот на трки и доколку возачот е ветеран, во нов ред печати `VETERAN`.
* **Оператор `==`**: споредува два возачи врз основа на нивната заработувачка по трка.

Од класата `Vozac` да се изведат две класи: `Avtomobilist` и `Motociklist`.

За `Avtomobilist` дополнително се чува:
* `cena` (децимален број - цена на автомобилот)

За `Motociklist` дополнително се чува:
* `mokjnost` (цел број - моќност на моторот во KS)

**Пресметка на заработувачка по трка:**
* За `Avtomobilist`: `CENA_AVTOMOBIL / 5`
* За `Motociklist`: `MOKJNOST_NA_MOTOR * 20`

**Пресметка на данок:**
* За `Avtomobilist`: Ако бројот на трки е поголем од 10, данокот е 15% од заработувачката, инаку е 10%.
* За `Motociklist`: Ако возачот е ветеран, данокот е 25% од заработувачката, инаку е 20%.

**Глобална функција:**
Да се напише надворешна функција `soIstaZarabotuvachka(Vozac **vozaci, int n, Vozac *v)` која прима низа од покажувачи кон `Vozac`, нивниот број `n` и покажувач кон конкретен возач `v`. Функцијата го враќа бројот на возачи од низата кои имаат иста заработувачка со возачот `v`.

---

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

### Test Case 3

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

### Test Case 4

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




