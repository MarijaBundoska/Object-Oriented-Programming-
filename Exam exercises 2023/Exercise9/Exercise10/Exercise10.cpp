#include <iostream>
#include<cstring>
using namespace std;

class NegativeValue{
public:
    void message(){
        cout<<"Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!"<<endl;
    }
};

class Advertisement{
private:
    char title[50];
    char category[30];
    char description[100];
    float price;

    void copy(const Advertisement &ad){
        strcpy(this->title, ad.title);
        strcpy(this->category, ad.category);
        strcpy(this->description, ad.description);
        this->price = ad.price;
    }

public:
    Advertisement(){
        strcpy(this->title, "title");
        strcpy(this->category,"category");
        strcpy(this->description, "description");
        this->price = 0;
    }

    Advertisement(char *title, char *category, char *description, float price){
        strcpy(this->title, title);
        strcpy(this->category, category);
        strcpy(this->description, description);
        this->price = price;
    }

    Advertisement(const Advertisement &ad){
        copy(ad);
    }

    Advertisement operator=(const Advertisement &ad){
        if(this != &ad){
            copy(ad);
        }
        return *this;
    }

    bool operator>(const Advertisement &ad){
        return price > ad.price;
    }

    friend ostream &operator<<(ostream &out, const Advertisement &ad){
        out<<ad.title << endl
        << ad.description<< endl
        << ad.price<<" evra\n";
        return out;
    }

    char *getCategory(){
        return category;
    }

    float getPrice() const{
        return price;
    }

    ~Advertisement(){}
};

class ClassifiedAds{
private:
    char name[20];
    Advertisement *advertisements;
    int n;

    void copy(const ClassifiedAds &ad){
        strcpy(this->name, ad.name);
        this->advertisements = new Advertisement[ad.n];

        for(int i=0; i<ad.n; i++){
            this->advertisements[i] = ad.advertisements[i];
        }
        this->n = ad.n;
    }

public:
    ClassifiedAds(){
        strcpy(this->name, "name");
        this->advertisements = nullptr;
        this->n = 0;
    }

    ClassifiedAds(char *name=""){
        strcpy(this->name, name);
        this->advertisements = nullptr;
        this->n = 0;
    }

    ClassifiedAds(const ClassifiedAds &ad){
        copy(ad);
    }

    ClassifiedAds operator=(const ClassifiedAds &ad){
        if(this != &ad){
            delete[] advertisements;
            copy(ad);
        }
        return *this;
    }

    ClassifiedAds &operator+=(Advertisement &ad){
        if(ad.getPrice() < 0){
            throw NegativeValue();
    }
     Advertisement *temp = new Advertisement[n+1];

        for(int i=0; i<n; i++){
            temp[i] = advertisements[i];
        }
        temp[n++] = ad;

        delete[] advertisements;
        advertisements = temp;

        return *this;
    }

    void advertisementsByCategory(const char *category){
        for(int i=0; i<n; i++){
            if(!strcmp(advertisements[i].getCategory(), category)){
                cout<<advertisements[i]<<endl;
            }
        }
    }

    void lowestPrice(){
        int index = 0;

        for(int i=1; i<n; i++){
            if(advertisements[i].getPrice() < advertisements[index].getPrice()){
                index = i;
            }
        }
        cout<<advertisements[index]<<endl;
    }

    friend ostream &operator<<(ostream &out,const ClassifiedAds &ad){
        out<<ad.name<<endl;

        for(int i=0; i<ad.n; i++){
            out<<ad.advertisements[i]<<endl;
        }
        return out;
    }

    ~ClassifiedAds(){}
};



int main(){
    char title[50];
    char category[30];
    char description[100];
    float price;

    char name[50];
    char categoryName[30];
    int n;

    int type;
    cin >> type;

    if (type == 1) {
        cout<<"-----Test Oglas & operator <<-----" <<endl;

        cin.get();
        cin.getline(title, 49);
        cin.getline(category, 29);
        cin.getline(description, 99);
        cin >> price;

        Advertisement ad(title, category, description, price);
        cout << ad;
    }

    else if (type == 2) {
        cout<<"-----Test Oglas & operator > -----" <<endl;

        cin.get();
        cin.getline(title, 49);
        cin.getline(category, 29);
        cin.getline(description, 99);
        cin >> price;

        Advertisement ad1(title, category, description, price);

        cin.get();
        cin.getline(title, 49);
        cin.getline(category, 29);
        cin.getline(description, 99);
        cin >> price;

        Advertisement ad2(title, category, description, price);

        if (ad1 > ad2)
            cout << "Prviot oglas e poskap." << endl;
        else
            cout << "Prviot oglas ne e poskap." << endl;
    }

    else if (type == 3) {
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;

        cin.get();
        cin.getline(name, 49);
        cin >> n;

        ClassifiedAds ads(name);

        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(title, 49);
            cin.getline(category, 29);
            cin.getline(description, 99);
            cin >> price;

            Advertisement ad(title, category, description, price);

            try {
                ads += ad;
            }
            catch (NegativeValue& n) {
                n.message();
            }
        }

        cout << ads;
    }

    else if (type == 4) {
        cout<<"-----Test oglasOdKategorija -----" <<endl ;

        cin.get();
        cin.getline(name, 49);
        cin >> n;

        ClassifiedAds ads(name);

        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(title, 49);
            cin.getline(category, 29);
            cin.getline(description, 99);
            cin >> price;

            Advertisement ad(title, category, description, price);

            try {
                ads += ad;
            }
            catch (NegativeValue& n) {
                n.message();
            }
        }

        cin.get();
        cin.getline(categoryName, 29);

        cout << "Oglasi od kategorijata: " << categoryName << endl;
        ads.advertisementsByCategory(categoryName);
    }

    else if (type == 5) {
        cout << "-----Test Exception -----" << endl;

        cin.get();
        cin.getline(name, 49);
        cin >> n;

        ClassifiedAds ads(name);

        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(title, 49);
            cin.getline(category, 29);
            cin.getline(description, 99);
            cin >> price;

            Advertisement ad(title, category, description, price);

            try {
                ads += ad;
            }
            catch (NegativeValue& n) {
                n.message();
            }
        }

        cout << ads;
    }

    else if (type == 6) {
        cout<<"-----Test najniskaCena -----" <<endl ;

        cin.get();
        cin.getline(name, 49);
        cin >> n;

        ClassifiedAds ads(name);

        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(title, 49);
            cin.getline(category, 29);
            cin.getline(description, 99);
            cin >> price;

            Advertisement ad(title, category, description, price);

            try {
                ads += ad;
            }
            catch (NegativeValue& n) {
                n.message();
            }
        }

        cout << "Oglas so najniska cena:" << endl;
        ads.lowestPrice();
    }

    else if (type == 7) {
        cout << "-----Test All -----" << endl;

        cin.get();
        cin.getline(name, 49);
        cin >> n;

        ClassifiedAds ads(name);

        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(title, 49);
            cin.getline(category, 29);
            cin.getline(description, 99);
            cin >> price;

            Advertisement ad(title, category, description, price);

            try {
                ads += ad;
            }
            catch (NegativeValue& n) {
                n.message();
            }
        }

        cout << ads;

        cin.get();
        cin.get();
        cin.getline(categoryName, 29);

        cout << "Oglasi od kategorijata: " << categoryName << endl;
        ads.advertisementsByCategory(categoryName);

        cout << "Oglas so najniska cena:" << endl;
        ads.lowestPrice();
    }

    return 0;
}
