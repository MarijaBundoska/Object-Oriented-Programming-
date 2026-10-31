#include <iostream>
#include <cstring>
using namespace std;

class Participant {
private:
    char *ime;
    bool pol;
    int vozrast;

public:
    void copyParticipant(const Participant &other) {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->pol = other.pol;
        this->vozrast = other.vozrast;
    }

    Participant() {
        this->ime = new char[5];
        strcpy(this->ime, "ime");
        this->pol = false;
        this->vozrast = 0;
    }

    Participant(char *ime, bool pol, int vozrast) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->pol = pol;
        this->vozrast = vozrast;
    }

    Participant(const Participant &other) {
        copyParticipant(other);
    }

    Participant& operator=(const Participant &other) {
        if (this != &other) {
            delete[] this->ime;
            copyParticipant(other);
        }
        return *this;
    }

    bool operator>(const Participant &other) {
        return other.vozrast > this->vozrast;
    }

    friend ostream& operator<<(ostream &os, Participant &other) {
        os << other.ime << " " << "\n"
           << (other.pol ? "mashki" : "zhenski") << "\n"
           << other.vozrast << "\n";
        return os;
    }

    int getAge() {
        return vozrast;
    }

    ~Participant() {
        delete[] ime;
    }
};

class Marathon {
private:
    char lokacija[100];
    Participant *ucesnici;
    int num;

    void copyMarathon(const Marathon &other) {
        strcpy(this->lokacija, other.lokacija);
        this->ucesnici = new Participant[other.num];

        for (int i = 0; i < other.num; i++) {
            this->ucesnici[i] = other.ucesnici[i];
        }

        this->num = other.num;
    }

public:
    Marathon() {
        strcpy(this->lokacija, "lokacija");
        this->ucesnici = nullptr;
        this->num = 0;
    }

    Marathon(char *lokacija) {
        strcpy(this->lokacija, lokacija);
        this->ucesnici = nullptr;
        this->num = 0;
    }

    Marathon& operator=(const Marathon &other) {
        if (this != &other) {
            delete[] this->ucesnici;
            copyMarathon(other);
        }
        return *this;
    }

    Marathon& operator+=(const Participant &other) {
        Participant *temp = new Participant[num + 1];

        for (int i = 0; i < num; i++) {
            temp[i] = this->ucesnici[i];
        }

        temp[num++] = other;

        delete[] ucesnici;

        this->ucesnici = new Participant[num];

        for (int i = 0; i < num; i++) {
            this->ucesnici[i] = temp[i];
        }

        delete[] temp;
        return *this;
    }

    float averageAge() {
        float s = 0;

        for (int i = 0; i < num; i++) {
            s += ucesnici[i].getAge();
        }

        return s / (float)num;
    }

    void printYounger(Participant &u) {
        for (int i = 0; i < num; i++) {
            if (ucesnici[i] > u) {
                cout << ucesnici[i];
            }
        }
    }

    ~Marathon() {
        delete[] ucesnici;
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;

    cin >> n;

    char lokacija[100];
    cin >> lokacija;

    Marathon m(lokacija);

    Participant **u = new Participant*[n];

    for (int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Participant(ime, maski, vozrast);
        m += *u[i];
    }

    m.printYounger(*u[n - 1]);
    cout << m.averageAge() << endl;

    for (int i = 0; i < n; ++i) {
        delete u[i];
    }

    delete[] u;
    return 0;
}
