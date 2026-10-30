## Exercise 8 - Laptop Store Offers

## Задача 8 - Понуди за лаптопи во продавници

### Problem Statement

In the C++ programming language, create a structure `Laptop` to describe the specifications of a given laptop. The structure should contain: **(5 points)**

- Manufacturer (a string of 100 characters)
- Monitor size in inches (a real number)
- Whether it has a touchscreen or not (a Boolean variable)
- Price (an integer)

Create a structure `ITStore` that contains: **(5 points)**

- Store name (a string of 100 characters)
- Location (a string of 100 characters)
- An array of available laptops (an array of a maximum of 100 elements of type `Laptop`)
- Number of elements in the array (an integer)

Create a function `print` to display information about all laptops in a store in the following format: **(10 points)**

```text
[StoreName] [Location]
[Brand1] [MonitorSize1] [Price1]
[Brand2] [MonitorSize2] [Price2]
[Brand3] [MonitorSize3] [Price3]
...
```

Create a function `cheapestOffer` that receives an array of variables of type `ITStore` and prints the name and location of the store offering the cheapest laptop, along with its price. The cheapest laptop is the one with the lowest price that also has a touchscreen option. If multiple stores offer such laptops at the same price, print the first one found. **(15 points)**

Complete the `main` function. **(10 points)**

Input consists of the number of stores, followed by the name and location of each store, then the number of laptops, and for each laptop, its manufacturer, monitor size, whether it has a touchscreen, and its price. After reading the input, print all the entered stores and the cheapest offer.

### Опис на задачата

Во програмскиот јазик C++ да се креира структура `Laptop` за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: **(5 поени)**

- Фирма која го произведува (низа од 100 знаци)
- Големина на монитор во инчи (реален број)
- Дали е со touch или не (булова променлива)
- Цена (цел број)

Да се креира структура `ITStore`, што содржи: **(5 поени)**

- Име на продавницата (низа од 100 знаци)
- Локација (низа од 100 знаци)
- Низа од достапни лаптопи (низа од максимум 100 елементи од структурата `Laptop`)
- Број на елементи во низата (цел број)

Да се креира функција `print` за печатење на информациите за сите лаптопи во една продавница во следниот формат: **(10 поени)**

```text
[Ime na prodavnicata] [Lokacija]
[Marka1] [dim_monitor1] [Cena1]
[Marka2] [dim_monitor2] [Cena2]
[Marka3] [dim_monitor3] [Cena3]
...
```

Да се креира функција `cheapestOffer`, што прима низа од променливи од типот `ITStore` и го печати името и локацијата на онаа продавница која нуди најевтин преносен компјутер и неговата цена. Најефтин преносен компјутер е оној што има најниска цена и плус опција за touch. Ако има повеќе такви продавници, се печати прво најдената. **(15 поени)**

Да се дополни функцијата `main`. **(10 поени)**

Од тастатура се внесува бројот на продавници, па потоа за секоја продавница се внесуваат името и локацијата, а потоа бројот на компјутери, па за секој од компјутерите фирма која го произведува, големина на монитор, дали има touch и цена. Потоа се печатат сите внесени продавници и најевтината понуда.





 ## Test Cases


### Test Case 1

**Input:**
```text
2
AMC
Skopje
3
dell
13.1
1
32500
asus
15.0
0
20200
hp
13.1
1
42000
Anhoch
Skopje
1
asus
13.3
1
32000
```
**Expected output:**

```text
AMC Skopje
dell 13.1 32500
asus 15 20200
hp 13.1 42000
Anhoch Skopje
asus 13.3 32000
Najeftina ponuda ima prodavnicata:
Anhoch Skopje
Najniskata cena iznesuva: 32000
```




### Test Case 2

**Input:**
```text
3
HPstore
Skopje
2
hp_1
13.0
1
41500
hp_2
13.3
1
69900
AMC
Skopje
3
dell
13.1
1
32500
asus
15.0
1
20200
hp
13.1
1
42000
Anhoch
Skopje
1
asus
13.1
1
32000
```
**Expected output:**

```text
HPstore Skopje
hp_1 13 41500
hp_2 13.3 69900
AMC Skopje
dell 13.1 32500
asus 15 20200
hp 13.1 42000
Anhoch Skopje
asus 13.1 32000
Najeftina ponuda ima prodavnicata:
AMC Skopje
Najniskata cena iznesuva: 20200
```




### Test Case 3

**Input:**
```text
1
AMC
Skopje
3
asus
15.0
1
20200
dell
13.3
1
32500
hp
13.3
1
42000
```
**Expected output:**

```text
AMC Skopje
asus 15 20200
dell 13.3 32500
hp 13.3 42000
Najeftina ponuda ima prodavnicata:
AMC Skopje
Najniskata cena iznesuva: 20200
```




### Test Case 4

**Input:**
```text
1
AMC
Skopje
3
hp
13.3
1
42000
asus
15.0
0
20200
dell
13.3
1
32500
```
**Expected output:**

```text
AMC Skopje
hp 13.3 42000
asus 15 20200
dell 13.3 32500
Najeftina ponuda ima prodavnicata:
AMC Skopje
Najniskata cena iznesuva: 32500
```




### Test Case 5

**Input:**
```text
3
HPstore
Skopje
2
hp_1
13.0
0
41500
hp_2
13.3
1
69900
AMC
Skopje
3
dell
13.1
0
32500
asus
15.6
0
49900
hp
13.1
1
69900
Anhoch
Skopje
1
asus
13.1
0
32000
```
**Expected output:**

```text
HPstore Skopje
hp_1 13 41500
hp_2 13.3 69900
AMC Skopje
dell 13.1 32500
asus 15.6 49900
hp 13.1 69900
Anhoch Skopje
asus 13.1 32000
Najeftina ponuda ima prodavnicata:
HPstore Skopje
Najniskata cena iznesuva: 69900
```
