#include <stdio.h>

struct Patient {
    char name[100];
    int insured;
    int examinations;
};

struct FamilyDoctor {
    char name[100];
    int patientCount;
    Patient patients[200];
    float examinationPrice;
};

void mostSuccessfulDoctor(FamilyDoctor doctors[], int n) {
    int i, j;
    int bestDoctor = 0;

    float maxEarnings = -1;
    int maxExaminations = -1;

    for (i = 0; i < n; i++) {
        float earnings = 0;
        int totalExaminations = 0;

        for (j = 0; j < doctors[i].patientCount; j++) {
            totalExaminations += doctors[i].patients[j].examinations;

            if (doctors[i].patients[j].insured == 0) {
                earnings += doctors[i].patients[j].examinations
                            * doctors[i].examinationPrice;
            }
        }

        if (earnings > maxEarnings ||
            (earnings == maxEarnings &&
             totalExaminations > maxExaminations)) {

            maxEarnings = earnings;
            maxExaminations = totalExaminations;
            bestDoctor = i;
        }
    }

    printf("%s %.2f %d\n",
           doctors[bestDoctor].name,
           maxEarnings,
           maxExaminations);
}

int main() {
    int i, j, n;
    FamilyDoctor doctors[200];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", doctors[i].name);
        scanf("%d", &doctors[i].patientCount);
        scanf("%f", &doctors[i].examinationPrice);

        for (j = 0; j < doctors[i].patientCount; j++) {
            scanf("%s", doctors[i].patients[j].name);
            scanf("%d", &doctors[i].patients[j].insured);
            scanf("%d", &doctors[i].patients[j].examinations);
        }
    }

    mostSuccessfulDoctor(doctors, n);

    return 0;
}
