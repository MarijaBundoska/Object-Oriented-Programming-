# Exercise 13- Image, TransparentImage and Folder


### Problem Statement

Create a class representing an image (`Image`) within a computer. For each file, the following data is stored **(5 points)**:

- image name (dynamically allocated array of characters). By default, it is set to `untitled`.
- name of the user who owns the file (array of maximum 50 characters). By default, it is set to `unknown`.
- image dimensions (2 integers representing width and height in pixels). By default, they are set to 800.

Derive the class `TransparentImage` from the class `Image`, representing an image that supports transparency. For a transparent image, the following additional data is stored:

- whether it supports transparency levels (bool variable, by default it does not support transparency).

For the classes `Image` and `TransparentImage`, provide a method (`fileSize`) for calculating the image size (in bytes). The size is calculated in the following way **(5 points)**:

- for objects of class `Image`, the file size is equal to: `height * width * 3`.
- for `TransparentImage`, if it supports transparency levels, the file size is equal to `width * height * 4`. If it does not support transparency, the image size is calculated as `width * height + number_of_pixels_present_in_the_image / 8`.

For the classes `Image` and `TransparentImage`, overload the following operators **(5 points)**:

- operator `<<` which prints the file data in the following format:

  `file_name author file_size_in_bytes`

- operator `>` which compares images according to their size.

Define a class `Folder`, representing a directory in which images can be stored. For each folder, the following data is stored **(5 points)**:

- folder name (array of maximum 255 characters)
- name of the user who owns the folder (array of maximum 50 characters). By default, it is set to `unknown`.
- array of pointers to `Image` objects (maximum 100 within one folder).

Implement the following methods **(5 points)**:

- a method for calculating the size of the folder (`folderSize`). The size of the folder is the sum of the sizes of all images within the folder.
- a method for finding the largest image within the folder (`getMaxFile`). The method returns a pointer to the largest image in the folder (calculated in bytes).

For the class `Folder`, implement the `operator+=` which adds objects of type `Image`/`TransparentImage` to the folder **(5 points)**.

Create the following functionalities for the classes **(5 points)**:

- `operator<<` - which prints the folder data in the following format *(5 points)*:

  `folder_name owner --`  
  `1. image_name author file_size_in_bytes`  
  `2. image_name author file_size_in_bytes -- folder_size_in_bytes`

- `operator[]` - which returns a pointer to the corresponding image in the folder. If there is no image at that index, `NULL` should be returned **(5 points)**.

Create a global function `max_folder_size` which receives an array of objects of type `Folder` and returns the folder that occupies the most space (in bytes). **(5 points)**

Enable the proper functioning of the classes (required set or get methods/operators/constructors/destructors) according to the source code that is already provided. All data members of the classes are `protected`. **(5 points)**



# Вежба 13 - Слика, Транспарентна слика и Фолдер

### Опис на задачата

Да се креира класа која претставува слика (`Image`) во рамките на еден компјутер. За секоја датотека се чуваат **(5 поени)**:

- име на сликата (дин. алоцирана низа од знаци). Предефинирано поставено на `untitled`.
- име на корисникот кој е сопственик на датотеката (низа од макс. 50 знаци). Предефинирано поставено на `unknown`.
- димензии на сликата (2 цели броеви кои претставуваат ширина и висина во пиксели). Предефинирано поставени на 800.

Од класата `Image` да се изведе класата `TransparentImage`, која претставува слика која поддржува транспарентност. За транспарентна слика дополнително се чува:

- дали поддржува нивоа на транспарентност (bool променлива, предефинирано не поддржува транспарентност).

За класите `Image` и `TransparentImage` да биде достапна метода (`fileSize`) за пресметка на големината на сликата (во бајти). Големината се пресметува на следниот начин **(5 поени)**:

- за објектите од класата `Image`, големината на датотеката е еднаква на: `висината * ширината * 3`.
- за `TransparentImage`, доколку поддржува нивоа на транспарентност, големината на датотеката е еднаква на `ширина * висина * 4`. Доколку не поддржува транспарентност, големината на сликата се пресметува како `ширина * висина + бр._на_пиксели_присутни_во_сликата / 8`.

За класите `Image` и `TransparentImage` да се преоптоварат следниве оператори **(5 поени)**:

- оператор `<<` кој ги печати податоците од датотеката во следниот формат:

  `ime_fajl avtor golemina_na_fajlot_vo_bajti`

- оператор `>` кој ги споредува сликите според нивната големина.

Да се дефинира класа `Folder`, што репрезентира директориум во кој може да се поставуваат слики. За секој фолдер се чува **(5 поени)**:

