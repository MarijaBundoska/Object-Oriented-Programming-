#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

void wtf() {
    ofstream fout("input.txt");
    string line;

    while (getline(cin, line)) {
        if (line == "----") {
            break;
        }

        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;

    while (getline(fin, line)) {
        cout << line << endl;
    }
}

class StudentFailedException {
private:
    string id;

public:
    StudentFailedException(string id) : id(id) {}

    string getMessage() const {
        return "Student with id " + id + " failed the course";
    }
};

class Student {
private:
    string index;
    string name;
    string surname;
    int points;

public:
    Student(string index = "", string name = "",
            string surname = "", int points = 0)
        : index(index), name(name), surname(surname), points(points) {}

    int grade() const {
        if (points < 50) {
            return 5;
        } else if (points < 60) {
            return 6;
        } else if (points < 70) {
            return 7;
        } else if (points < 80) {
            return 8;
        } else if (points < 90) {
            return 9;
        } else {
            return 10;
        }
    }

    string getIndex() const {
        return index;
    }

    int getPoints() const {
        return points;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << s.index << " " << s.name << " "
            << s.surname << " " << s.points
            << " Grade: " << s.grade();

        return out;
    }
};

class Results {
private:
    Student *students;
    int n;

public:
    Results() {
        students = nullptr;
        n = 0;
    }

    Results(const Results& other) {
        n = other.n;
        students = new Student[n];

        for (int i = 0; i < n; i++) {
            students[i] = other.students[i];
        }
    }

    Results& operator=(const Results& other) {
        if (this != &other) {
            delete[] students;

            n = other.n;
            students = new Student[n];

            for (int i = 0; i < n; i++) {
                students[i] = other.students[i];
            }
        }

        return *this;
    }

    Results& operator+=(const Student& s) {
        if (s.getPoints() < 50) {
            throw StudentFailedException(s.getIndex());
        }

        Student *temp = new Student[n + 1];

        for (int i = 0; i < n; i++) {
            temp[i] = students[i];
        }

        temp[n] = s;

        delete[] students;
        students = temp;
        n++;

        return *this;
    }

    Results withGrade(int grade) {
        Results result;

        for (int i = 0; i < n; i++) {
            if (students[i].grade() == grade) {
                result += students[i];
            }
        }

        return result;
    }

    bool isEmpty() const {
        return n == 0;
    }

    friend ostream& operator<<(ostream& out, const Results& r) {
        for (int i = 0; i < r.n; i++) {
            out << r.students[i] << endl;
        }

        return out;
    }

    ~Results() {
        delete[] students;
    }
};

int main() {
    wtf();

    Results results;

    // TODO your code here
    // TODO Read the students from the file and add them in `results`

    ifstream fin("input.txt");

    string index;
    string name;
    string surname;
    int points;

    while (fin >> index >> name >> surname >> points) {
        Student student(index, name, surname, points);

        try {
            results += student;
        }
        catch (StudentFailedException& e) {
            cout << e.getMessage() << endl;
        }
    }

    fin.close();

    // DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    int grade;
    cin >> grade;
    // DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    // TODO Save the results in the files output1.txt and output2.txt after this line

    ofstream fout1("output1.txt");
    fout1 << results;
    fout1.close();

    ofstream fout2("output2.txt");

    Results filtered = results.withGrade(grade);

    if (filtered.isEmpty()) {
        fout2 << "None" << endl;
    } else {
        fout2 << filtered;
    }

    fout2.close();

    // DO NOT MODIFY THE CODE BELOW

    cout << "All students:" << endl;
    rff("output1.txt");

    cout << "Grade report for grade " << grade << ": " << endl;
    rff("output2.txt");

    return 0;
}
