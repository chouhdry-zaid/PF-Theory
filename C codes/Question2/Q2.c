// Programmer ; Zaid
// Description ; Elevator Simulation


#include <stdio.h>

int main()
{

    int n, i, floor, current = 0;

    printf("Enter number of floor requests: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Enter floor request: ");
        scanf("%d", &floor);

        if(floor > current)
        {
            printf("Moving Up\n");
        }
        else if(floor < current)
        {
            printf("Moving Down\n");
        }
        else
        {
            printf("Doors Opening\n");
        }

        current = floor;
    }

    return 0;
}