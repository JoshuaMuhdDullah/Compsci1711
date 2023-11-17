#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here

// Global variables for filename and FITNESS_DATA array
char filename[buffersize];
FITNESS_DATA dataarray[buffersize];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

FILE *openfile(char *filename, char *mode)
{
    // to do
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }
    printf("File successfully loaded.");
    return file;
}

int totalrecords(FILE *inputfile)
{   
    char line[buffersize];
    int counter = 0;
    while (fgets(line, buffersize, inputfile))
    {
        counter++;
    }
    return counter;
}   


// Complete the main function
int main() 
{
    char choice;
    int counter = 0;
    int mean = 0;
    int lowest = 999999;
    int highest = 0;

    while(1) 
    {

        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");

        scanf(" %c",&choice);
    
        switch (choice)
        {
        case 'A':
        case 'a':
            printf("Input filename: ");
            scanf("%s", filename);

            FILE *file = openfile(filename, "r");
            break;
        
        case 'B':
        case 'b':
            counter = totalrecords(file);
            printf("Total records: %d\n", counter);
            break;
    
        case 'C'
        case 'c':
            break;
        
        case 'D':
        case 'd':
            break;

        case 'E':
        case 'e':
            break;

        case 'F':
        case 'f':
            break;

        case 'Q':
        case 'q':
            return(0);
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}









