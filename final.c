#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define QNO 30
#define totques 10
#define size 200
void show_record();
void reset_score();
void help();
void edit_score(float , char []);
 int asked(char option[size], const char option1[size], const char option2[size],
	const char option3[size], const char option4[size],const char correct[size], const char category[size],FILE * fp,int *);
	int main()
     {
    char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
	char empty[256][256];
	int i,j,k;
	int arr[QNO],x,loc;
	time_t t;
	char line[256];
    int counter,r,r1,count,n;
     float score;
     char choice;
     char playername[20];
      FILE * fp;
    FILE * output;
    fp = fopen("Quiz.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}
  mainhome:
     system("cls");
     printf("\n\t\t_________________________________________");

     printf("\n\t\t\t   WELCOME to THE GAME");
     printf("\n\t   +-------+                          ___       ___                             ");
     printf("\n\t   |       |      |         |            |                /                              ");
     printf("\n\t   |       |      |         |            |               /                               ");
     printf("\n\t   |       |      |         |            |              /                                ");
     printf("\n\t   |    // |      |         |            |             /                                 ");
     printf("\n\t   |   //  |      |         |            |            /                                  ");
     printf("\n\t   +--//---+      |___|         _|_        /___                          ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t   BECOME A MILLIONAIRE!!!!!!!!!!!    ") ;
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t > Press S to start the game");
     printf("\n\t\t > Press V to view the highest score  ");
     printf("\n\t\t > Press R to reset score");
     printf("\n\t\t > press H for help            ");
     printf("\n\t\t > press Q to quit             ");
     printf("\n\t\t________________________________________\n\n");
     choice=toupper(getch());
     if (choice=='V')
	{
	show_record();
	goto mainhome;
	}
     else if (choice=='H')
	{
	help();
	getch();
	goto mainhome;
	}
	else if (choice=='R')
	{reset_score();
	getch();
	goto mainhome;}
	else if (choice=='Q')
	exit(1);
    else if(choice=='S')
    {
     system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tResister your name:");
     gets(playername);
     system("cls");
    printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------",playername);
    printf("\n\n Here are some tips you might wanna know before playing:");
    printf("\n -------------------------------------------------------------------------");
    printf("\n >> There are 2 rounds in this Quiz Game,WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 3 questions to test your");
    printf("\n    general knowledge. You are eligible to play the game if you give atleast 2");
    printf("\n    right answers, otherwise you can't proceed further to the Challenge Round.");
    printf("\n >> Your game starts with CHALLANGE ROUND. In this round you will be asked a");
    printf("\n    total of 10 questions. Each right answer will be awarded $100,000!");
    printf("\n    By this way you can win upto ONE MILLION cash prize!!!!!..........");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option.");
    printf("\n >> You will be asked questions continuously, till right answers are given");
    printf("\n >> No negative marking for wrong answers!");
    printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
    printf("\n\n\n Press Y  to start the game!\n");
    printf("\n Press any other key to return to the main menu!");
     if (toupper(getch())=='Y')
		{
		    goto home;
        }
	else
		{
        goto mainhome;
       system("cls");
       }
       home :
       counter=0;
		k = 0;
		for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}
 for (j = 0; j <5; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);

			}

				if(i==2)
				{
					fputs(line,output);
				}

				if(i == 3)
			strncpy(option1,line,30);

				if(i == 4)
			strncpy(option2,line,30);

				if(i == 5)
			strncpy(option3,line,30);

				if(i == 6)
			strncpy(option4,line,30);

			if (i >1&&i<=7)
			{
				printf("%s",line);

			}
			if (i == 8)
			strncpy(correct,line,30);

			if (i == 9)
			strncpy(category,line,30);
		}


		counter+=asked(option, option1, option2, option3, option4, correct, category,output,&score);
     system("cls");
	}

	fclose(fp);

	fclose(output);

	output = fopen("Newtext.txt","r");

	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}

	fclose(output);
	    count=counter;
	    if(counter>=3)
   {  getch();
    fp = fopen("Quiz.txt","r");
   output = fopen("NewText.txt","w");
    goto test;}
	else
	{
	system("cls");
	printf("\n\nSORRY YOU ARE NOT ELIGIBLE TO PLAY THIS GAME, BETTER LUCK NEXT TIME");
	getch();
	goto mainhome;
	}
     test:
     system("cls");
     printf("\n\n\t*** CONGRATULATION %s you are eligible to play the Game ***",playername);
     printf("\n\n\n\n\t!Press any key to Start the Game!");
     getch();
     counter=0;
	 k = 0;
	 	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}
    for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);

			}

				if(i==2)
				{
					fputs(line,output);
				}

				if(i == 3)
			strncpy(option1,line,30);

				if(i == 4)
			strncpy(option2,line,30);

				if(i == 5)
			strncpy(option3,line,30);

				if(i == 6)
			strncpy(option4,line,30);

			if (i >1&&i<=7)
			{
				printf("%s",line);

			}
			if (i == 8)
			strncpy(correct,line,30);

			if (i == 9)
			strncpy(category,line,30);
		}


	counter+=asked(option, option1, option2, option3, option4, correct, category,output,&score);
		system("cls");
	}
	fclose(fp);

	fclose(output);

	output = fopen("Newtext.txt","r");

  	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}

	fclose(output);
    // counter=counter-count;
    score=0.00;
	score=(float)counter*100000;
	printf("%f",score);
	if(score>0.00 && score<1000000)
	{
	   printf("\n\n\t\t**************** CONGRATULATION *****************");
	     printf("\n\t You won $%.2f",score);goto go;}
     else if(score==1000000.00)
	{
	    printf("\n\n\n \t\t**************** CONGRATULATION ****************");
	    printf("\n\t\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
	    printf("\n\t\t You won $%.2f",score);
	    printf("\t\t Thank You!!");
	}
	 else
    {
	 printf("\n\n\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
	    printf("\n\t\t Thanks for your participation");
	    printf("\n\t\t TRY AGAIN");goto go;}

	go:
	    remove("Newtext.txt");
	puts("\n\n Press Y if you want to play next game");
	puts(" Press any key if you want to go main menu");
	if (toupper(getch())=='Y')
		goto home;
	else
		{
		edit_score(score,playername);
		goto mainhome;}
    }
        return 0;
    }
