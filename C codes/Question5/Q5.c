// Programmer ; Zaid
// Description ; Smart Campus Parking and Access Management System


#include <stdio.h>

int main()
{

    int n, i;
    char vehicle, category, permit, emergency;
    int a = 0, b = 0, c = 0;
    int cars = 0, bikes = 0, vans = 0;
    int accepted = 0, rejected = 0;
    int space, valid;

    printf("Enter number of vehicles,");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        valid = 0;

        while(valid == 0)
        {
            printf("\nVehicle %d\n", i);

            printf("Enter vehicle type (C Car, B Bike, V Van): ");
            scanf(" %c", &vehicle);

            printf("Enter category (F Faculty, S Student, G Visitor): ");
            scanf(" %c", &category);

            printf("Enter permit (Y/N): ");
            scanf(" %c", &permit);

            if(vehicle != 'C' &&
               vehicle != 'B' &&
               vehicle != 'V' )
            {
                printf("Invalid vehicle type\n");
            }
            else if(category != 'F' && 
                    category != 'S' && 
                    category != 'G')
            {
                printf("Invalid category\n");
            }
            else if(permit != 'Y' && 
                    permit != 'N' )
            {
                printf("Invalid permit\n");
            }
            else
            {
                valid = 1;
            }
        }

        if(permit == 'N' || permit == 'n')
        {
            printf("Is it an emergency vehicle (Y/N): ");
            scanf(" %c", &emergency);

            if(emergency != 'Y' )
            {
                printf("Rejected\n");
                rejected++;
                continue;
            }
        }
        else
        {
            emergency = 'N';
        }

        if(category == 'F' )
        {
            space = 1;

            if(vehicle == 'V')
                space = 2;

            if(a + space <= 20)
            {
                a = a + space;
                printf("Assigned Zone A\n");
                printf("Remaining capacity = %d\n", 20 - a);
                accepted = accepted + 1;

                if(vehicle == 'C' )
                    cars++;
                else if(vehicle == 'B' )
                    bikes++;
                else
                    vans++;
            }
            else
            {
                printf("Rejected\n");
                rejected++;
            }
        }
        else if(category == 'S' )
        {
            if(vehicle == 'V' )
            {
                if(c + 1 <= 15)
                {
                    c = c + 1;
                    printf("Assigned Zone C\n");
                    printf("Remaining capacity = %d\n", 15 - c);
                    accepted++;
                    vans++;
                }
                else
                {
                    printf("Rejected\n");
                    rejected++;
                }
            }
            else
            {
                if(b + 1 <= 40)
                {
                    b = b + 1;
                    printf("Assigned Zone B\n");
                    printf("Remaining capacity = %d\n", 40 - b);
                    accepted++;

                    if(vehicle == 'C')
                        cars++;
                    else
                        bikes++;
                }
                else
                {
                    printf("Rejected\n");
                    rejected++;
                }
            }
        }
        else if(category == 'G' )
        {
            if(vehicle == 'V' )
            {
                if(c + 2 <= 15)
                {
                    c = c + 2;
                    printf("Assigned Zone C\n");
                    printf("Remaining capacity = %d\n", 15 - c);
                    accepted++;
                    vans++;
                }
                else
                {
                    printf("Rejected\n");
                    rejected++;
                }
            }
            else
            {
                if(c + 1 <= 15)
                {
                    c = c + 1;
                    printf("Assigned Zone C\n");
                    printf("Remaining capacity = %d\n", 15 - c);
                    accepted++;

                    if(vehicle == 'C')
                        cars++;
                    else
                        bikes++;
                }
                else
                {
                    printf("Rejected\n");
                    rejected++;
                }
            }
        }
    }

    printf("Total Vehicles Processed = %d\n", n);
    printf("Total Accepted  = %d\n", accepted);
    printf("Total Rejected  = %d\n", rejected);
    printf("Cars  Parked = %d\n", cars);
    printf("Bikes  Parked = %d\n", bikes);
    printf("Vans  Parked = %d\n", vans);

    printf("\nZone A Occupied = %d\n", a);
    printf("Zone A Remaining = %d\n", 20 - a);

    printf("Zone B Occupied = %d\n", b);
    printf("Zone B Remaining = %d\n", 40 - b);

    printf("Zone C Occupied = %d\n", c);
    printf("Zone C Remaining = %d\n", 15 - c);

    if(a == 20 && b == 40 && c == 15)
        printf("Entire campus parking facility is full\n");
    else
        printf("Entire campus parking facility is not full\n");

    return 0;
}