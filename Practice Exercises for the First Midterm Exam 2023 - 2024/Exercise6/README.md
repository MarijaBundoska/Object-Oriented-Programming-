## Exercise 6 - Shortest Train Route

## Задача 6 - Најкратка релација на воз

### Problem Statement

Create a structure `Train` that stores information about the route traveled by the train (a string of at most 50 characters), the planned number of kilometers to be traveled (a real number), and the number of passengers on the train (an integer).

Then, create a structure `RailwayStation` that stores information about the city in which it is located (a string of 20 characters), an array of trains departing from the station (at most 30), and the number of trains (an integer).

Implement a function with the following signature:

```cpp
void shortestRoute(RailwayStation* stations, int n, char* city);
```

The function should print the route and the number of kilometers of the train that travels the shortest route (the fewest kilometers) and departs from the railway station in the city passed as an input argument. If multiple trains have the same minimum number of kilometers, the route of the last such train should be printed.

**Note:** The task must be solved in the C++ programming language.

### Опис на задачата

Да се креира структура `Train` во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци), предвидениот број на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креира структура `RailwayStation` во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис:

```cpp
void shortestRoute(RailwayStation* stations, int n, char* city);
```

Во функцијата се печатат релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица во градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков воз.

**Забелешка:** Задачата треба да се реши во програмскиот јазик C++.







 ## Test Cases


### Test Case 1

**Input:**
```text
1
Dresden
2
Dresden-Berlin 192 200
Dresden-Lajpcig 115 90
Dresden
```
**Expected output:**

```text
Najkratka relacija: Dresden-Lajpcig (115 km)
```





### Test Case 2

**Input:**
```text
3
Dresden
2
Dresden-Berlin 192 200
Dresden-Lajpcig 115 90
Berlin
3
Berlin-Hanover 286 300
Berlin-Postdam 110 100
Berlin-Magdeburg 215 150
Minhen
4
Minhen-Stutgart 213 200
Minhen-Frankfurt 392 300
Minhen-Berlin 392 300
Minhen-Nuremberg 213 100
Minhen
```
**Expected output:**

```text
Najkratka relacija: Minhen-Nuremberg (213 km)
```




### Test Case 3

**Input:**
```text
2
Dresden
2
Dresden-Berlin 192 200
Dresden-Lajpcig 115 90
Berlin
3
Berlin-Hanover 286 300
Berlin-Postdam 110 100
Berlin-Magdeburg 215 150
Berlin
```
**Expected output:**

```text
Najkratka relacija: Berlin-Postdam (110 km)
```

