/*Programmer:Zaid
section:BS-AI-1A
ROLL NO:0015
Description:Library Management system
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strcmp
void display_menu(){ // menu
    printf("== LIBRARY MANAGEMENT SYSTEM ==\n");
    printf("1. Register member\n");
    printf("2. Display available books\n");
    printf("3. Borrow a book\n");
    printf("4. Return a book\n");
    printf("5. Display member record\n");
    printf("6. Exit\n");
    printf("Enter your choice:\n");
}
void reg_mem(char name[],int *std_id,int *mem_type){ // register
    printf("Enter your name:\n");
    scanf(" %[^\n]",name);
    printf("Enter your student ID and Member type( 1-student & 2-faculty)\n");
    scanf("%d %d",std_id,mem_type);   
}
void display_books(int book_ids[],char book_titles[][50],int available_copies[],int totalcopies){ // display
    printf("|  ID  |         Title         |Copies|\n");
    printf(" -------------------------------------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("| %-4d | %-21s | %-4d |\n", book_ids[i], book_titles[i], available_copies[i]);
    }
    
}
void borrow_books(int book_ids[],char book_titles[][50],int available_copies[],int totalcopies, // borrow
    int borrowed_book_ids[],int *borrowed_count,int *member_type,int *count){
        int book_id,days;
        printf("Enter the book ID and the no of days intend to keep the book:\n");
        scanf("%d %d",&book_id,&days);
        if (book_id<101 || book_id>104) // validate
        {
            printf("enter valid book ID.\n");
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (*member_type==1)
            {
                if (book_id==book_ids[i])
                {
                    if (available_copies[i]>0)
                    {
                        if (days<=15) // limit
                        {
                            printf("you can take your book.\n");
                            (*borrowed_count)++;
                            borrowed_book_ids[*count]=book_ids[i];
                            totalcopies--;
                            available_copies[i]--;
                            /* code */
                        }else{
                            printf("You should have to return book in under 15 days.\n");
                        }
                    }else{
                        printf("No free book.\n");
                        
                    }
                }
            }else if (*member_type==2)
            {
                if (book_id==book_ids[i])
                {
                    if (available_copies[i]>0)
                    {
                        if (days<=30)
                        {
                            printf("you can take your book.\n");
                            (*borrowed_count)++;
                            borrowed_book_ids[*count]=book_ids[i];
                            available_copies[i]--;
                            /* code */
                        }else{
                            printf("You should have to return book in under 30 days.\n");
                        }
                        
                        /* code */
                    }else{
                        printf("No free book.\n");
    
                    }
                    /* code */
                } 
            }else{
                printf("You are not the member of institute----retry.\n");
                break;
            }
            
            
            /* code */
        }
        
        
        
    }
    float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int
borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine){
    int book_id,days,found=0,pos=0,allowed,rate;
    float fine=0,payable=0;
    char code[20];
    printf("Enter the book ID and the no of days the book was with you:\n");
    scanf("%d %d",&book_id,&days);
    if (days<=0) // validate
    {
        printf("No of days must be a positive no.\n");
        return 0;
        /* code */
    }
    for (int i = 0; i < *borrowedCount; i++)
    {
        if (borrowedBookIDs[i]==book_id)
        {
            found=1;
            pos=i;
            break;
            /* code */
        }
        /* code */
    }
    if (found==0)
    {
        printf("You have not borrowed this book.\n");
        return 0;
        /* code */
    }
    for (int i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i]==book_id)
        {
            availableCopies[i]++;
        }
        /* code */
    }
    if (memberType==1)
    {
        allowed=14;
        rate=20;
    }else{
        allowed=30;
        rate=10;
    }
    if (days>allowed)
    {
        fine=(days-allowed)*rate; // fine
        printf("Fine is Rs. %f\n",fine);
        printf("Enter the membership code for fine waiver:\n");
        scanf("%s",code);
        if (strcmp(code,"LIB2026")==0) // waiver
        {
            payable=fine/2;
            printf("Correct code.\n");
            /* code */
        }else{
            payable=fine;
            printf("Wrong code.\n");
            /* code */
        }
        printf("Fine: Rs. %f\n",payable);
    }else{
        printf("No fine.\n");
        /* code */
    }
    *totalFine+=fine;
    for (int i = pos; i < *borrowedCount-1; i++) // shift
    {
        borrowedBookIDs[i]=borrowedBookIDs[i+1];
    }
    (*borrowedCount)--;
    return payable;
}
void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver){ // record
    printf("== MEMBER RECORD ==\n");
    printf("Name: %s\n",name);
    printf("Student ID: %d\n",studentID);
    if (memberType==1)
    {
        printf("Membership type: Student\n");
        /* code */
    }else{
        printf("Membership type: Faculty\n");
        /* code */
    }
    printf("Currently borrowed books: ");
    if (borrowedCount==0)
    {
        printf("None");
        /* code */
    }
    for (int i = 0; i < borrowedCount; i++)
    {
        printf("%d ",borrowedBookIDs[i]);
        /* code */
    }
    printf("\n");
    printf("Total fine: Rs. %f\n",totalFine);
    printf("Final fine: Rs. %f\n",fineAfterWaiver);
}

int main(){
    char title[4][50]={
        "programming in c ",
        "Data structures",
        "Database systems",
        "Computer Networks"
    };
    int totalcopies=0;
    int copies[4];
    copies[0]=5;
    copies[1]=3;
    copies[2]=0;
    copies[3]=4;
    int Ids[4];
    for (int i = 0; i < 4; i++)
    {
        Ids[i]=101+i;
        totalcopies+=copies[i];
    }
    int borrowed_ids[3];
    int borrowed_count=0;
    char names[100];
    int std_id, mem_type;
    float total_fine=0,fine_after_waiver=0;
    int choice,registered=0; // flags

    int count=0;
    do
    {
        display_menu();
        scanf("%d",&choice);
        switch (choice) // switch
        {
        case 1:
            reg_mem(names,&std_id,&mem_type);
            if (mem_type==1 || mem_type==2)
            {
                registered=1;
                printf("you are registered now.\n");
                /* code */
            }else{
                registered=0;
                printf("Enter valid member type\n");
                /* code */
            }
            break;
        case 2:
            display_books(Ids,title,copies,totalcopies);
            break;
            /* code */
        case 3:
            if (registered==0)
            {
                printf("register first.\n");
            }else if (borrowed_count>=3)
            {
                printf("can borrow maximum three books at a time.\n");
                /* code */
            }else{
                count=borrowed_count;
                borrow_books(Ids,title,copies,totalcopies,borrowed_ids,&borrowed_count,&mem_type,&count);
                /* code */
            }
            break;
            /* code */
        case 4:
            if (registered==0)
            {
                printf("register first.\n");
            }else if (borrowed_count==0)
            {
                printf("not borrowed any book.\n");
                /* code */
            }else{
                fine_after_waiver+=returnBook(Ids,copies,4,borrowed_ids,&borrowed_count,mem_type,&total_fine);
                /* code */
            }
            break;
            /* code */
        case 5:
            if (registered==0)
            {
                printf("register first.\n");
            }else{
                displayMemberRecord(names,std_id,mem_type,borrowed_ids,borrowed_count,total_fine,fine_after_waiver);
            }
            break;
            /* code */
        case 6:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice-retry.\n");
            /* code */
        }
        
    } while (choice!=6); // exit
    
    

}
