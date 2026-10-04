#include <iostream>
#include <cstring>
#define MAX_PINS 4
#define DEFAULT_LIMIT 7
using namespace std;

class OutOfBoundsException{
public:

    void message(){
        cout<<"Brojot na pin kodovi ne moze da go nadmine dozvolenoto\n";
    }

};
class Card{
protected:
    char account[16];
    int pin;
    bool hasAdditionalPin;

private:

    void copyCard(const Card &other){
        strcpy(this->account, other.account);
        this->pin = other.pin;
        this->hasAdditionalPin = other.hasAdditionalPin;
    }

public:
    Card(){
        strcpy(this->account, "account");
        this->pin = 0;
        this->hasAdditionalPin = false;
    }

    Card(char *account, int pin){
        strcpy(this->account, account);
        this->pin = pin;
        this->hasAdditionalPin = false;
    }

    Card(const Card &other){
        copyCard(other);
    }

    Card &operator=(const Card &other){
        if(this != &other){
            copyCard(other);
        }
        return *this;
    }

    virtual int breakingDifficulty(){
        int s =0;
        int c = pin;
        while(c){
            s++;
            c /= 10;
        }
        return s;
    }

    friend ostream &operator<<(ostream &out, Card &c){
        out<<c.account<<": "<<c.breakingDifficulty()<<"\n";
        return out;
    }

    char *getAccount(){
        return account;
    }

    bool getAdditionalPin(){
        return hasAdditionalPin;
    }

    ~Card(){}
};

class SpecialCard: public Card{
    int *pins;
    int numPins;

    void copySpecial(const SpecialCard &other){
        strcpy(this->account, other.account);
        this->pin = other.pin;
        this->hasAdditionalPin = other.hasAdditionalPin;

        this->pins = new int[other.numPins];

        for(int i=0; i<other.numPins; i++){
            this->pins[i] = other.pins[i];
        }
        this->numPins = other.numPins;
    }

public:
    SpecialCard():Card(){
        this->hasAdditionalPin = true;
        this->pins = nullptr;
        this->numPins = 0;
    }

    SpecialCard(char *account, int pin): Card(account, pin){
        this->hasAdditionalPin = true;
        this->pins = nullptr;
        this->numPins = 0;
    }

    SpecialCard(const SpecialCard &other):Card(other){
        copySpecial(other);
    }

    SpecialCard &operator=(const SpecialCard &other){
        if(this != &other){
            Card::operator=(other);
            delete[] pins;
            copySpecial(other);
        }
        return *this;
    }

    SpecialCard& operator+=(int pin){
        if(numPins >= MAX_PINS){
            throw OutOfBoundsException();
        }
        int *temp = new int[numPins +1];

        for(int i=0; i<numPins; i++){
            temp[i] = this->pins[i];
        }

        temp[numPins++] = pin;

        delete[] pins;
        this->pins = new int[numPins];

        for(int i=0; i<numPins; i++){
            this->pins[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }

    int breakingDifficulty(){
        return Card::breakingDifficulty() + numPins;
    }

    ~SpecialCard(){
        delete[] pins;
    }
};

class Bank{
private:
    char name[30];
    Card *cards[20];
    int numOfCards;
    static int LIMIT;

public:
    Bank(){
        strcpy(this->name, "bank");
        this->numOfCards = 0;
    }

    Bank(char *name, Card **cards, int numOfCards){
        strcpy(this->name, name);

        for(int i=0; i<numOfCards; i++){
            if(cards[i] ->getAdditionalPin()){
                this->cards[i] =
                    new SpecialCard(*dynamic_cast<SpecialCard*>(cards[i]));
            }else{
                this->cards[i] = new Card(*cards[i]);
            }
        }
        this->numOfCards = numOfCards;
    }

    static void setLIMIT(int limit){
        LIMIT = limit;
    }

    void addAdditionalPin(char *account, int pin){
        for(int i=0; i<numOfCards; i++){
            if(cards[i]->getAdditionalPin() &&
            !strcmp(this->cards[i]->getAccount(), account)){

                *dynamic_cast<SpecialCard*>(cards[i]) += pin;
            }
        }
    }

    void printCards(){
        cout<<"Vo bankata "<<name <<" moze da se probijat kartickite: \n";

        for(int i=0; i<numOfCards; i++){
            if(this->cards[i]->breakingDifficulty() <= LIMIT){
                cout<<*cards[i];
            }
        }
    }

    ~Bank(){
        for(int i=0; i<numOfCards; i++){
            delete cards[i];
        }
    }
};

int Bank::LIMIT = DEFAULT_LIMIT;
int main(){
    Card **array;
    int n, m, pin;
    char account[16];
    bool hasAdditionalPins;

    cin >> n;

    array = new Card*[n];

    for (int i = 0; i < n; i++){
        cin >> account;
        cin >> pin;
        cin >> hasAdditionalPins;

        if (!hasAdditionalPins)
            array[i] = new Card(account, pin);
        else
            array[i] = new SpecialCard(account, pin);
    }

    Bank commercialBank("Komercijalna", array, n);

    for (int i = 0; i < n; i++)
        delete array[i];

    delete [] array;

    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> account >> pin;

        try {
            commercialBank.addAdditionalPin(account, pin);
        }
        catch(OutOfBoundsException& e) {
            e.message();
        }
    }

    Bank::setLIMIT(5);

    commercialBank.printCards();
    return 0;
}
