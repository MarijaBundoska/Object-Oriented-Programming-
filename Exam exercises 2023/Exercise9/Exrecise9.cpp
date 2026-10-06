#include <iostream>
#include <cstring>
using namespace std;
class Exception{
public:
    static void message(){
        cout<<"Ne moze da se vnese dadeniot trud\n";
    }
};
class Work{
    char type;
    int year;

    void copyWork(const Work &other){
        this->type = other.type;
        this-> year = other.year;
    }

public:
    Work(){
        this->type = 'A';
        this-> year = 0;
    }

    Work(char type, int year){
        this->type = type;
        this->year = year;
    }

    Work(const Work &other){
        copyWork(other);
    }

    Work &operator=(const Work &other){
        if(this != &other){
            copyWork(other);
        }
        return *this;
    }

    friend istream &operator>>(istream &in, Work &w){
        in>>w.type >> w.year;
        return in;
    }

    char getType(){
        return type;
    }

    int getYear(){
        return year;
    }

    ~Work(){}
};

class Student{
protected:
    char name[30];
    int index;
    int enrollmentYear;
    int *grades;
    int numberOfGrades;

    void copyStudent(const Student &other){
        strcpy(this->name, other.name);
        this->index = other.index;
        this->enrollmentYear = other.enrollmentYear;
        this->grades = new int[other.numberOfGrades];

        for(int i=0; i<other.numberOfGrades; i++) {
            this->grades[i] = other.grades[i];

            this->numberOfGrades = other.numberOfGrades;
        }
    }
public:
    Student(){
        strcpy(this->name, "name");
        this->index = this->enrollmentYear = this->numberOfGrades = 0;
        this->grades = nullptr;
    }

    Student(char *name, int index, int enrollmentYear, int *grades, int numberOfGrades){
        strcpy(this->name, name);
        this->index = index;
        this->enrollmentYear = enrollmentYear;
        this->grades = new int[numberOfGrades];

        for(int i=0; i<numberOfGrades; i++) {
            this->grades[i] = grades[i];

            this->numberOfGrades = numberOfGrades;
        }
    }

    Student(const Student &other){
        copyStudent(other);
    }

    Student &operator=(const Student &other){
        if(this != &other){
           delete[] grades;
            copyStudent(other);
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, Student &other){
        out<<other.index<<" "<<other.name<<" "<< other.enrollmentYear<<" "
        <<other.rank()<<"\n";
        return out;
    }

    int getIndex(){
        return index;
    }

    virtual double rank(){
        double sum = 0;

        for(int i=0; i<numberOfGrades; i++){
            sum+= grades[i];
        }
        return sum / numberOfGrades;
    }

    ~Student(){
        delete[] grades;
    }
};

class PhDStudent: public Student{
    Work *works;
    int numberOfWorks;
    static int conferencePoints;
    static int journalPoints;

    void copyPhDStudent(const PhDStudent &other){
        this->works = new Work[other.numberOfWorks];

        for(int i=0; i<numberOfWorks; i++){
            this->works[i] = works[i];
        }
        this->numberOfWorks = other.numberOfWorks;
    }
public:
    PhDStudent() : Student(){
        this->works = nullptr;
        this->numberOfWorks = 0;
    }

    PhDStudent(char *name, int index, int enrollmentYear, int *grades,
               int numberOfGrades, Work *works, int numberOfWorks)
               :Student(name, index, enrollmentYear, grades, numberOfGrades){
        this->works = new Work[numberOfWorks];

        for(int i=0; i<numberOfWorks; i++){
            try{
                works[i].getYear() < enrollmentYear ? throw Exception() : this->works[i] = works[i];
            }catch(Exception &e){
                e.message();
            }
        }
        this->numberOfWorks = numberOfWorks;
    }

    PhDStudent(const PhDStudent &other): Student(other){
        copyPhDStudent(other);
    }

    PhDStudent &operator=(const PhDStudent &other){
        if(this != &other){
            Student::operator=(other);
            delete[] works;
            copyPhDStudent(other);
        }
        return *this;
    }

