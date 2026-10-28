/*
Programmer:Zaid
section:BS-AI-1A
ROLL NO:0015
Description:Booking management system
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int rows=5,col=8,k,count=0,total=0; // variables
    printf("Enter the no: of seats you want to sit together:");
    scanf("%d",&k); // input
    if (k>col)
    {
        printf("Maximum seats in a Row is %d.\n Re-input:",col);
        scanf("%d",&k);
        /* code */
    }
    
    int **array=(int **)malloc(rows * sizeof(int *)); // allocate
    for (int i = 0; i < rows; i++)
    {
        array[i]=(int *)calloc(col, sizeof(int ));

    }
    array[0][2]=1; // booked
    array[0][7]=1;
    array[1][1]=1;
    array[1][2]=1;
    array[1][6]=1;
    array[2][0]=1;
    array[2][4]=1;
    array[3][5]=1;
    array[3][6]=1;
    array[4][0]=1;
    array[4][1]=1;
    
    for (int i = 0; i < rows; i++)
    {
        count=0;
        for (int j = 0; j < col; j++)
        {
            if (array[i][j]==0)
            {
                count++;
            }
        }
        printf("Free seats in R%d is %d\n",i,count); // availability
        total+=count;
    }
    printf("Total free seats:%d\n",total);
    count=0;
    int i,j;
    for ( i = rows/2; i >=0; i--) // search
    {
        for ( j = 0; j < col; j++)
        {
            if(array[i][j]==0){
                count++;
            }
            if(count==k){ // found
                if (j-k+1<0)
                {
                    printf("there were less seats in one row to sit together.\nRe-input:");
                    scanf("%d",&k);
                    /* code */
                }else{

                    printf("Group of %d seated in row %d, seats %d to %d\n.",k,i,j-k+1,j);
                }
                array[i][j]=1;
                for (int l = 0; l < k; l++)
                {
                    array[i][j-l]=1;
                    /* code */
                }
                
                break;
            }
            /* code */
        }
        if (count==k)
        {
            break;
            /* code */
        }
        count=0;
        if (i==0)
        {
            for( i = rows/2; i <rows; i++)
    {
        for ( j = 0; j < col; j++)
        {
            if(array[i][j]==0){
                count++;
            }
            if(count==k){
                printf("Group of 3 seated in row %d, seats %d to %d\n.",i,j-k+1,j);
                for (int l = 0; l < k; l++)
                {
                    array[i][j-l]=1;
                    /* code */
                }
                
                break;
            }
            /* code */
        }
        if (count==k)
        {
            break;
            /* code */
        }
        count=0;
        
    }
            /* code */
        }
        
    }
    //ISSUE
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array[i][j]==1)
            {
                array[i][j]=='X';
                /* code */
            }else{
                array[i][j]=='_';
            }
        }
        
    }
    for (int i = 0; i <8; i++)
    {
        if (i==0)
        {
            printf("  \t%d ",i);
            /* code */
        }else
        printf("%d ",i);
        
        /* code */
    }
    printf("\n");
    
    for (int i = 0; i < rows; i++)
    {
        printf("R%d\t",i); // display
        for (int j = 0; j < col; j++)
        {
            printf("%d|",array[i][j]);
        }
        printf("\n");
    }

}