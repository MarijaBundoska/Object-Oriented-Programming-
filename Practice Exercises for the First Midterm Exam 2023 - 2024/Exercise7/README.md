## Exercise 7 - Amusement Park Rides

## Задача 7 - Адреналински возења во забавен парк

### Problem Statement

In the C++ programming language, create a structure `Ride` to describe adrenaline rides in an amusement park. The structure should contain: **(5 points)**

- Name of the ride (a string of 100 characters)
- Duration in minutes (an integer)
- Price (a decimal number)
- Whether the ride offers a student discount (1 – yes, 0 – no)

Create a structure `AmusementPark` that contains: **(10 points)**

- Name of the amusement park (a string of 100 characters)
- Location (a string of 100 characters)
- An array of adrenaline rides in the park (an array of a maximum of 100 elements of type `Ride`)
- Number of elements in the array (an integer)

Create a function `print` to display information about all rides in the amusement park in the following format: **(10 points)**

```text
[Park name] [Location]
[Name1] [Duration1] [Price1]
[Name2] [Duration2] [Price2]
[Name3] [Duration3] [Price3]
...
```

Create a function `bestPark` that receives an array of variables of type `AmusementPark` and prints the name and location of the park that is the cheapest to visit for students. The cheapest park is the one that contains the largest number of rides offering student discounts. If multiple parks share this characteristic, print the park with the greatest total duration of all its rides. **(20 points)**

Complete the `main` function. **(5 points)**

### Опис на задачата

Во програмскиот јазик C++ да се креира структура `Ride` за опишување на адреналински возења во забавен парк. Структурата треба да содржи: **(5 поени)**

- Име на возењето (низа од 100 знаци)
- Времетраење во минути (цел број)
- Цена (децимален број)
- Дали има студентски попуст (1 – да, 0 – не)

Да се креира структура `AmusementPark`, што содржи: **(10 поени)**

- Име на забавниот парк (низа од 100 знаци)
- Локација (низа од 100 знаци)
- Низа од адреналински возења во паркот (низа од максимум 100 елементи од структурата `Ride`)
- Број на елементи во низата (цел број)

Да се креира функција `print` за печатење на информациите за сите возења во забавниот парк во следниот формат: **(10 поени)**

```text
[Ime na parkot] [Lokacija]
[Ime1] [Vremetraenje1] [Cena1]
[Ime2] [Vremetraenje2] [Cena2]
[Ime3] [Vremetraenje3] [Cena3]
...
```

Да се креира функција `bestPark`, што прима низа од променливи од типот `AmusementPark` и го печати името и локацијата на паркот кој е најефтин за посета од страна на студенти. Најефтин парк е оној што содржи најголем број возења со студентски попуст. Ако повеќе паркови ги делат овие карактеристики, да се испечати паркот со најголемото вкупно времетраење од сите возења. **(20 поени)**

Да се дополни функцијата `main`. **(5 поени)**




 ## Test Cases


### Test Case 1

**Input:**
```text
2
Disneyland
Paris
2
BigThunderMountain
15
10
1
Shark
22
13
0
TivoliGardens
Copenhagen
3
Devil
16
11
1
FlyMountain
35
19
1
Nemo
8
7
0
```
**Expected output:**

```text
Disneyland Paris
BigThunderMountain 15 10.00
Shark 22 13.00
TivoliGardens Copenhagen
Devil 16 11.00
FlyMountain 35 19.00
Nemo 8 7.00
Najdobar park: TivoliGardens Copenhagen
```



### Test Case 2

**Input:**
```text
2
Disneyland
Florida
3
IndianaJones
13
6.5
1
Elevator
2
4.4
0
SpaceMountain
3
7.7
1
ParadisePier
California
3
StarFlyer
6
5.9
1
Twilight
8
5.5
1
StarWars
7
6
0
```
**Expected output:**

```text
Disneyland Florida
IndianaJones 13 6.50
Elevator 2 4.40
SpaceMountain 3 7.70
ParadisePier California
StarFlyer 6 5.90
Twilight 8 5.50
StarWars 7 6.00
Najdobar park: ParadisePier California
```




### Test Case 3

**Input:**
```text
2
Disneyland
Florida
3
IndianaJones
13
6.5
1
Elevator
2
4.4
0
SpaceMountain
3
7.7
1
ParadisePier
California
3
StarFlyer
1
5.9
1
Twilight
1
5.5
1
StarWars
1
6
0
```
**Expected output:**

```text
Disneyland Florida
IndianaJones 13 6.50
Elevator 2 4.40
SpaceMountain 3 7.70
ParadisePier California
StarFlyer 1 5.90
Twilight 1 5.50
StarWars 1 6.00
Najdobar park: Disneyland Florida
```
