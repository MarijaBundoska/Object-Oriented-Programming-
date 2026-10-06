#include <iostream>
#include <cstring>
using namespace std;
class Artwork {
private:
    char name[50];
    int year;
    char from[50];

    void copy(const Artwork &a){
        strcpy(this->name, a.name);
        this->year = a.year;
        strcpy(this->from, a.from);
    }

public:

    Artwork(){
        this->year = 0;
        strcpy(this->name, "name");
        strcpy(this->from, "from");
    }

    Artwork(char *name, int year, char *from){
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->from, from);
    }

    ~Artwork(){}

    Artwork(const Artwork &other){
        copy(other);
    }

    Artwork operator=(const Artwork &a){
        if(this != &a){
            copy(a);
        }
        return *this;
    }

    const char *getFrom() const{
        return from;
    }

    int getYear() const{
        return year;
    }

    const char *getName() const{
        return name;
    }

    bool operator==(const Artwork &a){
        return (!strcmp(name, a.name));
    }
};

class Performance{
private:
    Artwork artwork;
    int tickets;
    char *date;

    void copy(const Performance &p){
        this->artwork = p.artwork;
        this->tickets =  p.tickets;
        this->date = new char[strlen(p.date)+1];
        strcpy(this->date, p.date);
    }

public:
    Performance(){
        this->artwork = Artwork();
        this->tickets = 0;
        this->date = new char[5];
        strcpy(this->date, "date");
    }

    Performance(Artwork artwork, int tickets, char *date){
        this->artwork = artwork;
        this->tickets = tickets;
        this->date = new char[strlen(date)+1];
        strcpy(this->date, date);
    }
    Performance(const Performance &p){
        copy(p);
    }

    Performance &operator=(const Performance &other){
        if(this != &other){
            delete[] date;
            copy(other);
        }
        return *this;
    }

    ~Performance(){
        delete[] date;
    }

    Artwork getArtwork(){
        return artwork;
    }

    const Artwork &getArtwork() const{
        return artwork;
    }

    int getTickets() const{
        return tickets;
    }

    virtual int price(){
        int m = 0;
        int n = 0;

        if(artwork.getYear() > 1900){
            n = 50;
        }else if(artwork.getYear() > 1800){
            n = 75;
        }else{
            n = 100;
        }

        if(!strcmp(artwork.getFrom(), "Italija")){
            m = 100;
        }else if(!strcmp(artwork.getFrom(), "Rusija")){
            m = 150;
        }else{
            m = 80;
        }
        return n + m;
    }
};

class Ballet : public Performance{
    static int BALLETPRICE;

public:
    Ballet() : Performance(){}

    Ballet(Artwork artwork, int tickets, char *date) : Performance(artwork, tickets, date){}

    int price(){
        return Performance::price() + BALLETPRICE;
    }

    static void setBalletPrice(int price){
        BALLETPRICE = price;
    }

    ~Ballet(){}
};

int Ballet::BALLETPRICE = 150;

class Opera : public Performance{
public:
    Opera() : Performance(){}

    Opera(Artwork artwork, int tickets, char *date): Performance(artwork, tickets, date){}

    ~Opera(){}
};

int revenue(Performance **p, int n){
    int sum = 0;

    for(int i=0; i<n; i++){
        sum+=p[i]->price() * p[i]->getTickets();
    }
    return sum;
}

int numberOfPerformancesForArtwork(Performance **p, int n, Artwork a){
    int count = 0;

    for(int i=0; i<n; i++){
        if(p[i]->getArtwork() == a){
            count++;
        }
    }
    return count;
}

Artwork readArtwork(){
    char name[50];
    int year;
    char country[50];

    cin>>name>>year>>country;

    return Artwork(name, year, country);
}

Performance *readPerformance(){
    int type;
    cin>>type;

    Artwork a = readArtwork();

    int ticketsSold;
    char date[15];

    cin>>ticketsSold>>date;

    if(type == 0){
        return new Ballet(a, ticketsSold, date);
    }else{
        return new Opera(a, ticketsSold, date);
    }
}
int main(){
    int testCase;
    cin >> testCase;

    switch (testCase) {

        case 1:
            // Testing the Opera and Ballet classes
        {
            cout << "======TEST CASE 1=======" << endl;

            Performance* p1 = readPerformance();
            cout << p1->getArtwork().getName() << endl;

            Performance* p2 = readPerformance();
            cout << p2->getArtwork().getName() << endl;
        }
            break;

        case 2:
            // Testing the Opera and Ballet classes with price
        {
            cout << "======TEST CASE 2=======" << endl;

            Performance* p1 = readPerformance();
            cout << p1->price() << endl;

            Performance* p2 = readPerformance();
            cout << p2->price() << endl;
        }
            break;

        case 3:
            // Testing the == operator
        {
            cout << "======TEST CASE 3=======" << endl;

            Artwork w1 = readArtwork();
            Artwork w2 = readArtwork();
            Artwork w3 = readArtwork();

            if (w1 == w2)
                cout << "Isti se" << endl;
            else
                cout << "Ne se isti" << endl;

            if (w1 == w3)
                cout << "Isti se" << endl;
            else
                cout << "Ne se isti" << endl;
        }
            break;

        case 4:
            // Testing the revenue function
        {
            cout << "======TEST CASE 4=======" << endl;

            int n;
            cin >> n;

            Performance **array = new Performance*[n];

            for (int i = 0; i < n; i++) {
                array[i] = readPerformance();
            }

            cout << revenue(array, n);
        }
            break;

        case 5:
            // Testing revenue with changed ballet price
        {
            cout << "======TEST CASE 5=======" << endl;

            int balletPrice;
            cin >> balletPrice;

            Ballet::setBalletPrice(balletPrice);

            int n;
            cin >> n;

            Performance **array = new Performance*[n];

            for (int i = 0; i < n; i++) {
                array[i] = readPerformance();
            }

            cout << revenue(array, n);
        }
            break;

        case 6:
            // Testing numberOfPerformancesForWork
        {
            cout << "======TEST CASE 6=======" << endl;

            int n;
            cin >> n;

            Performance **array = new Performance*[n];

            for (int i = 0; i < n; i++) {
                array[i] = readPerformance();
            }

            Artwork w = readArtwork();

            cout << numberOfPerformancesForArtwork(array, n, w);
        }
            break;
    }
    return 0;
}
