// Programmer : Zaid
// Description : Hotel Booking System


#include <stdio.h>

int main()
{

    int n, i, nights, room;
    char season;
    float rate, total, discount, hotelTotal = 0;

    printf("Enter number of guests: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Guest %d\n", i);

        printf("Enter season (P for Peak, O for Off Peak): ");
        scanf(" %c", &season);

        printf("Enter room type (1 Standard, 2 Deluxe, 3 Suite): ");
        scanf("%d", &room);

        printf("Enter number of nights: ");
        scanf("%d", &nights);

        if(season == 'P' )
        {
            if(room == 1)
                rate = 5000;
            else if(room == 2)
                rate = 8000;
            else if(room == 3)
                rate = 12000;
            else
            {
                printf("Invalid room type\n");
                continue;
            }
        }
        else if(season == 'O' )
        {
            if(room == 1)
                rate = 3000;
            else if(room == 2)
                rate = 5000;
            else if(room == 3)
                rate = 8000;
            else
            {
                printf("Invalid room type\n");
                continue;
            }
        }
        else
        {
            printf("Invalid season\n");
            continue;
        }

        total = rate * nights;

        if(nights > 7)
        {
            discount = total * 15 / 100;
            total = total - discount;
        }

        printf("Final Price = Rs. %.2f\n", total);

        hotelTotal = hotelTotal + total;
    }

    printf("\nHotel Total Revenue = Rs. %.2f", hotelTotal);

    return 0;
}