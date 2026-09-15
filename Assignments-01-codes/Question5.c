#include <stdio.h>

int main()
{
    int N, i;
    int zoneA = 0, zoneB = 0, zoneC = 0;
    int accepted = 0, rejected = 0;
    int cars = 0, bikes = 0, vans = 0;

    char vehicle, category, permit, emergency;

    printf("Smart Campus Parking System\n");

    printf("Enter number of vehicles: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++)
    {
        printf("\nVehicle %d\n", i);

        printf("Enter vehicle type (C=Car, B=Bike, V=Van): ");
        scanf(" %c", &vehicle);

        printf("Enter category (F=Faculty, S=Student, G=Visitor): ");
        scanf(" %c", &category);

        printf("Do you have parking permit? (Y/N): ");
        scanf(" %c", &permit);

        if(permit == 'N' || permit == 'n')
        {
            printf("Is it an emergency vehicle? (Y/N): ");
            scanf(" %c", &emergency);

            if(emergency == 'N' || emergency == 'n')
            {
                printf("Rejected: No permit\n");
                rejected++;
            }
            else
            {
                if(category == 'F' || category == 'f')
                {
                    if(vehicle == 'V' || vehicle == 'v')
                    {
                        if(zoneA + 2 <= 20)
                        {
                            zoneA = zoneA + 2;
                            accepted++;
                            vans++;
                            printf("Parked in Zone A\n");
                        }
                        else
                            rejected++;
                    }
                    else
                    {
                        if(zoneA < 20)
                        {
                            zoneA++;
                            accepted++;

                            if(vehicle == 'C' || vehicle == 'c')
                                cars++;
                            else
                                bikes++;

                            printf("Parked in Zone A\n");
                        }
                        else
                            rejected++;
                    }
                }
                else if(category == 'S' || category == 's')
                {
                    if(zoneB < 40)
                    {
                        zoneB++;
                        accepted++;

                        if(vehicle == 'C' || vehicle == 'c')
                            cars++;
                        else if(vehicle == 'B' || vehicle == 'b')
                            bikes++;
                        else
                        {
                            zoneB++;
                            vans++;
                        }

                        printf("Parked in Zone B\n");
                    }
                    else
                        rejected++;
                }
                else
                {
                    if(vehicle == 'V' || vehicle == 'v')
                    {
                        if(zoneC + 2 <= 15)
                        {
                            zoneC = zoneC + 2;
                            accepted++;
                            vans++;
                            printf("Parked in Zone C\n");
                        }
                        else
                            rejected++;
                    }
                    else
                    {
                        if(zoneC < 15)
                        {
                            zoneC++;
                            accepted++;

                            if(vehicle == 'C' || vehicle == 'c')
                                cars++;
                            else
                                bikes++;

                            printf("Parked in Zone C\n");
                        }
                        else
                            rejected++;
                    }
                }
            }
        }
        else
        {
            if(category == 'F' || category == 'f')
            {
                if(vehicle == 'V' || vehicle == 'v')
                {
                    if(zoneA + 2 <= 20)
                    {
                        zoneA = zoneA + 2;
                        accepted++;
                        vans++;
                        printf("Parked in Zone A\n");
                    }
                    else
                        rejected++;
                }
                else
                {
                    if(zoneA < 20)
                    {
                        zoneA++;
                        accepted++;

                        if(vehicle == 'C' || vehicle == 'c')
                            cars++;
                        else
                            bikes++;

                        printf("Parked in Zone A\n");
                    }
                    else
                        rejected++;
                }
            }
            else if(category == 'S' || category == 's')
            {
                if(vehicle == 'V' || vehicle == 'v')
                {
                    if(zoneC + 2 <= 15)
                    {
                        zoneC = zoneC + 2;
                        accepted++;
                        vans++;
                        printf("Student van parked in Zone C\n");
                    }
                    else
                        rejected++;
                }
                else
                {
                    if(zoneB < 40)
                    {
                        zoneB++;
                        accepted++;

                        if(vehicle == 'C' || vehicle == 'c')
                            cars++;
                        else
                            bikes++;

                        printf("Parked in Zone B\n");
                    }
                    else
                        rejected++;
                }
            }
            else
            {
                if(vehicle == 'V' || vehicle == 'v')
                {
                    if(zoneC + 2 <= 15)
                    {
                        zoneC = zoneC + 2;
                        accepted++;
                        vans++;
                        printf("Parked in Zone C\n");
                    }
                    else
                        rejected++;
                }
                else
                {
                    if(zoneC < 15)
                    {
                        zoneC++;
                        accepted++;

                        if(vehicle == 'C' || vehicle == 'c')
                            cars++;
                        else
                            bikes++;

                        printf("Parked in Zone C\n");
                    }
                    else
                        rejected++;
                }
            }
        }
    }

    printf("\n===== PARKING SUMMARY =====\n");

    printf("Total Vehicles: %d\n", N);
    printf("Accepted: %d\n", accepted);
    printf("Rejected: %d\n", rejected);

    printf("Cars: %d\n", cars);
    printf("Bikes: %d\n", bikes);
    printf("Vans: %d\n", vans);

    printf("\nZone A Occupied: %d\n", zoneA);
    printf("Zone A Remaining: %d\n", 20 - zoneA);

    printf("\nZone B Occupied: %d\n", zoneB);
    printf("Zone B Remaining: %d\n", 40 - zoneB);

    printf("\nZone C Occupied: %d\n", zoneC);
    printf("Zone C Remaining: %d\n", 15 - zoneC);

    if(zoneA >= zoneB && zoneA >= zoneC)
        printf("\nHighest Occupancy: Zone A\n");
    else if(zoneB >= zoneA && zoneB >= zoneC)
        printf("\nHighest Occupancy: Zone B\n");
    else
        printf("\nHighest Occupancy: Zone C\n");

    if(zoneA == 20 && zoneB == 40 && zoneC == 15)
        printf("Parking is FULL\n");
    else
        printf("Parking is NOT FULL\n");

    return 0;
}