#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    printf("Exercise 5.1.1: License plate combinations\n");
    int question_a = pow(35, 7); //26 (alphabets) + 9 (digits) = 35
    int question_b = 9 * pow(35,6);
    int question_c = pow(26, 3) + pow(35,4);
    int question_d = pow(26,3) + pow(9,4);
    printf("Answers for 5.1.1: %d, %d, %d, %d \n", question_a,question_b, question_c,question_d);
    
    printf("\n Exercise 5.1.2: Counting passwords made up of letters, digits, and special characters. \n");
    int q_a = pow(40, 6); // 10 (digits) + 26 (alphabets) + 4 (special char)
    int q_b = pow(40,7) + pow(40,8) + pow(40,9);
    int q_c = 14 * (pow(40,6) + pow(40,7) + pow(40,8));
    printf("Answers for 5.1.2: %d, %d, %d \n", q_a, q_b, q_c);

    printf("\n Exercise 5.1.3: Selecting lunch specials for the week. \n");
    int qa = pow(10,5);
    int qb = 3 * pow(10,4);
    int qc = 3 * pow(10,3) * 3;
    int qd = pow(20,5);
    printf("Answers for 5.1.3: %d, %d, %d, %d \n", qa, qb, qc, qd);
    return 0;
}