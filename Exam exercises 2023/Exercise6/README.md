# Exercise 5 - Game and User Management System

## Problem Description

Implement a class to represent a computer game (`Game`), which stores:

* `name` (array of maximum 100 characters)
* `price` (floating-point number)
* `onSale` (boolean variable indicating if the game was bought on sale)

Derive a class `SubscriptionGame` from `Game`, which additionally stores:

* `monthlyFee` (floating-point number for monthly subscription fee)
* `month` and `year` (positive integers representing purchase date)

For both `Game` and `SubscriptionGame`, overload the output (`<<`) and input (`>>`) operators. Also define `operator==` to compare games by name.

Implement a user class (`User`) which stores:

* `username` (array of maximum 100 characters)
* `games` (dynamically allocated array of pointers to `Game` objects)
* `numGames` (integer representing total number of purchased games)

Overload `operator+=` to add a new game to the user's collection. If the user already owns the game, throw an exception of type `ExistingGame`. The exception class must have an appropriate constructor and a `message()` method to output an error message.

Implement a `total_spent()` method in `User` to calculate total money spent on games. If a game is bought on sale, its price is 30% of standard price. For `SubscriptionGame`, add the total subscription fees: `(number_of_elapsed_months * monthly_fee)` relative to the reference date (May 2018 / month 5, year 2018).

Overload output operator (`<<`) for `User` to print details in the following format:

```text
User: username
- Game: PUBG, regular price: $70, bought on sale
- Game: Half Life 2, regular price: $70
- Game: Warcraft 4, regular price: $40, monthly fee: $10, purchased: 1-2017
```
### Method Prototypes

| Class / Module | Method Prototype | Description |
| :--- | :--- | :--- |
| **ExistingGame** | `void message()` | Prints the appropriate exception error message to the screen |
| **Game** | `bool operator==(const Game &)` | Compares two games based on their title/name |
| **User** | `User& operator+=(const Game &)` | Adds a new game to the user's collection (with exception checking) |
| **User** | `Game& get_game(int)` | Returns a reference to the game at the specified index in the collection |
| **User** | `double total_spent(int)` | Calculates the total amount of money spent on all purchased games |
| **User** | `const char* get_name()` | Returns the username of the user |
| **User** | `int get_games_number()` | Returns the total number of games in the collection |


# Задача 5 - Систем за управување со игри и корисници

## Опис на задачата

Потребно е да се имплементира класа за компјутерска игра (`Game`), што содржи информации за:
* `name` (низа од макс. 100 знаци - име на играта)
* `price` (децимален број - цена на играта)
* `onSale` (bool променлива - дали е играта купена на распродажба)

Од класата `Game` да се изведе класа `SubscriptionGame`, што дополнително ќе чува:
* `monthlyFee` (децимален број - месечен надоместок за играње)
* `month` и `year` (позитивни цели броеви - датум кога играта е купена)

За класите `Game` и `SubscriptionGame` да се преоптоварат операторите за печатење (`<<`) и читање (`>>`). Да се дефинира и операторот `==` кој ќе споредува игри според нивното име.

Да се дефинира класа за корисник (`User`) во која се чуваат:
* `username` (низа од макс. 100 знаци - корисничко име)
* `games` (динамички алоцирана низа од покажувачи кон `Game` - колекција од игри купени од корисникот)
* `numGames` (цел број - број на купени игри)

Да се преоптовари операторот `+=` кој ќе овозможи додавање на нова игра во колекцијата на игри. Притоа, ако корисникот ја има веќе купено играта, потребно е да се креира исклучок од типот `ExistingGame`. Класата за имплементација на исклучоци потребно е да има соодветен конструктор и метода `message()` за печатење на порака на екран.

Да се креира и метода `total_spent()` во класата `User` која ќе пресметува колку пари корисникот потрошил за својата колекција од игри. Доколку играта е купена на распродажба, цената на играта е 30% од стандардната цена. Доколку играта е од типот `SubscriptionGame`, потребно е да се вкалкулира и сумата потрошена за месечниот надоместок `(број_на_изминати_месеци * цена_на_месечен_надоместок)` без да се земе во предвид моменталниот месец (мај 2018).

Да се преоптовари и операторот за печатење на корисникот (`<<`), кој печати информации во следниот формат:

```text
User: username
- Game: PUBG, regular price: $70, bought on sale
- Game: Half Life 2, regular price: $70
- Game: Warcraft 4, regular price: $40, monthly fee: $10, purchased: 1-2017
```

