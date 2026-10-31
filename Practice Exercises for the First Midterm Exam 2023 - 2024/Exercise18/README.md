## Exercise 18 - Ski Center with the Highest Capacity

Define a structure `SkiLift` that stores information about the name of the ski lift (an array of 15 characters), the maximum number of users it can serve in one ride, and whether it is operational.

Then define a structure `SkiCenter` that stores information about the name of the ski center, the country in which it is located (arrays of 20 characters), an array of ski lifts (maximum 20) that it has, and the number of ski lifts.

Implement a function with the following signature:

```cpp
void najgolemKapacitet(SkiCenter *sc, int n)
```

The function should print the ski center with the highest capacity for serving skiers (the total number of skiers that can be served at one moment by all ski lifts in the center).

If two ski centers have the same capacity, the one with the greater number of ski lifts should be printed.

The name, country, and capacity of the ski center should be printed on separate lines.

When calculating the capacity of a ski center, only ski lifts that are operational should be taken into account.

## Задача 18 - Скијачки центар со најголем капацитет

Да се креира структура `SkiLift` во која се чуваат податоци за името на ски лифтот (низа од 15 знаци), максимален број на корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креира структура `SkiCenter` во која се чуваат податоци за името на скијачкиот центар, држава во која се наоѓа (низи од 20 знаци), низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис:

```cpp
void najgolemKapacitet(SkiCenter *sc, int n)
```

која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи (вкупниот број на скијачи кои може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот).

Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови.

Притоа треба да се испечатат во посебен ред името, државата и капацитетот на ски центарот.

Кога се пресметува капацитет на еден ски центар во предвид се земаат само ски лифтовите кои се поставени дека се во функција.




## Test Cases


### Test Case 1

**Input:**
```text
1
Mavrovo
Makedonija
6
Ednosed
30
1
Dvosed
60
1
Ciciban
10
1
Galicki
20
1
Belicki
36
0
Plavi
40
1
```
**Expected output:**

```text
Mavrovo
Makedonija
160
```




### Test Case 2

**Input:**
```text
5
Kopaonik
Srbija
7
MaloJezero
30
1
Zlatiborac
80
1
PanchevVrh
80
0
Karaman
25
1
Jaram
40
1
Krcmar
120
1
Vucak
20
1
Borovets
Bugarija
8
Rila
18
1
Iglika
20
1
Rotata
36
1
Sitnyakovo
40
0
Martinovibaraki
60
0
Yastrebetz
80
1
Popangelov
100
1
Suhar
32
1
Mavrovo
Makedonija
6
Ednosed
30
1
Dvosed
60
1
Ciciban
10
1
Galicki
20
1
Belicki
36
0
Plavi
40
1
Shapka
Makedonija
5
Teteks1
20
1
Teteks2
50
0
Ceripashina
100
0
Jelak
10
1
Aerodrom
36
1
Bansko
Bugarija
6
Tomba
40
0
Shiligarnika
80
1
Banderitsa
70
1
Todorka
36
1
ChalinValog
24
0
Plato
60
1
```
**Expected output:**

```text
Kopaonik
Srbija
315
```




### Test Case 3

**Input:**
```text
3
Shapka
Makedonija
5
Teteks1
20
1
Teteks2
50
0
Ceripashina
100
0
Jelak
10
1
Aerodrom
36
1
Bansko
Bugarija
6
Tomba
40
0
Shiligarnika
80
1
Banderitsa
70
1
Todorka
36
1
ChalinValog
56
1
Plato
60
1
Borovets
Bugarija
8
Rila
18
1
Iglika
20
1
Rotata
36
1
Sitnyakovo
40
0
Martinovibaraki
60
0
Yastrebetz
80
1
Popangelov
100
1
Suhar
32
1
```
**Expected output:**

```text
Bansko
Bugarija
302
```




### Test Case 4

**Input:**
```text
3
Shapka
Makedonija
5
Teteks1
20
1
Teteks2
50
0
Ceripashina
100
0
Jelak
10
1
Aerodrom
36
1
Bansko
Bugarija
6
Tomba
40
0
Shiligarnika
80
1
Banderitsa
70
1
Todorka
36
1
ChalinValog
100
1
Plato
60
0
Borovets
Bugarija
8
Rila
18
1
Iglika
20
1
Rotata
36
1
Sitnyakovo
40
0
Martinovibaraki
60
0
Yastrebetz
80
1
Popangelov
100
1
Suhar
32
1
```
**Expected output:**

```text
Borovets
Bugarija
286
```




### Test Case 5

**Input:**
```text
2
Shapka
Makedonija
5
Teteks1
20
1
Teteks2
50
0
Ceripashina
100
0
Jelak
10
1
Aerodrom
36
1
Bansko
Bugarija
6
Tomba
40
0
Shiligarnika
80
1
Banderitsa
70
1
Todorka
36
1
ChalinValog
24
0
Plato
60
1
```
**Expected output:**

```text
Bansko
Bugarija
246
```
