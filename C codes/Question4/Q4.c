// Programmer ; Zaid
// Description ; Online Shopping Bill Calculator


#include <stdio.h>

int main()
{

    int q;
    float p, d, t;
    float s, a, bill;

    printf("Enter quantity: ");
    scanf("%d", &q);

    printf("Enter price per item: ");
    scanf("%f", &p);

    printf("Enter discount percentage: ");
    scanf("%f", &d);

    printf("Enter tax percentage: ");
    scanf("%f", &t);

    if(q <= 0)
    {
        printf("Invalid quantity");
    }
    else if(p < 0)
    {
        printf("Invalid price");
    }
    else if(d < 0 || d > 100)
    {
        printf("Invalid discount percentage");
    }
    else if(t < 0)
    {
        printf("Invalid tax percentage");
    }
    else
    {
        s = q * p;

        a = s - (s * d) / 100;

        bill = a + (a * t) / 100;

        printf("Quantity = %d\n", q);
        printf("Price per item = %.2f\n", p);
        printf("Subtotal = %.2f\n", s);
        printf("Discount = %.2f\n", d);
        printf("Discounted Amount = %.2f\n", a);
        printf("Tax = %.2f\n", t);
        printf("Final Bill = %.2f\n", bill);
    }

    return 0;
}