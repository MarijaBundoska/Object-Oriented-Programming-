#include <iostream>
#include <cstring>
using namespace std;

struct Dance {
    char name[15];
    char country[15];
};

struct Dancer {
    char firstName[20];
    char lastName[20];
    Dance dances[5];
};

void findDancers(Dancer *dancers, int n, char *country) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            if (strcmp(dancers[i].dances[j].country, country) == 0) {
                cout << dancers[i].firstName << " "
                     << dancers[i].lastName << ", "
                     << dancers[i].dances[j].name << endl;

                break;
            }
        }
    }
}

int main() {
    int i, j, n;
    char country[15];
    Dancer dancers[5];

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> dancers[i].firstName;
        cin >> dancers[i].lastName;

        for (j = 0; j < 3; j++) {
            cin >> dancers[i].dances[j].name;
            cin >> dancers[i].dances[j].country;
        }
    }

    cin >> country;
    findDancers(dancers, n, country);

    return 0;
}
