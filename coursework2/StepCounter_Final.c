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
    // File open and handle error
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }
    printf("File successfully loaded.\n");
    return file;
}

int readfile(FILE *inputfile, FITNESS_DATA *dataarray)
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

int feweststeps(FITNESS_DATA *dataarray, int totalrecords)
{
    int lowest = 9999999;
    int index;
    for (int i = 0; i < totalrecords; i++)
    {   
        if (dataarray[i].steps < lowest)
        {   
            lowest = dataarray[i].steps;
            index = i;
        }
    }
    return index;
}

int largeststeps(FITNESS_DATA *dataarray, int totalrecords)
{
    int largest = 0;
    int index;
    for (int i = 0; i < totalrecords; i++)
    {   
        if (dataarray[i].steps > largest)
        {   
            largest = dataarray[i].steps;
            index = i;
        }
    }
    return index;
}

int meansteps(FITNESS_DATA *dataarray, int totalrecords)
{
    int total;
    for (int i =  0; i < totalrecords; i++)
    {
        total += dataarray[i].steps;
    }
    return total/totalrecords;
}

// Complete the main function
int main() 
{
    char choice;
    int counter = 0;
    int index;
    int mean;

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
            counter = readfile(file, dataarray);
            printf("Total records: %d\n", counter);
            break;
    
        case 'C':
        case 'c':
            counter = readfile(file, dataarray);
            index = feweststeps(dataarray, counter);
            printf("Fewest steps: %s %s\n", dataarray[index].date, dataarray[index].time);
            break;
        
        case 'D':
        case 'd':
            counter = readfile(file, dataarray);
            index = largeststeps(dataarray, counter);
            printf("Largest steps: %s %s\n", dataarray[index].date, dataarray[index].time);
            break;

        case 'E':
        case 'e':
            counter = readfile(file, dataarray);
            mean = meansteps(dataarray, counter);
            printf("Mean step count: %d", mean);
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









