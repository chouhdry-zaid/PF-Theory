// Programmer ; Zaid
// Description ; Class Result Processing


#include <stdio.h>

int main()
{

    int n, i, j;
    float marks, sum, avg;
    int fail;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        sum = 0;
        fail = 0;

        printf("Student %d\n", i);

        for(j=1; j<=5; j++)
        {
            printf("Enter marks of subject %d: ", j);
            scanf("%f", &marks);

            sum = sum + marks;

            if(marks < 33)
            {
                fail = 1;
            }
        }

        avg = sum / 5;

        printf("Average = %.2f\n", avg);

        if(fail == 1)
        {
            printf("Fail -\n");
        }
        else
        {
            if(avg >= 80)
            {
                printf("Distinction\n");
            }
            else if(avg >= 60)
            {
                printf("Pass\n");
            }
            else
            {
                printf("Fail\n");
            }
        }
    }

    return 0;
}