## Exercise 13 - Mountain Lodge and Cable Car

Define the class `CableCar`, which stores the following information:

- **Location** (a dynamically allocated character field)
- **Daily ticket price** (integer)

Define the class `MountainLodge`, which stores the following information:

- **Name** (a static character field of maximum 15 characters)
- **Seasonal prices** (an array of 2 integers representing the price for one night at the mountain lodge during the two different seasons. Each mountain lodge has two seasons: summer and winter. The summer season begins on April 1st and ends on September 1st. For example, the price for a stay on July 24th will be stored in the field with index 0, where the summer season price is stored.)
- **Mountain lodge class** (a single character that can have a value from A to F, where A is the best class)
- **Whether it has a cable car** (`bool` type)
- **The mountain lodge's cable car** (a pointer to an object of the `CableCar` class)

For the given classes, define the necessary constructors, destructors, `set` and `get` methods. Appropriately overload the `=` operator. (20 points)

Overload the following operators:

- **The prefix `--` operator** (in the `MountainLodge` class) to decrease the class of the mountain lodge. Note that the lowest class for a mountain lodge is F. (5 points)
- **The `<<` operator** for printing an object of the `MountainLodge` class. (5 points)
- **The `<=` operator** to determine whether the mountain lodge has a class lower than or equal to the given character (comparison of a mountain lodge with a character). (5 points)

The printing format for information about a mountain lodge is:

- `Pelister klasa:A so zichara` — if it has a cable car
- `Korab klasa:B` — if it does not have a cable car

In the `MountainLodge` class, implement a function named `calculateDailyStay` which calculates the price of a daily stay at the mountain lodge for a given day and month of the year.

If the mountain lodge has a cable car, the daily cable car ticket price is also included in the daily stay price.

The function returns `void` (it does not return anything). The first argument is the day (1–31), and the second argument is the month (1–12) for which the price is calculated. The third argument is the price of the daily stay, which will be calculated inside the function.

If the day or month is invalid, an appropriate exception must be thrown and handled in the `main` function. Assume that every month has 31 days. (15 points)

A `main` function is provided in which the `CableCar` and `MountainLodge` classes are used. Without modifying the `main` function, create the described classes.

---

## Задача 13 - Планинарски дом и жичара

Да се креира класата `Zichara` во која ќе се чуваат информации за:

- **Место** (динамичко алоцирано поле од знаци)
- **Цена на дневна карта** (цел број)

Да се креира класа `PlaninarskiDom` во која се чуваат информации за:

- **Име** (статичко поле од најмногу 15 знаци)
- **Цени по сезони** (поле од 2 цели броеви кои ја претставуваат цената за спиење за еден ден во планинарскиот дом во двете различни сезони. Секој планинарски дом има две сезони: летна и зимска. Летната сезона почнува на 1-ви април и завршува до 1-ви септември. На пример, цената за престој на 24-ти јули ќе биде сместена во полето со индекс 0 — каде е сместена цената за летната сезона.)
- **Класа на планинарскиот дом** (еден знак кој може да има вредност од A до F, каде A е најдобра класа)
- **Дали има жичара** (`bool`-тип)
- **Жичарата на планинарскиот дом** (покажувач кон објект од класата `Zichara`)

За дадените класи дефинирајте ги потребните конструктори, деструктори, `set` и `get` методи. Соодветно преоптоварете го операторот `=`. (20 поени)

Да се преоптоварат:

- **Операторот `--`** (префиксен) за намалување на класата на планинарскиот дом (во класата `PlaninarskiDom`). Да се запази дека за планинарскиот дом најмала класа е F. (5 поени)
- **Операторот `<<`** за печатење на објект од `PlaninarskiDom`. (5 поени)
- **Операторот `<=`** за одредување дали планинарскиот дом има класа помала или еднаква со дадениот знак (споредба на планинарски дом со знак). (5 поени)

Формат на печатење на информации за еден планинарски дом:

- `Pelister klasa:A so zichara` — ако има жичара
- `Korab klasa:B` — ако нема жичара

Во класата `PlaninarskiDom` да се имплементира функција со име `presmetajDnevenPrestoj` со која се пресметува цената за дневен престој во планинарскиот дом за даден ден и месец во годината.

Ако планинарскиот дом има жичара, во цената за дневен престој влегува и дневната карта за жичарата.

Функцијата враќа `void` (не враќа ништо). Првиот аргумент на функцијата е денот (1–31), а вториот е месецот (1–12) за кои се пресметува цената. Третиот аргумент е цената за дневен престој која ќе се пресмета во функцијата.

Доколку денот или месецот се невалидни, да се фрли соодветен исклучок со кој се справуваме во `main` функцијата. Да се земе дека секој месец има 31 ден. (15 поени)

Дадена е `main`-функција во која се користат класите `Zichara` и `PlaninarskiDom`. Без таа да се менува, креирајте ги опишаните класи.






 ## Test Cases


### Test Case 1

**Input:**
```text
Pelister 21 31 E
1
Molika 20
3 3
```
**Expected output:**

```text
Informacii za PlaninarskiDomot:
Pelister klasa:F so Zichara
Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D
Cenata za 3.3 e 51
```




### Test Case 2

**Input:**
```text
Korab 48 42 A
0
12 4
```
**Expected output:**

```text
Informacii za PlaninarskiDomot:
Korab klasa:C
Cenata za 12.4 e 48
```




### Test Case 3

**Input:**
```text
Pelister 21 31 E
1
Molika 20
32 3
```
**Expected output:**

```text
Mesecot ili denot e greshno vnesen!
```

