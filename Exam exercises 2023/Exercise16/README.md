# Exercise 16 - Transport Offers

## Description

A tourist agency offers different transport options for passengers. For each offer, the following information is stored:

- destination (array of characters)
- basic price (integer)
- distance to the destination in km (integer)

The `Transport` class should be used as a base class from which the classes `AvtomobilTransport` and `KombeTransport` are derived, for modeling transport offers by car and van, respectively.

For each car transport offer, information is stored about whether the offer includes a paid driver (boolean variable), while for van transport, the number of people that can be transported in the van is stored (integer). **(5 points)**

For each object of both derived classes, the following methods should be available:

- A constructor with arguments corresponding to the data members, as well as set and get methods for the data members. **(5 points)**
- A method `cenaTransport` for calculating the price of the offer in the following way:
  - For car transport - the basic price is increased by 20% if there is a paid driver.
  - For van transport - the basic price is reduced depending on the number of passengers in the van. For each passenger in the van, the price is reduced by 200. **(10 points)**
- An overloaded operator `<` for comparing two passenger transport offers according to the distance to the destination. **(5 points)**

A function `pecatiPoloshiPonudi` should be implemented. It receives as input an array of passenger transport offers, the number of elements in the array, and one offer `T`.

The function prints the destination, distance to the destination, and price for the offers from the array that are more expensive than offer `T`, sorted in ascending order according to the distance to the destination (see the function call). **(10 points)**

Complete functionality of the code. **(5 points)**

---

# Вежба 16 - Транспортни понуди

## Опис

Туристичка агенција нуди различни понуди за транспорт на патници. За секоја понуда се чуваат податоци за:

- дестинацијата (низа од знаци)
- основната цена (цел број)
- растојанието до дестинацијата изразено во km (цел број)

Од класата `Transport` да се изведат класите `AvtomobilTransport` и `KombeTransport` за моделирање на понудите за транспорт кои нудат транспорт со автомобил или комбе, соодветно.

За секоја понуда за транспорт со автомобил се чува податок за тоа дали во понудата има платен шофер (булова променлива), а за транспорт со комбе бројот на луѓе кои може да се превезат во комбето (цел број). **(5 поени)**

За секој објект од двете изведени класи треба да бидат на располагање следниве методи:

- конструктор со аргументи што одговараат на податочните членови и set и get методи за податочните членови **(5 поени)**
- метод `cenaTransport`, за пресметување на цената на понудата на следниот начин:
  - За транспорт со автомобил - основната цена се зголемува за 20% ако има платен шофер
  - За транспорт со комбе - основната цена ќе се намали зависно од бројот на патници во комбето. За секој патник во комбето цената се намалува за 200 **(10 поени)**
- преоптоварен оператор `<` за споредба на две понуди за транспорт на патник според растојанието до дестинацијата. **(5 поени)**

Да се имплементира функција `pecatiPoloshiPonudi` што на влез прима низа од понуди за транспорт на патник, бројот на елементите од низата и една понуда T.

Функцијата ја печати дестинацијата, растојанието до дестинацијата и цената за понудите од низата кои се поскапи од понудата T сортирани во растечки редослед по растојанието до дестинацијата (погледни го повикот на функцијата). **(10 поени)**

Комплетна функционалност на кодот **(5 поени)**


## Test Cases


### Test Case 1

**Input:**
```text
3
1 Belgrad 3200 900 1
1 Bitola 2500 400 0
2 Sofija 5000 1040 2
```
**Expected output:**

```text
Bitola 400 2500
Belgrad 900 3840
Sofija 1040 4600
```




### Test Case 2

**Input:**
```text	
2
1 Belgrad 3200 900 1
1 Bitola 2500 400 0
```
**Expected output:**

```text
Bitola 400 2500
Belgrad 900 3840
```




### Test Case 3

**Input:**
```text
2
1 Belgrad 3200 900 1
1 Bitola 1500 400 0
```
**Expected output:**

```text
Belgrad 900 3840
```




### Test Case 4

**Input:**
```text
4
2 Krushevo 1200 400 4
1 Belgrad 3200 900 1
1 Bitola 2500 400 0
2 Sofija 5000 1040 2
```
**Expected output:**

```text
Bitola 400 2500
Belgrad 900 3840
Sofija 1040 4600
```
