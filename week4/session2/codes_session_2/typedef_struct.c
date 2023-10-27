#include <stdio.h>

typedef struct {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

void output(student arr[], int i) {
    printf("-------------\n");
    printf("Student name: %s\n", arr[i].name);
    printf("Student ID: %s\n", arr[i].student_id);
    printf("Final mark: %u\n", arr[i].mark);
}

int main () {
    // Data generated using ChatGPT.
    int number_of_students = 10, i;

    student students [] = {
        {"Alice Smith",    "64827593", 67},
        {"Bob Johnson",    "19374650", 89},
        {"Charlie Brown",  "82056914", 76},
        {"David Davis",    "45790182", 44},
        {"Eve Wilson",     "36102478", 91},
        {"Frank Anderson", "93571826", 53},
        {"Grace Lee",      "50249867", 78},
        {"Hannah Clark",   "74820591", 62},
        {"Isaac Harris",   "61093745", 89},
        {"Jack White",     "92847501", 72},
    };

    #if 0
    student students [10];
    for (i = 0; i < number_of_students; i++) {
        printf("Name:       ");
        scanf("%s", students[i].name);
        printf("Student ID: ");
        scanf("%s", students[i].student_id);
        printf("Mark:       ");
        scanf("%u", &students[i].mark);
    }
    #endif
    
    for (i = 0; i < number_of_students; i++) {
        output(students, i);
    }
    printf("-------------\n");
    return 0;
}