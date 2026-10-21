#include <iostream>
#include <cstring>
using namespace std;

class Driver{
protected:
    char name[100];
    int age;
    int races;
    bool veteran;

public:
    Driver(char name[100], int age, int races, bool veteran){
        strcpy(this->name, name);
        this->age = age;
        this->races = races;
        this->veteran = veteran;
    }

    virtual double earnings() = 0;
    virtual double tax() = 0;

    friend ostream &operator<<(ostream &os, Driver &d){
        os << d.name << endl << d.age << endl << d.races << endl;
        if(d.veteran) os << "VETERAN" << endl;
        return os;
    }

    bool operator==(Driver &d){
        return this->earnings() == d.earnings();
    }

    virtual ~Driver(){}
};

class CarDriver : public Driver{
private:
    double carPrice;

public:
    CarDriver(char name[100], int age, int races, bool veteran, double carPrice)
        : Driver(name, age, races, veteran){
        this->carPrice = carPrice;
    }

    double earnings(){
        return carPrice / 5;
    }

    double tax(){
        return races > 10 ? 0.15 * earnings() : 0.10 * earnings();
    }
};

class MotorcycleDriver : public Driver{
private:
    int enginePower;

public:
    MotorcycleDriver(char name[100], int age, int races, bool veteran, int enginePower)
        : Driver(name, age, races, veteran){
        this->enginePower = enginePower;
    }

    double earnings(){
        return enginePower * 20;
    }

    double tax(){
        return veteran ? 0.25 * earnings() : 0.20 * earnings();
    }
};

int sameEarnings(Driver **drivers, int n, Driver *driver){
    int count = 0;

    for(int i = 0; i < n; i++){
        if(drivers[i]->earnings() == driver->earnings()){
            count++;
        }
    }

    return count;
}

int main(){
    int n, x;
    cin >> n >> x;

    Driver **drivers = new Driver*[n];

    char name[100];
    int age;
    int races;
    bool veteran;

    for(int i = 0; i < n; i++){
        cin >> name >> age >> races >> veteran;

        if(i < x){
            float carPrice;
            cin >> carPrice;

            drivers[i] = new CarDriver(name, age, races, veteran, carPrice);
        }
        else{
            int enginePower;
            cin >> enginePower;

            drivers[i] = new MotorcycleDriver(name, age, races, veteran, enginePower);
        }
    }

    cout << "=== DANOK ===" << endl;

    for(int i = 0; i < n; i++){
        cout << *drivers[i];
        cout << drivers[i]->tax() << endl;
    }

    cin >> name >> age >> races >> veteran;

    int enginePower;
    cin >> enginePower;

    Driver *driverX = new MotorcycleDriver(name, age, races, veteran, enginePower);

    cout << "=== VOZAC X ===" << endl;
    cout << *driverX;

    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << sameEarnings(drivers, n, driverX);

    for(int i = 0; i < n; i++){
        delete drivers[i];
    }

    delete[] drivers;
    delete driverX;

    return 0;
}
