## Exercise 22 - Order and Invoice Generation

Create a structure `Proizvod` that stores the following information about a product:

- Product code (a string of 20 characters)
- Unit price of the product (integer)
- Number of available products in a warehouse (integer)

Then, create a structure `Narachka` that stores the following information about an order:

- Name of the person placing the order (a string of 15 characters)
- An array of `Proizvod` elements (maximum 10) included in the order
- An array containing the number of ordered units for each product (maximum 10)
- Number of products in the order

Create a function with the following signature:

`void pecatiFaktura(Narachka n)`

The function should print an invoice for one order (`n`).

The first line of the invoice should be printed in the following format:

**Faktura za XXXXX**

where `XXXXX` is the name of the person placing the order.

If all products can be ordered, print the ordered products sorted alphabetically by product code. Each following line should contain the product code, unit price, number of ordered units, and total price for that product, separated by a single space.

The number of available units of each product should also be updated by decreasing it by the number of ordered units.

The last line should be printed in the following format:

**Vkupnata suma na fakturata e XXX**

where `XXX` is the total sum of all ordered products.

If there is a product that cannot be ordered because the warehouse does not have the required quantity, the invoice cannot be generated. In that case, print:

**Fakturata ne moze da se izgotvi**

---

## Задача 22 - Нарачка и изготвување фактура

Да се креира структура `Proizvod` во која се чуваат податоци за кодот на производот (низа од 20 знаци), единичната цена на производот (цел број) и бројот на достапни производи во еден магацин (цел број).

Потоа да се креира структура `Narachka` во која се чуваат податоци за:

- Името на лицето кое ја прави нарачката (низа од 15 знаци)
- Низа од производи (`Proizvod`), максимум 10, кои се нарачани
- Низа со бројот на нарачани производи за секој производ посебно (максимум 10)
- Бројот на производи во нарачката

Треба да се направи функција со потпис:

`void pecatiFaktura(Narachka n)`

која ќе испечати фактура за една нарачка (`n`).

Во фактурата, во првиот ред се печати:

**Faktura za XXXXX**

каде `XXXXX` е името на лицето кое ја прави нарачката.

Ако сите производи може да се нарачаат, нарачаните производи се печатат подредени по азбучен ред според кодот на производот. Во следните редови, во секој ред посебно се печатат кодот на производот, единичната цена на производот, бројот на нарачани производи и вкупната цена на производот (сите се одделени со едно празно место).

Исто така, бројот на достапни производи од тој производ треба да се ажурира, односно да се намали за бројот на нарачани производи од тој производ.

Во последниот ред се печати:

**Vkupnata suma na fakturata e XXX**

каде `XXX` е вкупната сума за цените на сите нарачани производи.

Ако постои производ кој не може да се нарача затоа што во магацинот не се достапни потребниот број производи, тогаш не може да се изготви фактура за нарачката. На екранот треба да се отпечати:

**Fakturata ne moze da se izgotvi**


 ## Test Cases


### Test Case 1

**Input:**
```text
Stefan 2
proizvod1 10 1
proizvod2 20 3
3 2
```
**Expected output:**

```text
Faktura za Stefan
Fakturata ne moze da se izgotvi
```



### Test Case 2

**Input:**
```text
Marko 2
proizvod1 10 4
proizvod2 20 3
3 2
```
**Expected output:**

```text
Faktura za Marko
proizvod1 10 3 30
proizvod2 20 2 40
Vkupnata suma na fakturata e 70
```



### Test Case 3

**Input:**
```text
Stefan 3
fanta 53 100
vino 130 40
voda 22 150
50 10 30
```
**Expected output:**

```text
Faktura za Stefan
fanta 53 50 2650
vino 130 10 1300
voda 22 30 660
Vkupnata suma na fakturata e 4610
```



### Test Case 4

**Input:**
```text
Stefan 3
voda 22 150
fanta 53 100
vino 130 40
50 10 30
```
**Expected output:**

```text
Faktura za Stefan
fanta 53 50 2650
vino 130 10 1300
voda 22 30 660
Vkupnata suma na fakturata e 4610
```


