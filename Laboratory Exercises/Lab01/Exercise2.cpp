/* # Exercise 2 – Students and Courses

## Description

The purpose of this exercise is to practice working with **structures**, arrays, nested loops, and functions in C/C++.

Two structures are defined:

- **Student**, which stores information about a student, including the student's name, index number, the number of enrolled courses, and the course codes.
- **Course**, which stores information about a course, including its name, course code, and the number of enrolled students.

The program reads information about students and courses, counts how many students are enrolled in each course, and determines the most popular course by using a separate function.


# Задача 2 – Студенти и курсеви

## Опис

Целта на оваа задача е практична примена на **структури**, низи, вгнездени циклуси и функции во програмскиот јазик C/C++.

Дефинирани се две структури:

- **Student**, која ги чува податоците за еден студент, вклучувајќи го името, бројот на индекс, бројот на курсеви и кодовите на курсевите што ги слуша.
- **Course**, која ги чува податоците за еден курс, како што се името на курсот, кодот на курсот и бројот на студенти кои го посетуваат.

Програмата внесува информации за студентите и курсевите, пресметува колку студенти посетуваат секој курс и со помош на посебна функција го одредува најпопуларниот курс.

*/

#include <iostream>
using namespace std;

// Structure for storing student information
struct Student{
    char name[100];
    char index[20];
    int courseCodes[20];
    int numOfCourses;
};

// Structure for storing course information
struct Course{
    char name[100];
    int code;
    int numOfStudents;
};

// Returns the index of the most popular course
int getMostPopularCourse(Course courses[], int numOfCourses){

    int index = -1;
    int maxStudents = -1;

// Find the course with the largest number of enrolled students
    for(int i=0; i<numOfCourses; i++){

        if(courses[i].numOfStudents > maxStudents){

            maxStudents = courses[i].numOfStudents;
            index = i;
        }
    }
    return index;
}
int main(){
    int numOfStudents;
    int numOfCourses;

    cin>> numOfStudents >> numOfCourses;

    Student students[20];
    Course courses[20];

    // Read all courses and initialize the number of students to 0
    for(int i=0; i< numOfCourses; i++){

        cin>> courses[i].name;
        cin>> courses[i].code;

        courses[i].numOfStudents = 0;
    }

    // Read all the students and count how many students attend each course
    for(int i=0; i < numOfStudents; i++){

        cin>> students[i].name;
        cin>> students[i].index;
        cin>> students[i].numOfCourses;

        for(int j=0; j<students[i].numOfCourses; j++){
            cin>> students[i].courseCodes[j];

            // Compare the student's course code with all available courses
            for(int k=0; k<numOfCourses; k++) {
                if (students[i].courseCodes[j] == courses[k].code){
                    courses[k].numOfStudents++;
                }
            }
        }
    }

    // Find and print the most popular course
    int index = getMostPopularCourse(courses, numOfCourses);

    cout<<"Most popular course: "<<courses[index].name;

    return 0;
}



