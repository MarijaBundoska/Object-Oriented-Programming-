# Exercise - Mobile Service

## Problem Statement

Create a class for describing a service for mobile devices. For each mobile device, the following data is stored: model (an array of 100 characters), device type (smartphone or computer), required hours for basic inspection (decimal number), and production year (integer). **(5 points)**

All devices have the same duration for basic inspection, initially set to 1 hour. This value can be changed by a decision of the service. Additionally, devices that are newer than 2015 require an additional 1.5 hours for inspection. During inspection, laptops require an additional 2 hours for software diagnostics. **(5 points)**

For this class, implement the `<<` operator for printing a device in the following format:

> `[device_model]`  
> `[device_type] [inspection_hours]`

Where the inspection hours are the basic inspection time + an additional 2 hours if the device is newer than 2015 + an additional 2 hours if the device is a laptop. **(5 points)**

Create a class `MobileService` that stores an address (an array of 100 characters), an array of devices (dynamically allocated array), and the number of devices. **(5 points)**

For the class, provide:

- `operator+=` for adding a new device to the service. **(5 points)**  
  The production year of the device must not be greater than 2019 or less than 2000. If an attempt is made to add a device with an invalid production year, an `InvalidProductionDate` exception should be generated. **(10 points)**

- A function `pecatiUredi` for printing all devices together with the time required for their inspection in the service. **(5 points)**

- All additional methods necessary for the proper functioning of the program. **(5 points)**

---

# Македонски

## Опис на задачата

Да се креира класа за опишување на еден сервис за мобилни уреди. За секој мобилен телефон се чуваат податоци за модел (низа од 100 знаци), тип на уред (смартфон или компјутер), потребни часови за основна проверка (децимален број), година на производство (цел број). **(5 поени)**

Сите уреди имаат исто времетраење за основна проверка и истата изнесува 1 час. Оваа вредност може да се смени со одлука на сервисот. Дополнително, уредите кои се понови од 2015 година имаат потреба од дополнителени 1.5 часа за проверка. При проверка, лаптопите имаат потреба од дополнителни 2 часа за софтверска дијагностика. **(5 поени)**

За оваа класа да се имплементира оператор `<<` за печатење на уред во формат:

> `[model_na_uredot]`  
> `[tip_na_ured] [casovi_za_proverka]`

Каде часовите за проверка се оние од основната проверка + дополнителни 2 часа доколку уредот е понов од 2015 + 2 часа доколку уредот е лаптоп. **(5 поени)**

Да се креира класа `MobileServis` во која се чува адреса (низа од 100 знаци), низа од уреди (динамички алоцирана низа) и број на уреди. **(5 поени)**

За класата да се обезбедат:

- `operator+=` за додавање на нов уред во сервисот. **(5 поени)**  
  Не смее да се дозволи годината на производство на уредот да биде поголема од 2019 или помала од 2000. Ако се направи обид за додавање на уред со невалидна година, треба да се генерира исклучок `InvalidProductionDate`. **(10 поени)**

- Функција `pecatiUredi` со која се печатат сите уреди со времето потребно за нивната проверка во сервисот. **(5 поени)**

- Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата. **(5 поени)**


## Test Cases


### Test Case 1

**Input:**
```text
3
TelService
6
iPhone
0
2020
Samsung
0
1999
Huawei
0
1990
Toshiba
1
2016
OnePlus
0
2009
Fujitsu
1
2010
```
**Expected output:**

```text
===== Testiranje na isklucoci ======
Невалидна година на производство
Невалидна година на производство
Невалидна година на производство
Ime: TelService
Toshiba
Laptop 5
OnePlus
Mobilen 1
Fujitsu
Laptop 3
```



### Test Case 2

**Input:**
```text
	
2
iStyle
10
iPhone
0
2019
Samsung
0
2015
Huawei
0
2013
Toshiba
1
2016
OnePlus
0
2009
Fujitsu
1
2010
Dell
1
2019
Sony
0
2007
Hp
1
2019
Alcatel
0
2011
```
**Expected output:**

```text
===== Testiranje na operatorot += ======
Ime: iStyle
iPhone
Mobilen 3
Samsung
Mobilen 1
Huawei
Mobilen 1
Toshiba
Laptop 5
OnePlus
Mobilen 1
Fujitsu
Laptop 3
Dell
Laptop 5
Sony
Mobilen 1
Hp
Laptop 5
Alcatel
Mobilen 1
```



### Test Case 3

**Input:**
```text
6
MobiClick
14
iPhone
0
2019
Samsung
0
2015
Huawei
0
2009
Toshiba
1
2016
OnePlus
0
2009
Fujitsu
1
2010
Dell
1
2019
Sony
0
2007
Hp
1
2019
Alcatel
0
2011
Simens
0
1990
Macintosh
1
1900
Lenovo
1
2016
Lg
0
2014
```
**Expected output:**

```text
===== Testiranje na kompletna funkcionalnost ======
Невалидна година на производство
Невалидна година на производство
Ime: MobiClick
iPhone
Mobilen 5
Samsung
Mobilen 3
Huawei
Mobilen 3
Toshiba
Laptop 7
OnePlus
Mobilen 3
Fujitsu
Laptop 5
Dell
Laptop 7
Sony
Mobilen 3
Hp
Laptop 7
Alcatel
Mobilen 3
Lenovo
Laptop 7
Lg
Mobilen 3
```



### Test Case 4

**Input:**
```text
5
MobileService
10
iPhone
0
2019
Samsung
0
2015
Huawei
0
2009
Toshiba
1
2016
OnePlus
0
2009
Fujitsu
1
2010
Dell
1
2019
Sony
0
2007
Hp
1
2019
Alcatel
0
2011
```
**Expected output:**

```text
===== Testiranje na static clenovi ======
Ime: MobileService
iPhone
Mobilen 3
Samsung
Mobilen 1
Huawei
Mobilen 1
Toshiba
Laptop 5
OnePlus
Mobilen 1
Fujitsu
Laptop 3
Dell
Laptop 5
Sony
Mobilen 1
Hp
Laptop 5
Alcatel
Mobilen 1
===== Promena na static clenovi ======
Ime: MobileService
iPhone
Mobilen 4
Samsung
Mobilen 2
Huawei
Mobilen 2
Toshiba
Laptop 6
OnePlus
Mobilen 2
Fujitsu
Laptop 4
Dell
Laptop 6
Sony
Mobilen 2
Hp
Laptop 6
Alcatel
Mobilen 2
```




### Test Case 5

**Input:**
```text
1
Nokia
0
2018
MobiClick
```
**Expected output:**

```text
===== Testiranje na klasite ======
Nokia
Mobilen 3
```




### Test Case 6

**Input:**
```text
4
MobileStar
10
iPhone
0
2019
Samsung
0
2011
Huawei
0
2016
Toshiba
1
2016
OnePlus
0
2025
Fujitsu
1
2010
Dell
1
2019
Sony
0
2015
Hp
1
2019
Alcatel
0
2011
```
**Expected output:**

```text
===== Testiranje na konstruktori ======
Невалидна година на производство
Ime: MobileStar
iPhone
Mobilen 3
Samsung
Mobilen 1
Huawei
Mobilen 3
Toshiba
Laptop 5
Fujitsu
Laptop 3
Dell
Laptop 5
Sony
Mobilen 1
Hp
Laptop 5
Alcatel
Mobilen 1
```
