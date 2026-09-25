// Programmer ; Zaid
// Description ; Smart EV Charging and Parking Management System


#include <stdio.h>

int main()
{

    char vehicle, member, disabled, station;
    int battery, required, hours, time;
    float charging, parking, discount, final;
    int emergency = 0;

    printf("Enter vehicle type (E-Electric, H-Hybrid): ");
    scanf(" %c", &vehicle);

    printf("Enter current battery percentage: ");
    scanf("%d", &battery);

    printf("Enter required charging percentage: ");
    scanf("%d", &required);

    printf("Enter parking duration in hours: ");
    scanf("%d", &hours);

    printf("Enter current time (24-hour): ");
    scanf("%d", &time);

    printf("Enter membership (Y/N): ");
    scanf(" %c", &member);

    printf("Enter disabled-person priority (Y/N): ");
    scanf(" %c", &disabled);

    printf("Is charging station available (Y/N): ");
    scanf(" %c", &station);

    

    if(station == 'N')
    {
        if(vehicle == 'H')
            printf("Charging unavailable - Parking only.\n");
        else
            printf("No charging slot available.\n");
    }
    else
    {
        if(vehicle == 'E' )
        {
            if(required <= battery)
            {
                printf("No charging required.\n");
            }
            else
            {
                if(battery <= 15 && required >= 80)
                {
                    printf("Emergency Charging Priority\n");
                    emergency = 1;
                }
                else if(disabled == 'Y' || (member == 'Y') && battery <= 30)
                {
                    printf("Priority Charging\n");
                }
                else
                {
                    printf("Normal Charging\n");
                }

                if(time < 17 || time > 22)
                {
                    printf("Off-Peak\n");
                    charging = (required - battery) * 35;

                    if((member == 'Y' || member == 'y') && emergency == 0)
                    {
                        discount = charging * 20 / 100;
                        charging = charging - discount;
                    }
                    else
                    {
                        discount = 0;
                    }
                }
                else
                {
                    printf("Peak\n");
                    charging = (required - battery) * 50;

                    discount = charging * 10 / 100;
                    charging = charging - discount;
                }

                if(hours <= 2)
                    parking = 200;
                else if(hours <= 5)
                    parking = 400;
                else
                    parking = 700;

                if(disabled == 'Y')
                {
                    parking = 0;
                }
                else if(member == 'Y' )
                {
                    parking = parking - (parking * 20 / 100);
                }

                final = charging + parking;

                printf("Vehicle Type = %c\n", vehicle);
                printf("Current Battery = %d\n", battery);
                printf("Required Charging = %d\n", required);
                printf("Charging Cost = Rs %.2f\n", charging);
                printf("Parking Cost = Rs %.2f\n", parking);
                printf("Discount = Rs %.2f\n", discount);
                printf("Final Payable Amount = Rs %.2f\n", final);

                if(hours > 8)
                    printf("Long-stay warning: Please relocate your vehicle after charging\n");
                else
                    printf("Standard parking duration\n");
            }
        }
        else if(vehicle == 'H' )
        {
            if(battery >= 40)
            {
                printf("Vehicle does not qualify for EV charging.\n");
            }
            else
            {
                if(required <= battery)
                {
                    printf("No charging required.\n");
                }
                else
                {
                    if(battery <= 15 && required >= 80)
                    {
                        printf("Emergency Charging Priority\n");
                        emergency = 1;
                    }
                    else if(disabled == 'Y' || (member == 'Y') && battery <= 30)
                    {
                        printf("Priority Charging\n");
                    }
                    else
                    {
                        printf("Normal Charging\n");
                    }

                    if(time < 17 || time > 22)
                    {
                        printf("Off-Peak\n");
                        charging = (required - battery) * 35;

                        if((member == 'Y' ) && emergency == 0)
                        {
                            discount = charging * 20 / 100;
                            charging = charging - discount;
                        }
                        else
                        {
                            discount = 0;
                        }
                    }
                    else
                    {
                        printf("Peak\n");
                        charging = (required - battery) * 50;

                        discount = charging * 10 / 100;
                        charging = charging - discount;
                    }

                    if(hours <= 2)
                        parking = 200;
                    else if(hours <= 5)
                        parking = 400;
                    else
                        parking = 700;

                    if(disabled == 'Y' )
                    {
                        parking = 0;
                    }
                    else if(member == 'Y')
                    {
                        parking = parking - (parking * 20 / 100);
                    }

                    final = charging + parking;

                    printf("Vehicle Type = %c\n", vehicle);
                    printf("Current Battery = %d\n", battery);
                    printf("Required Charging = %d\n", required);
                    printf("Charging Cost = Rs. %.2f\n", charging);
                    printf("Parking Cost = Rs. %.2f\n", parking);
                    printf("Discount = Rs. %.2f\n", discount);
                    printf("Final Payable Amount = Rs. %.2f\n", final);

                    if(hours > 8)
                        printf("Long stay warning, Please relocate your vehicle after charging.\n");
                    else
                        printf("Standard parking duration.\n");
                }
            }
        }
        else
        {
            printf("Invalid vehicle type.\n");
        }
    }

    return 0;
}