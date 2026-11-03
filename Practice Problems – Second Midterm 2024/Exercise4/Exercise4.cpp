#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Museum {
protected:
    string name;
    string city;
    float base_price;
    int working_hours;

public:
    Museum(string name, string city, float base_price, int working_hours)
        : name(name), city(city), base_price(base_price),
          working_hours(working_hours) {}

    virtual void printDetail() = 0;
    virtual double calculateTicketCost() = 0;

    int getWorkingHours() const {
        return working_hours;
    }

    virtual ~Museum() {}
};

class ScientificMuseum : public Museum {
private:
    bool interactive_shows;
    int multimedia_pres;

public:
    ScientificMuseum(string name, string city, float base_price,
                     int working_hours, bool interactive_shows,
                     int multimedia_pres)
        : Museum(name, city, base_price, working_hours),
          interactive_shows(interactive_shows),
          multimedia_pres(multimedia_pres) {}

    double calculateTicketCost() override {
        double price = base_price;

        if (interactive_shows) {
            price *= 1.12;
        }

        price += multimedia_pres * 6;

        return price;
    }

    void printDetail() override {
        cout << name << " - (Scientific) " << city << " "
             << multimedia_pres << " "
             << calculateTicketCost() << endl;
    }
};

class ArtMuseum : public Museum {
private:
    bool amateur_shows;
    int original_artwork;

public:
    ArtMuseum(string name, string city, float base_price,
              int working_hours, bool amateur_shows,
              int original_artwork)
        : Museum(name, city, base_price, working_hours),
          amateur_shows(amateur_shows),
          original_artwork(original_artwork) {}

    double calculateTicketCost() override {
        double price = base_price;

        if (amateur_shows) {
            price *= 0.82;
        }

        price += original_artwork * 3;

        return price;
    }

    void printDetail() override {
        cout << name << " - (Art) " << city << " "
             << amateur_shows << " "
             << calculateTicketCost() << endl;
    }
};

int findCheapestScientificMuseum(Museum **m, int n) {
    int index = -1;
    double minPrice = 0;
    int maxWorkingHours = -1;

    for (int i = 0; i < n; i++) {
        ScientificMuseum *scientific =
            dynamic_cast<ScientificMuseum*>(m[i]);

        if (scientific != nullptr) {
            double currentPrice = scientific->calculateTicketCost();
            int currentHours = scientific->getWorkingHours();

            if (index == -1 || currentPrice < minPrice) {
                minPrice = currentPrice;
                maxWorkingHours = currentHours;
                index = i;
            } 
            else if (currentPrice == minPrice &&
                     currentHours >= maxWorkingHours) {
                maxWorkingHours = currentHours;
                index = i;
            }
        }
    }

    return index;
}

int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Museum** m = new Museum*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        int working_hours;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> working_hours;
        cin.ignore();

        if (type == 1) {
            bool interactive_shows;
            int multimedia_pres;

            cin >> interactive_shows >> multimedia_pres;
            cin.ignore();

            m[i] = new ScientificMuseum(name, city, base_price,
                                        working_hours, interactive_shows,
                                        multimedia_pres);
        } else {
            bool amateur_shows;
            int original_artwork;

            cin >> amateur_shows >> original_artwork;
            cin.ignore();

            m[i] = new ArtMuseum(name, city, base_price,
                                 working_hours, amateur_shows,
                                 original_artwork);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateTicketCost() << endl;
        }
        cout << "calculateTicketCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int cheapest_sci_museum_index = findCheapestScientificMuseum(m, n);
        if(cheapest_sci_museum_index>=0){
            m[cheapest_sci_museum_index]->printDetail();
        }else{
            cout << "Scientific Museum not found in the array!"<<endl;
        }
        cout << "findCheapestOnlineOrder method OK" << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}
