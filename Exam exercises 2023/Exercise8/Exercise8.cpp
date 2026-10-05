#include <iostream>
#include <cstring>
using namespace std;

class Concert{
protected:
    char name[20];
    char location[20];
    static double discount;
    double price;

private:
    void copyConcert(const Concert &other){
        strcpy(this->name,other.name);
        strcpy(this->location, other.location);
        this-> price = other.price;
    }

public:
    Concert() {
        strcpy(this->name, "name");
        strcpy(this->location, "location");
        this->price = 0;
    }

    Concert(char *name, char *location, double price){
        strcpy(this->name, name);
        strcpy(this->location, location);
        this->price = price;
    }

    Concert(const Concert &other){
        copyConcert(other);
    }

    Concert &operator=(const Concert &other){
        if(this != &other){
            copyConcert(other);
        }
        return *this;
    }

    virtual double priceWithDiscount(){
        return price * (1.0 - discount);
    }

    char *getName(){
        return name;
    }

    double getSeasonalDiscount(){
        return discount;
    }

    void setSeasonalDiscount(double newDiscount){
        discount = newDiscount;
    }

    ~Concert(){}
};

class ElectronicConcert: public Concert{
    char *dj;
    float hours;
    bool daytime;

    void copyElectronicConcert(const ElectronicConcert &other){
        this->dj = new char[strlen(other.dj)+1];
        strcpy(this->dj, other.dj);
        this->hours = other.hours;
        this->daytime = other.daytime;
    }

public:
    ElectronicConcert() : Concert(){
        this->dj = new char[3];
        strcpy(this->dj, "dj");
        this->hours = 0;
        this->daytime = true;
    }

    ElectronicConcert(char *name, char *location, double price,
                      char *dj, float hours, bool daytime): Concert(name, location, price){
        this->dj = new char[strlen(dj)+1];
        strcpy(this->dj, dj);
        this->hours = hours;
        this->daytime = daytime;
    }

    ElectronicConcert(const ElectronicConcert &other):Concert(other){
        copyElectronicConcert(other);
    }

    ElectronicConcert &operator=(const ElectronicConcert &other){
        if(this != &other){
            Concert::operator=(other);
            delete[] dj;
            copyElectronicConcert(other);
        }
        return *this;
    }

    double priceWithDiscount(){
        int additionalPrice = 0;

        if(hours > 7){
            additionalPrice += 360;
        } else if(hours > 5){
            additionalPrice += 150;
        }
        additionalPrice += daytime ? -50 : 100;

        return price * (1.0 - discount) + additionalPrice;
    }

    ~ElectronicConcert(){
        delete[] dj;
    }
};

double Concert::discount = 0.2;

void mostExpensiveConcert(Concert **concerts, int n){
    int index = 0;
    int counter = 0;

    for(int i=1; i<n; i++){
        if(concerts[i]->priceWithDiscount() >
        concerts[index]->priceWithDiscount()){
            index = i;
        }
        if(dynamic_cast<ElectronicConcert*>(concerts[i])){
            counter++;
        }
    }

    cout<<"Najskap koncert: "
    <<concerts[index]->getName()<<" "
    <<concerts[index]->priceWithDiscount()<<"\n";

    cout<<"Elektronski koncerti: "
    <<counter<<" od vkupno "<<n<<"\n";
}

