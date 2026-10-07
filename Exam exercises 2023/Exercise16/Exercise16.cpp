#include<iostream>
#include <cstring>
using namespace std;

class Transport{
protected:
    char *destination;
    int price;
    int km;

    void copyTransport(const Transport &other){
        this->destination = new char [strlen(other.destination)+1];
        strcpy(this->destination, other. destination);
        this->price = other.price;
        this->km = other.km;
    }

public:
    Transport(){
        this->destination = new char[5];
        strcpy(this->destination, "dest");
        this->price = this->km = 0;
    }

    Transport(char *destination, int price, int km){
        this->destination = new char[strlen(destination)+1];
        strcpy(this->destination, destination);
        this->price = price;
        this->km = km;
    }

    Transport(const Transport &other){
        copyTransport(other);
    }

    Transport &operator=(const Transport &other){
        if(this != &other){
            delete[] destination;
            copyTransport(other);
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, Transport &t){
        out<<t.destination<<" "<<t.km<<" "<<t.price<<"\n";
        return out;
    }

    bool operator<(const Transport &other){
        return km < other.km;
    }

    virtual float transportPrice(){
        return price;
    }

    char *getDestination(){
        return destination;
    }

    int getKM(){
        return km;
    }

    virtual ~Transport() {
        delete[] destination;
    }
};

class CarTransport: public Transport{
    bool driver;

public:
    CarTransport():Transport(){
        this->driver = false;
    }

    CarTransport(char *destination, int price, int km, bool driver): Transport(destination, price, km){
        this->driver = driver;
    }

    CarTransport(const CarTransport &other): Transport(other){
        this->driver = other.driver;
    }

    CarTransport &operator=(const CarTransport &other){
        if(this != &other){
            Transport::operator=(other);
            this->driver =  other.driver;
        }
        return *this;
    }

    float transportPrice(){
        return driver ? price * 1.2 : price;
    }

    ~CarTransport(){}
};

class VanTransport: public Transport{
    int passengers;

public:
    VanTransport() : Transport(){
        this->passengers = 0;
    }

    VanTransport(char *destination, int price, int km, int passengers)
            : Transport(destination, price, km){
        this->passengers = passengers;
    }

    VanTransport(const VanTransport &other): Transport(other){
        this->passengers = other.passengers;
    }

    VanTransport &operator=(const VanTransport &other){
        if(this != &other){
            Transport::operator=(other);
            this->passengers = other.passengers;
        }
        return *this;
    }

    float transportPrice(){
        return price - (passengers * 200);
    }

    ~VanTransport(){}
};

void printWorseOffers(Transport **offers, int n, CarTransport t){
    Transport **temp = new Transport*[n];
    int k = 0;

    for(int i=0; i<n; i++){
        if(offers[i]->transportPrice() > t.transportPrice()){
            temp[k++] = offers[i];
        }
    }

    for(int i=0; i<k-1; i++){
        for(int j=0; j<k-i-1; j++){
            if(temp[j]->getKM() > temp[j+1]->getKM()){
                Transport *swap = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = swap;
            }
        }
    }

    for(int i=0; i<k; i++){
        cout<<temp[i]->getDestination()<<" "
            <<temp[i]->getKM()<<" "
            <<temp[i]->transportPrice()<<"\n";
    }
    delete[] temp;
}
int main(){
    char destination[20];
    int type, price, distance, passengers;
    bool driver;
    int n;

    cin >> n;

    Transport** offers;
    offers = new Transport*[n];

    for (int i = 0; i < n; i++) {

        cin >> type >> destination >> price >> distance;

        if (type == 1) {
            cin >> driver;

            offers[i] = new CarTransport(
                    destination,
                    price,
                    distance,
                    driver
            );
        }
        else {
            cin >> passengers;

            offers[i] = new VanTransport(
                    destination,
                    price,
                    distance,
                    passengers
            );
        }
    }

    CarTransport newTransport("Ohrid", 2000, 600, false);

    printWorseOffers(offers, n, newTransport);

    for (int i = 0; i < n; i++)
        delete offers[i];

    delete[] offers;
    return 0;
}
