/*
Login Id: 9920407045
Password: krishna123
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<Windows.h>
#include<conio.h>


int no_of_inv=0;
char *name12[10][50];
int s2, d2, t2, r2,nameI=0;
char *SPORT[10][15],*DAY[10][20],*TIME[10][15];
char *sport[15], *day[20], *time1[10];
int option=0;
int opt_name;

int loader(void);
void find_a_friend();


void heading();
void login();

void booking(int c,int n);
int s1, d1, t1;

void shop(int c,int n);
int s3,q3,p3;

struct resident
{
    char phd[11];
    char passd[11];
    char named[50];
    char flat[10];
};
struct resident r[5];
int name;

void main()
{

    login();

    int bookingCount = 0, shopCount=0;
    int choice;
    int ch=1;
    do
    {
        heading();
        printf("Hello %s,", r[name].named);
        printf("\n\nWhat would you like to do?");
        printf("\n\n[1] Booking \t [2] Find a Friend \t [3] Shop \t [4] Exit \n\n");
        tryAgain:
        printf("Your choice: ");
        scanf("%d", &choice);
        if(choice==1)
        {
            booking(bookingCount,name);
            bookingCount++;
        }
        else if(choice==2)
        {
            find_a_friend();
        }
        else if (choice==3)
        {
            shop(shopCount,name);
            shopCount++;
        }
        else if(choice==4)
        {
            printf("\n\nThank you for using our app :) \n");
        }
        else
        {
            printf("\nWrong input, please try again!!\n\n");
            goto tryAgain;
        }

    }while(choice!=4);
}

void heading()
{
    printf("\t\t\t\t\t          EzeePlay");
    printf("\n____________________________________________________________________________________________________________________\n\n");
}

void login()
{
    char phe[11]; char namee[50]; char passs[11];
    int n, m;

    heading();
    printf("\nWelcome to EzeePlay.\nWhere playing is made easy so you can enjoy!!\n");
    printf("In case of any problem in logging in, try contacting the chairmain of the society.\n");

    //Database
    //kanika
    strcpy(r[0].phd,"9930821886");
    strcpy(r[0].passd,"kanika1234");
    strcpy(r[0].named,"Kanika Nadar");
    strcpy(r[0].flat,"A/ 504");

    //rajat
    strcpy(r[1].phd,"7045274687");
    strcpy(r[1].passd,"rajat12345");
    strcpy(r[1].named,"Rajat Saboo");
    strcpy(r[1].flat,"B/ 1502");

    //saheel
    strcpy(r[2].phd,"7208082558");
    strcpy(r[2].passd,"saheel1234");
    strcpy(r[2].named,"Saheel Mayekar");
    strcpy(r[2].flat,"C/ 701");

    //sam
    strcpy(r[3].phd,"9819200361");
    strcpy(r[3].passd,"sam1234567");
    strcpy(r[3].named,"Sam Selvaraj");
    strcpy(r[3].flat,"A/ 603");

    //sir
    strcpy(r[4].phd,"9920407045");
    strcpy(r[4].passd,"krishna123");
    strcpy(r[4].named,"Krishna Samdani");
    strcpy(r[4].flat,"C/ 2102");

    retry:

    printf("\nEnter your contact number: ");
    gets(phe);
    printf("\nEnter your password: ");
    gets(passs);

    if(strcmp(r[0].phd,phe)==0 && strcmp(r[0].passd,passs)==0)
    {
        opt_name=0;
        printf("\n\nName        : %s", r[0].named);
        printf("\nContact no. : %s", r[0].phd);
        printf("\nFlat No.    : %s",r[0].flat);
        name=0;
        printf("\n\nEntered username and password are correct\n\n");
        printf("Press any key to continue....");
        getch();
        system("cls");

    }

    else if(strcmp(r[1].phd,phe)==0 && strcmp(r[1].passd,passs)==0)
    {
        opt_name=1;
        printf("\n\nName        : %s", r[1].named);
        printf("\nContact no. : %s", r[1].phd);
        printf("\nFlat No.    : %s",r[1].flat);
        name=1;
        printf("\n\nEntered username and password are correct\n\n");
        printf("Press any key to continue....");
        getch();
        system("cls");

    }

    else if(strcmp(r[2].phd,phe)==0 && strcmp(r[2].passd,passs)==0)
    {
        opt_name=2;
        printf("\n\nName        : %s", r[2].named);
        printf("\nContact no. : %s", r[2].phd);
        printf("\nFlat No.    : %s",r[2].flat);
        name=2;
        printf("\n\nEntered username and password are correct\n\n");
        printf("Press any key to continue....");
        getch();
        system("cls");
    }

    else if(strcmp(r[3].phd,phe)==0 && strcmp(r[3].passd,passs)==0)
    {
        opt_name=3;
        printf("\n\nName        : %s", r[3].named);
        printf("\nContact no. : %s", r[3].phd);
        printf("\nFlat No.    : %s",r[3].flat);
        name=3;
        printf("\n\nEntered username and password are correct\n\n");
        printf("Press any key to continue....");
        getch();
        system("cls");
    }

    else if(strcmp(r[4].phd,phe)==0 && strcmp(r[4].passd,passs)==0)
    {
        opt_name=4;
        printf("\n\nName        : %s", r[4].named);
        printf("\nContact no. : %s", r[4].phd);
        printf("\nFlat No.    : %s",r[4].flat);
        name=4;
        printf("\n\nEntered username and password are correct\n\n");
        printf("Press any key to continue....");
        getch();
        system("cls");
    }

    else
    {
        printf("\n\nIncorrect username and password combination, please try again ! \n");
        goto retry;
    }
}

void booking(int c,int n)
{
    retryBooking:
    system("cls");
    char sport[15][50] = {"Table Tennis",
                          "Squash",
                          "Lawn Tennis",
                          "Badminton",
                          "Swimming",
                          "Billiards",
                          "Volleyball Ball",
                          "Cricket",
                          "Football"};

    char day[5][50] = {"Tomorrow",
                       "Day after tomorrow"};

    char time [15][50] = {"9 am to 10 am",
                          "10 am to 11 am",
                          "11 am to 12 pm",
                          "12 pm to 1 pm",
                          "1 pm to 2 pm",
                          "2 pm to 3 pm",
                          "3 pm to 4 pm",
                          "4 pm to 5 pm",
                          "5 pm to 6 pm",
                          "6 pm to 7 pm",
                          "7 pm to 8 pm",
                          "8 pm to 9 pm"};

    heading();

    if(c==0)
    {
        printf("\nSelect a sport u would like to book (Per person price for non residents)\n");
        printf("[1] Table Tennis : 100         [2] Squash    : 100         [3] Lawn Tennis : 200         \n");
        printf("[4] Badminton    : 200         [5] Swimming  : 300         [6] Billiards   : 500         \n");
        printf("[7] Volleyball   : 200         [8] Cricket   : 300         [9] Football    : 300          \n");
        printf("Your choice: ");
        scanf("%d",&s1);

        printf("\nChoose on which day you would like to book \n");
        printf("[1] Tomorrow \t [2] Day after tomorrow \n");
        printf("Your choice: ");
        scanf("%d",&d1);

        printf("\nChoose timeslot \n");
        printf(" [1] 9 am to 10 am \t  [2] 10 am to 11 am \t [3] 11 am to 12 pm \n");
        printf(" [4] 12 pm to 1 pm \t  [5] 1 pm to 2 pm   \t [6] 2 pm to 3 pm   \n");
        printf(" [7] 3 pm to 4 pm  \t  [8] 4 pm to 5 pm   \t [9] 5 pm to 6 pm   \n");
        printf("[10] 6 pm to 7 pm  \t [11] 7 pm to 8 pm   \t[12] 8 pm to 9 pm   \n");
        printf("Your choice: ");
        scanf("%d",&t1);

        if(s1>9 || d1>2 || t1>12)
        {
            printf("\nInvalid input, please try again...");
            printf("\n\nEnter any key to continue....");
            getch();
            goto retryBooking;
        }

        else
        {
            printf("\n********************************************************************\n");
            printf("                          RECEIPT                                   \n");
            printf("Name      : %s \n", r[n].named);
            printf("Sport     : %s \n", sport[s1-1]);
            printf("Day       : %s\n", day[d1-1]);
            printf("Time slot : %s\n", time[t1-1]);
            printf("\n********************************************************************");

            printf("\n\nEnter any key to continue....");
            getch();
            system("cls");
        }


    }

    else
    {
        int cancel;
        printf("\nYou have already done your booking\n");
        printf("\n********************************************************************\n");
        printf("                          RECEIPT                                   \n");
        printf("Name      : %s \n", r[n].named);
        printf("Sport     : %s \n", sport[s1-1]);
        printf("Day       : %s \n", day[d1-1]);
        printf("Time slot : %s \n", time[t1-1]);
        printf("\n********************************************************************");
        printf("\nDo you want to cancel your booking and retry? \n[1] Yes \t [2] No\n\n");
        printf("Your choice: ");
        scanf("%d",&cancel);
        if(cancel==1)
        {
            booking(0,n);
        }
        system("cls");
    }
}

void shop(int c,int n)
{
    system("cls");
    char product[25][60]={"Stag 4 Star Table Tennis Racquet",
                          "Stag Seam Plastic Table Tennis Ball,40mm Pack of 6",
                          "Stag 4 Star Table Tennis Kit","Head Squash Racquet",
                          "Dunlop Squash Ball",
                          "Head Squash Racquet with Squash Balls Pack of 3",
                          "Tennex Lawn Tennis Racquet",
                          "Cosco All Court Tennis Ball Pack of 3",
                          "Yonex Aluminium Badminton Racquet with Full cover",
                          "Yonex Mavis 200i Nylon Shuttle Cock, Pack of 6",
                          " Swimming Goggles Silicone Anti Fog, UV Protection",
                          "Speedo Silicon Swimcap",
                          "Billiard Pool Cue Stick",
                          "Nivia Volleyball",
                          "Solimo Leather Cricket Ball Set of 2",
                          "GM Kashmir Willow Cricket Bat",
                          "Nivia Storm Football",
                          "Adidas Football Shoes"};

    int price[25]={450,
                   150,
                   1000,
                   4000,
                   300,
                   10000,
                   900,
                   300,
                   500,
                   450,
                   550,
                   450,
                   1500,
                   500,
                   500,
                   2000,
                   500,
                   3000};

    int cancel;
    heading();

    if (c==0)
    {
        printf("\nSelect the product you would like to buy \n");
        printf("Table Tennis \n");
        printf(" [1] Stag 4 Star Table Tennis Racquet                  : Rs. 450             [2] Stag Seam Plastic Table Tennis Ball, 40mm Pack of 6 : Rs. 150 \n");
        printf(" [3] Stag 4 Star Table Tennis Kit                      : Rs. 1000             \n");

        printf("\nSquash \n");
        printf(" [4] Head Squash Racquet                               : Rs. 4000            [5] Dunlop Squash Ball                                  : Rs. 300 \n");;
        printf(" [6] Head Squash Racquet with Squash Balls Pack of 3   : Rs. 10,000 \n");

        printf("\nLawn Tennis \n");
        printf(" [7] Tennex Lawn Tennis Racquet                        : Rs. 900             [8] Cosco All Court Tennis Ball Pack of 3               : Rs. 300 \n");

        printf("\nBadminton \n");
        printf(" [9] Yonex Aluminium Badminton Racquet with Full cover : Rs. 500            [10] Yonex Mavis 200i Nylon Shuttle Cock, Pack of 6      : Rs. 450 \n");

        printf("\nSwimming \n");
        printf("[11] Swimming Goggles Silicone Anti Fog, UV Protection : Rs. 550            [12] Speedo Silicon Swimcap                              : Rs. 450 \n");

        printf("\nBilliards and Volleyball\n");
        printf("[13] Billiard Pool Cue Stick                           : Rs. 1500           [14] Nivia Volleyball                                    : Rs. 500 \n");

        printf("\nCricket\n");
        printf("[15] Solimo Leather Cricket Ball Set of 2              : Rs. 500            [16] GM Kashmir Willow Cricket Bat                       : Rs. 2000 \n");

        printf("\nFootball \n");
        printf("[17] Nivia Storm Football                              : Rs. 500            [18] Adidas Football Shoes                               : Rs. 3000 \n");

        printf("\nYour Choice: ");
        scanf("%d",&s3);

        printf("\nSelect the quantity of the product\n");
        printf("[1] 1 \t [2] 2 \t [3] 3 \t [4] 4 \t [5] 5 \n");
        printf("Your choice: ");
        scanf("%d",&q3);

        printf("\n********************************************************************\n");
        printf("                          RECEIPT                                   \n");
        printf("Name     : %s \n", r[n].named);
        printf("Product  : %s \n", product[s3-1]);
        printf("Quantity : %d \n", q3);
        printf("Price    : Rs. %d \n", price[s3-1]*q3);
        printf("\n********************************************************************");

        printf("\n\nEnter any key to continue....");
        getch();
        system("cls");
    }

    else
    {
        printf("\nYou have already placed an order\n");
        printf("\n********************************************************************\n");
        printf("                          RECEIPT                                   \n");
        printf("Name     : %s \n", r[n].named);
        printf("Product  : %s \n", product[s3-1]);
        printf("Quantity : %d \n", q3);
        printf("Price    : Rs. %d \n", price[s3-1]*q3);
        printf("\n********************************************************************");
        printf("\n\nWould you like to cancel your order and try again?\n");
        printf("[1] Yes \t [2] No\n\n");
        printf("Your choice: ");
        scanf("%d", &cancel);
        if(cancel==1)
        {
            shop(0,n);
        }
        system("cls");
    }
}

//Find A Friend
void find_a_friend()
{
    retryFriend:
    system("cls");
    heading();
    char *n[50];

    printf("----||FINDING FRIENDS||----\n\n");
    int ch;

    printf("\n[1] View Invitations\n");
    printf("[2] Create your own Invitation\n");
    printf("Enter option: ");
    scanf("%d",&ch);

    if(ch>2)
    {
        printf("\nInvalid input, please try again...");
        printf("\n\nEnter any key to continue....");
        getch();
        goto retryFriend;
    }


    if(ch==1)
    {
        int i;
        system("cls");
        heading();
        printf("\nPending Invitations: \n");
        printf("Invitation #1 \nRajat Saboo would like to play Cricket tomorrow during 4 pm to 5 pm slot.\n\n");
        printf("Invitation #2 \nSaheel Mayekar would like to play Squash day after tomorrow during 1 pm to 2 pm slot.\n\n");
        printf("Invitation #3 \nKanika Nadar would like to play Badminton tomorrow during 6 pm to 7 pm slot.\n\n");
        printf("Invitation #4 \nKrishna Samdani would like to play Table Tennis day after tomorrow during 8 pm to 9 pm slot.\n\n");

        //printf("   NAME\t\t\tSPORT\t\t\tDATE\t\t\tTIME\n");
        for(i=0;i<nameI;i++)
        {
            if(r[opt_name].named!=(NULL))
            {
                printf("Invitation #%d \n%s would like to play %s %s during %s slot.\n\n",(i+5),r[opt_name].named,SPORT[i][15],DAY[i][20],TIME[i][15]);
            }
        }
        //printf("\n%d",nameI);
        if(nameI>=0)
        {
            printf("\nChoose invitation no.: ");
            scanf("%d",&option);

            if(nameI >= 1 && option > 4)
            {
                printf("Already booked.");
            }
            else if(option>0 && option<=nameI+4)
            {
                loader();
                printf("\nBOOKING CONFIRMED!");
            }
            else
            {
                printf("WRONG INPUT :/");
            }

        }
    }
    else if(ch==2)
    {

        /*printf("\n");
        printf("Enter name: ");
        gets(n);
        gets(n);
        name[nameI][50]=n;
        printf("\n");*/
        system("cls");
        heading();
        printf("Select a sport u would like to play \n");
        printf("[1] Table Tennis         [4] Badminton          [7] Volleyball               \n");
        printf("[2] Squash               [5] Swimming           [8] Cricket                 \n");
        printf("[3] Lawn Tennis          [6] Billiards          [9] Football                \n");
        printf("Your choice: ");
        scanf("%d",&s2);

        printf("\nChoose on which day you would like to play \n");
        printf("[1] Tomorrow \t [2] Day after tomorrow \n");
        printf("Your choice: ");
        scanf("%d",&d2);

        printf("\nChoose timeslot \n");
        printf(" [1] 9 am to 10 am \t  [2] 10 am to 11 am \t [3] 11 am to 12 pm \n");
        printf(" [4] 12 pm to 1 pm \t  [5] 1 pm to 2 pm   \t [6] 2 pm to 3 pm   \n");
        printf(" [7] 3 pm to 4 pm  \t  [8] 4 pm to 5 pm   \t [9] 5 pm to 6 pm   \n");
        printf("[10] 6 pm to 7 pm  \t [11] 7 pm to 8 pm   \t[12] 8 pm to 9 pm   \n");
        printf("Your choice: ");
        scanf("%d",&t2);

        //Sport's numbering
        if(s2==1)
            *sport="Table Tennis";
        if(s2==2)
            *sport="Squash";
        if(s2==3)
            *sport="Lawn Tennis";
        if(s2==4)
            *sport="Badminton";
        if(s2==5)
            *sport="Swimming";
        if(s2==6)
            *sport="Billiards";
        if(s2==7)
            *sport="Volley Ball";
        if(s2==8)
            *sport="Cricket";
        if(s2==9)
            *sport="Football";

        SPORT[nameI][15]=*sport;
        //printf("%s\n",*SPORT[nameI][15]);

        //Day numbering
        if(d2==1)
            *day="tomorrow";
        if(d2==2)
            *day="day after tomorrow";
        DAY[nameI][20]=*day;
        //printf("%s\n",*DAY[nameI][20]);


        //Time numbering
        if(t2==1)
            *time1="9 am to 10 am";
        if(t2==2)
            *time1="10 am to 11 am";
        if(t2==3)
            *time1="11 am to 12 pm";
        if(t2==4)
            *time1="12 pm to 1 pm";
        if(t2==5)
            *time1="1 pm to 2 pm";
        if(t2==6)
            *time1="2 pm to 3 pm";
        if(t2==7)
            *time1="3 pm to 4 pm";
        if(t2==8)
            *time1="4 pm to 5 pm";
        if(t2==9)
            *time1="5 pm to 6 pm";
        if(t2==10)
            *time1="6 pm to 7 pm";
        if(t2==11)
            *time1="7 pm to 8 pm";
        if(t2==12)
            *time1="8 pm to 9 pm";

        TIME[nameI][15]=*time1;
        //printf("\n%s",*time1);
        printf("\n");
        loader();
        //Receipt
        printf("\n********************************************************************\n");
        printf("                          Invitation                                  \n");
        printf("Name      : %s\n",r[opt_name].named);
        printf("Sport     : %s \n", *sport);
        printf("Day       : %s\n", *day);
        printf("Time slot : %s\n", *time1);
        printf("\n********************************************************************");

        nameI=nameI+1;

    }

    int ch2;
    printf("\n\nDo you want to quit? ");
    printf("\n[1] Yes \t [2] No");
    printf("\nEnter option: ");
    scanf("%d",&ch2);
    //scanf(" %c",&ch2);
    //ch2=tolower(ch2);
    if(ch2==1)
    {
        system("cls");
        //printf("\nTHANK YOU!\n");
    }
    else
    {
        find_a_friend();
    }

    //printf("%c",ch);
}



int loader(void)
{
    int loop, each;
    for (loop = 0; loop < 1; ++loop)
    {
        for (each=0; each < 4; ++each)
        {
            printf ( "\r%.*s   \b\b\b", each, "...");
            fflush ( stdout);//force printing as no newline in output
            Sleep (1);
        }
    }
    printf ( "\n");
    return 0;
}

