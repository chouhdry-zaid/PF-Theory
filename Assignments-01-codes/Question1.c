#include <stdio.h>

int main()
{
    int N, i;
    char season;
    int roomType, nights;
    double rate, total, discount;
    double hotelRevenue = 0;

    printf("Enter number of guests: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        printf("\n Guest %d\n", i);

        printf("Enter season (P = Peak, O = Off-Peak): ");
        scanf(" %c", &season);

        printf("Enter room type:\n");
        printf("1 = Standard\n");
        printf("2 = Deluxe\n");
        printf("3 = Suite\n");
        printf("Enter choice: ");
        scanf("%d", &roomType);

        printf("Enter number of nights: ");
        scanf("%d", &nights);

        rate = 0;

        if (season == 'P' || season == 'p')
        {
            if (roomType == 1)
                rate = 5000;
            else if (roomType == 2)
                rate = 8000;
            else if (roomType == 3)
                rate = 12000;
            else
            {
                printf("Invalid room type.\n");
                continue;
            }
        }
        else if (season == 'O' || season == 'o')
        {
            if (roomType == 1)
                rate = 3000;
            else if (roomType == 2)
                rate = 5000;
            else if (roomType == 3)
                rate = 8000;
            else
            {
                printf("Invalid room type.\n");
                continue;
            }
        }
        else
        {
            printf("Invalid season.\n");
            continue;
        }

        total = rate * nights;
        discount = 0;

        if (nights > 7)
        {
            discount = total * 15 / 100;
            total = total - discount;
        }

        printf("Room Rate: Rs. %.2f per night\n", rate);
        printf("Discount: Rs. %.2f\n", discount);
        printf("Final Price: Rs. %.2f\n", total);

        hotelRevenue = hotelRevenue + total;
    }

    printf("Hotel Total Revenue = Rs. %.2f\n", hotelRevenue);

    return 0;
}