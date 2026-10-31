#include <stdio.h>
#include <string.h>

#define WEEKS 4
#define DAYS 5

// Structure WorkWeek

struct WorkWeek {
    int hours[DAYS];
    int number;
};

typedef struct WorkWeek WW;

// Structure Worker

struct Worker {
    char name[50];
    WW weeks[WEEKS];
};

typedef struct Worker W;

// Functions

int maxWeek(W *worker) {
    int maxHours = 0;
    int maxNumber = 1;

    for (int i = 0; i < WEEKS; i++) {
        int total = 0;

        for (int j = 0; j < DAYS; j++) {
            total += worker->weeks[i].hours[j];
        }

        if (total > maxHours) {
            maxHours = total;
            maxNumber = i + 1;
        }
    }

    return maxNumber;
}

void table(W *workers, int n) {
    printf("Rab\t1\t2\t3\t4\tVkupno\n");

    for (int i = 0; i < n; i++) {
        int weeklyTotals[WEEKS] = {0};
        int totalHours = 0;

        for (int j = 0; j < WEEKS; j++) {
            for (int k = 0; k < DAYS; k++) {
                weeklyTotals[j] += workers[i].weeks[j].hours[k];
            }

            totalHours += weeklyTotals[j];
        }

        printf("%s\t", workers[i].name);

        for (int j = 0; j < WEEKS; j++) {
            printf("%d\t", weeklyTotals[j]);
        }

        printf("%d\n", totalHours);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    W workers[n];

    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", workers[i].name);

        int j;
        for (j = 0; j < WEEKS; ++j) {
            int k;
            for (k = 0; k < DAYS; ++k) {
                scanf("%d", &workers[i].weeks[j].hours[k]);
            }
        }
    }

    printf("TABLE\n");
    table(workers, n);

    printf("MAX NEDELA NA RABOTNIK: %s\n", workers[n / 2].name);
    printf("%d\n", maxWeek(&workers[n / 2]));

    return 0;
}
