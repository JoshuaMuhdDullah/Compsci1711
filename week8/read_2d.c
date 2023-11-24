#include <stdio.h>
#define numStu 4
#define numMod 3

typedef struct
{   
    // Create struct of Student
    char studentName[32];
    int studentID;
    float gpa;
    int procedural;
    int intro;
    int operating;
} Student;

void extract(Student students[], int extractedData[][numMod])
{   
    // Loop through students array and store marks in extractedData array
    for (int i = 0; i < numStu; i++)
    {
        extractedData[i][0] = students[i].procedural;
        extractedData[i][1] = students[i].intro;
        extractedData[i][2] = students[i].operating;
    }
}

int main() 
{
    // Initialize arrays
    int extractedData[numStu][numMod];
    Student students[numStu] = 
    {
        {"Alex Turner", 2306456, 3.5, 78, 82, 89},
        {"Bob Williams", 2385679, 3.9, 100, 85, 92},
        {"Sophia Mendes", 2374068, 3.7, 93, 90, 87},
        {"Laura Cerroni", 2398452, 3.2, 65, 70, 80}
    };
    extract(students, extractedData);

    // Loop through array of extracted data
    for (int i = 0; i < numStu; i++)
    {
        printf("Student %d: %d, %d, %d\n", i + 1, extractedData[i][0],extractedData[i][1], extractedData[i][2]);
    }

    // Return 0
    return 0;
}