## Exercise 1 - Songs and CDs

Define the class `Pesna` that stores information about (5 points):

- song name (dynamically allocated character array)
- song duration in minutes
- song type, which can be: pop, rap, or rock (enumeration `tip`)

Provide all the necessary methods for the class to function properly (10 points).

Additionally, define the following method for this class:

- `pecati()` - a function that prints, separated by a hyphen (-): the song name in quotation marks and the song duration with the suffix `min`. (5 points)

Create the class `CD` that stores information about (5 points):

- an array of songs recorded on the CD (an array of at most 10 objects of the class `Pesna`)
- the number of songs recorded on the CD
- the maximum duration of the songs on the CD (in minutes)

Provide all the necessary methods for the class to function properly (5 points).

Additionally, define the following methods for this class:

- `dodadiPesna (Pesna p)` - which adds the song p to the CD, but only if there is enough remaining space (taking into account the maximum duration of the songs on the CD and the durations of the songs on the CD) and if there are fewer than 10 songs on the CD. (10 points)
- `pecatiPesniPoTip(tip t)` – which prints the information about all songs of type t (pop, rap, or rock). (10 points)

Complete functionality (5 points).

## Задача 1 - Песни и CD-а

Да се дефинира класата `Pesna` во која се чуваат информации за (5 поени):

- име на песна (динамички алоцирано поле од знаци)
- времетраење на песната во минути
- тип на песна кој може да биде: поп, рап или рок (енумерација tip)

Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (10 поени)

Дополнително за оваа класа да се дефинира методот:

- `pecati()` - функција во која ќе се печатат одделени со цртичка(-): името на песната во наводници и времетраењето на песната со постфикс min. (5 поени)

Да се креира класата `CD` во која се чуваат информации за (5 поени):

- низа од песни снимени на CD-то (Поле од најмногу 10 објекти од класата Pesna )
- број на песни снимени на CD-то
- максимално времетраење на песните на CD-то (во минути)

Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (5 поени)

Дополнително за оваа класа да се дефинираат методите:

- `dodadiPesna (Pesna p)` - со кој се додава песната p на CDто, но само ако има доволно преостанато место (земајќи го предвид максималното времетраење на песните на CDто и времетраењата на песните на CD-то) и ако има помалку од 10 песни на CD-то. (10 поени)
- `pecatiPesniPoTip(tip t)` – со кој се печатат информациите за сите песни од тип t (поп, рап или рок). (10 поени)

Комплетна функционалност (5 поени).






 ## Test Cases


### Test Case 1

**Input:**
```text
3
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2
```
**Expected output:**

```text
===== Testiranje na metodot dodadiPesna() od klasata CD ======
"Happy"-5min
"Layla"-8min
"Stan"-4min
```




### Test Case 2

**Input:**
```text
2
4
Happy 5 0
Layla 2 2
Stan 2 1
Revolution 3 2
```
**Expected output:**

```text
===== Testiranje na klasata CD ======
"Happy"-5min
"Layla"-2min
"Stan"-2min
"Revolution"-3min
```





### Test Case 3

**Input:**
```text
5
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2
2
```
**Expected output:**

```text
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Layla"-8min
```




### Test Case 4

**Input:**
```text
5
11
Happy 1 0
Layla 1 2
Stan 1 1
Revolution 1 2
Love 1 0
Life 1 0
Photograph 1 2
Listen 1 0
Anaconda 1 1
Game 1 1
Hello 1 0
0
```
**Expected output:**

```text
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Happy"-1min
"Love"-1min
"Life"-1min
"Listen"-1min
```





### Test Case 5

**Input:**
```text
5
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2
1
```
**Expected output:**

```text
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Stan"-4min
```





### Test Case 6

**Input:**
```text
1
Happy 5 0
```
**Expected output:**

```text
===== Testiranje na klasata Pesna ======
"Happy"-5min
```




### Test Case 7

**Input:**
```text
4
4
Happy 5 0
Layla 2 2
Stan 2 1
Revolution 3 2
2
```
**Expected output:**

```text
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Layla"-2min
"Revolution"-3min
```

