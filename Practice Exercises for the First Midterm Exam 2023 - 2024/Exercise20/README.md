## Exercise 20 - Family Doctor and Patient Management

Create a structure `Pacient` in the programming language `C++` containing the following fields: (5 points)

- Patient's first and last name (a string of maximum 100 characters)
- Whether the patient is health-insured (1 - yes, 0 - no)
- Number of medical examinations during the last month (integer)

Create a structure `MaticenDoktor` containing the following fields: (5 points)

- Doctor's name (a string of 100 characters)
- Number of patients (integer)
- List of patients (an array of maximum 200 elements of type `Pacient`)
- Examination price (decimal number)

Create a method `najuspesen_doktor` that receives an array of variables of type `MaticenDoktor` and their number. The method should print the name, earned amount, and number of examinations of the doctor who earned the highest amount from patients examined privately (those who are not health-insured). (10 points)

If two or more doctors have earned the same amount, print the doctor who has performed the highest total number of examinations during the last month. (20 points)

Functionality (5 points)

---

## Задача 20 - Матичен доктор и пациенти

Да се креира структура `Pacient` во програмскиот јазик `C++`, која треба да ги содржи следните полиња: (5 поени)

- Име и презиме на пациентот (низа од максимум 100 знаци)
- Дали е здравствено осигуран (1 - да, 0 - не)
- Број на прегледи во текот на последниот месец (цел број)

Да се креира структура `MaticenDoktor`, која во себе содржи: (5 поени)

- Име на докторот (низа од 100 знаци)
- Број на пациенти (цел број)
- Листа од пациенти (низа од максимум 200 елементи од структурата `Pacient`)
- Цена на преглед (децимален број)

Да се креира метода `najuspesen_doktor`, која прима низа од променливи од типот `MaticenDoktor` и нивниот број; и го печати името, заработената сума и бројот на прегледи на оној доктор кој заработил најголема сума од пациенти кои ги прегледувал приватно (не се здравствено осигурени). (10 поени)

Доколку два или повеќе доктори имаат иста сума, тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)

Функционалност (5 поени)





 ## Test Cases


### Test Case 1

**Input:**
```text
3
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Петко_Петковски
1
50.00
Ивановска_Цветанка 0 18
Д-р.Трајче_Трајчев
3
300.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10
Ивановска_Цветанка 0 3
```
**Expected output:**

```text
Д-р.Петко_Петковски 900.00 18
```




### Test Case 2

**Input:**
```text
2
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Трајче_Трајчев
3
300.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10
Ивановска_Цветанка 0 3
```
**Expected output:**

```text
Д-р.Трајче_Трајчев 900.00 13
```




### Test Case 3

**Input:**
```text
2
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Трајче_Трајчев
2
650.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10
```
**Expected output:**

```text
Д-р.Јованка_Јовановска 900.00 5
```
