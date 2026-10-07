# Exercise 17 - Football Teams

## Description

An abstract class `FudblaskaEkipa` should be implemented, which stores: **(5 points)**

- the name of the team's coach (maximum 100 characters)
- the number of goals scored in the last 10 matches, where the last match is at position 9, the previous match at position 8, etc. (an array of 10 integers)

The classes `Klub` and `Reprezentacija` should be derived from the class `FudblaskaEkipa`.

For each club, the name and number of titles won are additionally stored, while for the national team, the name of the country and the total number of international appearances are stored.

The following methods should be implemented for these classes:

- appropriate constructor **(5 points)**
- overloaded `<<` operator for printing to standard output in the format:
  `[IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n` **(5 points)**
- overloaded `+=` operator for adding goals from the latest match (make sure that only the goals from the last 10 matches are always stored) **(10 points)**
- method `uspeh`, for calculating the team's success in the following way:
  - For `Klub`, it is calculated as the sum of the sum of goals from the last 10 matches multiplied by 3 and the number of titles multiplied by 1000 (for example, goals = `{2, 0, 1, 3, 2, 0, 1, 4, 2, 3}` and number of titles = 3, success = `18 * 3 + 3 * 1000 = 3054`)
  - For `Reprezentacija`, it is calculated as the sum of the sum of goals from the last 10 matches multiplied by 3 and the number of international appearances multiplied by 50 (for example, goals = `{2, 0, 1, 3, 2, 0, 1, 4, 2, 3}` and number of international appearances = 150, success = `18 * 3 + 150 * 50 = 7554`) **(10 points)**
- overloaded `>` operator for comparing two football teams of any type (clubs or national teams) according to their success **(5 points)**

A function `najdobarTrener` should be implemented. It receives an array of pointers to `FudblaskaEkipa` and the size of the array as input, and prints the team with the highest success. **(10 points)**

---

# Вежба 17 - Фудбалски екипи

## Опис

Да се имплементира апстрактна класа `FudblaskaEkipa` во која се чува: **(5 поени)**

- име на тренерот на екипата (максимум 100 знаци)
- бројот на постигнати голови на последните 10 натпревари, последниот натпревар е на позиција 9, предпоследниот на позиција 8, итн (поле од 10 цели броеви)

Од класата `FudblaskaEkipa` да се изведат класите `Klub` и `Reprezentacija`.

За секој клуб дополнително се чува податок за името и бројот на титули што ги има освоено, а за репрезентацијата се чуваат податоци за името на државата и вкупен број на меѓународни настапи.

За овие класи да се имплементираат следните методи:

- соодветен конструктор **(5 поени)**
- оператор `<<` за печатење на стандарден излез во формат:
  `[IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n` **(5 поени)**
- преоптоварен оператор `+=` за додавање на голови од последниот натпревар (внимавајте секогаш се чуваат головите само од последните 10 натпревари) **(10 поени)**
- метод `uspeh`, за пресметување на успехот на тимот на следниот начин:
  - За `Klub` се пресметува како збир од збирот на головите од последните 10 натпревари помножен со 3 и бројот на титули помножен со 1000 (на пр. голови = `{2, 0, 1, 3, 2, 0, 1, 4, 2, 3}` и број на титули = 3, достигнување = `18 * 3 + 3 * 1000 = 3054`)
  - За `Reprezentacija` како збир од збирот на головите од последните 10 натпревари помножен со 3 и бројот на меѓународни настапи помножен со 50 (на пр. голови = `{2, 0, 1, 3, 2, 0, 1, 4, 2, 3}` и број на меѓународни настапи = 150, достигнување = `18 * 3 + 150 * 50 = 7554`) **(10 поени)**
- преоптоварен оператор `>` за споредба на две фудбласки екипи од каков било вид (клубови или репрезентации) според успехот **(5 поени)**

Да се имплементира функција `najdobarTrener` што на влез прима низа од покажувачи кон `FudblaskaEkipa` и големина на низата и го печати тимот со најголем успех **(10 поени)**



## Test Cases


### Test Case 1

**Input:**
```text
	
5
0
Zinedin Zidane
2 2 2 3 4 1 5 3 0 3
Real Madrid CF
2
0
Luis Enrique
3 4 5 1 3 0 6 5 4 3
FC Barcelona
6
1
Visente Del Boske
1 1 4 0 2 2 3 1 3 5
Spain
2
1
Antonio Conte
0 0 1 4 2 3 4 1 2 2
Italy
3
0
Claudio Ranieri
3 2 2 3 1 2 2 0 3 4
Leicester City FC
1
3
2
3
2
1
```
**Expected output:**

```text
===== SITE EKIPI =====
Real Madrid CF
Zinedin Zidane
2075
FC Barcelona
Luis Enrique
6102
Spain
Visente Del Boske
166
Italy
Antonio Conte
207
Leicester City FC
Claudio Ranieri
1066
===== DODADI GOLOVI =====
dodavam golovi: 3
dodavam golovi: 2
dodavam golovi: 3
dodavam golovi: 2
dodavam golovi: 1
===== SITE EKIPI =====
Real Madrid CF
Zinedin Zidane
2078
FC Barcelona
Luis Enrique
6099
Spain
Visente Del Boske
172
Italy
Antonio Conte
213
Leicester City FC
Claudio Ranieri
1060
===== NAJDOBAR TRENER =====
FC Barcelona
Luis Enrique
6099
```



### Test Case 2

**Input:**
```text
2
0
Luis Enrique
2 0 1 3 2 0 1 4 2 3
FC Barcelona
3
1
Joachim Low
2 0 1 3 2 0 1 4 2 3
Germany
150
5
2


79 91 80 100 88
France
3
115
97
```
**Expected output:**

```text
===== SITE EKIPI =====
FC Barcelona
Luis Enrique
3054
Germany
Joachim Low
7554
===== DODADI GOLOVI =====
dodavam golovi: 5
dodavam golovi: 2
===== SITE EKIPI =====
FC Barcelona
Luis Enrique
3063
Germany
Joachim Low
7554
===== NAJDOBAR TRENER =====
Germany
Joachim Low
7554
```
