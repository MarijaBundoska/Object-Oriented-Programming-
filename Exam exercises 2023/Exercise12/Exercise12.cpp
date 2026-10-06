#include <iostream>
#include <cstring>
using namespace std;

class InvalidProductionDate {
public:
    void message() {
        cout << "Невалидна година на производство" << endl;
    }
};

enum Type {
    smartphone,
    computer
};

class Device {
    char model[100];
    static float INITIAL_HOURS;
    int year;
    Type type;

    void copy(const Device &device) {
        strcpy(this->model, device.model);
        this->type = device.type;
        this->year = device.year;
    }

public:
    Device(char *model, Type type, int year) {
        strcpy(this->model, model);
        this->type = type;
        this->year = year;
    }

    Device() {
        strcpy(this->model, "model");
        this->year = 0;
        this->type = smartphone;
    }

    ~Device() {}

    Device(const Device &device) {
        copy(device);
    }

    Device& operator=(const Device &device) {
        if (this != &device) {
            copy(device);
        }
        return *this;
    }

    static void setInitialHours(float hours) {
        INITIAL_HOURS = hours;
    }

    float check() {
        float score = 0;

        if (year > 2015) {
            score += 2;
        }

        if (type == computer) {
            score += 2;
        }

        return score + Device::INITIAL_HOURS;
    }

    int getYear() {
        return year;
    }

    friend ostream& operator<<(ostream &out, Device &device) {
        out << device.model << endl;

        if(device.type == smartphone){
            out<<"Mobilen ";
        } else{
            out<<"Laptop ";
        }
        out << device.check() << endl;
        return out;
    }
};

class MobileService {
private:
    char address[100];
    Device *devices;
    int n;

    void copy(const MobileService &service) {
        strcpy(this->address, service.address);

        this->devices = new Device[service.n];

        for (int i = 0; i < service.n; i++) {
            this->devices[i] = service.devices[i];
        }

        this->n = service.n;
    }

public:
    MobileService(char *address) {
        strcpy(this->address, address);
        this->devices = nullptr;
        this->n = 0;
    }

    MobileService(const MobileService &service) {
        copy(service);
    }

    ~MobileService() {
        delete[] devices;
    }

    MobileService operator=(const MobileService &service) {
        if (this != &service) {
            delete[] devices;
            copy(service);
        }

        return *this;
    }

    MobileService& operator+=(Device &device) {
        if (device.getYear() < 2000 || device.getYear() > 2019) {
            throw InvalidProductionDate();
        }

        Device *temp = new Device[n + 1];

        for (int i = 0; i < n; i++) {
            temp[i] = this->devices[i];
        }

        temp[n++] = device;

        delete[] devices;
        devices = temp;

        return *this;
    }

    void printHours() {
        cout << "Ime: " << address << endl;

        for (int i = 0; i < n; i++) {
            cout << devices[i];
        }
    }
};

float Device::INITIAL_HOURS = 1;

int main() {
    int testCase;
    cin >> testCase;

    char name[100];
    int deviceType;
    int year;
    int n;

    Device devices[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;

        cin >> name;
        cin >> deviceType;
        cin >> year;

        Device device(name, (Type)deviceType, year);

        cin >> name;

        MobileService service(name);

        cout << device;
    }

    if (testCase == 2) {
        cout << "===== Testiranje na operatorot += ======" << endl;

        cin >> name;
        cin >> n;

        MobileService service(name);

        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> deviceType;
            cin >> year;

            Device temp(name, (Type)deviceType, year);

            try {
                service += temp;
            }
            catch (InvalidProductionDate& e) {
                e.message();
            }
        }

        service.printHours();
    }

    if (testCase == 3) {
        cout << "===== Testiranje na isklucoci ======" << endl;

        cin >> name;
        cin >> n;

        MobileService service(name);

        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> deviceType;
            cin >> year;

            Device temp(name, (Type)deviceType, year);

            try {
                service += temp;
            }
            catch (InvalidProductionDate& e) {
                e.message();
            }
        }

        service.printHours();
    }

    if (testCase == 4) {
        cout << "===== Testiranje na konstruktori ======" << endl;

        cin >> name;
        cin >> n;

        MobileService service(name);

        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> deviceType;
            cin >> year;

            Device temp(name, (Type)deviceType, year);

            try {
                service += temp;
            }
            catch (InvalidProductionDate& e) {
                e.message();
            }
        }

        MobileService service2 = service;
        service2.printHours();
    }

    if (testCase == 5) {
        cout << "===== Testiranje na static clenovi ======" << endl;

        cin >> name;
        cin >> n;

        MobileService service(name);

        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> deviceType;
            cin >> year;

            Device temp(name, (Type)deviceType, year);

            try {
                service += temp;
            }
            catch (InvalidProductionDate& e) {
                e.message();
            }
        }

        service.printHours();

        cout << "===== Promena na static clenovi ======" << endl;

        Device::setInitialHours(2);

        service.printHours();
    }

    if (testCase == 6) {
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;

        cin >> name;
        cin >> n;

        MobileService service(name);

        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> deviceType;
            cin >> year;

            Device temp(name, (Type)deviceType, year);

            try {
                service += temp;
            }
            catch (InvalidProductionDate& e) {
                e.message();
            }
        }

        Device::setInitialHours(3);

        MobileService service2 = service;
        service2.printHours();
    }

    return 0;
}
