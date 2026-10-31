#include <iostream>
#include <cstring>
using namespace std;

struct SkiLift {
    char name[20];
    int maxSkiers;
    int inUse;
};

struct SkiCenter {
    char name[20];
    char country[20];
    SkiLift lifts[20];
    int liftCount;
};

int capacity(SkiCenter skiCenter) {
    int total = 0;

    for (int i = 0; i < skiCenter.liftCount; i++) {
        if (skiCenter.lifts[i].inUse == 1) {
            total += skiCenter.lifts[i].maxSkiers;
        }
    }

    return total;
}

void highestCapacity(SkiCenter *skiCenters, int n) {
    int max = 0;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
        int total = capacity(skiCenters[i]);

        if (total > max ||
            (total == max &&
             skiCenters[i].liftCount > skiCenters[maxIndex].liftCount)) {
            max = total;
            maxIndex = i;
        }
    }

    cout << skiCenters[maxIndex].name << endl;
    cout << skiCenters[maxIndex].country << endl;
    cout << max << endl;
}

int main() {
    int n;
    SkiCenter skiCenters[20];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> skiCenters[i].name;
        cin >> skiCenters[i].country;
        cin >> skiCenters[i].liftCount;

        for (int j = 0; j < skiCenters[i].liftCount; j++) {
            cin >> skiCenters[i].lifts[j].name;
            cin >> skiCenters[i].lifts[j].maxSkiers;
            cin >> skiCenters[i].lifts[j].inUse;
        }
    }

    highestCapacity(skiCenters, n);

    return 0;
}
