
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Ride {
    char name[100];
    int duration;
    float price;
    int hasDiscount;
};

struct AmusementPark {
    char name[100];
    char location[100];
    Ride rides[100];
    int numRides;
};

void print(AmusementPark *parks, int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        cout << parks[i].name << " " << parks[i].location << endl;

        for (j = 0; j < parks[i].numRides; j++) {
            cout << parks[i].rides[j].name << " "
                 << parks[i].rides[j].duration << " "
                 << fixed << setprecision(2)
                 << parks[i].rides[j].price << endl;
        }
    }
}

void bestPark(AmusementPark *parks, int n) {
    int i, j, bestIndex = 0, maxDiscounts = 0;
    int maxDuration = 0;

    for (i = 0; i < n; i++) {
        int count = 0;
        int totalDuration = 0;

        for (j = 0; j < parks[i].numRides; j++) {
            if (parks[i].rides[j].hasDiscount == 1) {
                count++;
            }

            totalDuration += parks[i].rides[j].duration;
        }

        if (count > maxDiscounts) {
            maxDiscounts = count;
            bestIndex = i;
            maxDuration = totalDuration;
        }
        else if (count == maxDiscounts &&
                 totalDuration > maxDuration) {
            bestIndex = i;
            maxDuration = totalDuration;
        }
    }

    cout << "Najdobar park: "
         << parks[bestIndex].name << " "
         << parks[bestIndex].location << endl;
}

int main() {
    int i, j, n;
    AmusementPark parks[100];

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> parks[i].name;
        cin >> parks[i].location;
        cin >> parks[i].numRides;

        for (j = 0; j < parks[i].numRides; j++) {
            cin >> parks[i].rides[j].name;
            cin >> parks[i].rides[j].duration;
            cin >> parks[i].rides[j].price;
            cin >> parks[i].rides[j].hasDiscount;
        }
    }

    print(parks, n);
    bestPark(parks, n);

    return 0;
}
