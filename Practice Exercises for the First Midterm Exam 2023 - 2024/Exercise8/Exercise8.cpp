#include <iostream>
#include <cstring>
using namespace std;

struct Laptop {
    char brand[100];
    float monitorSize;
    bool hasTouch;
    int price;
};

struct ITStore {
    char name[100];
    char location[100];
    Laptop laptops[100];
    int numLaptops;
};

void print(ITStore *stores, int n) {
    for (int i = 0; i < n; i++) {
        cout << stores[i].name << " "
             << stores[i].location << endl;

        for (int j = 0; j < stores[i].numLaptops; j++) {
            cout << stores[i].laptops[j].brand << " "
                 << stores[i].laptops[j].monitorSize << " "
                 << stores[i].laptops[j].price << endl;
        }
    }
}

void cheapestOffer(ITStore *stores, int n) {
    int minPrice = 0;
    int bestStore = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < stores[i].numLaptops; j++) {
            if (stores[i].laptops[j].hasTouch == 1) {
                if (bestStore == -1 ||
                    stores[i].laptops[j].price < minPrice) {
                    minPrice = stores[i].laptops[j].price;
                    bestStore = i;
                }
            }
        }
    }

    if (bestStore != -1) {
        cout << "Najeftina ponuda ima prodavnicata:" << endl;
        cout << stores[bestStore].name << " "
             << stores[bestStore].location << endl;
        cout << "Najniska cena iznesuva: "
             << minPrice << endl;
    }
}

int main() {
    int n;
    ITStore stores[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stores[i].name;
        cin >> stores[i].location;
        cin >> stores[i].numLaptops;

        for (int j = 0; j < stores[i].numLaptops; j++) {
            cin >> stores[i].laptops[j].brand;
            cin >> stores[i].laptops[j].monitorSize;

            int touch;
            cin >> touch;
            stores[i].laptops[j].hasTouch = touch;

            cin >> stores[i].laptops[j].price;
        }
    }

    print(stores, n);
    cheapestOffer(stores, n);

    return 0;
}
