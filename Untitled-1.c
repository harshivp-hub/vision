#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256 // maximum length of a line in the file

// Function to generate the win-loss record string from the given game results file
char* generate_record_string(const char* filename)
{
    // Open the file for reading
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Read each line of the file
    char line[MAX_LINE_LEN];
    int wins = 0, losses = 0; // counters for wins and losses
    while (fgets(line, MAX_LINE_LEN, fp) != NULL)
    {
        // Check the first character of the line to determine if it's a win or loss
        if (line[0] == 'W')
            wins++;
        else if (line[0] == 'L')
            losses++;
    }

    // Close the file
    fclose(fp);

    // Generate the win-loss record string using the counters
    char* record = malloc(16); // allocate memory for the record string
    sprintf(record, "%d-%d", wins, losses); // format the string

    return record;
}

int main()
{
    // Generate the win-loss record string from the game results file
    char* record = generate_record_string("game_results.txt");
    if (record == NULL)
        return 1;

    // Print the record string
    printf("Record: %s\n", record);

    // Free the memory allocated for the record string
    free(record);

    return 0;
}