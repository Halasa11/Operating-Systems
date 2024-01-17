#include <stdio.h>

int main() {
    // creation of variable (fptr) of type FILE
    FILE *fptr;
    // setting the variable to create a file called myfile.txt in write mode
    fptr = fopen("myfile.txt","w");
    // writing into the file Hello world
    fprintf(fptr,"Hello world");
    // closing the file
    fclose(fptr);
    // opening the file in read mode
    fptr = fopen("myfile.txt","r");
    // creating a variable array that stores up to 100 charecters
    char mystring[100];
    // reading from the file and saving into the variable created above
    fgets(mystring, 100, fptr);
    // printing all strings in the variable mystring
    printf("%s\n", mystring);
    // closing the file
    fclose(fptr);
}