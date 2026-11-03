## Exercise 1 - Song and Festival Classes

Define a class `Song`. The class should store information about a song, specifically: title of the song (string), first and last name of the song's author (string), song's performer (string), and duration of the song (in seconds, integer).

For the class, define the necessary constructors, `set()` and `get()` methods, the input operator `>>`, and a method `void print(ofstream& out)`, for printing the song information to a file passed as an argument to the method (through the ofstream object). **(10 p.)**

Define a class `Festival`. The class should store information about a music festival, namely: name of the festival (string), city where the festival is held (string), date of the festival (string; format: day/month/year), as well as a list of songs registered for the festival (dynamically allocated array of objects of class `Song`, and an integer `n` indicating the size of the list).

For the class `Festival` implement:

- Required constructors and destructor **(5 p.)**
- Operator `-=` for deleting a song (object of the class `Song`) from the list. All songs with identical data (same: title, author, performer, and duration) as the song passed as an argument to the operator are deleted from the list. Before deletion, check if the list is empty to prevent attempting deletion from an empty list, printing an appropriate message: "Trying to delete from an empty list!". **(10 p.)**
- Method `void print(ofstream& out)` to print festival information to a file passed as an argument to the method (through the ofstream object). This method must call the `print` method of the class `Song` to print information about the list of songs. **(5 p.)**
- Input operator `>>` **(5 p.)**
- Method `Festival notFromAuthor(string author)` - which takes the first and last name of an author as an argument (a single string - `author`), and returns a new object of class `Festival` that contains only those songs in the list whose author is NOT `author`. **(5 p.)**

Enhance the `main` function with the following requirements:

- Read festival information from the file `vlezna.txt`. Each piece of data is on a separate line (first the information about the festival itself, then the number of registered songs, and finally the information about each song registered for the festival). The information is read directly into the `festival` object.
- Print all information about the festival and all songs to the file `izlezna1.txt`.
- Print information about only those songs whose author is NOT `author`, read from the initial code, to the file `izlezna2.txt`. **(10 p.)**

---

## Задача 1 - Класи Song и Festival

Да се дефинира класа `Song` во која ќе се чуваат информации за некоја песна, и тоа: наслов на песната (стринг), име и презиме на авторот на песната (стринг), изведувач на песната (стринг), времетраење на песната (во секунди, цел број).

За класата да се дефинираат потребните конструктори, `set()` и `get()` методи, оператор за читање `>>`, како и метод `void print(ofstream& out)`, за печатење на информациите за песната во датотека што се предава како аргумент на методот (преку ofstream објектот). **(10 п.)**

Да се дефинира класа `Festival` во која ќе се чуваат информации за некој музички фестивал, и тоа: име на фестивалот (стринг), град во којшто се одржува фестивалот (стринг), датум на одржување (стринг; формат: ден/месец/година), како и листа на песни пријавени за фестивалот (динамички алоцирана низа од објекти од класата `Song`, како и цел број `n` кој ја означува големината на листата).

За класата `Festival` да се имплементираат:

- Потребните конструктори и деструктор **(5 п.)**
- Оператор `-=` за бришење на песна (објект од класата `Song`) од листата. Од листата се бришат сите песни со идентични податоци (исти: наслов, автор, изведувач и времетраење) како песната што е предадена како аргумент на операторот. Пред да се изведе бришење, да се провери дали листата е празна (да се спречи обидот за бришење на објект од празна листа, со печатење на соодветна порака: „Trying to delete from an empty list!“). **(10 п.)**
- Метод `void print(ofstream& out)`, за печатење на информациите за фестивалот во датотека што се предава како аргумент на методот (преку ofstream објектот). Овој метод задолжително треба да го повика методот `print` од класата `Song`, за печатење на информациите за листата од песни. **(5 п.)**
- Оператор за читање `>>` **(5 п.)**
- Метод `Festival notFromAuthor(string author)` - кој како аргумент прима име и презиме на автор (еден стринг - `author`), а враќа нов објект од класата `Festival` кој во листата од песни ги содржи само оние песни чиј автор НЕ е `author`. **(5 п.)**

Дополнете ја `main` функцијата со следните барања:

- Од датотеката `vlezna.txt` прочитајте ги информациите за фестивалот. Секој податок се наоѓа во засебен ред (прво се зададени информациите за самиот фестивал, па бројот на пријавени песни, па на крајот и информациите за секоја песна што е пријавена за фестивалот). Информациите се вчитуваат директно во објектот `festival`.
- Во датотеката `izlezna1.txt` се печатат сите информации за фестивалот и сите песни.
- Во датотеката `izlezna2.txt` се печатат информациите само за оние песни чиј автор НЕ е авторот `author`, вчитан во почетниот код. **(10 п.)**






## Test Cases:

### Test Case 1
**Input:**

