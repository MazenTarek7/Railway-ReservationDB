#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include "railway.h"
//-----------------------------------------Functions-------------------------------------------------------------------------
void reserveTicket();
void viewTrains();
void fileWrite();
void Admin();
void addTrain();
void userSearch();
//---------------------------------------------------------------------------------------------------------------------------
//----------------------------------------Global Variables-------------------------------------------------------------------
struct bookTicket book[10];
struct addTrain add[10];
int n;              // Global variable used for counter
FILE *bookedTickets;
//---------------------------------------------------------------------------------------------------------------------------
int main (){
    system ("COLOR F");
    int i,j,choice;
    printf("\t\t\t\tWelcome to the Railway Ticket Reservation System\n");
    while (1){
    printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Admin");
	printf("\n------------------------");
    printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&choice);
	switch (choice){
	    case 1: reserveTicket();break;
	    case 2: viewTrains();break;
	    case 3: Admin();break;
	    case 4: exit(0);
	    default: printf("Invalid choice,please try again\n");break;
	}
	}
return 0;
}
void reserveTicket(){
    printf("How many tickets do you want to buy?\n");
    int phone_length;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
    printf("\tTicket (%d of %d)\n",i+1,n);
    printf("Please enter your first Name: ");
    scanf("%s",&book[i].fname);
    printf("Please enter your last Name: ");
    scanf("%s",book[i].lname);
    do {
    printf("Enter train number: ");
    scanf("%d",&book[i].trainNum);
    if (book[i].trainNum < 1 || book[i].trainNum >5){
        printf("A train with this number doesn't exist, please try again\n");
    }
    } while (book[i].trainNum <1 || book[i].trainNum > 5);
    do {
    printf("Enter the number of seats you want in Train Number (%d): ",book[i].trainNum);
    scanf("%d",&book[i].num_seats);
    if (book[i].num_seats >5 || book[i].num_seats <=0)
        printf("Maximum number of seats allowed per transaction is 5 and Minimum is 1 \n");
    } while (book[i].num_seats >5 || book[i].num_seats <=0);
    do {
    printf("Please enter your phone number: ");
    scanf("%s",&book[i].phone);
    phone_length = strlen(book[i].phone);
    if (phone_length<11 || phone_length >11)
        printf("Phone number MUST be 11 digits\n");
    if (strncmp(book[i].phone,"01",2)!=0)
    printf("Phone number must start with 01,please try again\n");
    } while(strncmp(book[i].phone,"01",2)!=0 || phone_length<11 || phone_length>11);
    printf("%s",book[i].phone);
    printf("\n\t\t\t\t  >>>>Ticket Booked Successfully<<<<\n");
    printf("Thank you for choosing Mazen's Railway Service\n");
    system("PAUSE");
    system("cls");
    fileWrite();
    }
}
void viewTrains()
{
    system("cls");
	printf("-----------------------------------------------------------------------------");
	printf("\nTrain Number\tTrain Name\tDestination\tTime\tPrice\t\t\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1\t\tAlexandria\tRamses\t100 EGP\t\t11am");
	printf("\n2\t\tAlexandria\tLuxor \t100 EGP\t\t2pm");
	printf("\n3\t\tCairo     \tTanta \t100 EGP\t\t10am");
	printf("\n4\t\tCairo  \t    PortSaid \t100 EGP\t\t5pm");
	printf("\n5\t\tCairo  \t    Mansoura \t100 EGP\t\t2pm\n\n\n");
	system("PAUSE");
	system("cls");
}
void Admin(){                                                   //Admin Mode, can check users and add trains
    int i=0,choice,flag=0;
    char username[10],check=' ';
    char password[10];
    char user[10]="admin";
    char pass[10]="admin";
    do
{
    printf("\n------------------------  Admin Login Page  ------------------------\n");
    printf("Enter username: ");
	scanf("%s", &username);
	printf("Enter password: ");
	while(i<10)
	{
	    password[i]=getch();
	    check=password[i];
	    if(check==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';
	i=0;
		if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0)
	{
    flag=1;
	printf("\nLOGIN Successful\n");
	printf("\t\t\t\tWELCOME MAZEN!");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\nInvalid Username or Password, please try again\n");
		getch();
	}
} while(flag!=1);
		system("cls");
    while (1){
    printf("              ____________________________________\n");
	printf("              ||      CHOOSE AN OPERATION       ||\n");
	printf("              ||--------------------------------||\n");
	printf("              ||      [1] Add Train             ||\n");
	printf("              ||      [2] Search for User       ||\n");
	printf("              ||      [3] QUIT                  ||\n");
	printf("              ||________________________________||\n\n");
	printf("\nPlease select an operation: ");
	scanf("%d",&choice);
	switch (choice){
	    case 1: addTrain();break;
	    case 2: userSearch();break;
	    case 3: exit(0);
	    default: printf("Invalid input,please enter the correct input\n");break;
	}
    }
}
void addTrain(){
    system("cls");
    int n;
    printf("How many trains do you want to add?\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++ ){
        printf("\tTrain (%d of %d)\n",i+1,n);
        do {
        printf("Please enter Train Number: ");
        scanf("%d",&add[i].trainNum);
        if (add[i].trainNum >=1 && add[i].trainNum <=5)
        printf("Train number already exists,please enter a different number\n");
        } while (add[i].trainNum >=1 && add[i].trainNum <=5);
        printf("Please enter Train Name: ");
        scanf("%s",add[i].trainName);
        printf("Please enter Train Destination: ");
        scanf("%s",add[i].destination);
        do {
        printf("Please enter price of %s Train number (%d): ",add[i].trainName,add[i].trainNum);
        scanf("%d",&add[i].price);
        if (add[i].price <=0)
            printf("Price must be greather than 0\n");
        } while (add[i].price <=0);
        printf("\t\t\t<<<<Train Added Succesfully>>>\n");
    }
}
void userSearch(){
    char cmp[11];
    int index;
    printf("Enter the phone number of the user you want to search for\n");
    scanf("%s",&cmp);
    for (int i = 0; i<10; i++){
        if (strcmp(cmp,book[i].phone)==0){
        index = i;
        }
    }
        printf("First Name: %s",book[index].fname);
        printf("\nLast Name:  %s\n",book[index].lname);
        printf("Booked on Train Number: %d\n",book[index].trainNum);
        printf("Number of seats booked by this user %d\n",book[index].num_seats);
        printf("Price to Pay = %d \n\n",100*book[index].num_seats);
}
void fileWrite(){
    bookedTickets = fopen("Booked Tickets.txt","at");
    for (int i = 0; i < n;i++){
    fprintf(bookedTickets,"First Name: %s",book[i].fname);
    fprintf(bookedTickets,"\nLast Name: %s",book[i].lname);
    fprintf(bookedTickets,"\nTrain Number: %d",book[i].trainNum);
    fprintf(bookedTickets,"\nNo. of Seats: %d",book[i].num_seats);
    fprintf(bookedTickets,"\nPhone Number: %s",book[i].phone);
    fprintf(bookedTickets,"\n-------------------------------------\n");
    }
    fclose(bookedTickets);
}


