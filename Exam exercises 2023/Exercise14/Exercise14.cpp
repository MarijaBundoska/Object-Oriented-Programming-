#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class SMS {
protected:
    double basePrice;
    char number[16];

    const static double baseDDV;
    static double roamingDDV;
    static double notHumanDDV;

public:
    SMS(double price, const char *num) {
        this->basePrice = price;
        strcpy(this->number, num);
    }

    virtual ~SMS() {}

    virtual double SMS_price() = 0;

    static void set_rPercent(double per) {
        roamingDDV = per / 100.0 + 1;
    }

    static void set_sPercent(double per) {
        notHumanDDV = per / 100.0 + 1;
    }

    friend ostream &operator<<(ostream &os, SMS &s) {
        return os << "Tel: " << s.number
                  << " - cena: " << s.SMS_price()
                  << "den." << endl;
    }
};

const double SMS::baseDDV = 1.18;
double SMS::roamingDDV = 4.0;
double SMS::notHumanDDV = 2.5;


class RegularSMS : public SMS {
private:
    char *text;
    bool roaming;

public:
    RegularSMS(const char *number, double price,
               const char *text, bool roaming)
            : SMS(price, number) {

        this->text = new char[strlen(text) + 1];
        strcpy(this->text, text);

        this->roaming = roaming;
    }

    ~RegularSMS() {
        delete[] text;
    }

    double SMS_price() override {
        double newPrice;

        if (roaming) {
            newPrice = basePrice * roamingDDV;
        } else {
            newPrice = basePrice * baseDDV;
        }

        return newPrice * ceil((double) strlen(text) / 160.0);
    }
};


class SpecialSMS : public SMS {
private:
    bool human;

public:
    SpecialSMS(const char *number, double price, bool human)
            : SMS(price, number) {

        this->human = human;
    }

    double SMS_price() override {
        if (human) {
            return basePrice;
        } else {
            return basePrice * notHumanDDV;
        }
    }
};


void totalSMS(SMS **poraka, int n) {
    double sumR = 0;
    int numR = 0;

    double sumS = 0;
    int numS = 0;

    for (int i = 0; i < n; i++) {
        RegularSMS *temp =
                dynamic_cast<RegularSMS *>(poraka[i]);

        if (temp != nullptr) {
            sumR += temp->SMS_price();
            numR++;
        } else {
            SpecialSMS *t =
                    dynamic_cast<SpecialSMS *>(poraka[i]);

            if (t != nullptr) {
                sumS += t->SMS_price();
                numS++;
            }
        }
    }

    cout << "Vkupno ima " << numR
         << " regularni SMS poraki i nivnata cena e: "
         << sumR << endl;

    cout << "Vkuono ima " << numS
         << " specijalni SMS poraki i nivnata cena e: "
         << sumS << endl;
}


int main() {
    char tel[20], msg[1000];
    float cena;
    int p;

    bool roam, hum;

    SMS **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====== Testing RegularSMS class ======" << endl;

        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;

            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);

            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }

        for (int i = 0; i < n; i++) {
            delete sms[i];
        }

        delete[] sms;
    }

    if (testCase == 2) {
        cout << "====== Testing SpecialSMS class ======" << endl;

        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin >> hum;

            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);

            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }

        for (int i = 0; i < n; i++) {
            delete sms[i];
        }

        delete[] sms;
    }

    if (testCase == 3) {
        cout << "====== Testing method vkupno_SMS() ======" << endl;

        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> tel;
            cin >> cena;

            if (tip == 1) {
                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;

                sms[i] = new RegularSMS(tel, cena, msg, roam);
            } else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        totalSMS(sms, n);

        for (int i = 0; i < n; i++) {
            delete sms[i];
        }

        delete[] sms;
    }

    if (testCase == 4) {
        cout << "====== Testing RegularSMS class with a changed percentage======"
             << endl;

        SMS *sms1, *sms2;

        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;

        sms1 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        cin >> p;

        SMS::set_rPercent(p);

        sms2 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms2;

        delete sms1;
        delete sms2;
    }

    if (testCase == 5) {
        cout << "====== Testing SpecialSMS class with a changed percentage======"
             << endl;

        SMS *sms1, *sms2;

        cin >> tel;
        cin >> cena;
        cin >> hum;

        sms1 = new SpecialSMS(tel, cena, hum);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin >> hum;
        cin >> p;

        SMS::set_sPercent(p);

        sms2 = new SpecialSMS(tel, cena, hum);
        cout << *sms2;

        delete sms1;
        delete sms2;
    }

    return 0;
}

