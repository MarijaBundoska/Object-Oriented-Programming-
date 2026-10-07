#include <iostream>
#include <cstring>
using namespace std;

class  FootballClub{
protected:
    char coach[100];
    int goals[10];

private:
    void copy(const FootballClub& other) {
        strcpy(this->coach, other.coach);
        for(int i = 0; i<10; i++) {
            this->goals[i] = other.goals[i];
        }
    }

public:
    FootballClub() {
        strcpy(this->coach, "abc");
        for(int i = 0; i<10; i++) {
            this->goals[i] = 0;
        }
    }

    FootballClub(char* coach, int* goals) {
        strcpy(this->coach, coach);
        for(int i = 0; i<10; i++) {
            this->goals[i] = goals[i];
        }
    }

    FootballClub(const FootballClub& other) {
        copy(other);
    }

    FootballClub& operator=(const FootballClub& other) {
        if(this == &other) {
            return *this;
        }
        copy(other);
        return *this;
    }

    FootballClub& operator+=(int lastMatchGoals) {
        for(int i = 0; i<9; i++) {
            this->goals[i] = this->goals[i + 1];
        }
        this->goals[9] = lastMatchGoals;
        return *this;
    }

    bool operator>(FootballClub& other) {
        return Success() > other.Success();
    }

    int getTotalGoals() {
        int s = 0;
        for(int i = 0; i<10; i++) {
            s += goals[i];
        }
        return s;
    }

    virtual int Success() = 0;

    char* getCoach() {
        return coach;
    }

    ~FootballClub() { }
};

class Club : public FootballClub {
    char* name;
    int titles;

    void copy_klub(const Club& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->titles = other.titles;
    }

public:
    Club() : FootballClub() {
        this->name = new char[5];
        strcpy(this->name, "name");
        this->titles = 0;
    }

    Club(char* coach, int* goals, char* name, int titles) : FootballClub(coach, goals) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->titles = titles;
    }

    Club(const FootballClub& f, char* name, int titles) : FootballClub(f) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->titles = titles;
    }

    Club(const Club& other) {
        copy_klub(other);
    }

    Club& operator=(const Club& other) {
        if(this == &other) {
            return *this;
        }
        FootballClub::operator=(other);
        copy_klub(other);
        return *this;
    }

    int Success() {
        return getTotalGoals() * 3 + titles * 1000;
    }

    char* getName() {
        return name;
    }

    ~Club() {
        delete [] name;
    }
};

class Representation : public FootballClub {
    char* country;
    int matches;

    void copy(const Representation& other) {
        this->country = new char[strlen(other.country) + 1];
        strcpy(this->country, other.country);
        this->matches = other.matches;
    }

public:
    Representation() : FootballClub() {
        this->country = new char[8];
        strcpy(this->country, "country");
        this->matches = 0;
    }

    Representation(char* coach, int* goals, char* country, int matches) : FootballClub(coach, goals) {
        this->country = new char[strlen(country) + 1];
        strcpy(this->country, country);
        this->matches = matches;
    }

    Representation(const Representation& other) {
        copy(other);
    }

    Representation& operator=(const Representation& other) {
        if(this == &other) {
            return *this;
        }
        FootballClub::operator=(other);
        copy(other);
        return *this;
    }

    int Success() {
        return getTotalGoals() * 3 + matches * 50;
    }

    char* getCountry() {
        return country;
    }

    ~Representation() {
        delete [] country;
    }
};

ostream& operator<<(ostream& out, FootballClub& k) {
    if(dynamic_cast<Club*>(&k)) {
        out << dynamic_cast<Club*>(&k)->getName();
    } else if(dynamic_cast<Representation*>(&k)) {
        out << dynamic_cast<Representation*>(&k)->getCountry();
    }
    out << "\n" << k.getCoach() << "\n" << k.Success() << "\n";
    return out;
}

void bestCoach(FootballClub** clubs, int n) {
    int idx = -1;

    for(int i = 0; i < n; i++) {
        if(idx == -1 || clubs[i]->Success() > clubs[idx]->Success()) {
            idx = i;
        }
    }

    if(idx == -1) {
        return;
    }

    cout << *clubs[idx];
}

int main() {
    int n;
    cin >> n;
    FootballClub **clubs = new FootballClub*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i<n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j<10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            clubs[i] = new Club(coach, goals, x, tg);
        } else if (type == 1) {
            clubs[i] = new Representation(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i<n; ++i) {
        cout << *clubs[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i<n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *clubs[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i<n; ++i) {
        cout << *clubs[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    bestCoach(clubs, n);
    for (int i = 0; i<n; ++i) {
        delete clubs[i];
    }
    delete [] clubs;
    return 0;
}
