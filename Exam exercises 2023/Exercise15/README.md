# Exercise 15 - StudentKurs


A part of the definition of the class `StudentKurs` is given. For each student attending a course, information is stored about their **name** (character array), **written exam grade** (integer), and **whether the student wants to take an oral examination** (boolean variable).

The grade for the written part is a value from `1` to `MAX`. `MAX` has an initial value of `10`, which is the same for all students, and it can be changed using the appropriate `setMAX()` function. **(5 points)**

For students who want to take an oral examination, a descriptive grade is also given. Implement an appropriate class `StudentKursUsno` in which additional information about the descriptive grade from the oral examination is stored (dynamically allocated character array).

Descriptive grades can be: **`odlicen`**, **`dobro`**, **`losho`**, etc.

If the descriptive grade is `odlicen`, the final grade will be at most 2 grades higher than the written grade. If it is `dobro`, the grade will be at most 1 grade higher, and if it is `losho`, the grade will be 1 grade lower.

If the student receives any other descriptive grade, their grade remains the same as the written grade.

In the classes `StudentKurs` and `StudentKursUsno`, implement the necessary constructors, setter and getter functions, and destructor. **(5 points)**

For all objects of the classes, the following functions should be provided:

- **Overloaded `<<` operator** that prints information about the student attending the course in the following format:
  

```text
Ime --- ocenka
```
**(5 points)**
- `ocenka()` - returns the student's grade for the course. **(5 points)**

In the class StudentKursUsno, define the following function:

Overloaded `+= operator` for setting the student's descriptive grade. **(5 points)**
If an attempt is made to enter a descriptive grade that contains characters other than letters, an exception (an object of the class `BadInputException`) should be thrown.
Catch the exception in the main function where necessary.

After catching the exception, print the appropriate error message:
```text
Greshna opisna ocenka
```
Handle the exception by removing the non-letter characters from the string containing the descriptive grade.
For example, if the descriptive grade was:
```text
do1ba0r
```
it should be changed to:
```text
dobar
```
**(10 points)**
A part of the definition of the class `KursFakultet` is given. The class stores information about the **course name** (an array of 30 characters), the students enrolled in the course (an array of 20 pointers to the class `StudentKurs`), and the number of students enrolled in the course.
A student who has enrolled in a course passes the course if they have at least `MINOCENKA`.

The value `MINOCENKA` is a member of the class `StudentKurs` and has a fixed value of `6`, which cannot be changed. **(5 points)**
In the class `KursFakultet`, implement the following functions:

- `pecatiStudenti()` - prints all students who have passed the course, each on a separate line. Before the list, the first line should be:

```text
Kursot XXXXX go polozile:
```
**(5 points)**

- `postaviOpisnaOcenka(char *ime, char *opisnaOcenka)` - sets a descriptive grade for the student in the course with the given name. If this is not possible, the function does nothing. **(15 points)**
- Complete Functionality
The complete functionality of the implemented classes and functions should work correctly. **(5 points)**


# Задача 15 - StudentKurs

Дадена е дел од дефиниција на класата `StudentKurs`. За секој студент кој слуша некој курс се чуваат информации за неговото **име** (низа од знаци), **оценка од писмен дел** (цел број) и **дали студентот сака да биде испрашуван и усно** (булова променлива).

Оцената за писмениот дел е вредност од `1` до `MAX`. `MAX` има почетна вредност `10` која е иста е за сите и може да се промени со соодветна функција `setMAX()`. **(5 поени)**

Кај оние студенти кои сакаат да бидат испрашувани усно се добива и описна оценка. Имплементирај соодветна класа `StudentKursUsno` во која се чуваат дополнителни информации за описна оценка на усното испрашување (динамичко алоцирана низа од знаци).

Описни оценки може да бидат: **`odlicen`**, **`dobro`**, **`losho`**....

