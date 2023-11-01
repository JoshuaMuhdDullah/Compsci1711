#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int numRec = 0, row = 0, column = 0;
    char date[10], time[5], steps[4];
    char buffer[100];
    FITNESS_DATA data;

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
        char *token;
        token = strtok(buffer, ",");
        while(token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }


        numRec++;
    }

    printf("Number of records in file: %d\n",numRec);

    fclose(file);   
    return 0;
}
