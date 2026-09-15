#include <stdio.h>

int main()
{
    int quantity;
    float price, discount, tax;
    float subtotal, discountedAmount, taxAmount, finalBill;
    FILE *file;

    printf("Shopping Bill Calculator\n");

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price);

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    printf("Enter tax percentage: ");
    scanf("%f", &tax);

    if (quantity <= 0 || price < 0 || discount < 0 || discount > 100 || tax < 0 || tax > 100)
    {
        printf("Invalid input!\n");
        return 0;
    }


    printf("\nSHOPPING BILL\n");
    printf("Quantity: %d\n", quantity);
    printf("Price: Rs. %.2f\n", price);
    printf("Subtotal: Rs. %.2f\n", subtotal);
    printf("Discount: %.2f%%\n", discount);
    printf("Discounted Amount: Rs. %.2f\n", discountedAmount);
    printf("Tax: %.2f%%\n", tax);
    printf("Tax Amount: Rs. %.2f\n", taxAmount);
    printf("Final Bill: Rs. %.2f\n", finalBill);

    file = fopen("bill.txt", "w");

    if (file == NULL)
    {
        printf("File could not be created.\n");
        return 0;
    }

    fprintf(file, "===== SHOPPING BILL =====\n");
    fprintf(file, "Quantity: %d\n", quantity);
    fprintf(file, "Price: Rs. %.2f\n", price);
    fprintf(file, "Subtotal: Rs. %.2f\n", subtotal);
    fprintf(file, "Discount: %.2f%%\n", discount);
    fprintf(file, "Discounted Amount: Rs. %.2f\n", discountedAmount);
    fprintf(file, "Tax: %.2f%%\n", tax);
    fprintf(file, "Tax Amount: Rs. %.2f\n", taxAmount);
    fprintf(file, "Final Bill: Rs. %.2f\n", finalBill);

    fclose(file);

    printf("\nBill saved in bill.txt\n");

    return 0;
}