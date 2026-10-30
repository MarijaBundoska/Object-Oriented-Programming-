## Exercise 10 - Best Player in the Most Popular Computer Game

Create a structure `Player` that stores information about a player in a computer game. The following information is stored for each player:
- Player's username (a string of 15 characters)
- The level the player has reached (integer)
- The number of points earned (integer)

(10 points)

Then, create a structure `ComputerGame` that stores information about a computer game:
- Game name (a string of 20 characters)
- An array of players who play the game (maximum 30 players)
- Number of players

(10 points)

Implement a function with the following signature (15 points):

```cpp
void bestPlayer(ComputerGame *list, int n)
```

This function should print the username of the best player in the most popular game (the game played by the largest number of players).

The best player is the player who has earned the highest number of points. If multiple players have the same maximum number of points, the best player is the one who has reached the highest level.

The output should be in the following format:

```text
Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY
```

(XXXXXX is the username of the best player, and YYYYYY is the name of the game played by the largest number of players.)

**Note:** There will always be exactly one best player.

Task functionality and completion of the `main` function (10 points).

**Note:** The task must be solved in the C++ programming language.

---

## Задача 10 - Најдобар играч во најпопуларната компјутерска игра

Да се креира структура `Igrac` во која се чуваат податоци за еден играч на компјутерската игра. За играчот се чуваат информации за:
- Корисничкото име на играчот (низа од 15 знаци)
- Бројот на ниво до кој играчот е стигнат (цел број)
- Бројот на освоени поени (цел број)

(10 поени)

Потоа да се креира структура `KompjuterskaIgra` во која се чуваат податоци за:
- Името на играта (низа од 20 знаци)
- Низа од играчи кои ја играат играта (најмногу 30)
- Бројот на играчи

(10 поени)

Треба да се направи функција со потпис (15 поени):

```cpp
void najdobarIgrac(KompjuterskaIgra *lista, int n)
```

Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност (ја играат најголем број на играчи).

Најдобар играч е играчот кој има најголем број на освоени поени. Ако има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.

Печатењето е во форматот:

```text
Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY
```

(XXXXXX е корисничкото име на најдобриот играч, а YYYYYY е името на играта која ја играат најголем број на играчи.)

**Забелешка:** Секогаш ќе има точно еден најдобар играч.

Функционалност на задачата и дополнување на `main` функцијата (10 поени).

**Забелешка:** Задачата да се реши во програмскиот јазик C++.



 ## Test Cases


### Test Case 1

**Input:**
```text
2
Snake
2
user1 5 120
user2 4 120
Cars
3
koliubavi 5 130
fikjo 3 150
motor 4 140
```
**Expected output:**

```text
Najdobar igrac e igracot so korisnicko ime fikjo koj ja igra igrata Cars
```


### Test Case 2

**Input:**
```text
1
Snake
2
ana 5 120
ivan 4 120
```
**Expected output:**

```text
Najdobar igrac e igracot so korisnicko ime ana koj ja igra igrata Snake
```



### Test Case 3

**Input:**
```text
1
Snake
2
ana 5 120
ivan 4 200
```
**Expected output:**

```text
Najdobar igrac e igracot so korisnicko ime ivan koj ja igra igrata Snake
```
