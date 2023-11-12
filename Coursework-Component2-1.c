#include <stdio.h>

int main() { // ana al a7mar
    // creating a variable of type integer and setting it to 0
    int numrows = 0;
    // creating two variables of type integer for the for loops
    int i,j;
    // creating a variable of type float
    float max;
    // printing to the user to enter the number of users
    printf ("Please specify number of rows: ");
    // reading in the the number entered from the user and saving it to the variable numrows
    scanf ("%d", &numrows);
    // dividing the number in numrows by 2 and saving the answer to max
    max = numrows/2;
    // if statment checking if the number is even by seeing if it produces a remainder of 0 when divided by 2
    if (numrows % 2 == 0) {
        // add 1 to the max for the patern to not repeat on even numbers
        max += 1;
        // for loop that keeps going until it reaches numrows value, this for loop creates every row
        for (i = 1; i <= numrows; i++) {
            // if statment that checks if i is less than the value of max
            if (i <= max) {
                // for loop in the true value of the if statment that decrements from the value of numrows to 1, this for loop creates the first half rows which increase in size each row
                for (j = numrows; j >= 1; j--){
                    // if statment that checks if i value is larger of equal to j
                    if (i >= j)
                        // printing the star in the true value of the if statment with a space so that they are centered and not left aligned
                        printf ("* ");
                    else
                        // printing a space in the false value of the if statment 
                        printf (" ");
                }
                // printing a new line inside the true value of the if statment and outside the for loop
                printf("\n");
            } else {
                // for loop in the false value of the if statment that increments from 1 till it reaches the value of numrows, this for loop creates the last half rows which decrease in size each row
                for (j = 1; j <= numrows; j++){
                    // if statment that checks if i value is larger than j + 1
                    if (i > j + 1)
                        // printing a space in the true value of the if statment 
                        printf (" ");
                    else
                        // printing the star in the false value of the if statment with a space so that they are centered and not left aligned
                        printf ("* ");
                    }
                // printing a new line inside the true value of the if statment and outside the for loop
                printf ("\n");
            }
        }
    } else {
        // the same for loop thats in the true value of the if statment
        for (i = 1; i <= numrows; i++) {
            // the same if statment as the one in the true value of the if statment
            if (i <= max) {
                // the same for loop as the one in the true value of the if statment
                for (j = numrows; j >= 1; j--){
                    // the same if statment as the one in the true value of the if statment
                    if (i >= j)
                        // the same print statment as the one in the true value of the if stament
                        printf ("* ");
                    else
                        // the same print statment as the one in the true value of the if stament
                        printf (" ");
                }
                // the same print statment as the one in the true value of the if stament
                printf("\n");

            } else {
                // the same for loop thats in the true value of the if statment
                for (j = 1; j <= numrows; j++){
                    // an if statment that checks if is greater than j
                    if (i > j)
                        // the same print statment as the one in the true value of the if stament
                        printf (" ");
                    else
                        // the same print statment as the one in the true value of the if stament
                        printf ("* ");
                    }
                // the same print statment as the one in the true value of the if stament
                printf ("\n");
            }
        }
    }
}