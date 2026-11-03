#include <iostream>
#include <string>

using namespace std;

//Your code here

class Library {
protected:
    string name;
    string city;
    float base_price;
    bool weekend_working;

public:
    Library(string name, string city, float base_price, bool weekend_working)
        : name(name), city(city), base_price(base_price),
          weekend_working(weekend_working) {}

    virtual void printDetail() = 0;

    virtual double calculateMembershipCardCost() = 0;

    bool worksOnWeekend() const {
        return weekend_working;
    }

    virtual ~Library() {}
};

class AcademicLibrary : public Library {
private:
    bool open_cooperation;
    int specialized_articles;

public:
    AcademicLibrary(string name, string city, float base_price,
                    bool weekend_working, bool open_cooperation,
                    int specialized_articles)
        : Library(name, city, base_price, weekend_working),
          open_cooperation(open_cooperation),
          specialized_articles(specialized_articles) {}

    double calculateMembershipCardCost() override {
        double price = base_price;

        if (open_cooperation) {
            price *= 1.24;
        }

        price += specialized_articles * 6;

        return price;
    }

    void printDetail() override {
        cout << name << " - (Academic) " << city << " "
             << specialized_articles << " "
             << calculateMembershipCardCost() << endl;
    }
};

class NationalLibrary : public Library {
private:
    bool cultural_program;
    int national_articles;

public:
    NationalLibrary(string name, string city, float base_price,
                    bool weekend_working, bool cultural_program,
                    int national_articles)
        : Library(name, city, base_price, weekend_working),
          cultural_program(cultural_program),
          national_articles(national_articles) {}

    double calculateMembershipCardCost() override {
        double price = base_price;

        if (cultural_program) {
            price *= 0.93;
        }

        price += national_articles * 15;

        return price;
    }

    void printDetail() override {
        cout << name << " - (National) " << city << " "
             << national_articles << " "
             << calculateMembershipCardCost() << endl;
    }
};

int findMostExpensiveNationalLibrary(Library **l, int n) {
    int index = -1;
    double maxPrice = -1;

    for (int i = 0; i < n; i++) {
        NationalLibrary *national =
            dynamic_cast<NationalLibrary*>(l[i]);

        if (national != nullptr) {
            double currentPrice =
                national->calculateMembershipCardCost();

            if (currentPrice > maxPrice) {
                maxPrice = currentPrice;
                index = i;
            } else if (currentPrice == maxPrice &&
                       national->worksOnWeekend()) {
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

    Library** m = new Library*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        bool weekend_working;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> weekend_working;
        cin.ignore();

        if (type == 1) {
            bool open_cooperation;
            int specialized_articles;

            cin >> open_cooperation >> specialized_articles;
            cin.ignore();

            m[i] = new AcademicLibrary(name, city, base_price, weekend_working, open_cooperation, specialized_articles);
        } else {
            bool cultural_program;
            int national_articles;

            cin >> cultural_program >> national_articles;
            cin.ignore();

            m[i] = new NationalLibrary(name, city, base_price, weekend_working, cultural_program, national_articles);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateMembershipCardCost() << endl;
        }
        cout << "calculateMembershipCardCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int most_expensive_nat_lib_index = findMostExpensiveNationalLibrary(m, n);
        if(most_expensive_nat_lib_index>=0){
            m[most_expensive_nat_lib_index]->printDetail();
        }else{
            cout << "National Library not found in the array!"<<endl;
        }
        cout << "findMostExpensiveNationalLibrary method OK" << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}