### Листа на методи и нивни прототипови

| Класа / Модул | Прототип на метод | Опис |
| :--- | :--- | :--- |
| **ExistingGame** | `void message()` | Печати соодветна порака за фрлениот исклучок на екран |
| **Game** | `bool operator==(const Game &)` | Споредува две игри според нивното име |
| **User** | `User& operator+=(const Game &)` | Додава нова игра во колекцијата на корисникот (со проверка за исклучок) |
| **User** | `Game& get_game(int)` | Враќа референца до играта на соодветниот индекс во колекцијата |
| **User** | `double total_spent(int)` | Ја пресметува вкупната сума потрошена за сите купени игри |
| **User** | `const char* get_name()` | Го враќа корисничкото име на корисникот |
| **User** | `int get_games_number()` | Го враќа вкупниот број на игри во колекцијата |



## Test Cases


### Test Case 1

**Input:**
```text
	
4
World of Warcraft
40
0
10
1
2017

```
**Expected output:**

```text
Testing operator>> for SubscriptionGame
Game: World of Warcraft, regular price: $40, monthly fee: $10, purchased: 1-2017
```



### Test Case 2

**Input:**
```text
1
Sims
50
0
```
**Expected output:**

```text
Testing class Game and operator<< for Game
Game: Sims, regular price: $50
```



### Test Case 3

**Input:**
```text
	
1
Half Life
70
1

```
**Expected output:**

```text
Testing class Game and operator<< for Game
Game: Half Life, regular price: $70, bought on sale

```



### Test Case 4

**Input:**
```text
	
3
Half Life 2
70

```
**Expected output:**

```text
Testing operator>> for Game
Game: Half Life 2, regular price: $70, bought on sale

```



### Test Case 5

**Input:**
```text
2
PUBG
100
1
5
5
2018
```
**Expected output:**

```text
Testing class SubscriptionGame and operator<< for SubscritionGame
Game: PUBG, regular price: $100, bought on sale, monthly fee: $5, purchased: 5-2018

```



### Test Case 6

**Input:**
```text
7
BugsBunny
2
1
Half Life 2
70
0
2
Warcraft 4
40
0
10
1
2017
```
**Expected output:**

```text
Testing total_spent method() for User

User: BugsBunny
- Game: Half Life 2, regular price: $70
- Game: Warcraft 4, regular price: $40, monthly fee: $10, purchased: 1-2017

Total money spent: $270
```



### Test Case 7

**Input:**
```text
5
BugsBunny
1
1
Half Life 2
70
0
```
**Expected output:**

```text
Testing class User and operator+= for User

User: BugsBunny
- Game: Half Life 2, regular price: $70
```



### Test Case 8

**Input:**
```text
6
BugsBunny
3
1
Half Life 2
70
0
2
Warcraft 4
40
0
10
1
2017
1
Half Life 2
70
1
```
**Expected output:**

```text
Testing exception ExistingGame for User
The game is already in the collection

User: BugsBunny
- Game: Half Life 2, regular price: $70
- Game: Warcraft 4, regular price: $40, monthly fee: $10, purchased: 1-2017
```



### Test Case 9

**Input:**
```text
5
BugsBunny
2
1
Half Life 2
70
0
2
World od Warcraft
40
0
10
1
2017
```
**Expected output:**

```text
Testing class User and operator+= for User

User: BugsBunny
- Game: Half Life 2, regular price: $70
- Game: World od Warcraft, regular price: $40, monthly fee: $10, purchased: 1-2017

```



### Test Case 10

**Input:**
```text
7
DaffyDuck
1
2
Warcraft 4
40
0
10
4
2018
```
**Expected output:**

```text
Testing total_spent method() for User

User: DaffyDuck
- Game: Warcraft 4, regular price: $40, monthly fee: $10, purchased: 4-2018

Total money spent: $50
```



### Test Case 11

**Input:**
```text
6
BugsBunny
2
1
Half Life 2
70
1
2
Warcraft 4
40
0
10
1
2017
```
**Expected output:**

```text
Testing exception ExistingGame for User

User: BugsBunny
- Game: Half Life 2, regular price: $70, bought on sale
- Game: Warcraft 4, regular price: $40, monthly fee: $10, purchased: 1-2017
```



### Test Case 12

**Input:**
```text
2
World of Warcraft
40
0
10
1
2018
```
**Expected output:**

```text
Testing class SubscriptionGame and operator<< for SubscritionGame
Game: World of Warcraft, regular price: $40, monthly fee: $10, purchased: 1-2018

```


