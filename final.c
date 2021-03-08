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
	const char option3[size], const char option4[size],const char correct[size], const char category[size],FILE * fp,float *);
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
     printf("\n\t\t\tC PROGRAM QUIZ GAME\n");
     printf("\n\t\t_________________________________________");
     printf("\n\t\t\tWELCOME  to THE GAME  ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t GOOD CHANCE TO WIN CASH!!!!!!!!!!!    ") ;
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
	 printf("\nOld record was deleted\n");
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
    printf("\n -***...........Welcome %s to C Program Quiz Game ........***-",playername);
    printf("\n\n ---------------------------------------------------------------------");
    printf("\n >> Here are some tips you might wanna know before playing:");
    printf("\n ---------------------------------------------------------------------\n");
    printf("\n >> Now you are going to play WARMUP ROUND you will be asked a total of ");
    printf("\n    5 questions");
    printf("\n >> Give atleast 3 right answers otherwise you can't play the Game\n");
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
			strncpy(option1,line,50);

				if(i == 4)
			strncpy(option2,line,50);

				if(i == 5)
			strncpy(option3,line,50);

				if(i == 6)
			strncpy(option4,line,50);

			if (i >1&&i<=7)
			{
				printf("%s",line);

			}
			if (i == 8)
			strncpy(correct,line,50);

			if (i == 9)
			strncpy(category,line,50);
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
	system("pause");
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
	system("pause");
	exit(1);
	}
     test:
     system("cls");
     printf("\n\n\t*** CONGRATULATION %s you are eligible to play the Game ***",playername);
     printf("\n\n\n\n\t!Press N to go next level of the Game!");
    if (toupper(getch())=='N'){
            goto M;
            system("cls");
    }
    else
		{
        goto mainhome;
       system("cls");
       }
    M:
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
			strncpy(option1,line,50);

				if(i == 4)
			strncpy(option2,line,50);

				if(i == 5)
			strncpy(option3,line,50);

				if(i == 6)
			strncpy(option4,line,50);

			if (i >1&&i<=7)
			{
				printf("%s",line);

			}
			if (i == 8)
			strncpy(correct,line,50);

			if (i == 9)
			strncpy(category,line,50);
		}

    counter+=asked(option, option1, option2, option3, option4, correct, category,output,&score);
		system("cls");
	}
	fclose(fp);

	fclose(output);
	 score=0.00;
	score=(float)counter*10000;
	edit_score(score,playername);
	  output = fopen("Newtext.txt","r");

	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}

	fclose(output);

	system("pause");
	printf("\n\n\n\n\n");
	printf("\n\n\n\t\t\t\t\t WELL PLAYED %s",playername);
    printf("\n\n\t\t\t **************** CONGRATULATION!!!*****************");
     printf("\n\n\t\t\t\tYou won $%.2f",score);
     remove("Newtext.txt");
     	puts("\n\n Thankyou for playing the game");
	puts("\n Press any key if you want to exit from the game");
	getch();
   }
        return 0;
    }
    void show_record()
    {system("cls");
	char name[20];
	float scr;
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&name,&scr);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t %s has secured the Highest Score %0.2f",name,scr);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();}
void reset_score()
    {system("cls");
    float sc;
	char nm[20];
	FILE *f;
	remove("score.txt");
	f=fopen("score.txt","w");
	  fclose(f);
    }
    void help()
	{system("cls");
    printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ......................... C program Quiz Game...........");
    printf("\n >> There are two rounds in the game, WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In WARMUP ROUND you will be asked a total of 5 questions to test your programming");
    printf("\n    skills. You will be eligible to play the game if you can give atleast 3");
    printf("\n    right answers otherwise you can't play the Game...........");
    printf("\n >> Your game starts with the CHALLANGE ROUND. In this round you will be asked");
    printf("\n    total 10 questions each right answer will be awarded $10,000.");
    printf("\n    By this way you can win upto ONE Lakh cash prize in USD...............");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option");
    printf("\n >> You will be asked questions continuously if you keep giving the right answers.");
    printf("\n >> No negative marking for wrong answers");

	printf("\n\n\t*********************BEST OF LUCK*********************************");
	}
		int asked(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,float *counter)
	{
		printf("Your Option : ");
		scanf("%str",&option[0]);
		option[1] = '\0';
		strupr(option);

			char correctanswer[size];
			char wronganswer[size];

			fprintf(fp,"%s \n",category);

		if (option[0] == correct[0])
		{
			if (option[0] == option1[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
			if (option[0] == option2[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
			if (option[0] == option3[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
			if (option[0] == option4[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option4);
            fprintf(fp," -----------------------------------------------------------------------------\n");
			fprintf(fp," -----------------------------------------------------------------------------\n");

				counter = 1;
				return counter;
		}
		else
		{

			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,24);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,24);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,24);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,24);

			correctanswer[24] = '\0';

			if (option[0] == option1[0])
				strncpy(wronganswer, option1,24);
			if (option[0] == option2[0])
				strncpy(wronganswer, option2,24);
			if (option[0] == option3[0])
				strncpy(wronganswer, option3,24);
			if (option[0] == option4[0])
				strncpy(wronganswer, option4,24);

			wronganswer[24] = '\0';

			fprintf(fp," You entered     : %s \n", wronganswer);
			fprintf(fp," Correct answer  : %s \n", correctanswer);
            fprintf(fp," -----------------------------------------------------------------------------\n");
			fprintf(fp," -----------------------------------------------------------------------------\n");
			return 0;
		}

	}
void edit_score(float score, char plnm[20])
	{
	    system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc)
	  { sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
fclose(f);
	    }
    }
