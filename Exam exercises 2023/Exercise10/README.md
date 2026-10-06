# Exercise 10 - FINKI Classified Ads

## Problem Description

For the needs of the electronic classified ads system FINKI-Oglasi, develop a class `Oglas` that stores information about:

- title (a character array with a maximum of 50 characters)
- category (a character array with a maximum of 30 characters)
- description (a character array with a maximum of 100 characters)
- price expressed in euros (real number)

**(5 points)**

The following should be provided for this class:

- Operator `>` for comparing two advertisements according to their price. **(5 points)**
- Operator `<<` for printing the advertisement data in the following format: **(5 points)**

```text
[title]
[description]
[price] evra
```

Develop a class` Oglasnik` that stores information about:
- the name of the classified ads service (a character array with a maximum of 20 characters)
- an array of advertisements (a dynamically allocated array of objects of class `Oglas`)
- the number of advertisements in the array (integer)
**(5 points)**

The following should be provided for this class:

- `Operator +=` for adding a new advertisement to the array of advertisements. (5 points)
If the price of the advertisement being entered is negative, an exception NegativnaVrednost should be generated (an object of class NegativnaVrednost, which should also be defined). In this case, the message "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!" should be printed and the advertisement should not be added to the array. **(5 points)**
- Operator << for printing the advertisements in the classified ads service. (5 points)
The printing should be in the following format:
- `Operator << `for printing the advertisements in the classified ads service. (5 points)
The printing should be in the following format:

```text
[Classified ads service name]

[title1] [description1] [price1]

[title2] [description2] [price2]
```

- Function void `oglasOdKategorija(const char *k)` that prints all advertisements from the category k passed as an input argument to the method. **(5 points)**
- Function void `najniskaCena()` that prints the advertisement with the lowest price. If there are multiple advertisements with the same lowest price, the data of the first one should be printed. **(5 points)**

 All variables in the classes must be **private**.

 Provide all necessary methods for the correct functioning of the program. **(5 points)**



 # Задача 10 - ФИНКИ-Огласи

## Опис на задачата

За потребите на електронскиот огласник ФИНКИ-Огласи треба да се развие класа `Oglas` со информации за:

- наслов (текстуална низа од максимум 50 знаци)
- категорија (текстуална низа од максимум 30 знаци)
- опис (текстуална низа од максимум 100 знаци)
- цена изразена во евра (реален број)

**(5 points)**

За оваа класа да се обезбедат:

- Оператор `>` за споредба на два огласи според цената. **(5 поени)**
- Оператор `<<` за печатење на податоците за огласот во форма: **(5 поени)**

```text
[title]
[description]
[price] evra
```

Да се развие класа `Oglasnik` во која се чуваат податоци за:
- име на огласникот (текстуална низа од максимум 20 знаци)
- низа од огласи (динамички резервирана низа од објекти од класата `Oglas`)
- број на огласи во низата (цел број)
**(5 поени)**

За оваа класа да се обезбедат:

- `Оператор +=` за додавање нов оглас во низата од огласи. (5 поени)
Ако цената на огласот што се внесува е негативна, треба да се генерира исклучок NegativnaVrednost (објект од класата NegativnaVrednost што посебно треба да се дефинира). Во ваков случај се печати порака "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!" и не се додава во низата. **(5 поени)**
The printing should be in the following format:
-` Оператор <<` за печатење на огласите во огласникот. (5 поени)
The printing should be in the following format:

```text
[Име на огласникот]

[наслов1] [опис1] [цена1]

[наслов2] [опис2] [цена2]
```

- Функција void oglasOdKategorija(const char *k) со која се печатат сите огласи од категоријата k што е проследена како влезен аргумент на методот. **(5 поени)**
- Функција void najniskaCena() со која се печати огласот што има најниска цена. Ако има повеќе огласи со иста најниска цена, да се испечатат податоците за првиот од нив. **(5 поени)**

 Сите променливи во класите се **приватни**.

 Да се обезбедат сите потребни методи за правилно функционирање на програмата. **(5 поени)**


 ## Test Cases


### Test Case 1

**Input:**
```text
	
2
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
13000
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
```
**Expected output:**

```text
-----Test Oglas & operator > -----
Prviot oglas e poskap.
```


### Test Case 2

**Input:**
```text
	
6
FINKI-Oglasnik
7
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
13000
AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Avtomobili
Godina: 2013 Kilometraza: 150 000 - 159 999
12900
NOV STAN OD 102M2 NA VODNO
Stanovi
Broj na sobi: 4
99000
NOV DVOSOBEN STAN 35m2 VLAE
Stanovi
Broj na sobi: 2
36000
Luksuzen stan vo Aerodrom
Stanovi
Broj na sobi: 5, Povrsina 90m2
89000
Luksuzen stan vo Ohrid
Stanovi
Broj na sobi: 4, Povrsina 70m2
50000
```
**Expected output:**

```text
-----Test najniskaCena -----
Oglas so najniska cena:
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Godina: 2011 Kilometraza: 140 000 - 149 999
12000 evra
```


### Test Case 3

**Input:**
```text
2
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
13000
```
**Expected output:**

```text
-----Test Oglas & operator > -----
Prviot oglas ne e poskap.
```


### Test Case 4

**Input:**
```text
1
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
```
**Expected output:**

```text
-----Test Oglas & operator <<-----
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Godina: 2011 Kilometraza: 140 000 - 149 999
12000 evra
```



