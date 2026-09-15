#include <stdio.h>

int main()
{
    char vehicleType, membership, disabled, stationAvailable;
    float battery, requiredLevel, chargingUnits;
    float chargingRate, chargingCost, parkingCost;
    float discount, finalAmount;
    int parkingHours, currentTime;
    int isPeak;

    printf("Smart EV Charging and Parking System\n");

    printf("Enter vehicle type (E = Electric, H = Hybrid): ");
    scanf(" %c", &vehicleType);

    printf("Enter battery level: ");
    scanf("%f", &battery);

    printf("Enter required charging level: ");
    scanf("%f", &requiredLevel);

    printf("Enter parking hours: ");
    scanf("%d", &parkingHours);

    printf("Enter current time: ");
    scanf("%d", &currentTime);

    printf("Parking membership? (Y/N): ");
    scanf(" %c", &membership);

    printf("Disabled person? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Charging station available? (Y/N): ");
    scanf(" %c", &stationAvailable);

    if(battery < 0 || battery > 100)
    {
        printf("Invalid battery level");
        return 0;
    }

    if(requiredLevel < 0 || requiredLevel > 100)
    {
        printf("Invalid required level");
        return 0;
    }

    if(parkingHours < 0)
    {
        printf("Invalid parking hours");
        return 0;
    }

    if(stationAvailable == 'N' || stationAvailable == 'n')
    {
        if(vehicleType == 'E' || vehicleType == 'e')
        {
            printf("No charging station available\n");
            return 0;
        }
        else
        {
            printf("Charging unavailable. Parking only.\n");
            chargingUnits = 0;
            chargingCost = 0;
        }
    }

    if(vehicleType == 'H' || vehicleType == 'h')
    {
        if(battery >= 40)
        {
            printf("Hybrid does not qualify for charging.\n");
            chargingUnits = 0;
            chargingCost = 0;
        }
        else
        {
            chargingUnits = requiredLevel - battery;

            if(chargingUnits < 0)
                chargingUnits = 0;
        }
    }
    else
    {
        chargingUnits = requiredLevel - battery;

        if(chargingUnits < 0)
            chargingUnits = 0;
    }

    if(chargingUnits > 0)
    {
        if(battery <= 15 && requiredLevel >= 80)
            printf("Emergency Charging Priority\n");

        else if(disabled == 'Y' || disabled == 'y')
            printf("Priority Charging\n");

        else if(membership == 'Y' || membership == 'y')
            printf("Priority Charging\n");

        else
            printf("Normal Charging\n");
    }
    else
    {
        printf("No charging required\n");
    }

    if(currentTime < 17 || currentTime > 22)
    {
        printf("Off-Peak Time\n");
        chargingRate = 35;
        isPeak = 0;
    }
    else
    {
        printf("Peak Time\n");
        chargingRate = 50;
        isPeak = 1;
    }

    chargingCost = chargingUnits * chargingRate;
    discount = 0;

    if(chargingUnits > 0)
    {
        if(membership == 'Y' || membership == 'y')
        {
            if(isPeak == 0)
                discount = chargingCost * 20 / 100;
            else
                discount = chargingCost * 10 / 100;
        }

        chargingCost = chargingCost - discount;
    }

    if(parkingHours <= 2)
        parkingCost = 200;
    else if(parkingHours <= 5)
        parkingCost = 400;
    else
        parkingCost = 700;

    if(disabled == 'Y' || disabled == 'y')
    {
        parkingCost = 0;
    }
    else if(membership == 'Y' || membership == 'y')
    {
        parkingCost = parkingCost - parkingCost * 20 / 100;
    }

    finalAmount = chargingCost + parkingCost;

    printf("\n===== FINAL BILL =====\n");

    printf("Battery: %.2f%%\n", battery);
    printf("Required Level: %.2f%%\n", requiredLevel);
    printf("Charging Units: %.2f\n", chargingUnits);
    printf("Charging Rate: Rs. %.2f\n", chargingRate);
    printf("Charging Cost: Rs. %.2f\n", chargingCost);
    printf("Parking Hours: %d\n", parkingHours);
    printf("Parking Cost: Rs. %.2f\n", parkingCost);
    printf("Final Amount: Rs. %.2f\n", finalAmount);

    if(parkingHours > 8)
        printf("Long stay warning\n");
    else
        printf("Normal parking duration\n");

    return 0;
}