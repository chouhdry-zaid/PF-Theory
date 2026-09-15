#include <stdio.h>

int main()
{
    int N;
    int i, j;
    float mark, sum, average;
    int subjectDeficiency;

    printf("Enter number of students: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        sum = 0;
        subjectDeficiency = 0;

        printf("Student %d\n", i);

        for (j = 1; j <= 5; j++)
        {
            printf("Enter marks for subject %d: ", j);
            scanf("%f", &mark);

            sum = sum + mark;

            if (mark < 33)
            {
                subjectDeficiency = 1;
            }
        }

        average = sum / 5;

        printf("Total Marks = %.2f\n", sum);
        printf("Average = %.2f\n", average);

        if (subjectDeficiency == 1)
        {
            printf("Result: Fail - Subject Deficiency\n");
        }
        else
        {
            if (average >= 80)
            {
                printf("Result: Distinction\n");
            }
            else if (average >= 60)
            {
                printf("Result: Pass\n");
            }
            else
            {
                printf("Result: Fail\n");
            }
        }
    }

    return 0;
}