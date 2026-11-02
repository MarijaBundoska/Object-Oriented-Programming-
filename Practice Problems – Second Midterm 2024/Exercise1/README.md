## Exercise 1 - Product and Store Classes

Define a class `Product` to store information about a product in a store, including its name (string), category (string), price (integer), and available quantity (integer).

For the class, define:

- The necessary constructors.
- The print operator `<<`.
- A method `int totalPrice()` that returns the total value of the product, calculated as the product of its price and available quantity.

**(10 points)**

Define a class `Store` to store a list of products (a dynamically allocated array of objects from the `Product` class) and an integer indicating the size of the list.

For the class, implement:

- The necessary constructors.
- The operator `+=` for adding a product (`Product`) to the store. **(5 points)**
- The print operator `<<`. **(5 points)**
- A method `Store fromCategory(string &category)` that takes a category (string) as an argument and returns a new object of the `Store` class containing only products from the specified category. **(5 points)**

If there is no product from the specified category, throw an exception of the class `NoProductFoundException`. **(5 points)**

Handling the exception should print the message:

`No products from category {category} were found in the store`

**(5 points)**

Complete the `main` function with the following requirements:

- Read information about all products from the file `input.txt`:
  - For each product, the information about its name, category, price, and quantity is given in four lines.
  - After reading the information about each product, add the product to the `store` object.
- Print the store information to the file `output1.txt`.
- Print the result of the `fromCategory` method for the category `category` read in the initial code to the file `output2.txt`. **(15 points)**

---

## Задача 1 - Класи Product и Store

Да се дефинира класа `Product` во која ќе се чуваат информации за производ во една продавница и тоа име (стринг), категорија (стринг), цена (цел број) и достапна количина (цел број).

За класата да се дефинираат:

- Потребните конструктори.
- Оператор за печатење `<<`.
- Метод `int totalPrice()` кој ја враќа вкупната вредност на производот, пресметана како производ на цената и достапната количина.

**(10 поени)**

Да се дефинира класа `Store` во која ќе се чува листа на производи (динамички алоцирана низа од објекти од класата `Product`) и цел број кој ја означува големината на листата.

За класата да се имплементираат:

- Потребните конструктори.
- Оператор `+=` за додавање на производ (`Product`) во продавницата. **(5 поени)**
- Оператор за печатење `<<`. **(5 поени)**
- Метод `Store fromCategory(string &category)` кој прима како аргумент категорија (стринг), а враќа нов објект од класата `Store` во кој во листата на производи се сместени само производи од категоријата `category`. **(5 поени)**

Доколку нема ниту еден производ од бараната категорија, да се фрли исклучок од класата `NoProductFoundException`. **(5 поени)**

Справувањето со исклучокот треба да испечати порака:

`No products from category {category} were found in the store`

**(5 поени)**

Да се дополни функцијата `main` со следните барања:

- Од датотеката `input.txt` да се прочитаат информациите за сите производи:
  - За секој производ, информациите за името, категоријата, цената и количината се дадени во четири реда.
  - По читањето на информациите за секој производ, производот да се додаде во објектот `store`.
- Информациите за продавницата да се испечатат во датотеката `output1.txt`.
- Резултатот од методот `fromCategory` за категоријата `category`, вчитана во почетниот код, да се испечати во датотеката `output2.txt`. **(15 поени)**




## Test Cases


### Test Case 1

**Input:**
```text
Coca-cola zero 1.75L
drinks
80
100
Sandwich with ham and cheese
food
60
150
----
drinks
```
**Expected output:**

```text
All products:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
Sandwich with ham and cheese (food) 150 x 60 = 9000
Products from category drinks:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
```





### Test Case 2

**Input:**
```text
Coca-cola zero 1.75L
drinks
80
100
Sandwich with ham and cheese
food
60
150
----
food
```
**Expected output:**

```text
All products:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
Sandwich with ham and cheese (food) 150 x 60 = 9000
Products from category food:
Sandwich with ham and cheese (food) 150 x 60 = 9000
```





### Test Case 3

**Input:**
```text
Coca-cola zero 1.75L
drinks
80
100
Sandwich with ham and cheese
food
60
150
----
beauty
```
**Expected output:**

```text
No products from category beauty were found in the store
All products:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
Sandwich with ham and cheese (food) 150 x 60 = 9000
Products from category beauty:
```





### Test Case 4

**Input:**
```text
Apple
Fruit
100
50
Banana
Fruit
50
100
Milk
Dairy
200
30
Butter
Dairy
250
20
Bread
Bakery
80
40
Eggs
Dairy
150
60
Carrot
Vegetable
60
80
Potato
Vegetable
40
100
----
Fruit
```
**Expected output:**

