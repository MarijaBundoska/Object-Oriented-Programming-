## Exercise 19 - Ice Cream and Ice Cream Shop

Define a class `IceCream` that stores the following data:

- Name (a dynamically allocated character array)
- Ingredients (a character array of at most 100 characters)
- Price (a decimal number)
- Discount (an integer expressed as a percentage), with an initial value of 0.

The following should be implemented for the class:

- Appropriate constructors and destructor (refer to the calls in the `main` function).
- The `<<` operator for printing the ice cream data in the following format:

  `name: ingredients price [discounted price]`

  The “discounted price” part is printed **only if** a discount is offered for the ice cream (the discount value is greater than zero).

- The prefix `++` operator for increasing the discount by 5.
- The `+` operator for adding an object of the `IceCream` class to a character array. The operation is performed so that the name of the new ice cream is obtained by joining the original ice cream name and the character array, separated by `" + "`. The price of the new ice cream is increased by 10, while the discount and ingredients remain unchanged.
- Method `void setDiscount(int discount)` for changing the discount value. The allowed discount values are in the interval [0, 100].
- Method `void setName(char* name)` for changing the name of the ice cream.

Define a class `IceCreamShop` that stores:

- Shop name (a character array of at most 50 characters)
- A dynamically allocated field of objects of the `IceCream` class
- Number of ice creams in the field (an integer).

The following should be provided for this class:

- Appropriate constructors and destructor (refer to the calls in the `main` function).
- The `+=` operator for adding a new object of the `IceCream` class to the field.
- The `<<` operator for printing a list of all ice creams in the shop. First, the shop name is printed, followed by the data for all ice creams, each separated by a newline.

## Задача 19 - Сладолед и продавница за сладолед

Да се дефинира класа `IceCream` во која се чуваат податоци за:

- име (динамичка низа од знаци)
- состав (низа од знаци, најмногу 100)
- цена (децимален број)
- попуст (цел број, изразен во проценти), со иницијална вредност 0.

За потребите на класата да се имплементираат:

- соодветни конструктори и деструктор (да се погледнат повиците во функцијата `main`)
- оператор `<<` за печатење на податоците за сладоледот во следниов формат:

  `име: состав цена [цена на попуст]`

  Делот „цена на попуст“ се печати **само ако** за сладоледот се нуди попуст (вредноста на попустот е поголема од нула).

- оператор `++` во префикс нотација за зголемување на попустот за 5.
- оператор `+` за собирање на објект од класата `IceCream` со низа од знаци. Собирањето се реализира на начин што името на новиот сладолед се добива со спојување на името на сладоледот и низата од знаци, одделени со `" + "`. Цената на новиот сладолед се зголемува за 10, а попустот и составот на сладоледот остануваат исти.
- метод `void setDiscount(int discount)` со кој може да се смени вредноста на попустот. Дозволените вредности на попустот се во интервалот [0, 100].
- метод `void setName(char* name)` со кој се менува името на сладоледот.

Да се креира класа `IceCreamShop` во која се чува:

- име на продавницата (низа од знаци, најмногу 50)
- динамички резервирано поле од објекти од класата `IceCream`
- број на сладоледи во полето (цел број).

За оваа класа да се обезбедат:

- соодветни конструктори и деструктор (погледнете ги повиците во функцијата `main`)
- оператор `+=` за додавање нов објект од класата `IceCream` во полето
- оператор `<<` за печатење на листа од сите сладоледи во продавницата. Прво се печати името на продавницата, а потоа се печатат податоците за сите сладоледи, одделени со нов ред.





 ## Test Cases


### Test Case 1

**Input:**
```text
3
FINKI Ice Cream
3
Strawberry Ice Cream in Lemon Bowls
Strawberry ice cream, Lemons
100
Caramel Apple Delight
Caramel Delight ice cream, Apples
120
Dreyer’s Ice Cream Blueberry Pie
French Vanilla ice cream, Graham cracker pie crust, blueberries
60
```
**Expected output:**

```text
====== TESTING IceCreamShop ======
CONSTRUCTOR
OPERATOR +=
FINKI Ice Cream
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 100
Caramel Apple Delight: Caramel Delight ice cream, Apples 120
Dreyer’s Ice Cream Blueberry Pie: French Vanilla ice cream, Graham cracker pie crust, blueberries 60
```





### Test Case 2

**Input:**
```text
2
Caramel Apple Delight
Caramel Delight ice cream, Apples
60
Caramel Apple Delight Ice Cream in Apples
Special Ice Cream
-40
```
**Expected output:**

```text
====== TESTING IceCream CONSTRUCTORS ======
CONSTRUCTOR
Caramel Apple Delight: Caramel Delight ice cream, Apples 60
COPY CONSTRUCTOR
Caramel Apple Delight: Caramel Delight ice cream, Apples 60
Caramel Apple Delight Ice Cream in Apples: Caramel Delight ice cream, Apples 60
OPERATOR =
Caramel Apple Delight Ice Cream in Apples: Caramel Delight ice cream, Apples 60
Special Ice Cream: Caramel Delight ice cream, Apples 60
```




### Test Case 3

**Input:**
```text
1
Strawberry Ice Cream in Lemon Bowls
Strawberry ice cream, Lemons
80
10
Caramel Apple Delight
Caramel Delight ice cream, Apples
60
20
```
**Expected output:**

```text
====== TESTING IceCream CLASS ======
CONSTRUCTOR
OPERATOR <<
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 80 (72)
Caramel Apple Delight: Caramel Delight ice cream, Apples 60 (48)
OPERATOR ++
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 80 (68)
OPERATOR +
Caramel Apple Delight + chocolate: Caramel Delight ice cream, Apples 70 (56)
```




### Test Case 4

**Input:**
```text
4
FINKI Ice Cream
3
Strawberry Ice Cream in Lemon Bowls
Strawberry ice cream, Lemons
100
Caramel Apple Delight
Caramel Delight ice cream, Apples
120
Dreyer’s Ice Cream Blueberry Pie
French Vanilla ice cream, Graham cracker pie crust, blueberries
80
```
**Expected output:**

```text
====== TESTING IceCreamShop CONSTRUCTORS ======
FINKI Ice Cream
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 100
Caramel Apple Delight: Caramel Delight ice cream, Apples 120
Dreyer’s Ice Cream Blueberry Pie: French Vanilla ice cream, Graham cracker pie crust, blueberries 80
FINKI fruits: strawberry ice cream, raspberry ice cream, blueberry ice cream 60

FINKI Ice Cream
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 100
Caramel Apple Delight: Caramel Delight ice cream, Apples 120
Dreyer’s Ice Cream Blueberry Pie: French Vanilla ice cream, Graham cracker pie crust, blueberries 80
```
