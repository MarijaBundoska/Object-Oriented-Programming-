## Exercise 17 - Operating System Image Repository

The company **FINKI Cloud** needs a solution for managing image files of different operating systems used when setting up new servers. For this purpose, the following classes need to be defined:

### `OperativenSistem`

The class `OperativenSistem` should store the following data:

- Operating system name (dynamically allocated character array)
- Version (`float`)
- Type (enumeration with possible values `LINUX`, `UNIX`, `WINDOWS`)
- Size in GB (`float`)

Additionally, the class should define:

- Constructors with and without parameters
- Copy constructor
- Destructor
- Overloading of the `=` operator
- A method for printing the information - `void pecati()` (see the output from the test examples for the structure)
- A method for checking **equality** between two operating systems. Two operating systems are equal if they have the same name, version, type, and size - `bool ednakviSe(const OperativenSistem &os)`
- A method for comparing **versions** between two operating systems - `int sporediVerzija(const OperativenSistem &os)`, which returns 0 if the versions are the same, -1 if the version of the operating system passed as an argument is greater, and 1 otherwise.
- A method for checking whether two operating systems belong to the same **family**. Two operating systems belong to the same family if they have the same name and type - `bool istaFamilija(const OperativenSistem &sporedba)`

### `Repozitorium`

The class `Repozitorium` should store the following data:

- Repository name (an array of 20 characters)
- Dynamically allocated array of `OperativenSistem`
- Number of operating systems currently stored in the repository (`int`)

Additionally, the class should define:

- Constructor `Repozitorium(const char *ime)`
- Destructor
- Method `void pecatiOperativniSistemi()` which prints all operating systems that are part of the repository
- Method `void izbrishi(const OperativenSistem &operativenSistem)` which deletes the operating system passed as an argument, if it exists in the repository. The `ednakviSe` method should be used to compare two operating systems.
- Method for adding an operating system (`void dodadi(const OperativenSistem &nov)`) with the following behavior:
  - If an operating system from the same family already exists (the family-checking method should be used) and its version is older than the passed operating system, the existing operating system is replaced with the new one.
  - In all other cases, the passed operating system is added as an additional entry to the repository.

## Задача 17 - Репозиториум на оперативни системи

Фирмата **FINKI Cloud** има потреба од решение за управување со image датотеките од различните оперативни системи кои ги користат при сетирање на нови сервери. За таа цел потребно е да се дефинираат следниве класи:

### `OperativenSistem`

Во класата `OperativenSistem` треба да се чуваат следниве податоци:

- име на оперативниот систем (динамички алоцирана низа од знаци)
- верзија (`float`)
- тип (енумерација со можни вредности `LINUX`, `UNIX`, `WINDOWS`)
- големина (во GB) (`float`)

Дополнително, во рамките на класата потребно е да се дефинира:

- конструктори со и без параметри
- copy constructor
- destructor
- преоптоварување на операторот `=`
- метод за печатење на информациите - `void pecati()` (видете го излезот од тест примерите за структурата)
- метод за проверка на **еднаквост** помеѓу два оперативни системи (два оперативни системи се еднакви ако имаат исто име, верзија, тип и големина) - `bool ednakviSe(const OperativenSistem &os)`
- метод за споредба на **верзии** помеѓу два оперативни система - `int sporediVerzija(const OperativenSistem &os)`, кој ќе враќа 0 доколку верзиите се исти, -1 доколку верзијата на оперативниот систем од аргументот е поголема и 1 во преостанатиот случај.
- метод за проверка дали два оперативни системи се од иста **фамилија**. Два оперативни системи се од иста фамилија доколку имаат исто име и се од ист тип. `bool istaFamilija(const OperativenSistem &sporedba)`

### `Repozitorium`

Во класата `Repozitorium` треба да се чуваат следниве податоци:

- име на репозиториумот (низа од 20 знака)
- динамички алоцирана низа од `OperativenSistem`
- број на оперативни системи кои моментално се наоѓаат во репозиториумот (`int`)

Дополнително, во рамките на класата потребно е да се дефинира:

- конструктор `Repozitorium(const char *ime)`
- деструктор
- метод `void pecatiOperativniSistemi()` кој ќе ги печати сите оперативни системи кои се дел од репозиториумот
- метод `void izbrishi(const OperativenSistem &operativenSistem)` кој ќе го избрише оперативниот систем проследен како аргумент, доколку тој се наоѓа во репозиториумот. Да се користи методот `ednakviSe` за споредба на два оперативни система.
- метод за додавање на оперативен систем (`void dodadi(const OperativenSistem &nov)`) кој ќе го има следново однесување:
  - Доколку веќе постои оперативен систем од иста фамилија (да се користи методот за проверка на фамилија) кој е постар од проследениот оперативен систем, тогаш постоечкиот оперативен систем се заменува со новиот.
  - Во секој друг случај, проследениот оперативен систем се додава како дополнителен во репозиториумот.
 


## Test Cases


### Test Case 1

**Input:**
```text
FINKICloud
2
Ubuntu
17.04
1
2.25
Ubuntu
16.04
1
1.25
Ubuntu
14.04
1
1.25
```
**Expected output:**

```text
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
=====Brishenje na operativen sistem=====
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
```




### Test Case 2

**Input:**
```text
FINKICloud
2
Ubuntu
17.04
1
2.25
Ubuntu
16.04
1
1.25
Ubuntu
16.04
1
1.25
```
**Expected output:**

```text
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
=====Brishenje na operativen sistem=====
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
```





### Test Case 3

**Input:**
```text
FINKICloud
2
Ubuntu
16.04
1
1.25
Ubuntu
17.04
1
2.25
Ubuntu
12.04
1
2.25
```
**Expected output:**

```text
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
=====Brishenje na operativen sistem=====
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
```





### Test Case 4

**Input:**
```text
FINKICloud
4
Ubuntu
16.04
1
1.25
Windows
10
3
3.5
Fedora
27
1
2.25
FreeBSD
11
2
1.75
Fedora
25
1
2.25
```
**Expected output:**

```text
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
Ime: Windows Verzija: 10 Tip: 3 Golemina:3.5GB
Ime: Fedora Verzija: 27 Tip: 1 Golemina:2.25GB
Ime: FreeBSD Verzija: 11 Tip: 2 Golemina:1.75GB
=====Brishenje na operativen sistem=====
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
Ime: Windows Verzija: 10 Tip: 3 Golemina:3.5GB
Ime: Fedora Verzija: 27 Tip: 1 Golemina:2.25GB
Ime: FreeBSD Verzija: 11 Tip: 2 Golemina:1.75GB
```
