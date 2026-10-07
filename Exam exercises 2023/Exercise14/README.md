# Exercise 14 - SMS Messages

### Problem Statement

Within a telecommunications operator, SMS messages are divided into regular and special messages. For each SMS message, the following data is known:

- basic price for one message of up to 160 characters (real number)
- subscriber number to which the message was sent (an array of characters with length 12)

The class for describing SMS messages is **abstract (5 points)**.

For each `Regular SMS`, additional data is stored about the message text and whether a roaming service was used (bool variable). For each `Special SMS`, additional data is stored about whether the message is intended for humanitarian purposes (bool variable). **(5 points)**

For each object of both derived classes, the following methods should be available:

### `SMS_cena()`

A method for calculating the price of a sent SMS message in the following way: **(10 points)**

- For a regular SMS - the price is increased by 300% of the basic price if it is sent from abroad, and by 18% from home, and the price is calculated based on how many SMS messages are needed to fit the text we want to send. One regular message can contain a maximum of 160 characters. If the 160th character is exceeded, a new message is started and the price is calculated as for two or more messages (e.g. for 162 characters, the SMS price is the same as for 320 characters).
- For a special SMS - the price is increased by 150% of the basic price if the message is **not** intended for humanitarian purposes. If it is intended for humanitarian purposes, the 18% tax is not calculated on the price.
- The calculation of the 18% tax on the price of all SMS messages is fixed and does not change, while the percentage of 300% for regular SMS messages and 150% for special SMS messages is variable and may change depending on the operator. A mechanism should be provided for changing these percentages. **(5 points)**

Overload the `<<` operator for printing the SMS message data in the following format: **(5 points)**

```text
Phone number: price
```
Implement the function vkupno_SMS with the signature:

```text
void vkupno_SMS(SMS** poraka, int n)
```


which prints the total number of regular SMS messages and their total price, as well as the number of special SMS messages and their total price separately in the provided array. **(15 points)**
Provide all necessary functions for the proper functioning of the program. **(5 points)**


# Вежба 14 - СМС пораки

## Опис на задачата

Во рамките на еден телекомуникациски оператор, СМС пораките се делат на регуларни и специјални. За секоја СМС порака се знае:

- основна цена за една порака до 160 знаци (реален број)
- претплатнички број на кој е испратена (низа од знаци со должина 12)

Класата за опишување на СМС пораки е **апстрактна (5 поени)**.

За секоја `Регуларна СМС` дополнително се чуваат податоци за текстот на пораката и тоа дали е користена роаминг услуга (`bool` променлива). За секоја `Специјална СМС` дополнително се чуваат податоци за тоа дали е наменета за хуманитарни цели (`bool` променлива). **(5 поени)**

За секој објект од двете изведени класи треба да бидат на располагање следниве методи:

### `SMS_cena()`

Метод за пресметување на цената на испратена СМС порака на следниот начин: **(10 поени)**

- За регуларна СМС - цената се зголемува за 300% од основната цена ако е испратена од странство, а 18% од дома и цената се формира врз база на тоа во колку СМС пораки ќе го собере текстот што сакаме да го испратиме. Една регуларна порака може да собере најмногу 160 знаци. Притоа, доколку се надмине 160-от знак, се започнува нова порака и цената се пресметува како за две или повеќе пораки (пр. за 162 знаци, цената на СМС е иста како и за 320 знаци).
- За специјална СМС - цената се зголемува за 150% од основната цена ако пораката **НЕ** е наменета за хуманитарни цели. Доколку е наменета за тоа, данокот од 18% не се пресметува на цената.
- Пресметувањето 18% данок на цената на сите СМС пораки е фиксен и не се менува, додека пак процентот од 300% за регуларни и 150% за специјални СМС е променлив и во зависност од операторот може да се менува. Да се обезбеди механизам за можност за нивно менување. **(5 поени)**

### Оператор `<<`

Преоптоварен `оператор <<` за печатење на податоците за СМС пораките во формат: **(5 поени)**

```text
Тел.број: цена

```

