/*
Programmer:Zaid
section:BS-AI-1A
ROLL NO:0015
Description:TO find Amicable pair up to given range
*/


#include<stdio.h>
#include<stdlib.h>

int sum_of_divisors(int n); // prototype
int main(){
    int n,sum=0,sum2=0;
    printf("enter a number:");
    scanf("%d",&n); // input
    sum_of_divisors(n);
    
}
int sum_of_divisors(int n){
    int sum1=0,sum2=0,count=0;
    for (int i = 1; i <= n; i++)
    {
        sum1=0,sum2=0;
        for (int j = 1; j <= i/2; j++) // divisors
        {
            if (i%j==0)
            {
                sum1+=j;
                /* code */
            }
        }
        for (int k = 1; k <=sum1/2 ; k++) // verify
        {
            if (sum1%k==0)
            {
                sum2+=k;
                /* code */
            }
            
            /* code */
        }
        if (sum2==i) // amicable
        {
            if (sum1<i) // once
            {
            printf("(%d,%d)\n",sum1,i);
            count++;
            }
            // else if (i<sum1)
            // {
            //     printf("(%d,%d)\n",i,sum1);
            //     count++;
            // }
        }
    }
    if (count==0) // none
    {
        printf("None\n");
        /* code */
    }else{
        printf("The no of pairs are:%d\n",count);
    }    

}