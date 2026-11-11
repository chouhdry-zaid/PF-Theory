
/*
Programmer:Zaid
section:BS-AI-1A
ROLL NO:0015
Description:Booking management system
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int rows=5,col=8,k,count=0,total=0;
    int found=0;

    printf("Enter the no: of seats you want to sit together:");
    scanf("%d",&k);

    while(k<1 || k>col){
        printf("Maximum seats in a Row is %d.\nRe-input:",col);
        scanf("%d",&k);
    }

    int **array=(int **)malloc(rows * sizeof(int *));

    for(int i=0;i<rows;i++){
        array[i]=(int *)calloc(col,sizeof(int));
    }

    array[0][2]=1;
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

    // availability
    printf("\nFree seats per row: ");

    for(int i=0;i<rows;i++){

        count=0;

        for(int j=0;j<col;j++){
            if(array[i][j]==0){
                count++;
            }
        }

        printf("%d ",count);
        total+=count;
    }

    printf("   Total free: %d\n",total);

    int i,j;

    // search from middle row to first row
    for(i=rows/2;i>=0;i--){

        count=0;

        for(j=0;j<col;j++){

            if(array[i][j]==0){
                count++;
            }
            else{
                count=0;
            }

            if(count==k){

                printf("\nGroup of %d seated in Row %d, Seats %d to %d\n",
                k,i,j-k+1,j);

                for(int l=j-k+1;l<=j;l++){
                    array[i][l]=1;
                }

                found=1;
                break;
            }
        }

        if(found==1){
            break;
        }
    }

    // search from middle row to last row
    if(found==0){

        for(i=rows/2+1;i<rows;i++){

            count=0;

            for(j=0;j<col;j++){

                if(array[i][j]==0){
                    count++;
                }
                else{
                    count=0;
                }

                if(count==k){

                    printf("\nGroup of %d seated in Row %d, Seats %d to %d\n",
                    k,i,j-k+1,j);

                    for(int l=j-k+1;l<=j;l++){
                        array[i][l]=1;
                    }

                    found=1;
                    break;
                }
            }

            if(found==1){
                break;
            }
        }
    }

    if(found==0){
        printf("\nNo seats available.\n");
    }

    // display seats

    printf("\n");

    for(int i=0;i<col;i++){
        printf("%d ",i);
    }

    printf("\n");

    for(int i=0;i<rows;i++){

        printf("R%d\t",i);

        for(int j=0;j<col;j++){

            if(array[i][j]==1){
                printf("X ");
            }
            else{
                printf("_ ");
            }
        }

        printf("\n");
    }

    // free memory

    for(int i=0;i<rows;i++){
        free(array[i]);
    }

    free(array);

    return 0;
}
