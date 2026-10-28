/*Programmer:Zaid
section:BS-AI-1A
ROLL NO:0015
Description:TO find Amicable pair up to given range
*/


#include<stdio.h>
#include<stdlib.h>

int getvaliddays(){ // validate
    int days;
    printf("Enter valid days of festival:");
    scanf("%d",&days);

    if (days<1 && days>7)
    {
        getvaliddays();
        /* code */
    }
    return days;
    
}
float cal_daily_sales(int days_no){ // daily
    int orders,amount=0,max=0;
    float Total=0,fes_total=0;
        printf("Enter the no: of orders of Day %d.\n",days_no);
        scanf("%d",&orders);
        int array[orders];
        for (int j = 0; j < orders; j++)
        {
            printf("Enter the amount of order %d:",j+1);
            scanf("%d",&amount);
            if (amount<=0) // invalid
            {
                printf("Enter valid amount of order %d:",j+1);
                scanf("%d",&amount);
                /* code */
            }
            array[j]=amount;
            max=array[0];
            if (array[j]>max)
            {
                max=array[j];
                /* code */
            }
            Total+=amount;
        }
        for (int i = 0; i < orders; i++)
        {
            printf("%d  ",array[i]);
            /* code */
        }
        printf("\n");
        printf("Highest order:%d\n",max);
        printf("Average amount of Day %d is %.2f.\n",days_no,Total/orders);
        return Total; // return
        Total=0;
        amount=0; 
}

int main(){
    int days,total_sales,l=0;
    float fes_total=0,max=0;
    days =getvaliddays(); // days
    float array[days];
    for (int i = 1,j=0; i <= days;j++, i++)
    {
        total_sales=cal_daily_sales(i); // daily
        printf("Day %d total sales:%d\n",i,total_sales);
        array[j]=total_sales;
        fes_total+=total_sales;
        /* code */
    }
    for (int i = 0; i < days; i++)
    {
        max=array[0];
        if (array[i]>max)
        {
            max=array[i];
            l=i;
            /* code */
        }
        
        /* code */
    }
    
    printf("=====FESTIVAL SUMMARY=====\n"); // summary
    printf("Festival total sales: Rs.%.2f\n",fes_total);
    printf("Hieghest daily sale: Rs.%.2f\n",max);
    printf("Day with hieghest sale:Day %d.\n\n",l+1);
    printf("=====DAILY SALES BAR CHART=====\n"); // chart
    for (int i = 0; i < days; i++)
    {
        printf("Day %d:",i+1);
        for (int j = 0; j < array[i]/100; j++)
        {
            printf("*");
            /* code */
        }
        printf(" Rs. (%.2f)\n",array[i]);
        
        /* code */
    }
}
