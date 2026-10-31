## Exercise 16 - Working Hours of Employees

Define a structure `RabotnaNedela` that stores the number of working hours for each working day of the week (5 days) and the week number. Then define a structure `Rabotnik` that stores a name (an array of 50 characters) and an array of working weeks (maximum 4).

Implement the following functions:

- `int maxNedela(Rabotnik *r)` which, for the given employee, returns the number of the week with the highest number of working hours.
- `void table(Rabotnik *r, int n)` which prints a table for the array of employees in the following format:

**Example**

```text
Rab     1   2   3   4   Vkupno
Brianna 192 238 226 225 881
Ava     236 231 184 212 863
Matthew 236 235 219 243 933
Alyssa  240 254 217 228 939
Emma    247 205 204 242 898
```

In each row, the employee's name is printed along with the total number of working hours for each working week, as well as the total number of hours for all weeks. The data within each row is separated by a tab character `\t`.

## Задача  16 - Работни часови на вработени

Да се дефинира структура `RabotnaNedela` во која се чуваат бројот на работни часови за секој работен ден во неделата (5 дена) и број на неделата. Потоа да се дефинира структура `Rabotnik` за кој се чува име (низа од 50 знаци) и низа од работни недели (макс 4).

Да се имплементираат следните функции:

- `int maxNedela(Rabotnik *r)` која за проследениот работник ќе го врати бројот на неделата со најмногу работни часови.
- `void table(Rabotnik *r, int n)` која за низата од работници ќе отпечати приказ во следниот формат:

**Пример**

```text
Rab     1   2   3   4   Vkupno
Brianna 192 238 226 225 881
Ava     236 231 184 212 863
Matthew 236 235 219 243 933
Alyssa  240 254 217 228 939
Emma    247 205 204 242 898
```

каде во секој ред се печати името на работникот и вкупниот број на работни часови за секоја работна недела, како и вкупниот број на часови за сите недели. Во рамките на редот податоците се разделени со знак за табулатор `\t`.



## Test Cases


### Test Case 1

**Input:**
```text
  5
Brianna
35 33 42 42 40
31 57 52 54 44
56 32 51 52 35
43 39 34 54 55
Ava
44 47 44 50 51
30 46 59 36 60
39 32 35 31 47
44 38 41 46 43
Matthew
51 37 39 55 54
36 60 54 38 47
41 57 41 39 41
56 34 43 54 56
Alyssa
59 55 57 37 32
60 54 50 37 53
54 38 34 36 55
57 55 36 41 39
Emma
58 54 42 49 44
30 45 47 44 39
52 39 44 32 37
40 50 44 56 52
```
**Expected output:**

```text
TABLE
Rab\t1\t2\t3\t4\tVkupno
Brianna\t192\t238\t226\t225\t881
Ava\t236\t231\t184\t212\t863
Matthew\t236\t235\t219\t243\t933
Alyssa\t240\t254\t217\t228\t939
Emma\t247\t205\t204\t242\t898
MAX NEDELA NA RABOTNIK: Matthew
4
```




### Test Case 2

**Input:**
```text
10
Andrew
44 55 48 34 30
37 35 31 55 59
36 55 57 37 32
57 45 60 42 46
Mia
58 58 56 57 51
56 55 44 56 38
58 34 36 50 45
37 51 45 31 45
Natalie
50 59 42 33 43
44 30 48 38 59
53 34 53 52 31
40 45 44 41 59
John
37 43 39 59 49
51 60 49 60 33
40 38 58 39 46
42 33 31 42 60
Brianna
60 51 52 57 40
55 31 55 34 59
32 58 32 49 40
38 41 50 48 35
Samantha
40 35 45 55 38
39 31 56 55 40
55 46 38 36 32
46 31 56 47 57
Samantha
38 40 54 57 45
31 33 39 47 55
32 49 46 33 36
30 51 44 39 41
Ashley
32 39 49 31 38
45 54 41 45 55
41 59 47 35 30
45 43 40 37 53
Jacob
44 48 51 45 60
56 48 31 54 35
48 50 38 30 32
55 41 60 53 57
John
50 46 59 59 42
44 31 35 37 39
60 58 45 60 60
52 35 55 37 37
```
**Expected output:**

