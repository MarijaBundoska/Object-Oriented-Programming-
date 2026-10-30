#include <iostream>
using namespace std;

struct Laptop {
    char brand[100];
    float monitorSize;
    bool hasTouch;
    int price;

    void print();
};

void Laptop::print() {
    cout << brand << " " << monitorSize << " " << price << endl;
}

struct ITStore {
    char name[100];
    char location[100];
    Laptop laptops[100];
    int numLaptops;

    void print();
};

void ITStore::print() {
    cout << name << " " << location << endl;

    for (int i = 0; i < numLaptops; i++) {
        laptops[i].print();
    }
}

int lowestPrice(ITStore store) {
    int minPrice = 0;
    int found = 0;

    for (int i = 0; i < store.numLaptops; i++) {
        if (store.laptops[i].hasTouch) {
            if (!found) {
                minPrice = store.laptops[i].price;
                found = 1;
            }
            else if (store.laptops[i].price < minPrice) {
                minPrice = store.laptops[i].price;
            }
        }
    }

    return found ? minPrice : -1;
}

void cheapestOffer(ITStore stores[], int n) {
    int minPrice = lowestPrice(stores[0]);
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        int currentPrice = lowestPrice(stores[i]);

        if (currentPrice != -1 &&
            (minPrice == -1 || currentPrice < minPrice)) {
            minPrice = currentPrice;
            minIndex = i;
        }
    }

    if (minPrice != -1) {
        cout << "Najeftina ponuda ima prodavnicata:" << endl;
        cout << stores[minIndex].name << " "
             << stores[minIndex].location << endl;
        cout << "Najniskata cena iznesuva: "
             << minPrice << endl;
    }
}

int main() {
    ITStore s[100];
    int n;
    cin >> n; 



    for (int i = 0; i < n; i++) {
        cin >> s[i].name;
        cin >> s[i].location;
        cin >> s[i].numLaptops;

        for (int j = 0; j < s[i].numLaptops; j++) {
            cin >> s[i].laptops[j].brand;
            cin >> s[i].laptops[j].monitorSize;
            cin >> s[i].laptops[j].hasTouch;
            cin >> s[i].laptops[j].price;
        }
    }

   

    for (int i = 0; i < n; i++) {
        s[i].print();
    }



    cheapestOffer(s, n);

    return 0;
}
