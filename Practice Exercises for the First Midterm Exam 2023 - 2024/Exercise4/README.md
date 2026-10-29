## Exercise 4 - Train Passengers and Bicycles

**(40 points)**

Create a class `Patnik` that stores information about the passengers on a train, including:

- Name (a string of up to 100 characters).
- The class of carriage in which the passenger travels (an integer, either 1 or 2).
- Whether the passenger has a bicycle (a Boolean variable).

For this class, overload the following operator:

- `<<` – to print the passenger's information in the following format:

```text
Passenger name
Class number (1 or 2)
Whether the passenger has a bicycle
```

Then, create a class `Voz` that stores:

- Final destination (a string of up to 100 characters).
- A dynamically allocated array of objects of the `Patnik` class.
- The number of elements in the array (an integer).
- The number of permitted bicycles (an integer).

The following must be implemented for this class:

- `+=` operator – to add a new passenger to the train. A passenger with a bicycle can board the train only if the train allows it.
- `<<` operator – to print the final destination of the train and the list of passengers.
- Function with the signature `patniciNemaMesto()`. This function calculates the total number of passengers (from both first and second class) who cannot board the train with their bicycles. When calculating the total number of passengers with bicycles who can board the train, first-class passengers must be considered first. Then, second-class passengers are allowed to board until the maximum number of permitted bicycles on the train is reached. Finally, print the number of passengers with bicycles who remain unable to board, first from first class and then from second class.

---

## Задача 4 - Патници и велосипеди во воз

**(40 поени)**

Да се креира класа `Patnik` во која се чуваат податоци за патниците на еден воз и тоа:

- Име (низа од максимум 100 знаци).
- Класа на вагон во која се вози (цел број 1 или 2).
- Велосипед (булова променлива).

За оваа класа да се преоптовари:

- Оператор `<<` – за печатење на информациите за патникот во формат:

```text
Име на патник
Бројот на класата (1 или 2)
Дали има велосипед?
```

Потоа да се креира класа `Voz` во која се чува:

- Крајна дестинација (низа од максимум 100 знаци).
- Динамички алоцирана низа од објекти од класата `Patnik`.
- Број на елементи во низата (цел број).
- Број на дозволени велосипеди (цел број).

За класата да се обезбедат:

- Оператор `+=` – за додавање нов патник во воз. Патник со велосипед ќе може да се качи во воз само ако возот го дозволува тоа.
- Оператор `<<` – за печатење на крајната дестинација до која вози и листата на патници.
- Функција со потпис `patniciNemaMesto()`. Со оваа функција се пресметува вкупниот број на патници (од 1-ва класа и 2-ра класа) за кои нема место да влезат во возот со велосипед. Притоа треба да се внимава дека во пресметувањето на вкупниот број патници со велосипеди кои ќе влезат во возот прво треба да се земат предвид патниците од 1-ва класа, а потоа се дозволува да влегуваат патниците од 2-ра класа сè додека не се достигне максималниот број на дозволени велосипеди во возот. На крај се печати бројот на патници со велосипеди кои остануваат (не влегуваат во возот) од 1-ва класа, а потоа од 2-ра класа.




 ## Test Cases


### Test Case 1

**Input:**
```text
Amsterdam
0
5
Ana
1
1
Kate
2
0
Ace
2
0
Borce
2
1
Mimi
2
0
```
**Expected output:**

```text
Amsterdam
Kate
2
0

Ace
2
0

Mimi
2
0

Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 0
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 0
```




### Test Case 2

**Input:**
```text
Amsterdam
5
10
Ana
1
1
Kate
2
0
Ace
2
0
Borce
1
1
Mimi
2
0
Deni
1
0
Nikola
2
1
Bojan
1
1
Tamara
2
1
Kiki
2
1
```
**Expected output:**

```text
Amsterdam
Ana
1
1

Kate
2
0

Ace
2
0

Borce
1
1

Mimi
2
0

Deni
1
0

Nikola
2
1

Bojan
1
1

Tamara
2
1

Kiki
2
1

Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 0
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 1
```



### Test Case 3

**Input:**
```text
Berlin
10
20
Ana
1
1
Kate
2
0
Ace
2
0
Borce
1
1
Mimi
2
1
Deni
1
0
Nikola
1
1
Bojan
1
1
Tamara
1
1
Kiki
2
1
Ana
1
1
Kate
2
0
Ace
1
1
Borce
1
1
Mimi
1
0
Deni
1
0
Nikola
1
1
Bojan
1
1
Tamara
2
0
Kiki
1
1
```
**Expected output:**

```text
Berlin
Ana
1
1

Kate
2
0

Ace
2
0

Borce
1
1

Mimi
2
1

Deni
1
0

Nikola
1
1

Bojan
1
1

Tamara
1
1

Kiki
2
1

Ana
1
1

Kate
2
0

Ace
1
1

Borce
1
1

Mimi
1
0

Deni
1
0

Nikola
1
1

Bojan
1
1

Tamara
2
0

Kiki
1
1

Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 1
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 2
```





### Test Case 4

**Input:**
```text
Minhen
0
20
Ana
1
1
Kate
2
0
Ace
2
0
Borce
1
1
Mimi
2
1
Deni
1
0
Nikola
1
1
Bojan
1
1
Tamara
1
1
Kiki
2
1
Ana
1
1
Kate
2
0
Ace
1
1
Borce
1
1
Mimi
1
0
Deni
1
0
Nikola
1
1
Bojan
1
1
Tamara
2
0
Kiki
1
1
```
**Expected output:**

```text
Minhen
Kate
2
0

Ace
2
0

Deni
1
0

Kate
2
0

Mimi
1
0

Deni
1
0

Tamara
2
0

Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 0
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 0
```




### Test Case 5

**Input:**
```text
Brisel
10
10
Ana
1
1
Kate
2
0
Ace
2
0
Borce
1
1
Mimi
2
0
Deni
1
0
Nikola
2
1
Bojan
1
1
Tamara
2
1
Kiki
2
1
```
**Expected output:**

```text
Brisel
Ana
1
1

Kate
2
0

Ace
2
0

Borce
1
1

Mimi
2
0

Deni
1
0

Nikola
2
1

Bojan
1
1

Tamara
2
1

Kiki
2
1

Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 0
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 0
```





### Test Case 6

**Input:**
```text
Dizeldorf
10
3
Ana
1
1
Kate
2
0
Ace
2
0
```
**Expected output:**

```text
Dizeldorf
Ana
1
1

Kate
2
0

Ace
2
0

Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 0
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 0
```