### Test Case 5

**Input:**
```text
4
FINKI-Oglasnik
7
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
13000
AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Avtomobili
Godina: 2013 Kilometraza: 150 000 - 159 999
12900
NOV STAN OD 102M2 NA VODNO
Stanovi
Broj na sobi: 4
99000
NOV DVOSOBEN STAN 35m2 VLAE
Stanovi
Broj na sobi: 2
36000
Luksuzen stan vo Aerodrom
Stanovi
Broj na sobi: 5, Povrsina 90m2
89000
Luksuzen stan vo Ohrid
Stanovi
Broj na sobi: 4, Povrsina 70m2
50000
Stanovi
```
**Expected output:**

```text
-----Test oglasOdKategorija -----
Oglasi od kategorijata: Stanovi
NOV STAN OD 102M2 NA VODNO
Broj na sobi: 4
99000 evra

NOV DVOSOBEN STAN 35m2 VLAE
Broj na sobi: 2
36000 evra

Luksuzen stan vo Aerodrom
Broj na sobi: 5, Povrsina 90m2
89000 evra

Luksuzen stan vo Ohrid
Broj na sobi: 4, Povrsina 70m2
50000 evra
```



### Test Case 6

**Input:**
```text
7
FINKI-Oglasnik
9
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Avtomobili
Godina: 2013 Kilometraza: 150 000 - 159 999
12900
NOV STAN OD 110M2 NA VODNO
Stanovi
Broj na sobi: 4
99000
NOV DVOSOBEN STAN 33m2 VLAE
Stanovi
Broj na sobi: 2
-36000
Luksuzen stan vo Aerodrom
Stanovi
Broj na sobi: 5, Povrsina 90m2
89000
Luksuzen stan vo Ohrid
Stanovi
Broj na sobi: 4, Povrsina 74m2
50000
KUKA OD 250M2 VO KISELA VODA
Kuki
Prekrasen pogled, Broj na sobi > 10, Povrsina 400m2
156000
Moderno namestena vila itno
Kuki
Broj na sobi 6, Povrsina 130m2
80000
Stanovi
```
**Expected output:**

```text
-----Test All -----
Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!
FINKI-Oglasnik
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Godina: 2011 Kilometraza: 140 000 - 149 999
12000 evra

BMW 520 FULL OPREMA
Godina: 2011 Kilometraza: 140 000 - 149 999
12000 evra

AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Godina: 2013 Kilometraza: 150 000 - 159 999
12900 evra

NOV STAN OD 110M2 NA VODNO
Broj na sobi: 4
99000 evra

Luksuzen stan vo Aerodrom
Broj na sobi: 5, Povrsina 90m2
89000 evra

Luksuzen stan vo Ohrid
Broj na sobi: 4, Povrsina 74m2
50000 evra

KUKA OD 250M2 VO KISELA VODA
Prekrasen pogled, Broj na sobi > 10, Povrsina 400m2
156000 evra

Moderno namestena vila itno
Broj na sobi 6, Povrsina 130m2
80000 evra

Oglasi od kategorijata: Stanovi
NOV STAN OD 110M2 NA VODNO
Broj na sobi: 4
99000 evra

Luksuzen stan vo Aerodrom
Broj na sobi: 5, Povrsina 90m2
89000 evra

Luksuzen stan vo Ohrid
Broj na sobi: 4, Povrsina 74m2
50000 evra

Oglas so najniska cena:
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Godina: 2011 Kilometraza: 140 000 - 149 999
12000 evra
```



### Test Case 7

**Input:**
```text
5
FINKI-Oglasnik
7
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
-13000
AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Avtomobili
Godina: 2013 Kilometraza: 150 000 - 159 999
12900
NOV STAN OD 102M2 NA VODNO
Stanovi
Broj na sobi: 4
99000
NOV DVOSOBEN STAN 35m2 VLAE
Stanovi
Broj na sobi: 2
36000
Luksuzen stan vo Aerodrom
Stanovi
Broj na sobi: 5, Povrsina 90m2
-89000
Luksuzen stan vo Ohrid
Stanovi
Broj na sobi: 4, Povrsina 70m2
50000
```
**Expected output:**

```text
-----Test Exception -----
Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!
Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!
FINKI-Oglasnik
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Godina: 2011 Kilometraza: 140 000 - 149 999
12000 evra

AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Godina: 2013 Kilometraza: 150 000 - 159 999
12900 evra

NOV STAN OD 102M2 NA VODNO
Broj na sobi: 4
99000 evra

NOV DVOSOBEN STAN 35m2 VLAE
Broj na sobi: 2
36000 evra

Luksuzen stan vo Ohrid
Broj na sobi: 4, Povrsina 70m2
50000 evra
```



### Test Case 8

**Input:**
```text
3
FINKI-Oglasnik
3
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
13000
AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Avtomobili
Godina: 2013 Kilometraza: 150 000 - 159 999
12900
```
**Expected output:**

```text
-----Test Oglasnik, operator +=, operator << -----
FINKI-Oglasnik
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Godina: 2011 Kilometraza: 140 000 - 149 999
12000 evra

BMW 520 FULL OPREMA
Godina: 2011 Kilometraza: 140 000 - 149 999
13000 evra

AUDI A3 2.0 TDI LIMOUSINE PRO LINE
Godina: 2013 Kilometraza: 150 000 - 159 999
12900 evra
```
