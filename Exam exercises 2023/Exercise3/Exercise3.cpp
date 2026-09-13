#include <iostream>
#include <cstring>
using namespace std;
class NoCourseException{
private:
    int index;
public:
    NoCourseException(int index){
        this->index = index;
    }
    void message() const{
        cout<<"Demonstratorot so indeks "<<index<<" ne drzi laboratoriski vezbi"<<endl;
    }
};
class Course{
private:
    char name[21];
    int credits;
public:
    Course(){
        strcpy(this->name, "");
        this->credits = 0;
    }
    Course(const char *name, int credits){
        strcpy(this->name, name);
        this->credits = credits;
    }
    bool operator==(const char *name) const{
        return strcmp(this->name,name)==0;
    }
    char const *getName() const{
        return name;
    }
    void print() const{
        cout<<name<<" "<<credits<<"ECTS";
    }
};
class Student{
protected:
    int index;
private:
    int *grades;
    int numGrades;

    void copy(const Student &s){
        this->index = s.index;
        this->numGrades = s.numGrades;
        this->grades = new int[s.numGrades];
        for(int i=0; i<numGrades; i++){
            this->grades[i] = s.grades[i];
        }
    }
public:
    Student(){
        index = 0;
        grades = nullptr;
        numGrades = 0;
    }
    Student(int index, int *grades, int numGrades){
        this->index = index;
        this->numGrades = numGrades;
        this->grades = new int[numGrades];
        for(int i=0; i<numGrades; i++){
            this->grades[i] = grades[i];
        }
    }
    Student(const Student &s){
        copy(s);
    }
    Student &operator=(const Student &s){
        if(this != &s){
            delete[] grades;
            copy(s);
        }
        return *this;
    }
    virtual int getPoints(){
        if(numGrades ==0)
            return 0;
        int counter = 0;
        for(int i=0; i<numGrades; i++){
            if(grades[i] > 5){
                counter++;
            }
        }
        return (counter * 100.0) / numGrades;
    }
    virtual void print() const{
        cout<<index;
    }
    virtual ~Student(){
        delete[] grades;
    }
};
class Lecturer{
protected:
    char *nameAndSurname;
private:
    Course courses[11];
    int numCourses;

    void copy(const Lecturer &l){
        this-> numCourses = l.numCourses;
        for(int i=0; i<numCourses; i++){
            this->courses[i] = l.courses[i];
        }
        this->nameAndSurname = new char[strlen(l.nameAndSurname)+1];
        strcpy(this->nameAndSurname, l.nameAndSurname);
    }
public:
    Lecturer(){
        nameAndSurname = new char[1];
        nameAndSurname[0] = '\0';
        numCourses = 0;
    }
    Lecturer(const char *nameAndSurname, Course *courses, int numCourses){
        this->numCourses = numCourses;
        for(int i=0; i<numCourses; i++){
            this->courses[i] = courses[i];
        }
        this->nameAndSurname = new char[strlen(nameAndSurname)+1];
        strcpy(this->nameAndSurname,nameAndSurname);
    }
    Lecturer(const Lecturer &l){
        copy(l);
    }
    Lecturer& operator=(const Lecturer &l){
        if(this != &l){
            delete[] nameAndSurname;
            copy(l);
        }
        return *this;
    }
    virtual ~Lecturer(){
        delete[] nameAndSurname;
    }
    int getNumCourses() const{
        return numCourses;
    }
    char * const getNameAndSurname() const{
        return nameAndSurname;
    }
    Course operator[](int i) const{
        if(i < numCourses && i >= 0){
            return courses[i];
        }else{
            return Course();
        }
    }
    virtual void print() const{
        cout<<nameAndSurname<<" (";
        for(int i=0; i<numCourses; i++){
            courses[i].print();
            if(i < numCourses -1){
                cout<<", ";
            }else{
                cout<<")";
            }
        }
    }
};
class Demonstrator : public Student, public Lecturer{
private:
    int numClasses;
public:
    Demonstrator(int index = 0, int *grades = nullptr, int numGrades = 0, const char *name ="",
                 Course *courses = nullptr, int numCourses = 0, int numClasses = 0):
                 Student(index, grades, numGrades), Lecturer(name, courses, numCourses){
        this->numClasses = numClasses;
    }
    int getPoints() override{
        if(getNumCourses() ==0){
            throw NoCourseException(index);
        }
        return (Student::getPoints() + (numClasses * 20) / getNumCourses());
    }
    void print() const override{
        Student:: print();
        cout<<": ";
        Lecturer::print();
    }
};
Student &getTopRankedStudent(Student **students, int n){
    Student *tmp = nullptr;
    int maxPoints = -1;
    for(int i=0; i<n; i++){
        try{
            int currentPoints = students[i]->getPoints();
            if(currentPoints > maxPoints){
                maxPoints = currentPoints;
                tmp = students[i];
            }
        }catch(NoCourseException &e){
            e.message();
        }
    }
    return *tmp;
}

