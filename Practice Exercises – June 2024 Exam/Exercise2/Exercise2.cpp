#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <iomanip>

using namespace std;

class InvalidCodeFormatException : public exception {
private:
    string code;
public:
    InvalidCodeFormatException(string c = "") : code(c) {}
    
    void message() const {
        cout << "The code " << code << " is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA." << endl;
    }
};

class Doctor {
protected:
    string name;
    string surname;
    string code;

public:
    Doctor(string name = "", string surname = "", string code = "") {
        if (code.length() != 8 || code.find(',') != string::npos) {
            throw InvalidCodeFormatException(code);
        }
        this->name = name;
        this->surname = surname;
        this->code = code;
    }

    virtual ~Doctor() {}

    virtual float calculateSalary() = 0;
    virtual void print() = 0;
};

class GeneralDoctor : public Doctor {
private:
    int numberOfPatients;

public:
    GeneralDoctor(string name = "", string surname = "", string code = "", int numberOfPatients = 0)
        : Doctor(name, surname, code) {
        this->numberOfPatients = numberOfPatients;
    }

    float calculateSalary() override {
        float base = 45000;
        int bonus = (numberOfPatients / 10) * 3000;
        float gross = base + bonus;
        return gross * 0.93; 
    }

    void print() override {
        float sal = calculateSalary();
        cout << "General Doctor: " << name << " " << surname << " CODE:" << code 
             << " Salary: " << sal << endl;
    }
};


class Specialist : public Doctor {
private:
    string specialty;
    int numberOfInterventions;
    int yearsOfExperience;

public:
    Specialist(string name = "", string surname = "", string code = "", string specialty = "", int numberOfInterventions = 0, int yearsOfExperience = 0)
        : Doctor(name, surname, code) {
        this->specialty = specialty;
        this->numberOfInterventions = numberOfInterventions;
        this->yearsOfExperience = yearsOfExperience;
    }

    float calculateSalary() override {
        float base = 55000;
        float interventionBonus = numberOfInterventions * 85;
        float experienceBonus = yearsOfExperience * (base * 0.05);
        float gross = base + interventionBonus + experienceBonus;
        return gross * 0.93; 
    }

    void print() override {
        float sal = calculateSalary();
        cout << "Specialist: " << name << " " << surname << " CODE:" << code 
             << " " << specialty << " Salary: " << sal << endl;
    }
};


void findDoctorsPercentage(Doctor **doctors, int n) {
    if (n == 0) return;
    int countSpecialists = 0;
    int countGeneral = 0;

    for (int i = 0; i < n; i++) {
        if (dynamic_cast<Specialist*>(doctors[i]) != nullptr) {
            countSpecialists++;
        } else if (dynamic_cast<GeneralDoctor*>(doctors[i]) != nullptr) {
            countGeneral++;
        }
    }

    double specPercentage = ((double)countSpecialists / n) * 100;
    double genPercentage = ((double)countGeneral / n) * 100;

    cout << specPercentage << "% of the doctors are specialists and " << genPercentage << "% are general doctors." << endl;
}

int main()
{
    int testCase, n;
    string name, surname, specialty, code;
    int numberOfPatients, yearsOfExperience, numberOfInterventions;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "TESTING GENERAL DOCTOR CLASS" << endl;
        Doctor *d = new GeneralDoctor("John", "Smith", "236XY@2B", 120);
        Doctor *d1 = new GeneralDoctor("Marco", "Brown", "345X!Y2B", 120);
        Doctor *d2 = new GeneralDoctor("Emily", "Johnson", "ABCD123@", 230);
        d->print();
        d1->print();
        d2->print();
      
        cout << "GENERAL DOCTOR CLASS OK!" << endl;
        delete d;
        delete d1;
        delete d2;
    }
    else if (testCase == 2)
    {
        cout << "TESTING SPECIALIST DOCTOR CLASS" << endl;
        Doctor *d = new Specialist("Beth", "Davis", "96Tr$$33", "Cardiologist", 45, 5);
        Doctor *d1 = new Specialist("William", "Wilson", "785#Qy2B", "Pulmonologist", 50, 7);
        Doctor *d2 = new Specialist("Micheal", "Rosen", "7896YZ$s", "Radiologist", 41, 10);
        d->print();
        d1->print();
        d2->print();
        cout << "SPECIALIST DOCTOR CLASS OK!" << endl;
        delete d;
        delete d1;
        delete d2;
    }
    else if (testCase == 3)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new GeneralDoctor("John", "Smith", "23Y@2B", 120);
            d->print();
            delete d;
        } catch (const InvalidCodeFormatException &e) {
            e.message();
        }
       
        cout << "EXCEPTION HANDLING OK!" << endl;
    }
    else if (testCase == 4)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
            delete d;
        } catch (const InvalidCodeFormatException &e) {
            e.message();
        }
        cout << "EXCEPTION HANDLING OK!" << endl;
    }
    else if (testCase == 5)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
            delete d;
        } catch (const InvalidCodeFormatException &e) {
            e.message();
        }
      
        try {
            Doctor *d1 = new Specialist("William", "Wilson", "785#Qy2B", "Pulmonologist", 50, 7);
            d1->print();
            delete d1;
        } catch (const InvalidCodeFormatException &e) {
            e.message();
        }
      
        try {
            Doctor *d2 = new Specialist("Beth", "Davis", "96Tr,", "Cardiologist", 45, 5);
            d2->print();
            delete d2;
        } catch (const InvalidCodeFormatException &e) {
            e.message();
        }
      
        cout << "EXCEPTION HANDLING OK!" << endl;
    }
    else
    {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION!" << endl;
        cin >> n;
        Doctor **doctors = new Doctor *[n];
        int validCount = 0;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            cin >> name >> surname;
            cin >> code;
            if (t == 1) 
            {
                cin >> numberOfPatients;
                try {
                    doctors[validCount] = new GeneralDoctor(name, surname, code, numberOfPatients);
                    validCount++;
                } catch (const InvalidCodeFormatException &e) {
                    e.message();
                }
            }
            else 
            {
                cin >> specialty;
                cin >> numberOfInterventions >> yearsOfExperience;
                try {
                    doctors[validCount] = new Specialist(name, surname, code, specialty, numberOfInterventions, yearsOfExperience);
                    validCount++;
                } catch (const InvalidCodeFormatException &e) {
                    e.message();
                }
            }
        }
        cout << "LIST OF ALL DOCTORS: " << endl;
        for (int i = 0; i < validCount; i++)
        {
            doctors[i]->print();
        }
        findDoctorsPercentage(doctors, validCount);
        for (int i = 0; i < validCount; i++)
        {
            delete doctors[i];
        }
        delete[] doctors;
    }
    return 0;
}
