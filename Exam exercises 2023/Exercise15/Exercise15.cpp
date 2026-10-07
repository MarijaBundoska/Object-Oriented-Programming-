#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

class BadInputException{
public:
    static void message(){
        cout<<"Greshna opisna ocenka\n";
    }
};

class StudentCourse{
protected:
    char name[30];
    int grade;
    bool hasViva;
    static int MAX;

private:
    void copyCourse(const StudentCourse &other){
        strcpy(this->name, other.name);
        this->grade = other.grade;
        this->hasViva = other.hasViva;
    }

public:
    StudentCourse(char *name, int finalExam){
        strcpy(this->name, name);
        this->grade = finalExam;
        this->hasViva = false;
    }

    StudentCourse(const StudentCourse &other){
        copyCourse(other);
    }

    StudentCourse &operator=(const StudentCourse &other){
        if(this != &other){
            copyCourse(other);
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, StudentCourse &course){
        out << course.name << " --- " << course.getGrade() << "\n";
        return out;
    }

    static void setMAX(int value){
        MAX = value;
    }

    char *getName(){
        return name;
    }

    virtual int getGrade(){
        return grade;
    }

    bool getHasViva(){
        return hasViva;
    }

    virtual ~StudentCourse(){}
};

class StudentCourseViva: public StudentCourse{
    char *descriptiveGrade;

public:
    StudentCourseViva(char *name, int grade): StudentCourse(name, grade){
        this->descriptiveGrade = new char[10];
        strcpy(this->descriptiveGrade, "opisna");
        this->hasViva = true;
    }

    StudentCourseViva(const StudentCourseViva &other): StudentCourse(other){
        this->descriptiveGrade = new char[10];
        strcpy(this->descriptiveGrade, other.descriptiveGrade);
        this->hasViva = true;
    }

    StudentCourse &operator+=(char *grade){
        for(int i = 0; i < strlen(grade); i++){
            if(!isalpha(grade[i])){
                throw BadInputException();
            }
        }

        delete[] descriptiveGrade;

        this->descriptiveGrade = new char[10];
        strcpy(this->descriptiveGrade, grade);

        return *this;
    }

    int getGrade(){
        int courseGrade = StudentCourse::getGrade();
        int add = 0;

        if(!strcmp(descriptiveGrade, "odlicen")){
            add = 2;
        } else if(!strcmp(descriptiveGrade, "dobro")){
            add = 1;
        } else if(!strcmp(descriptiveGrade, "losho")){
            add = -1;
        }
        else{
            return courseGrade;
        }

        return courseGrade + add < MAX ? courseGrade + add : MAX;
    }

    ~StudentCourseViva(){
        delete[] descriptiveGrade;
    }
};

class FacultyCourse{
private:
    char name[30];
    StudentCourse *students[20];
    int count;
    const static int MIN_GRADE = 6;

public:
    FacultyCourse(char *name, StudentCourse **students, int count){
        strcpy(this->name, name);

        for(int i = 0; i < count; i++){
            if(students[i]->getHasViva()){
                this->students[i] =
                        new StudentCourseViva(*dynamic_cast<StudentCourseViva*>(students[i]));
            }
            else{
                this->students[i] = new StudentCourse(*students[i]);
            }
        }

        this->count = count;
    }

    void printStudents(){
        cout << "Kursot " << name << " go polozile:\n";

        for(int i = 0; i < count; i++){
            if(students[i]->getGrade() >= MIN_GRADE){
                cout << *students[i];
            }
        }
    }

    void setDescriptiveGrade(char *name, char *descriptiveGrade){
        for(int i = 0; i < count; i++){
            if(students[i]->getHasViva() &&
               !strcmp(name, students[i]->getName())){

                *dynamic_cast<StudentCourseViva*>(students[i])
                        += descriptiveGrade;
            }
        }
    }

    ~FacultyCourse(){
        for(int i = 0; i < count; i++){
            delete students[i];
        }
    }
};

int StudentCourse::MAX = 10;

int main(){
    StudentCourse **array;

    int n, m, grade;
    char name[30], descriptive[10];
    bool hasViva;

    cin >> n;

    array = new StudentCourse*[n];

    for(int i = 0; i < n; i++){
        cin >> name;
        cin >> grade;
        cin >> hasViva;

        if(!hasViva)
            array[i] = new StudentCourse(name, grade);
        else
            array[i] = new StudentCourseViva(name, grade);
    }

    FacultyCourse programming("OOP", array, n);

    for(int i = 0; i < n; i++)
        delete array[i];

    delete[] array;

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> name >> descriptive;

        try{
            programming.setDescriptiveGrade(name, descriptive);
        }
        catch(BadInputException){

            BadInputException::message();

            char newDescriptive[10];
            int count = 0;

            for(int j = 0; j < strlen(descriptive); j++){
                if(descriptive[j] >= '0' &&
                   descriptive[j] <= '9')
                    continue;

                newDescriptive[count++] = descriptive[j];
            }

            newDescriptive[count] = '\0';

            programming.setDescriptiveGrade(name, newDescriptive);
        }
    }

    StudentCourse::setMAX(9);

    programming.printStudents();

    return 0;
}
