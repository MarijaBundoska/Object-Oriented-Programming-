#include <iostream>
#include <cstring>
using namespace std;

class NoCourseException {
private:
    int indeks;

public:
    NoCourseException(int indeks) {
        this->indeks = indeks;
    }

    void message() {
        cout << "Demonstratorot so indeks " << indeks
             << " ne drzi laboratoriski vezbi" << endl;
    }
};

class Kurs {
private:
    char ime[20];
    int krediti;

public:
    Kurs(const char *ime = "", int krediti = 0) {
        strcpy(this->ime, ime);
        this->krediti = krediti;
    }

    bool operator==(const char *ime) const {
        return strcmp(this->ime, ime) == 0;
    }

    const char *getIme() const {
        return ime;
    }

    void pecati() const {
        cout << ime << " " << krediti << "ECTS";
    }
};

class Student {
protected:
    int indeks;

private:
    int *ocenki;
    int brojOcenki;

    void copy(const Student &s) {
        indeks = s.indeks;
        brojOcenki = s.brojOcenki;

        ocenki = new int[brojOcenki];

        for (int i = 0; i < brojOcenki; i++) {
            ocenki[i] = s.ocenki[i];
        }
    }

public:
    Student() {
        indeks = 0;
        ocenki = nullptr;
        brojOcenki = 0;
    }

    Student(int indeks, int *ocenki, int brojOcenki) {
        this->indeks = indeks;
        this->brojOcenki = brojOcenki;

        this->ocenki = new int[brojOcenki];

        for (int i = 0; i < brojOcenki; i++) {
            this->ocenki[i] = ocenki[i];
        }
    }

    Student(const Student &s) {
        copy(s);
    }

    Student &operator=(const Student &s) {
        if (this != &s) {
            delete[] ocenki;
            copy(s);
        }

        return *this;
    }

    virtual ~Student() {
        delete[] ocenki;
    }

    virtual int getBodovi() {
        if (brojOcenki == 0) {
            return 0;
        }

        int brojac = 0;

        for (int i = 0; i < brojOcenki; i++) {
            if (ocenki[i] > 5) {
                brojac++;
            }
        }

        return brojac * 100 / brojOcenki;
    }

    virtual void pecati() const {
        cout << indeks;
    }
};

class Predavach {
protected:
    char *imeIPrezime;

private:
    Kurs kursevi[11];
    int brojKursevi;

    void copy(const Predavach &p) {
        brojKursevi = p.brojKursevi;

        for (int i = 0; i < brojKursevi; i++) {
            kursevi[i] = p.kursevi[i];
        }

        imeIPrezime = new char[strlen(p.imeIPrezime) + 1];
        strcpy(imeIPrezime, p.imeIPrezime);
    }

public:
    Predavach() {
        imeIPrezime = new char[1];
        imeIPrezime[0] = '\0';
        brojKursevi = 0;
    }

    Predavach(const char *imeIPrezime, Kurs *kursevi,
              int brojKursevi) {
        this->brojKursevi = brojKursevi;

        for (int i = 0; i < brojKursevi; i++) {
            this->kursevi[i] = kursevi[i];
        }

        this->imeIPrezime =
            new char[strlen(imeIPrezime) + 1];

        strcpy(this->imeIPrezime, imeIPrezime);
    }

    Predavach(const Predavach &p) {
        copy(p);
    }

    Predavach &operator=(const Predavach &p) {
        if (this != &p) {
            delete[] imeIPrezime;
            copy(p);
        }

        return *this;
    }

    virtual ~Predavach() {
        delete[] imeIPrezime;
    }

    int getBrojKursevi() const {
        return brojKursevi;
    }

    char * const getImeIPrezime() const {
        return imeIPrezime;
    }

    Kurs operator[](int i) const {
        if (i >= 0 && i < brojKursevi) {
            return kursevi[i];
        }

        return Kurs();
    }

    virtual void pecati() const {
        cout << imeIPrezime << " (";

        for (int i = 0; i < brojKursevi; i++) {
            kursevi[i].pecati();

            if (i < brojKursevi - 1) {
                cout << ", ";
            }
        }

        cout << ")";
    }
};

class Demonstrator : public Student, public Predavach {
private:
    int brojCasovi;

public:
    Demonstrator(int indeks = 0, int *ocenki = nullptr,
                 int brojOcenki = 0, const char *ime = "",
                 Kurs *kursevi = nullptr, int brojKursevi = 0,
                 int brojCasovi = 0)
        : Student(indeks, ocenki, brojOcenki),
          Predavach(ime, kursevi, brojKursevi) {
        this->brojCasovi = brojCasovi;
    }

    int getBodovi() override {
        if (getBrojKursevi() == 0) {
            throw NoCourseException(indeks);
        }

        return Student::getBodovi()
               + (20 * brojCasovi) / getBrojKursevi();
    }

    void pecati() const override {
        Student::pecati();
        cout << ": ";
        Predavach::pecati();
    }
};

Student &vratiNajdobroRangiran(Student **studenti, int n) {
    int maxBodovi = 0;
    Student *najdobar = studenti[0];

    try {
        maxBodovi = studenti[0]->getBodovi();
    } catch (NoCourseException &) {
        maxBodovi = 0;
    }

    for (int i = 1; i < n; i++) {
        int bodovi = 0;

        try {
            bodovi = studenti[i]->getBodovi();
        } catch (NoCourseException &) {
            bodovi = 0;
        }

        if (bodovi > maxBodovi) {
            maxBodovi = bodovi;
            najdobar = studenti[i];
        }
    }

    return *najdobar;
}

void pecatiDemonstratoriKurs(char *kurs,
                            Student **studenti, int n) {
    for (int i = 0; i < n; i++) {
        Demonstrator *temp =
            dynamic_cast<Demonstrator *>(studenti[i]);

        if (temp != nullptr) {
            for (int j = 0; j < temp->getBrojKursevi(); j++) {
                if (temp->operator[](j) == kurs) {
                    temp->pecati();
                    cout << endl;
                    break;
                }
            }
        }
    }
}
