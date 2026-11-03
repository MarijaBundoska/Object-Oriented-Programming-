## Exercise 2 - Doctor Salaries and Invalid Code Format Exception

Define an abstract class **Doctor** that stores information about:

- The first name of the doctor (string)
- The last name of the doctor (string)
- Salary (decimal number)
- Code (string)

Within this class, define two pure virtual methods:

- `float calculateSalary()` - for calculating the salary of a doctor.
- `void print()` - for printing the information about a doctor.

**(5 points)**

The code for each doctor is exactly 8 characters long and must not contain a comma. If a doctor's code does not meet these conditions, throw an exception of class **InvalidCodeFormatException**. Handle the exception in the main program whenever attempting to create an object. Upon handling the exception, print an appropriate message.

**(15 points)**

From the class **Doctor**, derive two classes: **GeneralDoctor** and **Specialist**, representing a general doctor and a specialist, respectively.

For each general doctor, additionally store the number of patients (integer). For each specialist, additionally store their specialty (string), number of interventions (integer), and years of experience (integer).

**(5 points)**

Override the virtual methods appropriately in the derived classes. The printing format should be determined from the test examples, and the salary calculation is as follows:

- For **GeneralDoctor**: the base salary is 45,000 denars. Additionally, for every 10 patients, the doctor receives an additional 3,000 denars. Return the salary with a calculated personal tax of 7%.
- For **Specialist**: the base salary is 55,000 denars. For each intervention, specialists receive an additional 85 denars on top of the base salary. Additionally, for each year of work experience, specialists receive a 5% bonus of the base salary. Return the salary with a calculated personal tax of 7%.

**(10 points)**

Define a global function with the signature:

`void findDoctorsPercentage(Doctor **doctors, int n)`

The function takes an array of pointers to doctors and its size as arguments. It should print the percentage of specialists and the percentage of general doctors. The output format should be determined from the test examples.

**(15 points)**

---

## Задача 2 - Плати на доктори и исклучок за невалиден формат на код

Да се дефинира апстрактна класа **Doctor**, во која се чуваат информации за:

- Името на докторот (стринг)
- Презимето на докторот (стринг)
- Плата (децимален број)
- Код (стринг)

Во рамките на оваа класа да се дефинираат два чисто виртуелни методи:

- `float calculateSalary()` - за пресметка на платата на еден доктор.
- `void print()` - за печатење на информациите за еден доктор.

**(5 поени)**

Кодот на секој доктор е стринг со должина 8, кој не смее да содржи запирка. Доколку кодот на еден доктор не ги исполнува овие услови, да се фрли исклучок од класата **InvalidCodeFormatException**. Со исклучокот треба да се справите во главната програма, при секој обид за креирање објект. При справувањето со исклучокот да се испечати соодветна порака.

**(15 поени)**

Од класата **Doctor** да се изведат две класи: **GeneralDoctor** и **Specialist**, кои претставуваат матичен доктор и специјалист, соодветно.

За секој матичен доктор, дополнително се чува бројот на пациенти (цел број), а за секој специјалист дополнително се чува неговата специјалност (стринг), бројот на неговите интервенции (цел број) и години искуство (цел број).

**(5 поени)**

Во изведените класи соодветно да се препокријат виртуелните методи. Форматот за печатење да се види од тест-примерите, а пресметката на плата се прави на следниот начин:

- За **GeneralDoctor** - основна плата е 45000 денари. Дополнително, за секои 10 пациенти докторот добива по 3000 денари. Да се врати платата со пресметан персонален данок од 7%.
- За **Specialist** - основна плата е 55000 денари. За секоја интервенција, специјалистите добиваат по 85 денари плус на основната плата. Дополнително, за секоја година работно искуство, специјалистите добиваат по 5% бонус од основната плата. Да се врати платата со пресметан персонален данок од 7%.

**(10 поени)**

Да се дефинира глобална функција со потпис:

`void findDoctorsPercentage(Doctor **doctors, int n)`

Функцијата како аргументи прима низа од покажувачи кон доктори и нејзината големина. Треба да го испечати процентот на специјалисти и процентот на матични доктори. Форматот да се види од тест-примерите.

**(15 поени)**






## Test Cases:
  For example:

### Test Case 1
**Input:**

```text
1
```

Result

```text
TESTING GENERAL DOCTOR CLASS
General Doctor: John Smith CODE:236XY@2B Salary: 75330
General Doctor: Marco Brown CODE:345X!Y2B Salary: 75330
General Doctor: Emily Johnson CODE:ABCD123@ Salary: 106020
GENERAL DOCTOR CLASS OK!
```



### Test Case 2
**Input:**

```text
2
```

Result

```text
TESTING SPECIALIST DOCTOR CLASS
Specialist: Beth Davis CODE:96Tr$$33 Cardiologist Salary: 67494.8
Specialist: William Wilson CODE:785#Qy2B Pulmonologist Salary: 73005
Specialist: Micheal Rosen CODE:7896YZ$s Radiologist Salary: 79966
SPECIALIST DOCTOR CLASS OK!
```





### Test Case 3
**Input:**

```text
3
```

Result

```text
TESTING SPECIALIST DOCTOR CLASS
Specialist: Beth Davis CODE:96Tr$$33 Cardiologist Salary: 67494.8
Specialist: William Wilson CODE:785#Qy2B Pulmonologist Salary: 73005
Specialist: Micheal Rosen CODE:7896YZ$s Radiologist Salary: 79966
SPECIALIST DOCTOR CLASS OK!
```



### Test Case 4
**Input:**

```text
4
```

Result