    PhDStudent &operator+=(Work &work){
        if(work.getYear() < enrollmentYear){
            throw Exception();
        }

        Work *temp = new Work[numberOfWorks +1];

        for(int i=0; i<numberOfWorks; i++){
            temp[i] = works[i];
        }
        temp[numberOfWorks++] = work;

        delete[] works;

        this->works = new Work[numberOfWorks];

        for(int i=0; i<numberOfWorks; i++){
            works[i] = temp[i];
        }

        delete[] temp;
        return *this;
    }

    static void setConferencePoints(int points){
        conferencePoints = points;
    }

    static void setJournalPoints(int points){
        journalPoints = points;
    }

    double rank(){
        double currentRank = Student::rank();

        for(int i=0; i<numberOfWorks; i++){
            if(tolower(works[i].getType()) == 'c'){
                currentRank += conferencePoints;
            }
            else if(tolower(works[i].getType()) == 'j'){
                currentRank += journalPoints;
            }
        }
        return currentRank;
    }

    ~PhDStudent(){
        delete[] works;
    }
};

int PhDStudent::conferencePoints = 1;
int PhDStudent::journalPoints = 3;

int main(){
    int testCase;
    cin >> testCase;

    int year, index, numberOfGrades, workYear, numberOfStudents, numberOfWorks;
    int choice; // 0 for Student, 1 for PhDStudent
    char name[30];
    int grades[50];
    char type;
    Work works[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;

        cin >> name;
        cin >> index;
        cin >> year;
        cin >> numberOfGrades;

        for (int j = 0; j < numberOfGrades; j++)
            cin >> grades[j];

        Student student(name, index, year, grades, numberOfGrades);
        cout << student;

        cin >> name;
        cin >> index;
        cin >> year;
        cin >> numberOfGrades;

        for (int j = 0; j < numberOfGrades; j++)
            cin >> grades[j];

        cin >> numberOfWorks;

        for (int j = 0; j < numberOfWorks; j++) {
            cin >> type;
            cin >> workYear;

            Work work(type, workYear);
            works[j] = work;
        }

        PhDStudent phdStudent(
                name, index, year, grades,
                numberOfGrades, works, numberOfWorks
        );

        cout << phdStudent;
    }

    if (testCase == 2) {
        cout << "===== Testiranje na operatorot += ======" << endl;

        Student **students;

        cin >> numberOfStudents;
        students = new Student *[numberOfStudents];

        for (int i = 0; i < numberOfStudents; i++) {
            cin >> choice;
            cin >> name;
            cin >> index;
            cin >> year;
            cin >> numberOfGrades;

            for (int j = 0; j < numberOfGrades; j++)
                cin >> grades[j];

            if (choice == 0) {
                students[i] = new Student(
                        name, index, year, grades, numberOfGrades
                );
            }
            else {
                cin >> numberOfWorks;

                for (int j = 0; j < numberOfWorks; j++) {
                    cin >> type;
                    cin >> workYear;

                    Work work(type, workYear);
                    works[j] = work;
                }

                students[i] = new PhDStudent(
                        name, index, year, grades,
                        numberOfGrades, works, numberOfWorks
                );
            }
        }

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];

        Work work;
        cin >> index;
        cin >> work;

        bool found = false;

        try {
            for(int i = 0; i < numberOfStudents; i++) {
                if(students[i]->getIndex() == index &&
                   dynamic_cast<PhDStudent*>(students[i])) {

                    *dynamic_cast<PhDStudent*>(students[i]) += work;
                    found = true;
                }
            }
        }
        catch(Exception& e) {
            e.message();
        }

        if(!found)
            cout << "Ne postoi PhD student so indeks " << index << "\n";

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];
    }

    if (testCase == 3) {
        cout << "===== Testiranje na operatorot += ======" << endl;

        Student **students;

        cin >> numberOfStudents;
        students = new Student *[numberOfStudents];

        for (int i = 0; i < numberOfStudents; i++) {
            cin >> choice;
            cin >> name;
            cin >> index;
            cin >> year;
            cin >> numberOfGrades;

            for (int j = 0; j < numberOfGrades; j++)
                cin >> grades[j];

            if (choice == 0) {
                students[i] = new Student(
                        name, index, year, grades, numberOfGrades
                );
            }
            else {
                cin >> numberOfWorks;

                for (int j = 0; j < numberOfWorks; j++) {
                    cin >> type;
                    cin >> workYear;

                    Work work(type, workYear);
                    works[j] = work;
                }

                students[i] = new PhDStudent(
                        name, index, year, grades,
                        numberOfGrades, works, numberOfWorks
                );
            }
        }

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];

        Work work;
        cin >> index;
        cin >> work;

        try {
            for(int i = 0; i < numberOfStudents; i++) {
                if(students[i]->getIndex() == index &&
                   dynamic_cast<PhDStudent*>(students[i])) {

                    *dynamic_cast<PhDStudent*>(students[i]) += work;
                }
            }
        }
        catch(Exception& e) {
            e.message();
        }

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];
    }

    if (testCase == 4) {
        cout << "===== Testiranje na isklucoci ======" << endl;

        cin >> name;
        cin >> index;
        cin >> year;
        cin >> numberOfGrades;

        for (int j = 0; j < numberOfGrades; j++)
            cin >> grades[j];

        cin >> numberOfWorks;

        for (int j = 0; j < numberOfWorks; j++) {
            cin >> type;
            cin >> workYear;

            Work work(type, workYear);
            works[j] = work;
        }

        PhDStudent phdStudent(
                name, index, year, grades,
                numberOfGrades, works, numberOfWorks
        );

        cout << phdStudent;
    }

    if (testCase == 5) {
        cout << "===== Testiranje na isklucoci ======" << endl;

        Student **students;

        cin >> numberOfStudents;
        students = new Student *[numberOfStudents];

        for (int i = 0; i < numberOfStudents; i++) {
            cin >> choice;
            cin >> name;
            cin >> index;
            cin >> year;
            cin >> numberOfGrades;

            for (int j = 0; j < numberOfGrades; j++)
                cin >> grades[j];

            if (choice == 0) {
                students[i] = new Student(
                        name, index, year, grades, numberOfGrades
                );
            }
            else {
                cin >> numberOfWorks;

                for (int j = 0; j < numberOfWorks; j++) {
                    cin >> type;
                    cin >> workYear;

                    Work work(type, workYear);
                    works[j] = work;
                }

                students[i] = new PhDStudent(
                        name, index, year, grades,
                        numberOfGrades, works, numberOfWorks
                );
            }
        }

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];

        Work work;
        cin >> index;
        cin >> work;

        try {
            for(int i = 0; i < numberOfStudents; i++) {
                if(students[i]->getIndex() == index &&
                   dynamic_cast<PhDStudent*>(students[i])) {

                    *dynamic_cast<PhDStudent*>(students[i]) += work;
                }
            }
        }
        catch(Exception& e) {
            e.message();
        }

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];
    }

    if (testCase == 6) {
        cout << "===== Testiranje na static clenovi ======" << endl;

        Student **students;

        cin >> numberOfStudents;
        students = new Student *[numberOfStudents];

        for (int i = 0; i < numberOfStudents; i++) {
            cin >> choice;
            cin >> name;
            cin >> index;
            cin >> year;
            cin >> numberOfGrades;

            for (int j = 0; j < numberOfGrades; j++)
                cin >> grades[j];

            if (choice == 0) {
                students[i] = new Student(
                        name, index, year, grades, numberOfGrades
                );
            }
            else {
                cin >> numberOfWorks;

                for (int j = 0; j < numberOfWorks; j++) {
                    cin >> type;
                    cin >> workYear;

                    Work work(type, workYear);
                    works[j] = work;
                }

                students[i] = new PhDStudent(
                        name, index, year, grades,
                        numberOfGrades, works, numberOfWorks
                );
            }
        }

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];

        int conference, journal;
        cin >> conference;
        cin >> journal;

        PhDStudent::setConferencePoints(conference);
        PhDStudent::setJournalPoints(journal);

        cout << "\nLista na site studenti:\n";

        for (int i = 0; i < numberOfStudents; i++)
            cout << *students[i];
    }
    return 0;
}
