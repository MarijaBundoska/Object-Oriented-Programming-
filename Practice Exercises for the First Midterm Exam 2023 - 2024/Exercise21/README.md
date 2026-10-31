## Exercise 21 - Dancers and Their Dances

Create a structure `Tanc` that stores the name of a dance and its country of origin (strings of 15 characters).

Then, create a structure `Tancer` that stores the first and last name (strings of maximum 20 characters), and an array of 5 dances (structure `Tanc`) that the given dancer can perform.

Additionally, provide the following function for this structure:

`void tancuvanje(Tancer *t, int n, char *zemja)`

The function should print, on a separate line, the first and last name of dancers who know how to perform at least one dance originating from the country passed as an argument to the function, as well as the name of the dance, in the following format:

**FirstName LastName, DanceName**

---

## Задача 21 - Танчер и танци

Да се креира структура `Tanc` во која се чуваат податоци за името на танцот и земјата на потекло (низи од 15 знаци).

Потоа да се креира структура `Tancer` во која се чуваат податоци за име и презиме (низи од максимум 20 знаци), како и низа од 5 танци (структура `Tanc`) кои дадениот танчер може да ги игра.

Дополнително, за оваа структура да се обезбеди функција со потпис:

`void tancuvanje(Tancer *t, int n, char *zemja)`

Функцијата треба да ги испечати во посебен ред името и презимето на танчерите што знаат да играат барем еден танц од земјата која е проследена како аргумент на функцијата, како и името на танцот во формат:

**Име Презиме, Име на танц**




 ## Test Cases


### Test Case 1

**Input:**
```text
4
Aleks
Aleksov
samba
brazil
salsa
kuba
merengue
dominikana
Marko
Markov
tango
argentina
flamenco
spanija
samba
brazil
Nikola
Nikolov
chacha
kuba
samba
brazil
vienski
avstrija
Marta
Martovska
samba
brazil
samba1
brazil
bachata
dominikana
brazil
```
**Expected output:**

```text
Aleks Aleksov, samba
Marko Markov, samba
Nikola Nikolov, samba
Marta Martovska, samba
```



### Test Case 2

**Input:**
```text
2
Aleks
Aleksov
samba
brazil
salsa
kuba
merengue
dominikana
Marko
Markov
tango
argentina
flamenco
spanija
samba
brazil
kuba
```
**Expected output:**

```text
Aleks Aleksov, salsa
```




### Test Case 3

**Input:**
```text
4
Aleks
Aleksov
samba
brazil
salsa
kuba
merengue
dominikana
Marko
Markov
tango
argentina
flamenco
spanija
samba
brazil
Nikola
Nikolov
chacha
kuba
samba
brazil
vienski
avstrija
Marta
Martovska
samba
brazil
bachata
dominikana
angliski
anglija
dominikana
```
**Expected output:**

```text
Aleks Aleksov, merengue
Marta Martovska, bachata
```