```text
Ohridski Trubaduri
Ohrid
30/08/2024
2
Usni na usni
Grigor Koprov
Toshe Proeski
215
Tvoeto pismo moja Biblija
Damir Imeri
Andrijana Janevska
198
----
Grigor Koprov
```

Result

```text
All the data for the festival:
Ohridski Trubaduri
Ohrid
30/08/2024
2
Usni na usni
Grigor Koprov
Toshe Proeski
215
Tvoeto pismo moja Biblija
Damir Imeri
Andrijana Janevska
198
Songs NOT from the author Grigor Koprov:
Ohridski Trubaduri
Ohrid
30/08/2024
1
Tvoeto pismo moja Biblija
Damir Imeri
Andrijana Janevska
198
```



### Test Case 2
**Input:**

```text
Empty Festival
No city
XX/XX/XXXX
0
----
Grigor Koprov
```

Result

```text
All the data for the festival:
Empty Festival
No city
XX/XX/XXXX
0
Songs NOT from the author Grigor Koprov:
Empty Festival
No city
XX/XX/XXXX
0
```




### Test Case 3
**Input:**

```text
Coachella Valley Music and Arts Festival
Indio, California
12/04/2024
3
Bohemian Rhapsody
Freddie Mercury
Queen
360
Shape of You
Ed Sheeran
Ed Sheeran
240
Billie Jean
Michael Jackson
Michael Jackson
300
----
Ed Sheeran
```

Result

```text
All the data for the festival:
Coachella Valley Music and Arts Festival
Indio, California
12/04/2024
3
Bohemian Rhapsody
Freddie Mercury
Queen
360
Shape of You
Ed Sheeran
Ed Sheeran
240
Billie Jean
Michael Jackson
Michael Jackson
300
Songs NOT from the author Ed Sheeran:
Coachella Valley Music and Arts Festival
Indio, California
12/04/2024
2
Bohemian Rhapsody
Freddie Mercury
Queen
360
Billie Jean
Michael Jackson
Michael Jackson
300
```



### Test Case 4
**Input:**

```text
Festival Name
City of Festival
25/06/2024
3
Song Title 1
Author 1
Singer 1
180
Song Title 2
Author 2
Singer 2
210
Song Title 3
Author 1
Singer 3
190
----
Author 1
```

Result

```text
All the data for the festival:
Festival Name
City of Festival
25/06/2024
3
Song Title 1
Author 1
Singer 1
180
Song Title 2
Author 2
Singer 2
210
Song Title 3
Author 1
Singer 3
190
Songs NOT from the author Author 1:
Festival Name
City of Festival
25/06/2024
1
Song Title 2
Author 2
Singer 2
210
```




### Test Case 5
**Input:**

```text
Glastonbury Festival
Pilton, Somerset, England
26/06/2024
10
Bohemian Rhapsody
Freddie Mercury
Queen
360
Shape of You
Ed Sheeran
Ed Sheeran
240
Billie Jean
Michael Jackson
Michael Jackson
300
Hey Jude
Paul McCartney
The Beatles
360
Stairway to Heaven
Jimmy Page
Led Zeppelin
480
Purple Rain
Prince
Prince and The Revolution
300
Imagine
John Lennon
John Lennon
180
Hotel California
Don Felder
Eagles
360
Smells Like Teen Spirit
Kurt Cobain
Nirvana
300
Thriller
Rod Temperton
Michael Jackson
420
----
Michael Jackson
```

Result

```text
All the data for the festival:
Glastonbury Festival
Pilton, Somerset, England
26/06/2024
10
Bohemian Rhapsody
Freddie Mercury
Queen
360
Shape of You
Ed Sheeran
Ed Sheeran
240
Billie Jean
Michael Jackson
Michael Jackson
300
Hey Jude
Paul McCartney
The Beatles
360
Stairway to Heaven
Jimmy Page
Led Zeppelin
480
Purple Rain
Prince
Prince and The Revolution
300
Imagine
John Lennon
John Lennon
180
Hotel California
Don Felder
Eagles
360
Smells Like Teen Spirit
Kurt Cobain
Nirvana
300
Thriller
Rod Temperton
Michael Jackson
420
Songs NOT from the author Michael Jackson:
Glastonbury Festival
Pilton, Somerset, England
26/06/2024
9
Bohemian Rhapsody
Freddie Mercury
Queen
360
Shape of You
Ed Sheeran
Ed Sheeran
240
Hey Jude
Paul McCartney
The Beatles
360
Stairway to Heaven
Jimmy Page
Led Zeppelin
480
Purple Rain
Prince
Prince and The Revolution
300
Imagine
John Lennon
John Lennon
180
Hotel California
Don Felder
Eagles
360
Smells Like Teen Spirit
Kurt Cobain
Nirvana
300
Thriller
Rod Temperton
Michael Jackson
420
```






