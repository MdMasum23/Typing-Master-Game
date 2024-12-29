#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

static int x=1;
#define pos gotoxy(33,x++)
#define ln  printf(".......................");
//....................................................................................
COORD coord= {0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//.................................................................................
void delay(unsigned int mseconds)
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}


//.................................................................................
void setcolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;


    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);

        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

//..............................................................................
void sett();
int t=30;
int c=0;

char name[15];
void getscore(int score,int speed,int level);
void startgame();
void scorecard();
void About_me();
void help();


//.............................................................................
void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y);
    printf("%c",201);
    for(i=x+1; i<l-1; i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y);
    printf("%c",187);

    for (m=y+1; m<b; m++)
    {
        gotoxy(x,m);
        for(i=x; i<l; i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m);
                printf("%c",186);
            }

        }

    }

    gotoxy(x,m);
    printf("%c",200);
    for(i=x+1; i<l-1; i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m);
    printf("%c",188);
}

//...................................................................

int main()
{
    int ch;

    time_t t;
    time(&t);
//	rectangle(0,0,70,15);
    x=1;
    system("cls");
    pos;
    setcolor(12) ;
    printf("Welcome to Typing Master Game ");
    setcolor(11) ;
    pos;
    printf("%s",ctime(&t));
    setcolor(10) ;
    pos;
    ln pos;
    if(c==0)
    {
        printf("Enter player's name::");
        gets(name);
    }
    c++;
    pos;
    ln pos;
    printf("#..MAIN MENU..#");
    pos;
    ln
    pos;
    printf("1.Start_Game");
    pos;
    printf("2.Scorecard");
    pos;
    printf("3.Set the time limit::");
    pos;
    printf("4.Help");
    pos;
    printf("5.About us");
    pos;
    printf("0.Exit");
    pos;
    printf("Enter your choice::");
    scanf("%d",&ch);
    pos;
    switch(ch)
    {
    case 1:
        startgame();
        break;
    case 2:
        scorecard();
        break;
    case 3:
        sett();
        main();
    case 4:
        help();
        break;
    case 5:
        About_me();
        break;
    case 0:
        system("cls");
        gotoxy(17,10);
        setcolor(6);
        printf("#This Game is created by Mohammad Masum Alam#\t\t");
        printf("Sami Farhan#\t\t");
        printf("Asir Intisar Rifat#");
        delay(1000);
        exit(1);

    default:
        main();
    }

    getch();
}

//..........................................................................

void startgame()
{
    char r[100], typedWord[100];
    int  letter, ch;
    rectangle(0, 0, 80, 20);
    delay(500);

    int score = 0, level = 1, mode = 100, count = 0;
    clock_t begin;
    int time_spent, speed;

    char wordsLevel2[][50] = {"apple", "banana", "cat", "dog", "fish","horse","bat","ball","egg","goat"};
    char wordsLevel3[][50] = {"elephant", "giraffe", "kangaroo", "rhinoceros",
                              "hippopotamus","dinosaurs","importance","flexible","example","mangrove"
                             };

    srand(time(NULL));
    int x = 2;

    system("cls");

    pos;
    setcolor(15);
    printf("# Select the Mode #");
    pos;
    printf("1. Easy mode");
    pos;
    printf("2. Medium mode");
    pos;
    printf("3. Hard mode");
    pos;
    printf("4. Back to the main menu");
    pos;
    scanf("%d", &level);

    if (level == 4)
        main();
    else
    {
        if (level == 1)
        {

            mode = rand() % 2 == 0 ? 65 : 97;
        }
        else if (level == 2)
            mode = 2;
        else if (level == 3)
            mode = 3;

        begin = clock();
        while (1)
        {
            system("cls");
            time_spent = (int)(clock() - begin) / CLOCKS_PER_SEC;

            if (time_spent >= t)
                break;

            if (mode == 2)
            {

                int wordIndex = rand() % (sizeof(wordsLevel2) / sizeof(wordsLevel2[0]));
                strcpy(r, wordsLevel2[wordIndex]);
            }
            else if (mode == 3)
            {

                int wordIndex = rand() % (sizeof(wordsLevel3) / sizeof(wordsLevel3[0]));
                strcpy(r, wordsLevel3[wordIndex]);
            }
            else
            {

                r[0] = rand() % 26 + mode;
                r[1] = '\0';

            }

            gotoxy(20, 8);
            printf(".... Type the following word ....");
            gotoxy(36, 11);
            printf(" %s\n\t\t\t\t", r);

            scanf("%s", typedWord);


            if (strcmp(typedWord, r) == 0)
            {

                count++;
                score = score + 10;
                gotoxy(28, 9);
                printf("Score=%d", score);
                gotoxy(37, 9);
                printf("Time_Spent=%d sec", time_spent);

                if (level == 1)
                    delay(600);
                else if (level == 2)
                    delay(400);
                else if (level == 3)
                    delay(200);
            }
            else
            {
                system("cls");

                break;
            }

        }


        gotoxy(26, x);
        delay(400);
        setcolor(11);
        ++x;
        pos;

        speed = (count * 60) / time_spent;

        if (time_spent <t-1)
            printf("You are a loser! Game Over!");
        else
        {
            setcolor(11);
            printf("Time's up! Game over!");
            pos;
            setcolor(15);

            if ((speed >= 30) && (speed <= 40))
            {
                printf("Good Work! Keep it up!");
                pos;
                printf("You got a Silver medal");
            }
            else if (speed > 40)
            {
                printf("Nice work! You got a Gold medal");
            }
            else
                printf("Sorry, no medal! You need practice...");
        }

        pos;
        printf("Total score is: %d", score);
        pos;
        printf("Your net speed =%d word per minute(WPM)", speed);
        getscore(score, speed, level);

        ++x;
        pos;
        printf("1. # Play again #");
        pos;
        printf("2. # Main menu #");
        pos;
        printf("3. Exit\n");
        pos;
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            startgame();
            break;
        case 2:
            main();
            break;
        case 3:
            system("cls");
            gotoxy(17, 10);
            setcolor(6);
            printf("# This Game is created by Mohammad Masum Alam\t\tSami Farhan\t\tAsir Intisar Rifat #");
            delay(1000);
            exit(1);

        default:
            pos;
            printf("Wrong choice!");
            pos;
            main();
        }
    }
}



