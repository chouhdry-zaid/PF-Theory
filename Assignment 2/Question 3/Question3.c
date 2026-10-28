/*
Programmer:Zaid
section:BS-AI-1A
ROLL NO:0015
Description:Temperature Monitor Sensors Report
*/


#include<stdio.h>
#include<stdlib.h>

void init_sensors(int **sensors,int rows,int col){ // input
    for (int i = 0; i <rows ; i++)
    {
        printf("===Enter the hourly temp: readings for sensor %d===\n",i+1);
        for (int  j = 0; j < col; j++)
        {
            printf("Reading %d:\n",j+1);
            scanf("%d",&sensors[i][j]);
            /* code */
        }
        /* code */
    }
    
}
void analysis(int **sensors,int rows,int col){ // analysis
    int sum=0, max,min,critical=0,warnings=0,streak=0;
    for (int i = 0; i <rows ; i++)
    {
        for (int  j = 0; j < col; j++)
        {
            max=sensors[i][0];
            if (sensors[i][j]>max)
            {
                max=sensors[i][j];
                /* code */
            }
            min=sensors[i][0];
            if (sensors[i][j]<min)
            {
                min=sensors[i][j];
                /* code */
            }
            if (sensors[i][j]>=40) // critical
            {
                critical++;
                /* code */
            }
            if (sensors[i][j]>=35 && sensors[i][j]<=39) // warning
            {
                warnings++;
                /* code */
            }
            if (sensors[i][j]>=35) // streak
            {
                streak++;
                /* code */
            }else{
                streak=0;
            }
            
            sum+=sensors[i][j];
            /* code */
        }
        float avg=sum/col; // average
        printf("Sensor %d:",i+1);
        printf("Total:%d   Average:%.2f   Max:%d  Min:%d\n",sum,avg,max,min);
        printf("\tcritical:%d   warning:%d   longest hot streak:%d",critical,warnings,streak);
        printf("\n");
        sum=0;
        critical=0;
        warnings=0;
        streak=0;
    }
}

int sum_of_divisors(int n);
int main(){
    int no_of_sensors,readings;
    printf("Enter the no: of sensors and no: of hourly readings.");
    scanf("%d %d",&no_of_sensors,&readings);
    int **sensors=(int **)malloc(no_of_sensors * sizeof(int *)); // allocate
    for (int i = 0; i < readings; i++)
    {
        sensors[i]=(int *)calloc(readings,sizeof(int));
        /* code */
    }
    init_sensors(sensors,no_of_sensors,readings); // call
    analysis(sensors,no_of_sensors,readings);
    
    
}