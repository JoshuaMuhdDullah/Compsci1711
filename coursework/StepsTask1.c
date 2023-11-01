#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
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


// Complete the main function
int main() {

    //declaring varaibles
    int count = 0;
    char date[11], time[6], steps[4];
    char buffer[21], value[21];
    FITNESS_DATA outputData[3];

    //open file
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    //read file
    while (fgets(buffer, 100, file) != NULL)
    {   
        if (count < 3)
        {   
            //copy values from buffer to variable to handled
            strcpy(value,buffer);

            //strip string
            for (int i = 0; i < 21; i++)
            {   
                if (value[i] == '\r')
                {
                    value[i] = '\0';
                }
            }

            //tokenise record
            tokeniseRecord(value,",",date,time,steps);

            //copy values over to struc list
            strcpy(outputData[count].date,date);
            strcpy(outputData[count].time,time);
            outputData[count].steps = atoi(steps);   
        }
        count++;
    }

    //print
    printf("Number of records in file: %d\n",count);
    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n",outputData[i].date,outputData[i].time,outputData[i].steps);
    }

    //close file
    fclose(file);   
    return 0;
}