```text
TESTING EXCEPTION HANDLING
The code 9,R$$334 is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
EXCEPTION HANDLING OK!
```






### Test Case 5
**Input:**

```text
5
```

Result

```text
TESTING EXCEPTION HANDLING
The code 9,R$$334 is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
Specialist: William Wilson CODE:785#Qy2B Pulmonologist Salary: 73005
The code 96Tr, is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
EXCEPTION HANDLING OK!
```



### Test Case 6
**Input:**

```text
6
7
1 John Smith 236XY@2B 120
2 Alice Johnson ABCD123@ Pediatrician 35 8
1 Michael Brown 345X!Y2B 150
2 Sarah Davis 785#Qy2B Cardiologist 42 6
1 Emily Wilson 96Tr$$33 200
2 William Parker 7896YZ$s Neurologist 38 10
1 Jessica Lee 1234ABCD 130
```

Result

```text
INTEGRATION TEST AND TESTING GLOBAL FUNCTION!
LIST OF ALL DOCTORS:
General Doctor: John Smith CODE:236XY@2B Salary: 75330
Specialist: Alice Johnson CODE:ABCD123@ Pediatrician Salary: 74376.8
General Doctor: Michael Brown CODE:345X!Y2B Salary: 83700
Specialist: Sarah Davis CODE:785#Qy2B Cardiologist Salary: 69815.1
General Doctor: Emily Wilson CODE:96Tr$$33 Salary: 97650
Specialist: William Parker CODE:7896YZ$s Neurologist Salary: 79728.9
General Doctor: Jessica Lee CODE:1234ABCD Salary: 78120
42.8571% of the doctors are specialists and 57.1429% are general doctors.
```





### Test Case 7
**Input:**

```text
6
10
1 John Smith 236XY@2B 120
2 Alice Johnson ABCD123@ Pediatrician 35 8
1 Michael Brown 345X!Y2B 150
2 Sarah Davis 785#Qy2B Cardiologist 42 6
1 Emily Wilson 96Tr$$33 200
2 William Parker 7896YZ$s Neurologist 38 10
1 Jessica Lee 1234ABCD 130
2 David Miller 4567PQR$ Surgeon 55 12
1 Olivia Taylor MNBV0987 180
2 Daniel Clark 8901XYZ$ Orthopedist 40 9
```

Result

```text
INTEGRATION TEST AND TESTING GLOBAL FUNCTION!
LIST OF ALL DOCTORS:
General Doctor: John Smith CODE:236XY@2B Salary: 75330
Specialist: Alice Johnson CODE:ABCD123@ Pediatrician Salary: 74376.8
General Doctor: Michael Brown CODE:345X!Y2B Salary: 83700
Specialist: Sarah Davis CODE:785#Qy2B Cardiologist Salary: 69815.1
General Doctor: Emily Wilson CODE:96Tr$$33 Salary: 97650
Specialist: William Parker CODE:7896YZ$s Neurologist Salary: 79728.9
General Doctor: Jessica Lee CODE:1234ABCD Salary: 78120
Specialist: David Miller CODE:4567PQR$ Surgeon Salary: 86187.8
General Doctor: Olivia Taylor CODE:MNBV0987 Salary: 92070
Specialist: Daniel Clark CODE:8901XYZ$ Orthopedist Salary: 77329.5
50% of the doctors are specialists and 50% are general doctors.
```



### Test Case 8
**Input:**

```text
6
15
1 John Smith 236XY@2B 120
1 Alice Johnson ABCD123@ 150
2 Michael Brown 345X!Y2B Gynecologist 45 7
1 Sarah Davis 785#Qy2B 180
2 Emily Wilson 96Tr$$33 Pediatrician 30 5
1 William Parker 7896YZ$s 130
2 Jessica Lee 1234ABCD Cardiologist 40 8
1 David Miller 4567PQR$ 200
2 Olivia Taylor MNBV0987 Surgeon 50 9
1 Daniel Clark 8901XYZ$ 140
2 Matthew White 5678QWE$ Orthopedist 35 6
1 Sophia Martinez /345ASD$ 170
2 Ethan Moore BVC6789 Neurologist 48 10
1 Lily Robinson XYZ12384 160
2 Benjamin Garcia PLM9876, Radiologist 42 7
```

Result

```text
INTEGRATION TEST AND TESTING GLOBAL FUNCTION!
The code BVC6789 is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
The code PLM9876, is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
LIST OF ALL DOCTORS:
General Doctor: John Smith CODE:236XY@2B Salary: 75330
General Doctor: Alice Johnson CODE:ABCD123@ Salary: 83700
Specialist: Michael Brown CODE:345X!Y2B Gynecologist Salary: 72609.8
General Doctor: Sarah Davis CODE:785#Qy2B Salary: 92070
Specialist: Emily Wilson CODE:96Tr$$33 Pediatrician Salary: 66309
General Doctor: William Parker CODE:7896YZ$s Salary: 78120
Specialist: Jessica Lee CODE:1234ABCD Cardiologist Salary: 74772
General Doctor: David Miller CODE:4567PQR$ Salary: 97650
Specialist: Olivia Taylor CODE:MNBV0987 Surgeon Salary: 78120
General Doctor: Daniel Clark CODE:8901XYZ$ Salary: 80910
Specialist: Matthew White CODE:5678QWE$ Orthopedist Salary: 69261.8
General Doctor: Sophia Martinez CODE:/345ASD$ Salary: 89280
General Doctor: Lily Robinson CODE:XYZ12384 Salary: 86490
38.4615% of the doctors are specialists and 61.5385% are general doctors.
```
