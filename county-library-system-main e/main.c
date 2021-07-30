/*-----------------------------
* Version: C99                *
* Project: Library management *
* Author:  Renny Kariuki      *
* Date:    June,2021          *
* License: MIT                *
******************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//Adding user:
//name
//id
//contact
//is_staff

struct user {
    char name[100];
    int id;
    char tel[13];
    int is_staff;
};

//function prototype
void execute_action(int action);
void close();
int menu();
void add_user();


int main()
{
    int action;
    while(1) {
        action = menu();
        execute_action(action);
        printf("\nPress any key to continue");
        getch();
        system("cls");
    }



    return 0;
}

 void execute_action(int action)  {
        switch(action) {
case 1:
    add_user();
    break;

 case 2:
    printf("Adding a book\n");
    break;
 case 3:
    close();
    break;

 default:
    printf("unknown action. \n");
}        }
void close() {
    printf("Thank you for using the system\n");
    printf("Bye\n");
    Sleep(5000);
    exit(0);





}
int menu(){
    //navigation menu
    int action;

do {    printf("\tCounty Library Management System!\n");
        printf("Welcome Renny\n");
        printf("1. Add user\n");
        printf("2. Add Book\n");
        printf("3. Exit\n");
        printf("Select action(1-3): ");
        scanf("%d",&action);
        // validate input
        if (action < 1 || action > 3)
            printf("Invalid action. Try again\n");
            Sleep(2000);
            system("cls");
    } while(action < 1 || action > 3);

    return action;



}
void add_user() {
    struct user u;
    FILE *fp;
    if ((fp = fopen("users","ab"))==NULL) {
        printf("cannot open file.\n");
        exit (1);
    }
    printf("Name: ");
    getchar();
    gets(u.name);
    printf("ID number: ");
    scanf("%d",&u.id);
    printf("Phone number: ");
    scanf("%s",&u.tel);
    printf("user type(1 for staff, 0 for ordinary user: ");
    scanf("%d",&u.is_staff);
    fwrite(&u, sizeof(struct user), 1, fp);
    fclose(fp);
    printf("user successfully added\n");
}
