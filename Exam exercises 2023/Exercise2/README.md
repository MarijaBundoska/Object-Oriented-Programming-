# Exercise 2 - Drivers Tax & Earnings Management

## Problem Description

Define an abstract class `Driver` that stores the following information:

- `name` – array of max 100 characters (driver's name)
- `age` – integer (driver's age)
- `races` – integer (total number of races)
- `isVeteran` – boolean (veteran status indicator)

Overload the following operators:

- **Operator `<<`** – prints the name, age, number of races, and if the driver is a veteran, prints `VETERAN` on a new line.
- **Operator `==`** – compares two drivers based on their earnings per race.

Derive two classes from `Driver`: `CarDriver` and `Motorcyclist`.

### Additional Attribute for `CarDriver`

- `carPrice` – double (price of the car)

### Additional Attribute for `Motorcyclist`

- `enginePower` – integer (engine power)

### Earnings per Race Calculation

- For `CarDriver`: `carPrice / 5`
- For `Motorcyclist`: `enginePower * 20`

### Tax Calculation

- For `CarDriver`: If the number of races is greater than 10, the tax rate is 15% of earnings; otherwise, it is 10%.
- For `Motorcyclist`: If the driver is a veteran, the tax rate is 25% of earnings; otherwise, it is 20%.

### Global Function

Implement a global function `countSameEarnings(Driver **drivers, int n, Driver *targetDriver)` that takes an array of pointers to `Driver`, the total number of drivers `n`, and a pointer to a driver `targetDriver`. The function returns the number of drivers from the array who have the same earnings per race as the given driver.

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
Да се напише надворешна функција `countSameEarnings(Driver **drivers, int n, Driver *targetDriver)` која како аргументи прима низа од покажувачи кон објекти од класата `Driver`, нивниот број `n`, како и покажувач кон објект од класата `Driver`. Функцијата како резултат го враќа бројот на возачи кои имаат иста заработувачка по трка со проследениот возач.
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




