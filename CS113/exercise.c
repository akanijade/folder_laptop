#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

/***
int factorial(int n)
{
    int fact = 0;
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.\n");
    else {
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
    }
    return fact;
} ***/

int main(int ac, char **av)
{
    printf("Exercise 5.4.1: Counting functions from a set to itself.\n");
    int q541a = pow(2, (7 * pow(2,7)));
    char q541b[] = "128!";
    int q541c = pow(2, (5*pow(2,7)));
    char q541d[] = "128! / 32!";
    printf("Answers for 5.4.1: a) %d b) %s c) %d d) %s \n \n", q541a, q541b, q541c, q541d);

    printf("Exercise 5.4.2: Counting telephone numbers. \n");
    int q542a = 20000;
    int q542b = 10080;
    printf("Answers for 5.4.2: a) %d b) %d \n\n", q542a, q542b);

    printf("Exercise 5.5.1: Mapping permutations to subsets \n");
    char q551a[] = "{1,3,9,12,15} \n";
    char q551b[] = " It is not a 5-permutation because every element in the permutation must be unique. \n";
   char q551c[] = "5! = 120";
    printf("Answer for 5.5.1: a) %s \t\t b) %s \t\t c) %s \n\n", q551a, q551b, q551c);

    printf("Exercise 5.5.3: Counting bit strings. \n");
    int q553a = pow(2,10);
    int q553b = pow(2,7);
    int q553c = pow(2,7) + pow(2,8);
    int q553d = 4 * pow(2,6);
    int q553e = 210;
    int q553f = 84;
    int q553g = 50;
    printf("Answers for 5.5.3: a) %d b) %d c) %d d) %d e) %d f) %d g) %d \n\n", q553a, q553b, q553c, q553d, q553e, q553f, q553g);

    printf("Exercise 5.6.4: Hiring a software engineer. \n");
    char q564a[] = "C(100,9)";
    int q564b = 84;
    int q564c = 20;
    int q564d = 20 * 6;
    printf("Answers for 5.6.4: a) %s b) %d c) %d d) %d \n", q564a, q564b, q564c, q564d);

    
    
    

    return 0;
}