void  printCourseDemonstrators(const char *courseName, Student **students, int n){
    for(int i=0; i<n; i++){
        Demonstrator *demo = dynamic_cast<Demonstrator*>(students[i]);
        if(demo != nullptr){
            for(int j=0; j<demo->getNumCourses(); j++){
                if((*demo)[j] == courseName){
                    demo -> print();
                    cout<<endl;
                    break;
                }
            }
        }
    }
}
int main(){
    Course courses[10];
    int index, courseCount, grades[20], grade, gradeCount, option, hours, credits;
    char courseName[20], fullName[50];

    cin >> option;

    if (option == 1) {
        cout << "-----TEST Demonstrator-----" << endl;
        cin >> index >> gradeCount;
        for (int i = 0; i < gradeCount; i++) {
            cin >> grade;
            grades[i] = grade;
        }
        cin >> fullName >> courseCount;
        for (int i = 0; i < courseCount; i++) {
            cin >> courseName >> credits;
            courses[i] = Course(courseName, credits);
        }
        cin >> hours;

        Demonstrator d(index, grades, gradeCount, fullName, courses, courseCount, hours);
        cout << "Objekt od klasata Demonstrator e kreiran";

    } else if (option == 2) {
        cout << "-----TEST pecati-----" << endl;
        cin >> index >> gradeCount;
        for (int i = 0; i < gradeCount; i++) {
            cin >> grade;
            grades[i] = grade;
        }

        Student s(index, grades, gradeCount);
        s.print();

    } else if (option == 3) {
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> index >> gradeCount;
        for (int i = 0; i < gradeCount; i++) {
            cin >> grade;
            grades[i] = grade;
        }
        Student s(index, grades, gradeCount);
        cout << "Broj na bodovi: " << s.getPoints() << endl;

    } else if (option == 4) {
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> index >> gradeCount;
        for (int i = 0; i < gradeCount; i++) {
            cin >> grade;
            grades[i] = grade;
        }
        cin >> fullName >> courseCount;
        for (int i = 0; i < courseCount; i++) {
            cin >> courseName >> credits;
            courses[i] = Course(courseName, credits);
        }
        cin >> hours;

        Demonstrator d(index, grades, gradeCount, fullName, courses, courseCount, hours);
        cout << "Broj na bodovi: " << d.getPoints() << endl;

    } else if (option == 5) {
        cout << "-----TEST pecati -----" << endl;
        cin >> index >> gradeCount;
        for (int i = 0; i < gradeCount; i++) {
            cin >> grade;
            grades[i] = grade;
        }
        cin >> fullName >> courseCount;
        for (int i = 0; i < courseCount; i++) {
            cin >> courseName >> credits;
            courses[i] = Course(courseName, credits);
        }
        cin >> hours;

        Demonstrator d(index, grades, gradeCount, fullName, courses, courseCount, hours);
        d.print();

    } else if (option == 6) {
        cout << "-----TEST Student i Demonstrator-----" << endl;
        cin >> index >> gradeCount;
        for (int i = 0; i < gradeCount; i++) {
            cin >> grade;
            grades[i] = grade;
        }
        cin >> fullName >> courseCount;
        for (int i = 0; i < courseCount; i++) {
            cin >> courseName >> credits;
            courses[i] = Course(courseName, credits);
        }
        cin >> hours;

        Student *s = new Demonstrator(index, grades, gradeCount, fullName, courses, courseCount, hours);
        s->print();
        cout << "\nBroj na bodovi: " << s->getPoints() << endl;
        delete s;

    } else if (option == 7) {
        cout << "-----TEST vratiNajdobroRangiran-----" << endl;
        int k, opt;
        cin >> k;
        Student **students = new Student*[k];
        for (int j = 0; j < k; j++) {
            cin >> opt;
            cin >> index >> gradeCount;
            for (int i = 0; i < gradeCount; i++) {
                cin >> grade;
                grades[i] = grade;
            }
            if (opt == 1) {
                students[j] = new Student(index, grades, gradeCount);
            } else {
                cin >> fullName >> courseCount;
                for (int i = 0; i < courseCount; i++) {
                    cin >> courseName >> credits;
                    courses[i] = Course(courseName, credits);
                }
                cin >> hours;
                students[j] = new Demonstrator(index, grades, gradeCount, fullName, courses, courseCount, hours);
            }
        }

        Student &best = getTopRankedStudent(students, k);
        cout << "Maksimalniot broj na bodovi e:" << best.getPoints();
        cout << "\nNajdobro rangiran:";
        best.print();

        for (int j = 0; j < k; j++) delete students[j];
        delete[] students;

    } else if (option == 8) {
        cout << "-----TEST pecatiDemonstratoriKurs-----" << endl;
        int k, opt;
        cin >> k;
        Student **students = new Student *[k];
        for (int j = 0; j < k; j++) {
            cin >> opt;
            cin >> index >> gradeCount;
            for (int i = 0; i < gradeCount; i++) {
                cin >> grade;
                grades[i] = grade;
            }
            if (opt == 1) {
                students[j] = new Student(index, grades, gradeCount);
            } else {
                cin >> fullName >> courseCount;
                for (int i = 0; i < courseCount; i++) {
                    cin >> courseName >> credits;
                    courses[i] = Course(courseName, credits);
                }
                cin >> hours;
                students[j] = new Demonstrator(index, grades, gradeCount, fullName, courses, courseCount, hours);
            }
        }
        char searchCourse[20];
        cin >> searchCourse;
        cout << "Demonstratori na " << searchCourse << " se:" << endl;
        printCourseDemonstrators(searchCourse, students, k);
        for (int j = 0; j < k; j++) delete students[j];
        delete[] students;
    }
    return 0;
}