Ако описната оценка е `odlicen`, тогаш оцената ќе биде најмногу за оценки 2 повисока од оценката од писмениот дел, ако е `dobro` оценката ќе биде најмногу за 1 повисока, а ако е `losho` за 1 пониска.

Ако студентот добие некоја друга описна оценка, неговата оценка ќе остане иста со оценката од писмениот дел.

Во класите `StudentKurs` и `StudentKursUsno` треба да се имплементираат потребните конструктори, функции за поставување и преземање и деструктор. **(5 поени)**

За сите објекти од класите треба да се обезбедат следните функции:

- **Преоптоварен оператор `<<`** во кој се печатат информации за студентот на курсот во формат:

```text
Ime --- ocenka
```

**(5 поени)**
- `ocenka()` - ја враќа оценката на студентот на курсот. **(5 поени)**

Во класата StudentKursUsno дефинирај ја функцијата:

Преоптоварен `оператор +=` за поставување на описна оценка на студентот. **(5 поени)**
Ако се направи обид да се внесе описна оценка во која покрај букви има и други знаци, треба да се фрли исклучок (објект од класата `BadInputException`).
Фатете го исклучокот во главната функција каде што е потребно.

Откако ќе го фатите, отпечатете соодветна порака за грешка:
```text
Greshna opisna ocenka
```
и справете се со исклучокот така што тие знаци ќе се отстранат од стрингот со описната оценка.
Ако описната оценка била:
```text
do1ba0r
```
ќе се промени во:
```text
dobar
```
**(10 поени)**
Дадена е дел од дефиницијата на класата `KursFakultet` во која се чуваат информаци за **името** на курсот (низа од 30 знаци) и за студентите запишани на курсот (низа од 20 покажувачи кон класата`StudentKurs`), како и бројот на студенти запишани на курсот.
Еден студент кој запишал некој курс ќе го положи курсот ако има барем `MINOCENKA`.

Вредноста `MINOCENKA` е членка на класата `StudentKurs` и има фиксна вредност `6` која не може да се промени. **(5 поени)**
Во класата `KursFakultet` имплементирај ги функциите:

- `pecatiStudenti()` - во која се печатат сите студенти кои го положиле курсот, секој во посебен ред. Претходно во првиот ред се печати:

```text
Kursot XXXXX go polozile:
```
**(5 поени)**

- `postaviOpisnaOcenka(char *ime, char *opisnaOcenka)` - во која на студентот на курсот со даденото име му се поставува описна оценка. Ако тоа не е можно, функцијата не прави ништо. **(15 поени)**
- Комплетна функционалност
Целосната функционалност на имплементираните класи и функции треба да работи правилно. **(5 поени)**


## Test Cases


### Test case 1

###  Input:
```text	
2
Tanja 4 0
Vasko 8 1
2
Vasko do7br4o
Ana losho
```

### Expected output:
```text
Greshna opisna ocenka
Kursot OOP go polozile:
Vasko --- 9
```



###  Test case 2

### Input:
```text
2
Tanja 4 0
Vasko 8 1
1
Vasko do7br4o
```

### Expected output:
```text
Greshna opisna ocenka
Kursot OOP go polozile:
Vasko --- 9
```



### Test case 3

### Input:
```text
2
Tanja 4 0
Vasko 9 1
1
Vasko dobro
```

### Expected output:
```text
Kursot OOP go polozile:
Vasko --- 9
```



### Test case 4

### Input:
```text	
2
Tanja 4 1
Vasko 9 0
1
Tanja odlicen
```

### Expected output:
```text
Kursot OOP go polozile:
Tanja --- 6
Vasko --- 9
```



### Test case 5

### Input:
```text
2
Tanja 4 0
Vasko 9 0
0
```

### Expected output:
```text
Kursot OOP go polozile:
Vasko --- 9
```



### Test case 6

### Input:
```text
2
Tanja 4 0
Vasko 9 1
1
Vasko losho
```

### Expected output:
```text
Kursot OOP go polozile:
Vasko --- 8
```


