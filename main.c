#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

struct Patient p[100];
int count = 0;
void saveFile()
{
    FILE *fp;

    fp = fopen("patients.txt","w");

    for(int i=0; i<count; i++)
    {
        fprintf(fp,"%d %s %d %s %s\n",
        p[i].id,
        p[i].name,
        p[i].age,
        p[i].gender,
        p[i].disease);
    }

    fclose(fp);
}


void loadFile()
{
    FILE *fp;

    fp = fopen("patients.txt","r");

    if(fp == NULL)
        return;

    while(fscanf(fp,"%d %s %d %s %s",
    &p[count].id,
    p[count].name,
    &p[count].age,
    p[count].gender,
    p[count].disease) != EOF)
    {
        count++;
    }

    fclose(fp);
}


// Login Function
void login()
{
    char username[20];
    char password[20];

    printf("\n=====================================\n");
    printf("      HOSPITAL MANAGEMENT SYSTEM\n");
    printf("=====================================\n");

    printf("\nUsername: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    if(strcmp(username,"admin")==0 && strcmp(password,"1234")==0)
    {
        printf("\nLogin Successful!\n");
    }
    else
    {
        printf("\nInvalid Login!\n");
        exit(0);
    }
}


// Add Patient
void addPatient()
{
    printf("\nEnter Patient ID: ");
    scanf("%d",&p[count].id);

    printf("Enter Name: ");
    scanf("%s",p[count].name);

    printf("Enter Age: ");
    scanf("%d",&p[count].age);

    printf("Enter Gender: ");
    scanf("%s",p[count].gender);

    printf("Enter Disease: ");
    scanf("%s",p[count].disease);

    count++;

    saveFile();

    printf("\nPatient Added Successfully!\n");
}


// View Patients
void viewPatient()
{
    if(count==0)
    {
        printf("\nNo Patient Records Found!\n");
        return;
    }

    printf("\n------ Patient Records ------\n");

    for(int i=0;i<count;i++)
    {
        printf("\nID: %d",p[i].id);
        printf("\nName: %s",p[i].name);
        printf("\nAge: %d",p[i].age);
        printf("\nGender: %s",p[i].gender);
        printf("\nDisease: %s\n",p[i].disease);
    }
}


// Search Patient
void searchPatient()
{
    int id, found=0;

    printf("\nEnter Patient ID to Search: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++)
    {
        if(p[i].id==id)
        {
            printf("\nPatient Found!");
            printf("\nName: %s",p[i].name);
            printf("\nAge: %d",p[i].age);
            printf("\nGender: %s",p[i].gender);
            printf("\nDisease: %s\n",p[i].disease);

            found=1;
            break;
        }
    }

    if(found==0)
        printf("\nPatient Not Found!\n");
}


// Update Patient
void updatePatient()
{
    int id;

    printf("\nEnter Patient ID to Update: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++)
    {
        if(p[i].id==id)
        {
            printf("Enter New Disease: ");
            scanf("%s",p[i].disease);
            saveFile();

            printf("\nRecord Updated Successfully!\n");
            return;
        }
    }

    printf("\nPatient Not Found!\n");
}


// Delete Patient
void deletePatient()
{
    int id;

    printf("\nEnter Patient ID to Delete: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++)
    {
        if(p[i].id==id)
        {
            for(int j=i;j<count-1;j++)
            {
                p[j]=p[j+1];
            }

            count--;
            saveFile();

            printf("\nPatient Deleted Successfully!\n");
            return;
        }
    }

    printf("\nPatient Not Found!\n");
}


// Main Function
int main()
{
    int choice;

    loadFile();

    login();

    while(1)
    {
        printf("\n\n=====================================");
        printf("\n      HOSPITAL MANAGEMENT SYSTEM");
        printf("\n=====================================");

        printf("\n1. Add Patient");
        printf("\n2. View Patient");
        printf("\n3. Search Patient");
        printf("\n4. Update Patient");
        printf("\n5. Delete Patient");
        printf("\n6. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);


        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                viewPatient();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                printf("\nThank You for using Hospital Management System!");
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }
    }

    return 0;
}
