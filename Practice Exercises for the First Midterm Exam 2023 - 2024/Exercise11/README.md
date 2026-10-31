## Exercise 11 - Marathon Participants

Define a class `Participant` for a marathon participant, which stores the following information:

- Name (a dynamically allocated character array)
- Gender (`bool`)
- Age (integer)

(5 points)

For this class, overload the necessary constructors and write an appropriate destructor. (10 points)

Additionally, overload the following operators for this class:

- The comparison operator `>` (compares two participants according to their age). (5 points)
- The output stream operator `<<`, which prints the name, gender (male/female), and age, each on a separate line. (5 points)

Define a class `Marathon` which stores:

- Location (a string of maximum 100 characters)
- An array of `Participant` objects (a dynamically allocated array of objects of the `Participant` class)
- Number of participants (integer)

(5 points)

For this class, overload the necessary constructors and write an appropriate destructor. (10 points)

Also, implement the following methods:

- The `+=` operator for adding a new `Participant` to the `Marathon`. (10 points)
- `averageAge()` — returns the average age of the marathon participants. (5 points)
- `printYounger(Participant &p)` — prints all participants younger than the participant passed as an argument to the method. (5 points)

---

## Задача 11 - Учесници на маратон

Да се дефинира класа `Ucesnik` за учесник во маратон за кој ќе се чуваат информации за:

- Име (динамички алоцирана низа од знаци)
- Пол (`bool`)
- Возраст (цел број)

(5 поени)

За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)

Дополнително за оваа класа да се преоптоварат:

- Оператор за споредување `>` (споредува двајца учесници според возраста). (5 поени)
- Операторот за проследување на излезен тек `<<`, кој ќе ги печати името, полот (машки/женски) и возраста, секој во посебен ред. (5 поени)

Да се дефинира класа `Maraton` за кој се чуваат:

- Локација (низа од максимум 100 знаци)
- Низа од `Ucesnik` објекти (динамички алоцирана низа од објекти од класата `Ucesnik`)
- Број на учесници (цел број)

(5 поени)

За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)

Исто така да се имплементираат следните методи:

- Операторот `+=` за додавање нов `Ucesnik` на маратонот `Maraton`. (10 поени)
- `prosecnoVozrast()` — враќа просечна возраст на учесниците на маратонот. (5 поени)
- `pecatiPomladi(Ucesnik &u)` — ги печати сите учесници помлади од учесникот проследен како аргумент на методот. (5 поени)




 ## Test Cases


### Test Case 1

**Input:**
```text
5
Skopje
Elena 0 23
Mitko 1 41
Iskra 0 31
Jovan 1 28
Zoran 1 40
```
**Expected output:**

```text
Elena
zhenski
23
Iskra
zhenski
31
Jovan
mashki
28
32.6
```
