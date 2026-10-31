#include <iostream>
#include <cstring>
using namespace std;

class CableCar {
    char* location;
    int price;

    void copyCableCar(const CableCar& other) {
        this->location = new char[strlen(other.location) + 1];
        strcpy(this->location, other.location);
        this->price = other.price;
    }

public:
    CableCar() {
        this->location = new char[6];
        strcpy(this->location, "place");
        this->price = 0;
    }

    CableCar(char* location, int price) {
        this->location = new char[strlen(location) + 1];
        strcpy(this->location, location);
        this->price = price;
    }

    CableCar(const CableCar& other) {
        copyCableCar(other);
    }

    CableCar& operator=(const CableCar& other) {
        if (this == &other) {
            return *this;
        }

        delete[] location;
        copyCableCar(other);
        return *this;
    }

    int getPrice() {
        return price;
    }

    ~CableCar() {
        delete[] location;
    }
};

class MountainLodge {
    char name[15];
    int prices[2];
    char lodgeClass;
    bool hasCableCar;
    CableCar* cableCar;

    void copyLodge(const MountainLodge& other) {
        strcpy(this->name, other.name);
        this->prices[0] = other.prices[0];
        this->prices[1] = other.prices[1];
        this->lodgeClass = other.lodgeClass;
        this->hasCableCar = other.hasCableCar;
        this->cableCar = other.cableCar;
    }

public:
    MountainLodge() {
        this->prices[0] = this->prices[1] = 0;
        strcpy(this->name, "lodge");
        this->lodgeClass = 'F';
        this->hasCableCar = false;
        this->cableCar = nullptr;
    }

    MountainLodge(char* name, const int* prices, char lodgeClass) {
        strcpy(this->name, name);

        for (int i = 0; i < 2; i++) {
            this->prices[i] = prices[i];
        }

        this->lodgeClass = lodgeClass;
        this->hasCableCar = false;
        this->cableCar = nullptr;
    }

    MountainLodge(const MountainLodge& other) {
        copyLodge(other);
    }

    MountainLodge& operator=(const MountainLodge& other) {
        if (this == &other) {
            return *this;
        }

        copyLodge(other);
        return *this;
    }

    MountainLodge& operator--() {
        if (lodgeClass < 'F') {
            lodgeClass++;
        }

        return *this;
    }

    bool operator<=(char c) const {
        return lodgeClass >= c;
    }

    friend ostream& operator<<(ostream& os, const MountainLodge& other) {
        os << other.name << " klasa:" << other.lodgeClass
           << (other.hasCableCar ? " so Zichara" : "") << "\n";

        return os;
    }

    void setCableCar(CableCar cableCar) {
        this->cableCar = &cableCar;
        hasCableCar = true;
    }

    void calculateDailyStay(int day, int month, int &price) {
        price = 0;

        if (cableCar) {
            price += cableCar->getPrice();
        }

        if (month < 1 || month > 12 || day < 1 || day > 31) {
            throw -1;
        }

        price += (month >= 4 && month <= 8) || (month == 9 && day == 1)
                 ? prices[0] : prices[1];
    }
};

int main() {
    MountainLodge lodge;

    // Vnesuvanje informacii za planinarskiot dom
    char lodgeName[15], cableCarLocation[30], lodgeClass;
    int prices[12];
    int dailyCableCarTicket;
    bool hasCableCar;

    cin >> lodgeName;

    for (int i = 0; i < 2; i++) {
        cin >> prices[i];
    }

    cin >> lodgeClass;
    cin >> hasCableCar;

    // Vnesuvanje informacii za zicharata, dokolku postoi
    if (hasCableCar) {
        cin >> cableCarLocation >> dailyCableCarTicket;

        MountainLodge temp(lodgeName, prices, lodgeClass);
        CableCar cableCar(cableCarLocation, dailyCableCarTicket);

        temp.setCableCar(cableCar);
        lodge = temp;
    }
    else {
        MountainLodge *ptr = new MountainLodge(lodgeName, prices, lodgeClass);
        lodge = *ptr;
    }

    // Namaluvanje na klasata na planinarskiot dom za 2
    --lodge;
    --lodge;

    int price;
    int day, month;

    cin >> day >> month;

    try {
        lodge.calculateDailyStay(day, month, price);

        cout << "Informacii za PlaninarskiDomot:" << endl;
        cout << lodge;

        if (lodge <= 'D') {
            cout << "Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";
        }

        cout << "Cenata za " << day << "." << month << " e " << price;
    }
    catch (int) {
        cout << "Mesecot ili denot e greshno vnesen!";
    }

    return 0;
}
