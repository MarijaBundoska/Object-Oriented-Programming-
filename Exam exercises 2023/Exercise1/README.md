# Exam exercise - FINKI-Education

## English Description
FINKI-Education publishing house issues online and printed books. For each book, information about the ISBN (array of max 20 characters), title (array of max 50 characters), 
  author (array of max 30 characters), and base price in $ (real number) is stored. The base class for describing books is abstract.

For each online book, additional data is kept for the download URL (dynamically allocated character array) and size in MB (integer).
For each printed book, additional data is kept for weight in kg (real number) and whether it is in stock (boolean).

Implement the following methods for derived classes:
- `bookPrice()`: Calculates the selling price (Online: +20% base price if size > 20MB; Printed: +15% base price if weight > 0.7kg).
- Operator `>`: Compares two books by selling price.
- Operator `<<`: Prints book details.
- Global function `mostExpensiveBook(Book** books, int n)`: Counts online and printed books, then prints details of the most expensive book.


## Испитна задача - FINKI-Education
Издавачката куќа FINKI-Education издава онлајн и печатени книги. За секоја книга се чуваат податоци за ISBN бројот (низа од најмногу 20 знаци), насловот (низа од најмногу 50 знаци),
авторот (низа од најмногу 30 знаци) и основната цена изразена во $ (реален број). Класата за опишување на книгите е апстрактна.

За секоја онлајн книга дополнително се чуваат податоци за url од каде може да се симне (динамички резервирана низа од знаци) и големината изразена во MB (цел број).
За секоја печатена книга дополнително се чуваат податоци за масата изразена во килограми (реален број) и дали ја има на залиха (логичка променлива).

За секој објект од двете изведени класи треба да бидат на располагање следниве методи:
- `bookPrice()`: Пресметување на продажната цена (Онлајн: +20% од основната цена ако е > 20MB; Печатена: +15% од основната цена ако е > 0.7kg).
- Преоптоварен оператор `>` за споредба на две книги според нивната цена.
- Преоптоварен оператор `<<` за печатење на податоците за книгите.
- Глобална функција `mostExpensiveBook(Book** books, int n)` која го печати вкупниот број на онлајн и печатени книги посебно, а потоа ја наоѓа и печати најскапата книга.

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

**Expected Output:**

```text

====== Testing method mostExpensiveBook() ======
FINKI-Education
Total number of online books: 2
Total number of print books: 1
The most expensive book is:
007-6092006565: Thinking in C++, Bruce Eckel 59.8
```

### Test Case 3
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

### Test Case 4
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

### Test Case 5
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