```text
All products:
Apple (Fruit) 50 x 100 = 5000
Banana (Fruit) 100 x 50 = 5000
Milk (Dairy) 30 x 200 = 6000
Butter (Dairy) 20 x 250 = 5000
Bread (Bakery) 40 x 80 = 3200
Eggs (Dairy) 60 x 150 = 9000
Carrot (Vegetable) 80 x 60 = 4800
Potato (Vegetable) 100 x 40 = 4000
Products from category Fruit:
Apple (Fruit) 50 x 100 = 5000
Banana (Fruit) 100 x 50 = 5000
```






### Test Case 5

**Input:**
```text
Yogurt
Dairy
180
25
Cheese
Dairy
300
15
Tomato
Vegetable
70
50
Chicken
Meat
500
10
Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
----
Dairy
```
**Expected output:**

```text
All products:
Yogurt (Dairy) 25 x 180 = 4500
Cheese (Dairy) 15 x 300 = 4500
Tomato (Vegetable) 50 x 70 = 3500
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Products from category Dairy:
Yogurt (Dairy) 25 x 180 = 4500
Cheese (Dairy) 15 x 300 = 4500
```





### Test Case 6

**Input:**
```text
Fish
Seafood
600
12
Shrimp
Seafood
700
8
Pork
Meat
450
20
Onion
Vegetable
30
50
Garlic
Vegetable
20
100
Cabbage
Vegetable
40
30
Apple
Fruit
100
50
Milk
Dairy
200
30
----
Seafood
```
**Expected output:**

```text
All products:
Fish (Seafood) 12 x 600 = 7200
Shrimp (Seafood) 8 x 700 = 5600
Pork (Meat) 20 x 450 = 9000
Onion (Vegetable) 50 x 30 = 1500
Garlic (Vegetable) 100 x 20 = 2000
Cabbage (Vegetable) 30 x 40 = 1200
Apple (Fruit) 50 x 100 = 5000
Milk (Dairy) 30 x 200 = 6000
Products from category Seafood:
Fish (Seafood) 12 x 600 = 7200
Shrimp (Seafood) 8 x 700 = 5600
```





### Test Case 7

**Input:**
```text
Pasta
Grains
150
35
Rice
Grains
120
40
Beans
Legumes
90
60
Lentils
Legumes
100
50
Cucumber
Vegetable
60
40
Mushroom
Vegetable
70
25
Peach
Fruit
80
20
Milk
Dairy
200
30
----
Grains
```
**Expected output:**

```text
All products:
Pasta (Grains) 35 x 150 = 5250
Rice (Grains) 40 x 120 = 4800
Beans (Legumes) 60 x 90 = 5400
Lentils (Legumes) 50 x 100 = 5000
Cucumber (Vegetable) 40 x 60 = 2400
Mushroom (Vegetable) 25 x 70 = 1750
Peach (Fruit) 20 x 80 = 1600
Milk (Dairy) 30 x 200 = 6000
Products from category Grains:
Pasta (Grains) 35 x 150 = 5250
Rice (Grains) 40 x 120 = 4800
```



### Test Case 8

**Input:**
```text
Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
Apple
Fruit
100
50
Banana
Fruit
50
100
Eggs
Dairy
150
60
Potato
Vegetable
40
100
----
Legumes
```
**Expected output:**

```text
No products from category Legumes were found in the store
All products:
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Apple (Fruit) 50 x 100 = 5000
Banana (Fruit) 100 x 50 = 5000
Eggs (Dairy) 60 x 150 = 9000
Potato (Vegetable) 100 x 40 = 4000
Products from category Legumes:
```





### Test Case 9

**Input:**
```text
Tomato
Vegetable
70
50
Chicken
Meat
500
10
Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
Apple
Fruit
100
50
Milk
Dairy
200
30
----
Meat
```
**Expected output:**

```text
All products:
Tomato (Vegetable) 50 x 70 = 3500
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Apple (Fruit) 50 x 100 = 5000
Milk (Dairy) 30 x 200 = 6000
Products from category Meat:
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000
```




### Test Case 10

**Input:**
```text
Tomato
Vegetable
70
50
Chicken
Meat
500
10
Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
Apple
Fruit
100
50
Milk
Dairy
200
30
----
Drink
```
**Expected output:**

```text
No products from category Drink were found in the store
All products:
Tomato (Vegetable) 50 x 70 = 3500
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Apple (Fruit) 50 x 100 = 5000
Milk (Dairy) 30 x 200 = 6000
Products from category Drink:
```
