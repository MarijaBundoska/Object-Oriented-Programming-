## Exercise 2 - Discount Product

Given a class `Product` that stores the id and price of a product, along with an appropriate constructor, a set method, and a printing method.

Define a class `DiscountProduct` that inherits from the class `Product` and includes an integer variable for the discount percentage. The discount percentage must be a value greater than 0% and less than 100%; otherwise, the discount should be set to 10%.

For the class `DiscountProduct`, define:

- An appropriate constructor.
- A method `float calculatePrice()` that calculates the price of the product with the discount.
- A printing method `void print()`, which prints the product's id, its price, and its discount.


## Задача 2 - Продукт со попуст

Дадена е класата `Product` во која се чуваат id и цена на продуктот, соодветен конструктор, метод за поставување и метод за печатење.

Да се дефинира класа `DiscountProduct` која наследува од класата `Product` и која вклучува целобројна променлива за процент на попуст. Процентот на попустот мора да биде вредност поголема од 0% и помала од 100%; во спротивно, попустот да се постави на 10%.

За класата `DiscountProduct` да се дефинира:

- Соодветен конструктор.
- Метод `float calculatePrice()` со којшто се пресметува цената на продуктот со попуст.
- Метод за печатење `void print()`, којшто го печати id-то на продуктот, неговата цена и попустот.




## Test Cases


### Test Case 1

**Input:**
```text
1
```
**Expected output:**

```text
PROD-123456 10 10
```




### Test Case 2

**Input:**
```text
2
```
**Expected output:**

```text
CS101 50 5
CS102 70 10
```




### Test Case 3

**Input:**
```text
3
```
**Expected output:**

```text
CS101 50 10
CS102 70 10
```




### Test Case 4

**Input:**
```text
4
```
**Expected output:**

```text
32
```




### Test Case 5

**Input:**
```text
5
3
Product1 100 30
Product2 220 55
Product3 339 90
```
**Expected output:**

```text
Product1 100 30
Product2 220 55
Product3 339 90
```




### Test Case 6

**Input:**
```text
5
3
Product1 1110 130
Product2 2000 -6
Product3 300 90
```
**Expected output:**

```text
Product1 1110 10
Product2 2000 10
Product3 300 90
```




### Test Case 7

**Input:**
```text
6
3
Product1 100 30
Product2 220 55
Product3 339 90
```
**Expected output:**

```text
Product1 100 30
Product2 220 55
Product3 339 90
70
99
33.9
```




### Test Case 8

**Input:**
```text
6
3
Product1 1110 130
Product2 2000 -6
Product3 300 90
```
**Expected output:**

```text
Product1 1110 10
Product2 2000 10
Product3 300 90
999
1800
30
```
