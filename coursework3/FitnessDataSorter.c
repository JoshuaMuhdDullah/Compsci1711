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
    char date[11], time[6];
    int steps;
    int *address;
    address = &steps;
    
    char line[buffersize];
    int counter = 0;

    while (fgets(line, buffersize, inputfile))
    {     
        // Tokenise and put into data array
        tokeniseRecord(line, ',', date, time, address);
        strcpy(dataarray[counter].date, date);
        strcpy(dataarray[counter].time, time);
        dataarray[counter].steps = steps;

        // Validate data

        // Increase count
        counter++;
    }
    return counter;
}   

// Sort function
void bubbleSort(FitnessData *dataarray, int len)
{   
    FitnessData temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len; j++)
        {   
            // if smaller swap
            if (dataarray[j].steps < dataarray[j+1].steps)
            {   
                // preform swap
                temp = dataarray[j];
                dataarray[j] = dataarray[j+1];
                dataarray[j+1] = temp;
            }
        }
    }
}


int main() {
    // Initialize variables
    int NumRecords;

    // Ask user for filename
    printf("Enter Filename: ");
    scanf("%s",filename);

    // Open file using fucntion
    FILE *file = openfile(filename, "r");
    
    // Read file to array using functiom
    NumRecords = readfile(file, DataArray);

    // Vaidate data
    for (int i = 0; i < NumRecords; i++)
    {
        if (DataArray[i].date == NULL || DataArray[i].time == NULL || DataArray[i].steps == 0)
        {   
            return 1;
        }
    }

    // Sort Array
    bubbleSort(DataArray, NumRecords);

    fclose(file);

    // Write to tsv file
    FILE *newfile = fopen("mydata.csv.tsv", "w");
    for (int i = 0; i < NumRecords; i++)
    {   
        fprintf(newfile, "%s\t%s\t%i\n", DataArray[i].date, DataArray[i].time, DataArray[i].steps);
    }
    fclose(newfile);

    return 0;
}