```text
TABLE
Rab\t1\t2\t3\t4\tVkupno
Andrew\t211\t217\t217\t250\t895
Mia\t280\t249\t223\t209\t961
Natalie\t227\t219\t223\t229\t898
John\t227\t253\t221\t208\t909
Brianna\t260\t234\t211\t212\t917
Samantha\t213\t221\t207\t237\t878
Samantha\t234\t205\t196\t205\t840
Ashley\t189\t240\t212\t218\t859
Jacob\t248\t224\t198\t266\t936
John\t256\t186\t283\t216\t941
MAX NEDELA NA RABOTNIK: Samantha
4
```




### Test Case 3

**Input:**
```text
20
Abigail
45 49 34 37 45
51 48 52 38 50
56 60 55 36 32
54 45 44 44 32
Jacob
36 30 32 44 42
36 54 38 38 46
45 58 36 32 36
38 50 54 44 46
Matthew
48 60 59 43 31
40 34 57 39 30
44 60 40 39 42
50 32 38 40 36
William
48 59 34 53 37
44 34 48 44 40
30 50 34 43 30
49 47 38 37 31
Abigail
47 41 49 50 33
36 31 50 34 36
44 34 45 59 55
52 46 30 50 39
John
59 44 40 42 31
31 54 44 41 36
44 42 54 47 50
40 60 32 39 41
Matthew
34 36 54 36 30
47 47 58 55 33
31 40 46 59 39
43 50 60 38 55
Ashley
35 41 43 37 59
31 50 43 38 54
32 33 30 53 54
45 46 32 33 60
Natalie
47 51 41 46 57
42 59 40 42 31
52 40 58 50 31
56 35 39 50 38
Emily
35 51 37 32 41
37 32 54 54 51
34 33 38 38 42
30 37 47 30 39
Madison
46 55 37 50 32
53 39 54 60 59
54 51 52 57 53
58 48 35 55 34
Chloe
53 51 41 53 50
41 44 44 44 50
57 35 56 53 46
47 35 33 38 55
Jonathan
58 41 59 53 44
44 47 43 53 39
31 56 35 48 52
57 57 54 60 41
Isabella
57 55 34 47 54
36 38 45 52 53
40 51 47 38 48
57 36 33 30 48
Jacob
58 37 37 40 35
34 44 56 54 49
39 52 46 40 60
53 35 53 34 45
Natalie
47 50 54 42 41
32 36 53 50 52
46 50 45 50 33
34 31 39 32 32
William
44 31 50 43 53
54 44 55 45 48
47 43 50 55 47
56 49 55 59 46
Nicholas
47 59 32 48 43
58 53 59 59 60
43 45 35 53 58
39 34 59 35 34
Michael
32 45 60 50 52
55 38 41 47 30
46 30 35 42 56
38 40 38 57 45
Emily
55 36 52 36 40
45 40 47 35 42
49 34 51 32 35
42 48 43 59 51
```
**Expected output:**

```text
TABLE
Rab\t1\t2\t3\t4\tVkupno
Abigail\t210\t239\t239\t219\t907
Jacob\t184\t212\t207\t232\t835
Matthew\t241\t200\t225\t196\t862
William\t231\t210\t187\t202\t830
Abigail\t220\t187\t237\t217\t861
John\t216\t206\t237\t212\t871
Matthew\t190\t240\t215\t246\t891
Ashley\t215\t216\t202\t216\t849
Natalie\t242\t214\t231\t218\t905
Emily\t196\t228\t185\t183\t792
Madison\t220\t265\t267\t230\t982
Chloe\t248\t223\t247\t208\t926
Jonathan\t255\t226\t222\t269\t972
Isabella\t247\t224\t224\t204\t899
Jacob\t207\t237\t237\t220\t901
Natalie\t234\t223\t224\t168\t849
William\t221\t246\t242\t265\t974
Nicholas\t229\t289\t234\t201\t953
Michael\t239\t211\t209\t218\t877
Emily\t219\t209\t201\t243\t872
MAX NEDELA NA RABOTNIK: Madison
3
```
