#include <iostream>
#include <cstring>
using namespace std;

struct Train {
    char route[50];
    float kilometers;
    int passengers;
};

struct RailwayStation {
    char city[20];
    Train trains[30];
    int num;
};

void shortestRoute(RailwayStation *stations, int n, char *city) {
    float minKilometers;
    char shortest[50];
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (strcmp(stations[i].city, city) == 0) {
            for (int j = 0; j < stations[i].num; j++) {
                if (!found || stations[i].trains[j].kilometers <= minKilometers) {
                    minKilometers = stations[i].trains[j].kilometers;
                    strcpy(shortest, stations[i].trains[j].route);
                    found = true;
                }
            }
        }
    }

    if (found) {
        cout << "Najkratka relacija: "<< shortest << " (" << minKilometers<<" km)" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    RailwayStation stations[100];

    for (int i = 0; i < n; i++) {
        cin >> stations[i].city;
        cin >> stations[i].num;

        for (int j = 0; j < stations[i].num; j++) {
            cin >> stations[i].trains[j].route;
            cin >> stations[i].trains[j].kilometers;
            cin >> stations[i].trains[j].passengers;
        }
    }

    char city[20];
    cin >> city;

    shortestRoute(stations, n, city);

    return 0;
}
