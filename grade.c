#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subject {
    char name[20];
    int marks[6];
};

typedef struct Subject Subject;

void calculateCGPA(Subject *subjects, int numSubjects) {
    int totalMarks = 0;
    for (int i = 0; i < numSubjects; i++) {
        int subjectTotal = 0;
        for (int j = 0; j < 6; j++) {
            subjectTotal += subjects[i].marks[j];
        }
        totalMarks += subjectTotal;
        printf("%s\t\t", subjects[i].name);
        for (int j = 0; j < 6; j++) {
            printf("%d\t", subjects[i].marks[j]);
        }
        printf("\n");
    }

    float cgpa = (float)totalMarks / (numSubjects * 600) * 10;
    printf("CGPA: %.2f\n", cgpa);

    // Determine Grade
    if (cgpa == 10)
        printf("GRADE: S\n");
    else if (cgpa >= 9)
        printf("GRADE: A\n");
    else if (cgpa >= 8)
        printf("GRADE: B\n");
    else if (cgpa >= 7)
        printf("GRADE: C\n");
    else if (cgpa >= 6)
        printf("GRADE: D\n");
    else if (cgpa >= 5)
        printf("GRADE: E\n");
    else
        printf("GRADE: Fail\n");
}

int main() {
    int SRN;
    printf("Enter your SRN: ");
    scanf("%d", &SRN);

    int numSubjects;
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    Subject *subjects = (Subject *)malloc(numSubjects * sizeof(Subject));

    char sub[][20] = {"Physics", "Maths", "EEE", "Mech", "C.S", "EVS"};

    for (int i = 0; i < numSubjects; i++) {
        strcpy(subjects[i].name, sub[i]);
        printf("Enter marks for %s: ", subjects[i].name);
        for (int j = 0; j < 6; j++) {
            scanf("%d", &subjects[i].marks[j]);
        }
    }

    printf("\nSubject\t\tMarks1\tMarks2\tMarks3\tMarks4\tMarks5\tMarks6\n");
    calculateCGPA(subjects, numSubjects);

    
    free(subjects);

    return 0;
}
