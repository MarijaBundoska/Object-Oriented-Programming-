#include <iostream>
#include <cstring>
using namespace std;

class Guitar {
private:
    char serialNumber[25];
    float price;
    int year;
    char type[40];

    void copyGuitar(const Guitar &other) {
        strcpy(this->serialNumber, other.serialNumber);
        this->price = other.price;
        this->year = other.year;
        strcpy(this->type, other.type);
    }

public:
    Guitar() {
        strcpy(this->serialNumber, "serial");
        this->price = 0;
        this->year = 2023;
        strcpy(this->type, "type");
    }

    Guitar(char *type, char *serialNumber, int year, float price) {
        strcpy(this->serialNumber, serialNumber);
        this->price = price;
        this->year = year;
        strcpy(this->type, type);
    }

    Guitar(const Guitar &other) {
        copyGuitar(other);
    }

    Guitar& operator=(const Guitar &other) {
        if (this != &other) {
            copyGuitar(other);
            return *this;
        }
        return *this;
    }

    char *getSerialNumber() {
        return serialNumber;
    }

    float getPrice() {
        return price;
    }

    int getYear() {
        return year;
    }

    char *getType() {
        return type;
    }

    bool isSame(Guitar g) {
        return !strcmp(serialNumber, g.serialNumber);
    }

    void print() {
        cout << serialNumber << " " << type << " " << price << "\n";
    }

    ~Guitar() {}
};

class Warehouse {
private:
    char name[30];
    char location[60];
    Guitar *guitars;
    int num;
    int year;

    void copyWarehouse(const Warehouse &other) {
        strcpy(this->name, other.name);
        strcpy(this->location, other.location);
        this->num = other.num;
        this->year = other.year;
        this->guitars = new Guitar[other.num];

        for (int i = 0; i < num; i++) {
            this->guitars[i] = other.guitars[i];
        }
    }

public:
    Warehouse() {
        strcpy(this->name, "name");
        strcpy(this->location, "location");
        this->guitars = nullptr;
        this->num = this->year = 0;
    }

    Warehouse(char *name, char *location) {
        strcpy(this->name, name);
        strcpy(this->location, location);
        this->guitars = nullptr;
        this->num = 0;
        this->year = 2023;
    }

    Warehouse(char *name, char *location, int year) {
        strcpy(this->name, name);
        strcpy(this->location, location);
        this->guitars = nullptr;
        this->num = 0;
        this->year = year;
    }

    Warehouse(const Warehouse &other) {
        copyWarehouse(other);
    }

    Warehouse& operator=(const Warehouse &other) {
        if (this != &other) {
            delete[] this->guitars;
            copyWarehouse(other);
        }
        return *this;
    }

    double value() {
        double sum = 0;

        for (int i = 0; i < num; i++) {
            sum += guitars[i].getPrice();
        }

        return sum;
    }

    void add(Guitar g) {
        Guitar *temp = new Guitar[num];

        for (int i = 0; i < num; i++) {
            temp[i] = this->guitars[i];
        }

        delete[] this->guitars;
        this->guitars = new Guitar[num + 1];

        for (int i = 0; i < num; i++) {
            this->guitars[i] = temp[i];
        }

        delete[] temp;
        this->guitars[num++] = g;
    }

    void sell(Guitar g) {
        int count = 0;
        int index = 0;

        for (int i = 0; i < num; i++) {
            count += !guitars[i].isSame(g);
        }

        if (!count) {
            return;
        }

        Guitar *temp = new Guitar[count];

        for (int i = 0; i < num; i++) {
            if (guitars[i].isSame(g)) {
                continue;
            }

            temp[index++] = this->guitars[i];
        }

        delete[] this->guitars;
        this->guitars = new Guitar[index];

        for (int i = 0; i < index; i++) {
            this->guitars[i] = temp[i];
        }

        this->num = index;
        delete[] temp;
    }

    void print(bool onlyNew) {
        cout << name << " " << location << "\n";

        for (int i = 0; i < num; i++) {
            if (onlyNew && guitars[i].getYear() > year) {
                guitars[i].print();
            }
            else if (!onlyNew) {
                guitars[i].print();
            }
        }
    }

    ~Warehouse() {
        delete[] guitars;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, year;
    float price;
    char serialNumber[50], type[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> type;
        cin >> serialNumber;
        cin >> year;
        cin >> price;

        Guitar g(type, serialNumber, year, price);

        cout << g.getType() << endl;
        cout << g.getSerialNumber() << endl;
        cout << g.getYear() << endl;
        cout << g.getPrice() << endl;
    }
    else if (testCase == 2) {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Warehouse warehouse("Magacin1", "Lokacija1");
        warehouse.print(false);
    }
    else if (testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Warehouse warehouse("Magacin1", "Lokacija1", 2005);
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> type;
            cin >> serialNumber;
            cin >> year;
            cin >> price;

            Guitar g(type, serialNumber, year, price);
            cout << "gitara dodadi" << endl;
            warehouse.add(g);
        }

        warehouse.print(true);
    }
    else if (testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Warehouse warehouse("Magacin1", "Lokacija1", 2012);
        cin >> n;

        Guitar guitarToSell;

        for (int i = 0; i < n; i++) {
            cin >> type;
            cin >> serialNumber;
            cin >> year;
            cin >> price;

            Guitar g(type, serialNumber, year, price);

            if (i == 2)
                guitarToSell = g;

            cout << "gitara dodadi" << endl;
            warehouse.add(g);
        }

        warehouse.print(false);
        warehouse.sell(guitarToSell);
        warehouse.print(false);
    }
    else if (testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Warehouse warehouse("Magacin1", "Lokacija1", 2011);
        cin >> n;

        Guitar guitarToSell;

        for (int i = 0; i < n; i++) {
            cin >> type;
            cin >> serialNumber;
            cin >> year;
            cin >> price;

            Guitar g(type, serialNumber, year, price);

            if (i == 2)
                guitarToSell = g;

            cout << "gitara dodadi" << endl;
            warehouse.add(g);
        }

        warehouse.print(true);
        warehouse.sell(guitarToSell);
        cout << "Po brisenje:" << endl;

        Warehouse warehouse3;
        warehouse3 = warehouse;
        warehouse3.print(true);
    }
    else if (testCase == 6) {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Warehouse warehouse("Magacin1", "Lokacija1", 2011);
        cin >> n;

        Guitar guitarToSell;

        for (int i = 0; i < n; i++) {
            cin >> type;
            cin >> serialNumber;
            cin >> year;
            cin >> price;

            Guitar g(type, serialNumber, year, price);

            if (i == 2)
                guitarToSell = g;

            warehouse.add(g);
        }

        cout << warehouse.value() << endl;
        warehouse.sell(guitarToSell);
        cout << "Po brisenje:" << endl;
        cout << warehouse.value();

        Warehouse warehouse3;
        warehouse3 = warehouse;
    }

    return 0;
}