//............................................................................
void sett()
{
    int choice;
    system("cls");
    setcolor(11);
    x=5;
    pos;
    printf("Set the time limit for the game in minutes::");
    pos;
    ln
    pos;
    printf("Press 0 for half a minute") ;
    pos;
    printf("Press 1 for 1 minute");
    pos;
    printf("Press 2 for 2 minutes");
    pos;
    printf("Press 3 to go back to the Main Menu");
    pos;
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
        t = 30;
        break;
    case 1:
        t = 60;
        break;
    case 2:
        t = 120;
        break;
    case 3:
        main();
        break;
    default:
        main();
    }
}



//........................................................................
void help()
{
    char choice;
    system("cls");
    rectangle(0, 0, 87, 22);
    gotoxy(7, 5);
    setcolor(6);

    printf("#......Rules of the Game......#");
    gotoxy(7, 6);
    printf("=>Enter your name as player name");
    gotoxy(7, 7);
    printf("=>Set the time limit under option 3 in the main menu (default limit is 30 sec)");
    gotoxy(7, 8);
    printf("=>Select the level and get started :");
    gotoxy(7, 9);
    printf("=>Characters are displayed, and you have to type them as fast as you can..");
    gotoxy(7, 10);
    printf("=>Avoid incorrect typing; otherwise, the game will be over..");

    setcolor(15);
    printf("\n\n\tPress 'B' or 'b' to go back to the main menu : ");
    choice = getch();
    if (choice == 'B' || choice == 'b')
    {
        main();
    }

}



//........................................................................
void About_me()
{
    char choice;
    system("cls");
    gotoxy(7, 7);
    setcolor(7);
    printf("Created by:\n");
    printf("\tMohammad Masum Alam ,ID:CE21023,Tangail.\n");
    printf("\tSami Farhan ,ID:CE21027,Tangail.\n");
    printf("\tAsir Intisar Rifat ,ID:CE21026,Tangail.\n\n");
    setcolor(11);
    printf("Under the supervision of:\nMd. Mosaddik Hasan sir\nAssociate Professor\nDepartment of CSE\nMawlana Bhashani Science and Technology University\n\n");
    setcolor(12);
    printf("I think it would be better....thanks...");

    printf("\n\nPress 'B' or 'b' to go back to the main menu: ");
    choice = getch();

    if (choice == 'B' || choice == 'b')
    {
        main();
    }

}


//.........................................................................
void getscore(int score, int speed, int level)
{
    FILE *fp;
    fp = fopen("file.txt", "a");
    pos;

    if (fp == NULL)
    {
        printf("Error in opening file");
    }
    else
    {

        fprintf(fp, "\nname=%-15s\tscore=%-5d\tspeed=%-5d\tlevel=%-5d", name, score, speed, level);
        fclose(fp);
        pos;
        printf("Scorecard Updated");
    }
}


//........................................................................
void scorecard()
{
    int ch;
    char choice;
    FILE *fp;
    system("cls");

    printf("\t\t\t....The scores are...\n\n");

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening file");
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
        fclose(fp);
    }
    setcolor(6);
    printf("\n\nPress 'B' or 'b' to go back to the main menu: ");
    choice = getch();

    if (choice == 'B' || choice == 'b')
    {
        main();
    }

}




