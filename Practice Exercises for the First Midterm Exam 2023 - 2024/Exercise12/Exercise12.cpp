#include <iostream>
#include <cstring>
using namespace std;

class Pizza {
private:
    char ime[15];
    int cena;
    char *sostojki;
    int popust;

    void copyPizza(const Pizza &other) {
        strcpy(this->ime, other.ime);
        this->cena = other.cena;

        this->sostojki = new char[strlen(other.sostojki) + 1];
        strcpy(this->sostojki, other.sostojki);

        this->popust = other.popust;
    }

public:
    Pizza() {
        strcpy(this->ime, "ime");
        this->cena = 0;
        this->popust = 0;

        this->sostojki = new char[1];
        this->sostojki[0] = '\0';
    }

    Pizza(char *ime, int cena, char *sostojki, int popust) {
        strcpy(this->ime, ime);
        this->cena = cena;

        this->sostojki = new char[strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);

        this->popust = popust;
    }

    Pizza(const Pizza &other) {
        copyPizza(other);
    }

    Pizza& operator=(const Pizza &other) {
        if (this != &other) {
            delete[] sostojki;
            copyPizza(other);
        }
        return *this;
    }

    ~Pizza() {
        delete[] sostojki;
    }

    void print() {
        cout << ime << " - " << sostojki << ", " << cena;
    }

    int getPrice() {
        return cena;
    }

    int getDiscount() {
        return popust;
    }

    bool sameIngredients(const Pizza &p) {
        return !strcmp(this->sostojki, p.sostojki);
    }
};

class Pizzeria {
private:
    char ime[15];
    Pizza *pici;
    int num;

    void copyPizzeria(const Pizzeria &other) {
        strcpy(this->ime, other.ime);

        this->pici = new Pizza[other.num];

        for (int i = 0; i < other.num; i++) {
            this->pici[i] = other.pici[i];
        }

        this->num = other.num;
    }

public:
    Pizzeria() {
        strcpy(this->ime, "picerija");
        pici = nullptr;
        num = 0;
    }

    Pizzeria(char *ime) {
        strcpy(this->ime, ime);
        pici = nullptr;
        num = 0;
    }

    Pizzeria(const Pizzeria &other) {
        copyPizzeria(other);
    }

    Pizzeria& operator=(const Pizzeria &other) {
        if (this != &other) {
            delete[] pici;
            copyPizzeria(other);
        }
        return *this;
    }

    Pizzeria& operator+=(const Pizza &other) {
        for (int i = 0; i < num; i++) {
            if (pici[i].sameIngredients(other)) {
                return *this;
            }
        }

        Pizza *temp = new Pizza[num + 1];

        for (int i = 0; i < num; i++) {
            temp[i] = pici[i];
        }

        temp[num] = other;
        num++;

        delete[] pici;

        pici = new Pizza[num];

        for (int i = 0; i < num; i++) {
            pici[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }

    char *getName() {
        return ime;
    }

    void setName(const char *ime) {
        strcpy(this->ime, ime);
    }

    void promotionalPizzas() {
        for (int i = 0; i < num; i++) {
            if (pici[i].getDiscount() != 0) {
                pici[i].print();

                cout << " "
                     << pici[i].getPrice() *
                        (1 - pici[i].getDiscount() / 100.0)
                     << "\n";
            }
        }
    }

    ~Pizzeria() {
        delete[] pici;
    }
};

int main() {
    int n;
    char ime[15];

    cin >> ime;
    cin >> n;

    Pizzeria p1(ime);

    for (int i = 0; i < n; i++) {
        char imp[100];

        cin.get();
        cin.getline(imp, 100);

        int cena;
        cin >> cena;

        char sostojki[100];

        cin.get();
        cin.getline(sostojki, 100);

        int popust;
        cin >> popust;

        Pizza p(imp, cena, sostojki, popust);
        p1 += p;
    }

    Pizzeria p2 = p1;

    cin >> ime;
    p2.setName(ime);

    char imp[100];

    cin.get();
    cin.getline(imp, 100);

    int cena;
    cin >> cena;

    char sostojki[100];

    cin.get();
    cin.getline(sostojki, 100);

    int popust;
    cin >> popust;

    Pizza p(imp, cena, sostojki, popust);
    p2 += p;

    cout << p1.getName() << endl;
    cout << "Pici na promocija:" << endl;
    p1.promotionalPizzas();

    cout << p2.getName() << endl;
    cout << "Pici na promocija:" << endl;
    p2.promotionalPizzas();

    return 0;
}
