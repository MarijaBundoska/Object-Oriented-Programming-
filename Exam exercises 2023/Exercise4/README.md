# Exercise 4 - Pizza Management System

### Problem Description

Create an abstract class `Pizza` used to represent pizzas. **(5 points)** For each pizza, store the following information:
* `ime` (character array with a maximum of 20 characters - pizza name)
* `sostojki` (character array with a maximum of 100 characters - pizza ingredients)
* `osnovnaCena` (floating-point number - base price)

Derive the classes `FlatPizza` and `FoldedPizza` from the base class `Pizza` to represent flat and folded pizzas, respectively. **(5 points)**

For each flat pizza, additionally store:
* `golemina` (enum - one of three possible sizes: `SMALL`, `LARGE`, `FAMILY`)

For each folded pizza, additionally store:
* information indicating whether the dough is made from white flour (`boolean`).

**Price Calculation:**

Each pizza must provide a method for calculating its `selling price`:

* The price of a flat pizza is calculated by increasing the base price by:
  * 10% for a small pizza
  * 20% for a large pizza
  * 30% for a family pizza

* The price of a folded pizza is calculated by increasing the base price by:
  * 10% if the dough is made from white flour
  * 30% otherwise

**(10 points)**

**Operator Overloading:**

* `operator<<` - prints all information about the pizzas in the following format:
  * For a flat pizza:
    `[name]: [ingredients], [size] - [selling price of the pizza]`

  * For a folded pizza:
    `[name]: [ingredients], [wf - if made with white flour / nwf - if not made with white flour] - [selling price of the pizza]`

**(5 points)**

* `operator<` - compares pizzas of any type according to their selling price.

**(5 points)**

**Global Function:**

* `expensivePizza(Pizza **pizzas, int n)` - receives an array of pointers to objects of the class `Pizza` and their number as input, and prints the information about the pizza with the highest selling price.
  * If there are multiple pizzas with the same highest selling price, the first pizza is printed.

**(10 points)**

**Constructors and Methods:**

Define the necessary constructors and methods in the classes for the program to function correctly.

**(5 points)**


---

### Опис на задачата

Да се креира апстрактна класа `Pizza` за опишување пици. **(5 поени)** За секоја пица се чуваат следните информации:
* `ime` (низа од максимум 20 знаци)
* `sostojki` (низа од максимум 100 знаци)
* `osnovnaCena` (реален број - основна цена)

Од оваа класа да се изведат класите `FlatPizza` и `FoldedPizza` за опишување на рамни и преклопени пици соодветно. **(5 поени)**

За секоја рамна пица дополнително се чува:
* `golemina` (enum - една од три можности: мала, голема и фамилијарна)

За секоја преклопена пица дополнително се чува:
* информација дали тестото е од бело брашно или не (`boolean`).

**Пресметка на продажна цена:**

За секоја пица треба да се обезбеди метод за пресметување на нејзината `продажна цена`:

* Цената на рамната пица се пресметува така што основната цена се зголемува за:
  * 10% за мала пица
  * 20% за голема пица
  * 30% за фамилијарна пица

* Цената на преклопената пица се пресметува така што основната цена се зголемува за:
  * 10% ако тестото е од бело брашно
  * 30% ако тестото не е од бело брашно

**(10 поени)**

**Преоптоварување на оператори:**

* `operator<<` - за печатење на сите податоци за пиците во следниов формат:

  * За рамна пица:
    `[име]: [состојки], [големина] - [продажната цена на пицата]`

  * За преклопена пица:
    `[име]: [состојки], [wf - ако е со бело брашно / nwf - ако не е со бело брашно] - [продажната цена на пицата]`

**(5 поени)**

* `operator<` - за споредување на пиците од каков било вид според нивната продажна цена.

**(5 поени)**

**Глобална функција:**

* `expensivePizza(Pizza **pizzas, int n)` - прима низа од покажувачи кон објекти од класата `Pizza` и нивниот број, а како резултат ги печати информациите за пицата со највисока продажна цена.
  * Ако има повеќе пици со иста највисока цена, се печати првата.

**(10 поени)**

**Конструктори и методи:**

Да се дефинираат потребните конструктори и методи во класите за правилно функционирање на програмата.

**(5 поени)**


##  Test Cases

### Test Case 1

### Input
```text
5
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
2
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
0
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
```

### Output
```text
Margarita: Tomato sauce, cheese, mozzarella, basil, oregano, family - 130
Margarita: Tomato sauce, cheese, mozzarella, basil, oregano, small - 110
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, wf - 154
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, nwf - 182
Lower price: 
110
130
110
154
```

### Test Case 2

### Input
```text
	
6
6
1
Peperoni
Tomato sauce, cheese, kulen sausage, oregano
250
0
1
Capricciosa
tomato sauce, cheese, ham, fresh mushrooms, oregano
250
0
1
Prosciutto
tomato sauce, cheese, prosciutto, oregano
310
0
2
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
1
Veggie
tomato sauce, cheese, tomatoes, peppers, onion, olives, fresh mushrooms, oregano
270
0
1
Caprese
tomato sauce, cheese, mozzarella, tomatoes, pesto, garlic, oregano
310
0
```

### Output
```text
Peperoni: Tomato sauce, cheese, kulen sausage, oregano, small - 275
Capricciosa: tomato sauce, cheese, ham, fresh mushrooms, oregano, small - 275
Prosciutto: tomato sauce, cheese, prosciutto, oregano, small - 341
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, nwf - 182
Veggie: tomato sauce, cheese, tomatoes, peppers, onion, olives, fresh mushrooms, oregano, small - 297
Caprese: tomato sauce, cheese, mozzarella, tomatoes, pesto, garlic, oregano, small - 341

The most expensive pizza:
Prosciutto: tomato sauce, cheese, prosciutto, oregano, small - 341
```

### Test Case 3

### Input
```text
3
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
```

### Output
```text
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, wf - 154
```

### Test Case 4

### Input
```text
	
6
4
1
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
2
1
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
0
2
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
2
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
```

### Output
```text

4
1
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
2
1
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
0
2
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
2
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
Margarita: Tomato sauce, cheese, mozzarella, basil, oregano, family - 130
Margarita: Tomato sauce, cheese, mozzarella, basil, oregano, small - 110
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, wf - 154
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, nwf - 182

The most expensive pizza:
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, nwf - 182
```


### Test Case 5

### Input
```text	
2
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
2
```

### Output
```text
Margarita: Tomato sauce, cheese, mozzarella, basil, oregano, family - 130
```

### Test Case 6


### Input
```text
1
Margarita
Tomato sauce, cheese, mozzarella, basil, oregano
100
```

### Output
```text
Margarita: Tomato sauce, cheese, mozzarella, basil, oregano, small - 110
```

### Test Case 7

### Input
```text	
4
Capricciosa calzone
Tomato sauce, cheese, ham, fresh mushrooms
140
```

### Output
```text
Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, nwf - 182
```