Да се имплементира функција vkupno_SMS со потпис:

```text
void vkupno_SMS(SMS** poraka, int n)
```
во која се печати вкупниот број на регуларни СМС пораки и нивната вкупна цена, како и бројот на специјални СМС пораки и нивната вкупна цена во проследената низа посебно. **(15 поени)**
Да се обезбедат сите потребни функции за правилно функционирање на програмата. **(5 поени)**


## Test Cases


### Test Case 1

**Input:**
```text
4
0038971123456
5
Test poraka za testiranje na promena na procentot?
1
0038971123456
5
Test poraka za testiranje na promena na procentot?
1
350
```
**Expected output:**

```text
====== Testing RegularSMS class with a changed percentage======
Tel: 0038971123456 - cena: 20den.
Tel: 0038971123456 - cena: 22.5den.
```



### Test Case 2

**Input:**
```text
3
3
2
0500123456
45
0
2
0038971140300
200
1
2
0038975140300
100
1
```
**Expected output:**

```text
====== Testing method vkupno_SMS() ======
Vkupno ima 0 regularni SMS poraki i nivnata cena e: 0
Vkupno ima 3 specijalni SMS poraki i nivnata cena e: 412.5
```



### Test Case 3

**Input:**
```text
2
2
0038971111222
15.8
0
0038975140300
100
1
```
**Expected output:**

```text
2
0038971111222
15.8
0
0038975140300
100
1
====== Testing SpecialSMS class ======
CONSTRUCTOR
OPERATOR <<
Tel: 0038971111222 - cena: 39.5den.
CONSTRUCTOR
OPERATOR <<
Tel: 0038975140300 - cena: 100den.
```



### Test Case 4

**Input:**
```text
3
5
2
0500123456
45
0
1
0038975123456
5
Test poraka!
1
1
0038971123456
5
Test poraka za testiranje na dolzinata na porakata. Ovaa poraka treba da bide pogolema od 160 karakteri. Kolkava e cenata na ovaa poraka iako e ispratena od domasen operator!? Test poraka za testiranje na dolzinata na porakata. Ovaa poraka treba da bide pogolema od 160 karakteri. Kolkava e cenata na ovaa poraka iako e ispratena od domasen operator!?
0
2
0038971111222
45
0
2
0038975140300
100
1
```
**Expected output:**

```text
====== Testing method vkupno_SMS() ======
Vkupno ima 2 regularni SMS poraki i nivnata cena e: 37.7
Vkupno ima 3 specijalni SMS poraki i nivnata cena e: 325
```



### Test Case 5

**Input:**
```text	
1
2
0038975123456
5
Test poraka!
1
0038971123456
5
Test poraka za testiranje na dolzinata na porakata. Ovaa poraka treba da bide pogolema od 160 karakteri. Kolkava e cenata na ovaa poraka iako e ispratena od domasen operator!?
```
**Expected output:**

```text
====== Testing RegularSMS class ======
CONSTRUCTOR
OPERATOR <<
Tel: 0038975123456 - cena: 20den.
CONSTRUCTOR
OPERATOR <<
Tel: 0038971123456 - cena: 11.8den.
```



### Test Case 6

**Input:**
```text
5
0038971111222
20
0
0038971111222
20
0
180
```
**Expected output:**

```text
====== Testing SpecialSMS class with a changed percentage======
Tel: 0038971111222 - cena: 50den.
Tel: 0038971111222 - cena: 56den.
```



### Test Case 7

**Input:**
```text
1
2
0038975123456
5
Test poraka!
0
0038971123456
5.5
Testirame isprakjanje na poraka.
0
```
**Expected output:**

```text
5
Test poraka!
0
0038971123456
5.5
Testirame isprakjanje na poraka.
0
====== Testing RegularSMS class ======
CONSTRUCTOR
OPERATOR <<
Tel: 0038975123456 - cena: 5.9den.
CONSTRUCTOR
OPERATOR <<
Tel: 0038971123456 - cena: 6.49den.
```