- име на фолдерот (низа од макс 255 знаци)
- име на корисникот кој е сопственик на фолдерот (низа од макс. 50 знаци). Предефинирано поставено на `unknown`.
- низа од покажувачи кон `Image` објекти (макс. 100 во рамките на еден фолдер).

Да се имплементираат следниве методи **(5 поени)**:

- метода за пресметка на големината на фолдерот (`folderSize`). Големината на фолдерот е сума од големините од сите слики во рамките на фолдерот.
- метода за пронаоѓање на наголемата слика во рамките на фолдерот (`getMaxFile`). Методата враќа покажувач кон најголемата слика во фолдерот (сметано во бајти).

За класата `Folder` да се имплементира и `оператор +=` кој додава објекти од типот `Image`/`TransparentImage` во рамките на фолдерот **(5 поени)**.

Да се креираат следниве функционалности за класите **(5 поени)**:

- `operator <<` - со кој се печатат податоците за фолдерот во формат *(5 поени)*:

  `ime_folder sopstvenik --`  
  `1. ime_slika avtor golemina_na_fajlot_vo_bajti`  
  `2. ime_slika avtor golemina_na_fajlot_vo_bajti -- golemina_na_folder_vo_bajti`

- `operator []` - кој враќа покажувач кон соодветната слика во фолдерот. Доколку не постои слика на тој индекс, треба да се врати `NULL` **(5 поени)**.

Да се креира и глобална функција `max_folder_size` која го прима низа од објекти од типот `Folder` и го враќа фолдерот кој има зафаќа најмногу простор (во бајти). **(5 поени)**

Да се овозможи правилно функционирање на класите (потребни set или get методи/оператори/конструктори/деструктори) според изворниот код кој е веќе зададен. Сите податочни членови на класите се `protected`. **(5 поени)**



## Test Cases


### Test Case 1

**Input:**
```text
5
folder
user
1
2
image1
u1
100 100
1
1
2
image1
u1
100 100
0
0
```
**Expected output:**

```text
image1 u1 40000
```




### Test Case 2

**Input:**
```text
7
3
dd
uu
1
1
fileName1
user1
50 50
1
2
textfile
pero
100 100
1
1
2
textfile
kiro
100 100
0
0
directory2
ana
1
1
fajl
ana
10 10
0
oop
alek
0
```
**Expected output:**

```text
dd uu
--
fileName1 user1 7500
textfile pero 40000
textfile kiro 11250
--
Folder size: 58750
```




### Test Case 3

**Input:**
```text
4
folder
user
1
2
image1
u1
100 100
1
1
2
image1
u1
100 100
0
0
```
**Expected output:**

```text
folder user
--
image1 u1 40000
image1 u1 11250
--
Folder size: 51250
```




### Test Case 4

**Input:**
```text
1
filename
username
10
10
```
**Expected output:**

```text
untitled unknown 1920000
filename unknown 1920000
filename username 1920000
filename username 300
```




### Test Case 5

**Input:**
```text
3
folder
user
```
**Expected output:**

```text
folder user
--
--
Folder size: 0
```




### Test Case 6

**Input:**
```text
4
folder
user
1
1
image1
u1
1000 1000
1
1
image1
u1
100 100
0
```
**Expected output:**

```text
folder user
--
image1 u1 3000000
image1 u1 30000
--
Folder size: 3030000
```




### Test Case 7

**Input:**
```text
4
folder
user
1
1
image1
u1
100 100
1
2
image1
u1
10 10
0
0
```
**Expected output:**

```text
folder user
--
image1 u1 30000
image1 u1 112
--
Folder size: 30112
```



### Test Case 8

**Input:**
```text
6
dirName
user
1
1
image1
user1
100 100
1
2
trasnparentImage
pero
100 100
1
1
2
trasparentImage2
kiro
500 500
0
0
1
```
**Expected output:**

```text
trasnparentImage pero 40000

```




### Test Case 9

**Input:**
```text
2
transpImage
user
10
10
0
```
**Expected output:**

```text
untitled unknown 2560000
transpImage user 112
```




### Test Case 10

**Input:**
```text
	
6
dirName
user
1
1
image1
user1
100 100
1
2
trasnparentImage
pero
100 100
1
1
2
trasparentImage2
kiro
500 500
0
0
2
```
**Expected output:**

```text
trasparentImage2 kiro 281250
```



### Test Case 11

**Input:**
```text
5
folder
user
1
2
image1
u1
100 100
1
1
2
image1
u1
10 10
0
0
```
**Expected output:**

```text
image1 u1 40000
```
