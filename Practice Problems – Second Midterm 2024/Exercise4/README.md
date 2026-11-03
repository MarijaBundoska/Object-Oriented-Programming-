## Exercise 4 - Museum Ticket Pricing System

Define an abstract class `Museum` with the following specifications **(5 points)**:

- Name of the museum (string with a maximum of 50 characters).
- City where the museum is located (string with a maximum of 50 characters).
- Base ticket price (floating-point number).
- Number of working hours in the week (integer).

Additionally, the class should contain two pure virtual member functions:

- `void printDetails()` - function that prints the object's information.
- `double calculateTicketCost()` - function that returns the ticket price for visiting the museum.

Define two classes, `ScientificMuseum` and `ArtMuseum`, which inherit from the class `Museum` **(5 points)**.

For the class `ScientificMuseum`, additionally store information about:

- Interactive exhibits within the museum (Boolean variable).
- Number of multimedia presentations available in the museum (integer variable).

The ticket price (function `double calculateTicketCost()`) for `ScientificMuseum` is calculated as follows:

- If the museum offers interactive exhibits, the price increases by 12%.
- Additionally, each multimedia presentation increases the price by $6.

The function `void printDetail()` prints the characteristics of the museum in the following format:

`[Museum Name] - (Scientific) [City] [Number of multimedia presentations] [Ticket price]`

**(10 points)**

For the class `ArtMuseum`, additionally store information about:

- Whether the museum offers options for amateur exhibitions (Boolean variable).
- Number of original non-restored artworks (integer variable).

The ticket price (function `double calculateTicketCost()`) for `ArtMuseum` is calculated as follows:

- If the museum offers options for amateur exhibitions, the price decreases by 18%.
- Additionally, each original non-restored artwork increases the price by $3.

The function `void printDetail()` prints the characteristics of the museum in the following format:

`[Museum Name] - (Art) [City] [Amateur exhibitions] [Ticket price]`

**(10 points)**

Define the following global function:

`int findCheapestScientificMuseum(Museum **m, int n)`

The function takes as arguments an array of pointers to museums and the size of the array, and returns the index of the scientific museum (`ScientificMuseum`) with the lowest ticket price in the array.

- If no such object exists in the array, the function returns `-1`.
- If multiple scientific museums have the same ticket price, the one with more working hours in the week is chosen (the last one found).

**(20 points)**

---

## Задача 4 - Пресметување на цена на билет во музеи

Да се дефинира апстрактна класа `Museum` со следниве спецификации **(5 поени)**:

- Име на музејот (стринг со максимум 50 знаци).
- Град во кој се наоѓа музејот (стринг со максимум 50 знаци).
- Основна цена на билет (реален број).
- Број на работни часови во неделата (цел број).

Дополнително, класата треба да содржи две чисто виртуелни функции-членки:

- `void printDetails()` - функција која ги печати информациите за објектот.
- `double calculateTicketCost()` - функција која ја враќа цената на билетот за посета на музејот.

Да се дефинираат две класи, `ScientificMuseum` и `ArtMuseum`, кои наследуваат од класата `Museum` **(5 поени)**.

За класата `ScientificMuseum` дополнително се чува информација за:

- Интерактивни поставки во рамки на музејот (Boolean променлива).
- Број на мултимедијални презентации кои може да се посетат во музејот (целобројна променлива).

Цената на билет (функција `double calculateTicketCost()`) за `ScientificMuseum` се пресметува на следниот начин:

- Ако музејот нуди интерактивни поставки, цената се зголемува за 12%.
- Дополнително, секоја мултимедијална презентација ја зголемува цената за $6.

Функцијата `void printDetail()` ги печати карактеристиките на музејот во следниот формат:

`[Име на музеј] - (Scientific) [Град] [Број на мултимедијални презентации] [Цена на билет]`

**(10 поени)**

За класата `ArtMuseum` дополнително се чува информација за:

- Дали музејот нуди опции за аматерски изложби (Boolean променлива).
- Број на оригинални нереставрирани уметнички дела (цел број).

Цената на билет (функција `double calculateTicketCost()`) за `ArtMuseum` се пресметува на следниот начин:

- Ако музејот нуди опција за аматерски изложби, цената се намалува за 18%.
- Дополнително, секое оригинално нереставрирано уметничко дело ја зголемува цената за $3.

Функцијата `void printDetail()` ги печати карактерист





## Test Cases


### Test Case 1

**Input:**
```text
1
2
1
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203
```
**Expected output:**

```text
Abstract and child classes OK
```



### Test Case 2

**Input:**
```text
2
4
1
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203
1
Natural History Museum
Los Angeles
12.5
40
0
3
2
Classic Art Museum
San Francisco
20.0
20
0
82
```
**Expected output:**

```text
47.36
623.76
30.5
266
calculateTicketCost method OK
```





### Test Case 3

**Input:**
```text
3
2
1
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203
```
**Expected output:**

```text
Science and Tech Museum - (Scientific) New York 5 47.36
Modern Art Museum - (Art) Chicago 1 623.76
printDetail method OK
```




### Test Case 4

**Input:**
```text
4
2
2
Modern Art Museum
Chicago
18.0
35
1
203
2
Classic Art Museum
San Francisco
20.0
20
0
82
```
**Expected output:**

```text
Scientific Museum not found in the array!
findCheapestOnlineOrder method OK
```




### Test Case 5

**Input:**
```text
	
4
4
1
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203
1
Natural History Museum
Los Angeles
12.5
40
0
3
2
Classic Art Museum
San Francisco
20.0
20
0
82
```
**Expected output:**

```text
Natural History Museum - (Scientific) Los Angeles 3 30.5
findCheapestOnlineOrder method OK
```



### Test Case 6

**Input:**
```text
4
4
1
Science and Tech Museum
New York
15.5
42
1
5
1
Science and Tech Museum 2
New York
15.5
43
1
5
1
Natural History Museum
Los Angeles
15.5
40
1
5
2
Classic Art Museum
San Francisco
20.0
20
0
82
```
**Expected output:**

```text
Science and Tech Museum 2 - (Scientific) New York 5 47.36
findCheapestOnlineOrder method OK
```
