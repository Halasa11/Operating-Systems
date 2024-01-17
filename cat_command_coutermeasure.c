#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void print_file(char *file) {

    char content[10];
    FILE *fptr = fopen (file,"r");

        // Check if the file opening was successful
        if (fptr == NULL) {  
            perror("Error opening file");
            exit (1); // Exit the program with an error code
        }

        // Read and print each line from the file
        while (fgets(content, sizeof(content), fptr) != NULL) {
            content[strcspn(content, "\n")] = '\0'; // Remove newline character
            printf("%s\n", content);
        }

    // Close the file
    fclose(fptr);
}

void create_file(char *file) {

    char content[10];
    char temp[256]; // Temporary buffer to hold user input
    FILE *fptr = fopen (file,"w");

        // Check if the file opening was successful
        if (fptr == NULL) {  
            perror("Error opening file");
            exit (1); // Exit the program with an error code
        }

        if (fgets(temp, sizeof(temp), stdin) != NULL) {
            // Check if the input is too large for the content buffer
            if (strlen(temp) >= sizeof(content)) {
                printf("Input over 10, buffer overflow detected!\n");
                printf("Try an input smaller than 10\n");
                return create_file(file);
            } else {
                // Copy the input to the content buffer
                strncpy(content, temp, sizeof(content) - 1);
                content[sizeof(content) - 1] = '\0'; // Ensure null-termination
            }
        }

        fprintf(fptr,"%s", content); // writing in the data the user wrote

    // close the file
    fclose(fptr);
}

void append_file(char *file) {

    char content[10];
    char temp[256]; // Temporary buffer to hold user input
    FILE *fptr = fopen (file,"a");

        // Check if the file opening was successful
        if (fptr == NULL) {  
            perror("Error opening file");
            exit (1); // Exit the program with an error code
        }

        if (fgets(temp, sizeof(temp), stdin) != NULL) {
            // Check if the input is too large for the content buffer
            if (strlen(temp) >= sizeof(content)) {
                printf("Input over 10, buffer overflow detected!\n");
                printf("Try an input smaller than 10\n");
                return append_file(file);
            } else {
                // Copy the input to the content buffer
                strncpy(content, temp, sizeof(content) - 1);
                content[sizeof(content) - 1] = '\0'; // Ensure null-termination
            }
        }

        fprintf(fptr,"%s", content); // writing in the data the user wrote

    // close the file
    fclose(fptr);

}

void overwrite_file(char *file) {

    char content[10];
    char temp[256]; // Temporary buffer to hold user input
    FILE *fptr = fopen (file,"w");

        // Check if the file opening was successful
        if (fptr == NULL) {  
            perror("Error opening file");
            exit (1); // Exit the program with an error code
        }

        if (fgets(temp, sizeof(temp), stdin) != NULL) {
            // Check if the input is too large for the content buffer
            if (strlen(temp) >= sizeof(content)) {
                printf("Input over 10, buffer overflow detected!\n");
                printf("Try an input smaller than 10\n");
                return overwrite_file(file);
            } else {
                // Copy the input to the content buffer
                strncpy(content, temp, sizeof(content) - 1);
                content[sizeof(content) - 1] = '\0'; // Ensure null-termination
            }
        }

        fprintf(fptr,"%s", content); // writing in the data the user wrote

    // close the file
    fclose(fptr);
}

void flag_number(char *file) {

    FILE *fptr = fopen (file,"r");

        // Check if the file opening was successful
        if (fptr == NULL) {  
            perror("Error opening file");
            exit (1); // Exit the program with an error code
        }

        int line_number = 1; // variable to number the lines
        char *line = NULL; // line pointer
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, fptr)) != -1) {
            printf("%6d  %s", line_number++, line); // 6d makes a standariesed output
        }

        // free the allocated memory
        free(line);

    // Close the file
    fclose(fptr);
}

void flag_dollar_sign(char *file) {

    FILE *fptr = fopen(file, "r");

        // Check if the file opening was successful
        if (fptr == NULL) {
            perror("Error opening file");
            exit(1); // Exit the program with an error code
        }

        char *line = NULL; // line pointer
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, fptr)) != -1) {
            // Remove the newline character if present
            if (line[read - 1] == '\n') {
                line[read - 1] = '\0';
            }

            // Print the line followed by the $ sign
            printf("%s$\n", line);
        }

        // free the allocated memory
        free(line);

    // Close the file
    fclose(fptr);
}

void flag_help(char *help) {
    printf("Usage: %s [OPTION]... [FILE]...\n", help);
    printf("Concatenate FILE(s) to standard output.\n\n");
    printf("%s <FILE> (not in directory / ls) creates the file and lets you input data in it.\n\n", help);
    printf("With no FILE, or when FILE is -, read standard input.\n\n");
    printf("  -h, --help\t\tshow this help message and exit\n");
    printf("  -o  <file>\t\toverwrite the specified file\n");
    printf("  -a  <file>\t\tappend to the specified file\n");
    printf("  -n  <file>\t\tnumber all output lines\n");
    printf("  -E  <file>\t\tdisplay $ at end of each line\n");
}

int main (int argc, char *argv[]) {
    
    if (argc < 2) {
        flag_help(argv[0]);
        return 1;
    } else if (strcmp(argv[1], "-o") == 0 && argc == 3) {
        overwrite_file(argv[2]);
    } else if (strcmp(argv[1], "-a") == 0 && argc == 3) {
        append_file(argv[2]);
    } else if (strcmp(argv[1], "-n") == 0 && argc >= 3) {
        for (int i = 2; i < argc; i++) {
            flag_number(argv[i]);
        }
    } else if (strcmp(argv[1], "-E") == 0 && argc >= 3) {
        for (int i = 2; i < argc; i++) {
            flag_dollar_sign(argv[i]);
        }
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        flag_help(argv[0]);
        return 0;
    } else if (access(argv[1], F_OK) == 0) {
        for (int x=1; x < argc; x++) {
            print_file(argv[x]);
        }
    } else {
        create_file(argv[1]);
    }
}