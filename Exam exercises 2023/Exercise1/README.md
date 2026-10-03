# Exam exercise 1 - FINKI-Education

## Description

FINKI-Education publishing house issues online and printed books. For each book, information about the ISBN number (array of max 20 characters), title (array of max 50 characters), author (array of max 30 characters), and base price expressed in $ (real number) is stored. The class for describing books is abstract. **(5 points)**

For each `online book`, additional data is stored for the URL from which it can be downloaded (dynamically allocated character array) and the size expressed in MB (integer). For each `printed book`, additional data is stored for the weight expressed in kilograms (real number) and whether it is in stock (boolean). **(5 points)**

For each object of the two derived classes, the following methods should be available:

- Method `bookPrice`, for calculating the selling price of the book in the following way: **(10 points)**
  - For an online book - the price is increased by 20% of the base price if the book is larger than 20MB.
  - For a printed book - the price is increased by 15% of the base price if the weight of the book is greater than 0.7kg.
- Overloaded operator `>` for comparing two books of any type according to their price. **(5 points)**
- Overloaded operator `<<` for printing the book data in the specified format. **(5 points)**

Implement the function `mostExpensiveBook` with the following signature:

void mostExpensiveBook(Book** books, int n)
which prints the total number of online and printed books in the given array separately. **(5 points)** Then, the most expensive book is found and printed. **(5 points)**

Provide all necessary functions for the proper functioning of the program. **(5 points)**


## Опис на задача

Издавачката куќа `FINKI-Education` издава онлајн и печатени книги. За секоја книга се чуваат податоци за ISBN бројот (низа од најмногу 20 знаци), насловот (низа од најмногу 50 знаци), авторот (низа од најмногу 30 знаци) и основната цена изразена во $ (реален број). Класата за опишување на книгите е апстрактна **(5 поени)**.

За секоја `онлајн книга` дополнително се чуваат податоци за url од каде може да се симне (динамички резервирана низа од знаци) и големината изразена во MB (цел број). За секоја `печатена книга` дополнително се чуваат податоци за масата изразена во килограми (реален број) и дали ја има на залиха (логичка променлива). **(5 поени)**

За секој објект од двете изведени класи треба да бидат на располагање следниве методи:

- Метод `bookPrice`, за пресметување на продажната цена на книгата на следниот начин: **(10 поени)**
  - За онлајн книга - цената се зголемува за 20% од основната цена ако книгата е поголема од 20MB.
  - За печатена книга - цената се зголемува за 15% од основната цена ако масата на книгата е поголема од 0.7kg.
- Преоптоварен оператор `>` за споредба на две книги од каков било вид според нивната цена. **(5 поени)**
- Преоптоварен оператор `<<` за печатење на податоците за книгите во формат. **(5 поени)**

Да се имплементира функција `mostExpensiveBook` со потпис:

void mostExpensiveBook(Book** books, int n)

во која се печати вкупниот број на онлајн, односно, печатени книги во проследената низа посебно.  **(5 поени)**  Потоа се наоѓа и печати најскапата книга.  **(5 поени)**
Да се обезбедат сите потребни функции за правилно функционирање на програмата.  **(5 поени)**


## Test Cases:
  For example:

### Test Case 1
**Input:**

```text
4
3
1
0-312-31677-1
The Moscow Vector
Robert Ludlum
7
www.finki-education/olinebooks/book1.pdf
1
2
007-6092006565
Thinking in C++
Bruce Eckel
52
1.2
1
1
978-0672326974
C++ Primer Plus
Stephen Prata
20
www.finki-education/olinebooks/book2.pdf
30
```

Result

```text
====== Testing method mostExpensiveBook() ======
FINKI-Education
Total number of online books: 2
Total number of print books: 1
The most expensive book is: 
007-6092006565: Thinking in C++, Bruce Eckel 59.8

```

### Test Case 2
**Input:**

```text
	
2
978-0672326974
C++ Primer Plus
Stephen Prata
20
www.finki-education/olinebooks/book2.pdf
30
000-0672326974
111-0672326974
```

**Expected Output:**

```text
====== Testing OnlineBook CONSTRUCTORS ======
CONSTRUCTOR
978-0672326974: C++ Primer Plus, Stephen Prata 24

COPY CONSTRUCTOR
978-0672326974: C++ Primer Plus, Stephen Prata 24

000-0672326974: C++ Primer Plus, Stephen Prata 24

OPERATOR =
000-0672326974: C++ Primer Plus, Stephen Prata 24

111-0672326974: C++ Primer Plus, Stephen Prata 24
```

### Test Case 3
**Input:**

```text	
3
2
007-6092006565
Thinking in C++
Bruce Eckel
52
1.2
1
978-1118823774
C++ for Dummies
Stephen R. Davis
21
2.2
10
```


**Expected Output:**
```text


====== Testing PrintBook class ======
CONSTRUCTOR
OPERATOR <<
007-6092006565: Thinking in C++, Bruce Eckel 59.8
CONSTRUCTOR
OPERATOR <<
978-1118823774: C++ for Dummies, Stephen R. Davis 24.15
OPERATOR >
Rezultat od sporedbata e:
007-6092006565: Thinking in C++, Bruce Eckel 59.8
```

### Test Case 4
**Input:**
```text
1
2
0-312-31677-1
The Moscow Vector
Robert Ludlum
7
www.finki-education/olinebooks/book1.pdf
1
978-0672326974
C++ Primer Plus
Stephen Prata
20
www.finki-education/olinebooks/book2.pdf
30
```

**Expected Output:**
```text

====== Testing OnlineBook class ======
CONSTRUCTOR
OPERATOR <<
0-312-31677-1: The Moscow Vector, Robert Ludlum 7
CONSTRUCTOR
OPERATOR <<
978-0672326974: C++ Primer Plus, Stephen Prata 24
OPERATOR >
Rezultat od sporedbata e:
978-0672326974: C++ Primer Plus, Stephen Prata 24
```