bool searchConcert(Concert **concerts, int n, char *name, bool electronic){
    for(int i=0; i<n; i++){
        if(!electronic || dynamic_cast<ElectronicConcert*>(concerts[i])){
            if(!strcmp(name, concerts[i]->getName())){

                cout<<concerts[i]->getName()<<" "
                <<concerts[i]->priceWithDiscount()<<"\n";
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int type, n, newPrice;
    char name[100], location[100], djName[40];
    bool daytime;
    float ticketPrice, newDiscount;
    float hours;

    cin >> type;

    if (type == 1)
    {//Concert
        cin >> name >> location >> ticketPrice;

        Concert c1(name, location, ticketPrice);

        cout << "Kreiran e koncert so naziv: "
             << c1.getName() << endl;
    }

    else if (type == 2)
    {//price - Concert
        cin >> name >> location >> ticketPrice;

        Concert c1(name, location, ticketPrice);

        cout << "Osnovna cena na koncertot so naziv "
             << c1.getName()
             << " e: "
             << c1.priceWithDiscount()
             << endl;
    }

    else if (type == 3)
    {//ElectronicConcert
        cin >> name >> location >> ticketPrice
            >> djName >> hours >> daytime;

        ElectronicConcert concert(
                name,
                location,
                ticketPrice,
                djName,
                hours,
                daytime
        );

        cout << "Kreiran e elektronski koncert so naziv "
             << concert.getName()
             << " i sezonskiPopust "
             << concert.getSeasonalDiscount()
             << endl;
    }

    else if (type == 4)
    {//price - ElectronicConcert
        cin >> name >> location >> ticketPrice
            >> djName >> hours >> daytime;

        ElectronicConcert concert(
                name,
                location,
                ticketPrice,
                djName,
                hours,
                daytime
        );

        cout << "Cenata na elektronskiot koncert so naziv "
             << concert.getName()
             << " e: "
             << concert.priceWithDiscount()
             << endl;
    }

    else if (type == 5)
    {//mostExpensiveConcert

    }

    else if (type == 6)
    {//searchConcert
        Concert **concerts = new Concert *[5];

        int n;

        concerts[0] =
                new Concert("Area", "BorisTrajkovski", 350);

        concerts[1] =
                new ElectronicConcert(
                        "TomorrowLand",
                        "Belgium",
                        8000,
                        "Afrojack",
                        7.5,
                        false
                );

        concerts[2] =
                new ElectronicConcert(
                        "SeaDance",
                        "Budva",
                        9100,
                        "Tiesto",
                        5,
                        true
                );

        concerts[3] =
                new Concert("Superhiks", "PlatoUkim", 100);

        concerts[4] =
                new ElectronicConcert(
                        "CavoParadiso",
                        "Mykonos",
                        8800,
                        "Guetta",
                        3,
                        true
                );

        char name[100];

        mostExpensiveConcert(concerts, 5);
    }

    else if (type == 7)
    {//search
        Concert **concerts = new Concert *[5];

        int n;

        concerts[0] =
                new Concert("Area", "BorisTrajkovski", 350);

        concerts[1] =
                new ElectronicConcert(
                        "TomorrowLand",
                        "Belgium",
                        8000,
                        "Afrojack",
                        7.5,
                        false
                );

        concerts[2] =
                new ElectronicConcert(
                        "SeaDance",
                        "Budva",
                        9100,
                        "Tiesto",
                        5,
                        true
                );

        concerts[3] =
                new Concert("Superhiks", "PlatoUkim", 100);

        concerts[4] =
                new ElectronicConcert(
                        "CavoParadiso",
                        "Mykonos",
                        8800,
                        "Guetta",
                        3,
                        true
                );

        char name[100];
        bool electronic;

        cin >> electronic;

        if (searchConcert(concerts, 5, "Area", electronic))
            cout << "Pronajden" << endl;
        else
            cout << "Ne e pronajden" << endl;

        if (searchConcert(concerts, 5, "Area", !electronic))
            cout << "Pronajden" << endl;
        else
            cout << "Ne e pronajden" << endl;
    }

    else if (type == 8)
    {//change price
        Concert **concerts = new Concert *[5];

        int n;

        concerts[0] =
                new Concert("Area", "BorisTrajkovski", 350);

        concerts[1] =
                new ElectronicConcert(
                        "TomorrowLand",
                        "Belgium",
                        8000,
                        "Afrojack",
                        7.5,
                        false
                );

        concerts[2] =
                new ElectronicConcert(
                        "SeaDance",
                        "Budva",
                        9100,
                        "Tiesto",
                        5,
                        true
                );

        concerts[3] =
                new Concert("Superhiks", "PlatoUkim", 100);

        concerts[2]->setSeasonalDiscount(0.9);

        mostExpensiveConcert(concerts, 4);
    }

    return 0;
}
