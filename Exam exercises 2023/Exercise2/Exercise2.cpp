#include <iostream>
#include <cstring>
using namespace std;
class Driver{
protected:
    char name[101];
    int age;
    int races;
    bool isVeteran;

public:
    Driver(const char *name="", int age=0, int races=0,bool isVeteran=true){
        strcpy(this->name, name);
        this->age = age;
        this->races = races;
        this->isVeteran = isVeteran;
    }

    virtual double getEarnings() = 0;

    virtual double getTax() = 0;

    friend ostream &operator<<(ostream &os, const Driver &d){
        os << d.name<<endl<<d.age<<endl<<d.races<<endl;
        if(d.isVeteran){
            os<<"VETERAN"<<endl;
        }
        return os;
    }

    bool operator==(Driver &other){
        return this->getEarnings() == other.getEarnings();
    }

    virtual ~Driver() {}
};

class CarDriver : public Driver{
private:
    double carPrice;

public:
    CarDriver(const char *name="", int age=0, int races=0,bool isVeteran=true, double carPrice=0.0):Driver(name,age,races, isVeteran){
        this->carPrice = carPrice;
    }

    double getEarnings() override{
        return carPrice / 5.0;
    }

    double getTax() override{
        return (races > 10 ) ? (getEarnings() * 0.15) : (getEarnings() * 0.10);
    }
};

class Motorcyclist : public Driver{
private:
    int enginePower;
public:
    Motorcyclist(const char *name="", int age=0, int races=0,bool isVeteran=true, int enginePower=0):Driver(name,age,races, isVeteran){
        this->enginePower = enginePower;
    }

    double getEarnings() override{
        return enginePower * 20.0;
    }

    double getTax() override {
        return isVeteran ? (getEarnings() * 0.25) : (getEarnings() * 0.20);
    }
};

int countSameEarnings(Driver **drivers, int n, Driver *targetDriver){
    int count = 0;
    for(int i=0; i<n; i++){
        if(*drivers[i] == *targetDriver){
            count++;
        }
    }
    return count;
}

int main(){
    int n, x;
    if (!(cin >> n >> x)) return 0;

    Driver **drivers = new Driver*[n];
    char name[100];
    int age, races;
    bool isVeteran;

    for (int i = 0; i < n; ++i) {
        cin >> name >> age >> races >> isVeteran;
        if (i < x) {
            double carPrice;
            cin >> carPrice;
            drivers[i] = new CarDriver(name, age, races, isVeteran, carPrice);
        } else {
            int enginePower;
            cin >> enginePower;
            drivers[i] = new Motorcyclist(name, age, races, isVeteran, enginePower);
        }
    }

    cout << "=== DANOK ===" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *drivers[i];
        cout << drivers[i]->getTax() << endl;
    }

    cin >> name >> age >> races >> isVeteran;
    int enginePower;
    cin >> enginePower;

    Driver *targetDriver = new Motorcyclist(name, age, races, isVeteran, enginePower);

    cout << "=== VOZAC X ===" << endl;
    cout << *targetDriver;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << countSameEarnings(drivers, n, targetDriver) << endl;

    for (int i = 0; i < n; ++i) {
        delete drivers[i];
    }
    delete[] drivers;
    delete targetDriver;
    return 0;
}
