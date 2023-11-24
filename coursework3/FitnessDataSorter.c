#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffersize 1024

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Global variables and array
char filename[buffersize];
FitnessData DataArray[buffersize];

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


// Function to open file
FILE *openfile(char *filename, char *mode)
{
    // File open and handle error
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error: invalid file\n");
        exit(1);
    }
    printf("File successfully loaded.\n");
    return file;
}

// Function to read file
int readfile(FILE *inputfile, FitnessData *dataarray)
{   
    // Initialize Elements
    char date[11], time[6], steps[10];
    char line[buffersize];
    int counter = 0;

    while (fgets(line, buffersize, inputfile))
    {     
        // Tokenise and put into data array
        tokeniseRecord(line, ",", date, time, steps);
        strcpy(dataarray[counter].date, date);
        strcpy(dataarray[counter].time, time);
        dataarray[counter].steps = atoi(steps);
        // Increase count
        counter++;
    }
    return counter;
}   


int main() {
    // Ask user for filename
    printf("Enter Filename: ");
    scanf("%c",filename);

    // Open file using fucntion
    FILE *file = openfile(filename, "r")
    
    // Read file to array using functiom
    NumRecords = readfile(file, DataArray)

    // Sort Array
}
