#include <iostream>
#include <cstring>
using namespace std;

class Passenger {
    char name[100];
    int classNumber;
    bool bicycle;

    void copyPassenger(const Passenger& other) {
        strcpy(this->name, other.name);
        this->classNumber = other.classNumber;
        this->bicycle = other.bicycle;
    }

public:
    Passenger() {
        strcpy(this->name, "name");
        this->classNumber = 1;
        this->bicycle = false;
    }

    Passenger(char* name, int classNumber, bool bicycle) {
        strcpy(this->name, name);
        this->classNumber = classNumber;
        this->bicycle = bicycle;
    }

    Passenger(const Passenger& other) {
        copyPassenger(other);
    }

    Passenger& operator=(const Passenger& other) {
        if (this == &other) {
            return *this;
        }
        copyPassenger(other);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Passenger& p) {
        os << p.name << "\n"
           << p.classNumber << "\n"
           << p.bicycle << "\n\n";
        return os;
    }

    int getClassNumber() const {
        return classNumber;
    }

    bool hasBicycle() const {
        return bicycle;
    }

    ~Passenger() {}
};

class Train {
    char destination[100];
    Passenger* passengers;
    int numberOfPassengers;
    int allowedBicycles;

    void copyTrain(const Train& other) {
        strcpy(this->destination, other.destination);
        this->passengers = new Passenger[other.numberOfPassengers];

        for (int i = 0; i < other.numberOfPassengers; i++) {
            this->passengers[i] = other.passengers[i];
        }

        this->numberOfPassengers = other.numberOfPassengers;
        this->allowedBicycles = other.allowedBicycles;
    }

public:
    Train() {
        strcpy(this->destination, "destination");
        this->passengers = nullptr;
        this->numberOfPassengers = this->allowedBicycles = 0;
    }

    Train(char* destination, int allowedBicycles) {
        strcpy(this->destination, destination);
        this->passengers = nullptr;
        this->numberOfPassengers = 0;
        this->allowedBicycles = allowedBicycles;
    }

    Train(const Train& other) {
        copyTrain(other);
    }

    Train& operator=(const Train& other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->passengers;
        copyTrain(other);
        return *this;
    }

    Train& operator+=(const Passenger& p) {
        if (p.hasBicycle() && !allowedBicycles) {
            return *this;
        }

        Passenger* temp = new Passenger[numberOfPassengers + 1];

        for (int i = 0; i < this->numberOfPassengers; i++) {
            temp[i] = passengers[i];
        }

        temp[numberOfPassengers++] = p;

        delete[] passengers;
        this->passengers = new Passenger[numberOfPassengers];

        for (int i = 0; i < numberOfPassengers; i++) {
            passengers[i] = temp[i];
        }

        delete[] temp;
        return *this;
    }

    friend ostream& operator<<(ostream& os, Train& other) {
        os << other.destination << endl;

        if (other.allowedBicycles == 0) {
            for (int i = 0; i < other.numberOfPassengers; i++) {
                if (!other.passengers[i].hasBicycle()) {
                    os << other.passengers[i];
                }
            }
            return os;
        }

        for (int i = 0; i < other.numberOfPassengers; i++) {
            os << other.passengers[i];
        }

        return os;
    }

    void countPassengersWithoutSpace() {
        int firstClassWithoutSpace = 0;
        int secondClassWithoutSpace = 0;
        int remainingBicycles = allowedBicycles;

        for (int i = 0; i < numberOfPassengers; i++) {
            if (passengers[i].hasBicycle() &&
                passengers[i].getClassNumber() == 1) {
                if (remainingBicycles) {
                    remainingBicycles--;
                } else {
                    firstClassWithoutSpace++;
                }
            }
        }

        for (int i = 0; i < numberOfPassengers; i++) {
            if (passengers[i].hasBicycle() &&
                passengers[i].getClassNumber() == 2) {
                if (remainingBicycles) {
                    remainingBicycles--;
                } else {
                    secondClassWithoutSpace++;
                }
            }
        }

        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "
             << firstClassWithoutSpace << "\n";
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "
             << secondClassWithoutSpace << "\n";
    }

    ~Train() {
        delete[] passengers;
    }
};

int main() {
    Passenger p;
    char name[100], destination[100];
    int n;
    bool bicycle;
    int classNumber;
    int maxBicycles;

    cin >> destination >> maxBicycles;
    cin >> n;

    Train train(destination, maxBicycles);

    for (int i = 0; i < n; i++) {
        cin >> name >> classNumber >> bicycle;
        Passenger p(name, classNumber, bicycle);
        train += p;
    }

    cout << train;
    train.countPassengersWithoutSpace();

    return 0;
}
