## Exercise 12 - Pizzeria and Promotional Pizzas

Define a class `Pizza` that stores the following information:

- Pizza name (a string of 15 characters)
- Price (integer)
- Ingredients (a dynamically allocated character array)
- Price reduction in percentage (integer) — if the pizza is not on promotion, the reduction is zero; otherwise, it is greater than zero and not greater than 100.

For this class, create the necessary constructors and write an appropriate destructor.

Additionally, define the following functions for this class:

- `print()` — prints the pizza information in the following format: name - ingredients, price.
- `sameIngredients(Pizza p)` — a function for comparing two pizzas according to their ingredients.

Define a class `Pizzeria` that stores:

- Name (a string of maximum 15 characters)
- A dynamically allocated array of objects of the `Pizza` class
- Number of pizzas (integer)

For this class, define the necessary constructors and write an appropriate destructor.

Also, implement the following methods:

- `add(Pizza p)` — adds a new pizza to the pizzeria, but only if an identical pizza does not already exist in the array (there is no pizza with the same ingredients as the pizza being added).
- `void promotionalPizzas()` — prints all pizzas from the pizzeria that are on promotion in the following format: name - ingredients, price, discounted price.

---

## Задача 12 - Пицерија и пици на промоција

Да се дефинира класа `Пица` за која ќе се чуваат податоци за:

- Име на пицата (низа од 15 знаци)
- Цена (цел број)
- Состојки (динамички алоцирана низа од знаци)
- Намалување на цената во проценти (цел број) — ако пицата не е на промоција, намалувањето има вредност нула, во спротивно, вредност поголема од нула и не поголема од 100.

За потребите на оваа класа да се креираат потребните конструктори и да се напише соодветен деструктор.

Дополнително за оваа класа да се дефинираат функциите:

- `pecati()` — функција во која ќе се печатат податоците за пицата во следниот формат: име - состојки, цена.
- `istiSe(Pica p)` — функција за споредба на две пици според состојките.

Да се дефинира класа `Picerija` во која се чуваат:

- Име (низа од максимум 15 знаци)
- Динамички алоцирана низа од објекти од класата `Pica`
- Број на пици (цел број)

За потребите на оваа класа да се дефинираат потребните конструктори и да се напише соодветен деструктор.

Да се имплементираат и следниве методи:

- `dodadi(Pica P)` — за додавање нова пица во пицеријата, но само ако не постои иста во низата (нема пица со исти состојки со пицата што треба да се додаде).
- `void piciNaPromocija()` — се печатат сите пици од пицеријата што се на промоција во формат: име - состојки, цена, цена со попуст.



 ## Test Cases


### Test Case 1

**Input:**
```text
FINKI-Pica
4
Margarita
200
Domaten sos, kaskaval, maslinovo maslo
0
Napolitana
210
Domaten sos, kaskaval, svezi sampinjoni, maslinovo maslo
0
Kapricioza
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
30
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
Pica-FINKI
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
```
**Expected output:**

```text
FINKI-Pica
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
Pica-FINKI
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
```





### Test Case 2

**Input:**
```text
FINKI-Pica
4
Margarita
200
Domaten sos, kaskaval, maslinovo maslo
0
Napolitana
210
Domaten sos, kaskaval, svezi sampinjoni, maslinovo maslo
0
Kapricioza
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
30
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
Pica-FINKI
Tuna
230
Domaten sos, kaskaval, pcenka, maslinki, tuna, rukola
10
```
**Expected output:**

```text
FINKI-Pica
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
Pica-FINKI
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
Tuna - Domaten sos, kaskaval, pcenka, maslinki, tuna, rukola, 230 207
```





### Test Case 3

**Input:**
```text
FINKI-Pica
5
Margarita
200
Domaten sos, kaskaval, maslinovo maslo
0
Napolitana
210
Domaten sos, kaskaval, svezi sampinjoni, maslinovo maslo
0
Kapricioza
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
30
Kapricioza
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
30
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
Pica-FINKI
Tuna
230
Domaten sos, kaskaval, pcenka, maslinki, tuna, rukola
0
```
**Expected output:**

```text
FINKI-Pica
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
Pica-FINKI
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
```




### Test Case 4

**Input:**
```text
	
FINKI-Pica
3
Margarita
200
Domaten sos, kaskaval, maslinovo maslo
0
Napolitana
210
Domaten sos, kaskaval, svezi sampinjoni, maslinovo maslo
0
Kapricioza
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
0
Pica-FINKI
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
```
**Expected output:**

```text
FINKI-Pica
Pici na promocija:
Pica-FINKI
Pici na promocija:
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
```




### Test Case 5

**Input:**
```text
	
FINKI-Pica
4
Margarita
200
Domaten sos, kaskaval, maslinovo maslo
0
Napolitana
210
Domaten sos, kaskaval, svezi sampinjoni, maslinovo maslo
0
Kapricioza
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
30
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
Pica-FINKI
Tuna
230
Domaten sos, kaskaval, pcenka, maslinki, tuna, rukola
0
```
**Expected output:**

```text
FINKI-Pica
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
Pica-FINKI
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
```
