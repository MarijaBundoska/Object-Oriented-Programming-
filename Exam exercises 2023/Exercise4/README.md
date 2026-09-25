#Pizza Management System

##Description

Create an abstract class `Pizza` used to represent pizzas. For each pizza, store the following information:
* **Name** (character array of maximum 20 characters)
* **Ingredients** (character array of maximum 100 characters)
* **Base price** (floating-point number)

Derive the classes `FlatPizza` and `FoldedPizza` from the base class `Pizza` to represent flat and folded pizzas, respectively.

* For each **flat pizza** (`FlatPizza`), additionally store its **size** (`enum` - one of three options: `SMALL`, `LARGE`, `FAMILY`).
* For each **folded pizza** (`FoldedPizza`), additionally store a boolean flag indicating **whether the dough is made from white flour** (`bool`).

---

## Price Calculation Logic

Each pizza class must implement a pure virtual function to calculate its final selling price (`price()`):

1. **Flat Pizza (`FlatPizza`):**
   * **Small:** Base price + 10%
   * **Large:** Base price + 20%
   * **Family:** Base price + 30%

2. **Folded Pizza (`FoldedPizza`):**
   * **White flour (`true`):** Base price + 10%
   * **Non-white flour (`false`):** Base price + 30%

---

## Operator Overloading

* **Operator `<<`** — outputs all pizza details in the following format:
  * **Flat Pizza:**  
    `[Name]: [Ingredients], [small/large/family] - [Selling Price]`
  * **Folded Pizza:**  
    `[Name]: [Ingredients], [wf / nwf] - [Selling Price]` *(wf = white flour, nwf = non-white flour)*

* **Operator `<`** — compares any two pizzas based on their final selling price.

---

## Global Function





# Систем за управување со пици (Pizza Management System)

## Опис на задачата

Да се креира апстрактна класа `Pizza` за опишување пици. За секоја пица се чуваат следните информации:
* **Име** (низа од максимум 20 знаци)
* **Состојки** (низа од максимум 100 знаци)
* **Основна цена** (реален број)

Од оваа класа да се изведат класите `FlatPizza` и `FoldedPizza` за опишување на рамни и преклопени пици соодветно.

* За секоја **рамна пица** (`FlatPizza`) дополнително се чува **големина** (`enum` - една од три можности: `мала`, `голема` и `фамилијарна`).
* За секоја **преклопена пица** (`FoldedPizza`) дополнително се чува информација **дали тестото е од бело брашно или не** (`bool`).

---

## Пресметка на продажна цена

За секоја пица треба да се обезбеди чисто виртуелен метод за пресметување на нејзината продажна цена (`price()`):

1. **Рамна пица (`FlatPizza`):**
   * **Мала:** Основна цена + 10%
   * **Голема:** Основна цена + 20%
   * **Фамилијарна:** Основна цена + 30%

2. **Преклопена пица (`FoldedPizza`):**
   * **Бело брашно (`true`):** Основна цена + 10%
   * **Друго брашно (`false`):** Основна цена + 30%

---

## Преоптоварување на оператори

* **Оператор `<<`** — за печатење на сите податоци за пиците во следниот формат:
  * **За рамна пица:**  
    `[име]: [состојки], [мала/голема/фамилијарна] - [продажна цена]`
  * **За преклопена пица:**  
    `[име]: [состојки], [wf / nwf] - [продажна цена]` *(wf = white flour, nwf = non-white flour)*

* **Оператор `<`** — за споредување на две пици од каков било вид според нивната продажна цена.

---

##Глобална функција

Да се дефинира глобална функција `expensivePizza` што прима низа од покажувачи кон објекти од класата `Pizza` (`Pizza **pizzas`) и нивниот број (`int n`), а ги печати информациите за пицата со највисока продажна цена.  
*(Ако има повеќе пици со иста највисока цена, се печати првата).*

Define a global function `expensivePizza` that receives an array of pointers to `Pizza` objects (`Pizza **pizzas`) and their count (`int n`). The function prints the details of the pizza with the highest selling price.  
*(If there are multiple pizzas with the same maximum price, print the first one).*



## Тест примери / Test Cases

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
