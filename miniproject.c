#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insert();
void search();
void update(); // declaration of function

struct student // structure
{
    int roll;
    char sec[5];
    char name[20];
    int marks;
};
struct student s; // s is a variable of structure student
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\t  rupan nag(RA2111051010052)\n\n");
        printf("\t\t\t\t###################################\n");
        printf("\t\t\t\t'WELCOME TO SRM STUDENT DATABASE'\n");
        printf("\t\t\t\t###################################\n\n\n");
        printf("\t\t\t\tAVAILABLE OPTIONS:\n\n");
        printf("\t\t\t\t1: Insert Student record\n");
        printf("\t\t\t\t2: Search Student record\n");
        printf("\t\t\t\t3: Update Student record\n");
        printf("\t\t\t\t4: Exit\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            insert(); // calling the function
            break;
        case 2:
            system("cls");
            search();
            break;
        case 3:
            system("cls");
            update();
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("\n\t\t!!! You Entered The Wrong Choice !!!\n\n");
            // it is a menu driven program
        }
        getchar(); // again go to the loop
    }
}
void insert() // declaration
{
    FILE *fp;
    //(*fp)points to the file directory
    // file created/mod in buffer/secondary memory. functions done in primary memory

    fp = fopen("stu.txt", "a+");

    //file opened in append mode(a+) to read and write in buffer

    printf("\n\n\t\t^^^^ENTER NEW STUDENT DATA^^^^");
    printf("\n\n\t\tEnter Student Roll Number : ");
    scanf("%d", &s.roll);//the roll segment to the data structure is getting stored by input
    fflush(stdin);

    //dump whatever is stored in buffer into file and clear the buffer

    printf("\n\t\tEnter Student Name : ");
    gets(s.name);
    printf("\n\t\tEnter Student Section : ");
    gets(s.sec);
    printf("\n\t\tEnter Student Total Marks : ");
    scanf("%d", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);

    // use to store data taken from user
    // fwrite use to write in binary mode

    {
        printf("\n\n\tStudent Database Recorded Sucessfully !!!\n");
    }
    fclose(fp);

    // close the file fp
    // as soon as the file closes by the help of buffer(fp) data write in the 2nd memory from the 1st memory

    printf("\n\t\tRecord Updated !!!\n\n");
}
void search()
{
    int ro, flag = 0;

    //as soon flag value is 0 we go into the loop and if it is 1 we go outside the loop
    // ro is taken for roll no.

    FILE *fp;
    fp = fopen("stu.txt", "r");

    //(r),is use to open file in read mode
    if (fp == NULL)//no input given previously
    {
        printf("\n\t\tError : File Does Not Exist !!! ");
        return;
    }
    printf("\n\n\tEnter Student Roll No. Which You Want To Search : ");
    scanf("%d", &ro);
    while (fread(&s, sizeof(s), 1, fp) > 0 && flag == 0)
    {
        if (s.roll == ro)

        // ro is the roll no. that user has entered

        {
            flag = 1;
            printf("\n\n\tSearch Sucessful And Student Records Is as follows");
            printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\n");
            printf("%d\t\t\t%s  \t\t  %s \t\t%d\n\n\n", s.roll, s.name, s.sec, s.marks);
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\t!!! No Record Found !!!\n\n");
    }
    fclose(fp);
}
void update()
{
    int ro, flag = 0;
    FILE *fp;
    fp = fopen("stu.txt", "r+");

    // r+ is use to open file for reading and writing

    if (fp == NULL)
    {
        printf("\n\t\tError : File Does Not Exist");
        return;
    }
    printf("\n\n\tEnter Roll Number Of Students Whose Record You Want To Update :");
    scanf("%d", &ro);
    printf("\n\n\t\t *** Previously Stored Record Of Given Roll No. ***\n\n");
    while (fread(&s, sizeof(s), 1, fp) > 0 && flag == 0)
    {
        if (s.roll == ro)
        {
            flag = 1;
            printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\n");
            printf("%d\t\t\t%s  \t\t %s \t\t%d\n", s.roll, s.name, s.sec, s.marks);
            printf("\n\n\n\t\t*** Now Enter The New Record Of The Student ***\n\n");
            printf("\n\t\tUpdated Student Roll No.: ");
            scanf("%d", &s.roll);
            fflush(stdin);
            printf("\n\t\tUpdated Student Name: ");
            gets(s.name);
            printf("\n\t\tUpdated Student Section: ");
            gets(s.sec);
            printf("\n\t\tUpdated Student Marks: ");
            scanf("%d", &s.marks);
            fseek(fp, -(long)sizeof(s), 1);

            // fseek,it is a update function,minus is used to update file from beginning

            fwrite(&s, sizeof(s), 1, fp);
            printf("\n\n\t\tRecord Updated\n\n\n");
        }
    }
    if (flag == 0)
    {
        printf("\n\t\tError : Something Went Wrong !!!\n\n");
    }
    fclose(fp);
}
