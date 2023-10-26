#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void login();
char password(char username[]);
void Add();
void Modify();
void View();
void Search();
void Sort();

char username[5];
char *meal[100];
char *type[100];
int calories[100];
float time1[100];
int i = -1;

int main(void) 
{
	
	char key[5] = "Hey";
	char option[10] = {0};
	
	do
	{
		
		system("cls");
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("\t\tWELCOME TO THE MAIN SCREEN MR. SPATALAKIS\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		
		login();
		
		do
		{
			system("cls");
			
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			printf("\t\t\tWELCOME TO THE FOOD SCREEN\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			
			printf("Please select one of the following options:\nAdd\nModify\nView\nSearch\nSort\nExit\n\n->");
			scanf("%s", &option);
			
			while(strcmp(option, "Add") != 0 && strcmp(option, "Modify") != 0 && strcmp(option, "View") != 0 && strcmp(option, "Search") != 0 && strcmp(option, "Sort") != 0 && strcmp(option, "Exit") != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("Incorrect option.\nPlease enter a valid option.\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("->");
				scanf("%s", &option);
			}
			
			if(strcmp(option, "Add") == 0)
			{
				Add();
			}
			else if(strcmp(option, "Modify") == 0)
			{
				Modify();
			}
			else if(strcmp(option, "View") == 0)
			{
				View();
			}
			else if(strcmp(option, "Search") == 0)
			{
				Search();
			}
			else if(strcmp(option, "Sort") == 0)
			{
				Sort();
			}
			else if(strcmp(option, "Exit") == 0)
			{
				system("cls");
			}
		
			if(strcmp(option, "Exit") != 0)
			{
				printf("\nPress any key to go to the Food Screen.\nPress Exit to go to the Main Screen.\n");
				scanf("%s", &key);	
			}
		}
		while((strcmp(key, "Exit") != 0) && (strcmp(option, "Exit") != 0));
	}
	while((strcmp(key, "Exit") == 0) || (strcmp(option, "Exit") == 0));
	
	return 0;
}


void Sort()
{
	
	system("cls");
	
	int o, r, s;
	int temp1;
	float temp2;
	char temp3[11], temp4[30];
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("\t\t\tWELCOME TO THE 'SORT' SCREEN\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	for(o = 1; o <= i; o++)
	{
		for(r = i; r <= o; r--)
		{
			if(calories[r -1] < calories[r])
			{
				temp1 = calories[r];
				calories[r] = calories[r - 1];
				calories[r - 1] = temp1;
				
				temp2 = time1[r];
				time1[r] = time1[r - 1];
				time1[r - 1] = temp2;
				
				temp3[11] = meal[r];
				meal[r] = meal[r - 1];
				meal[r - 1] = temp3;
				
				temp4[30] = type[r];
				type[r] = type[r - 1];
				type[r - 1] = temp4;
			}
		}
	}
	
	for(s = 0; s <= i; s++)
	{
		printf("|\tMeal\t|\tCalories\t|\tTime\t|\tType of Meal\n");
		printf("\t %s \t\t %d \t\t\t %.2f \t\t %s \n", meal[s], calories[s], time1[s], type[s]);
	}
}


void Search()
{
	
	system("cls");
	
	char typeofmeal[11];
	int s;
	int e = 0;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("\t\t\tWELCOME TO THE 'SEARCH' SCREEN\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	printf("Please enter a Type of Meal to be searched(prwino/mesimeriano/vradino):\n");
	scanf("%s", &typeofmeal);
	printf("\n\n");
	while(strcmp(typeofmeal, "prwino") != 0 && strcmp(typeofmeal, "mesimeriano") != 0 && strcmp(typeofmeal, "vradino") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("Incorrect Type of Meal.\nPlease enter a valid type:\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		scanf("%s", &typeofmeal);
		printf("\n\n");
	}
	
	printf("|\tMeal\t|\tCalories\t|\tTime\t|\tType of Meal\n");
	
	for(s = 0; s <= i; s++)
	{
		if(strcmp(type[s], typeofmeal) == 0)
		{
			e = 1;
			printf("\t %s \t\t %d \t\t\t %.2f \t\t %s \n", meal[s], calories[s], time1[s], type[s]);
		}
	}
	
	if(e == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("There are no meals of this type.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	
}


void Modify()
{
	
	system("cls");
	
	char type2[11] = {0};
	char meal2[30] = {0};
	int k;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("\t\t\tWELCOME TO THE 'MODIFY' SCREEN\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	printf("|\tMeal\t|\tCalories\t|\tTime\t|\tType of Meal\n");
	printf("\t %s \t\t %d \t\t\t %.2f \t\t %s \n\n", meal[i], calories[i], time1[i], type[i]);
	
	if(i != -1)
	{
		
		printf("Which data would you like to modify?(Type 1 for Meal, 2 for Calories, 3 for Time or 4 for Type of Meal)\n->");
		scanf("%d", &k);
		printf("\n");
		while(k != 1 && k != 2 && k != 3 && k != 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("Incorrect number.\nPlease enter a valid number of the ones above:\t");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			scanf("%d", &k);
			printf("\n");
		}
		
		if(k == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			printf("You are now able to modify the Meal:\t");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			scanf(" %s", &meal2);
			meal[i] = meal2;
			printf("\n\n");
		}
		else if(k == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			printf("You are now able to modify the Calories:\t");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			scanf("%d", &calories[i]);
			printf("\n\n");
		}
		else if(k == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			printf("You are now able to modify the Time:\t");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			scanf("%.2f", &time1[i]);
			printf("\n\n");
		}
		else if(k == 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			printf("You are now able to modify the Type of Meal:\t");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			scanf(" %s", &type2);
			type[i] = type2;
			printf("\n\n");
		}
	}
	else if(i == -1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("There are no data for modification.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	
}


void View()
{
	
	system("cls");
	
	int v, ath = 0;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("\t\t\tWELCOME TO THE 'VIEW' SCREEN\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	printf("|\tMeal\t|\tCalories\t|\tTime\t|\tType of Meal\n");
	for(v = 0; v <= i; v++)
	{
		printf("\t %s \t\t %d \t\t\t %.2f \t\t %s \n", meal[v], calories[v], time1[v], type[v]);
	}
	
	if(i == -1)
		printf("\nTotal number of meals added so far: 0.\n");
	else
		printf("\nTotal number of meals added so far: %d.\n", i + 1);
	
	for(v = 0; v <= i; v++)
	{
		ath += calories[v];
	}
	
	printf("Total calories out of all meals so far: %d.\n\n\n", ath);
	
}


void Add()
{
	
	system("cls");
	
	char type1[11] = {0};
	char meal1[30] = {0};
	
	i++;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("\t\tWELCOME TO THE 'ADD' SCREEN\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	printf("Please enter your meal:\t");
	scanf("%s", &meal1);
	printf("\n\n");
	printf("Please enter the calories of your meal:\t");
	scanf("%d", &calories[i]);
	printf("\n\n");
	printf("Please enter the time you ate your meal(XX.YY):\t");
	scanf("%f", &time1[i]);
	printf("\n\n");
	
	meal[i] = meal1;
	
	if(time1[i] >= 05.00 && time1[i] <= 11.59)
	{
		type1[0] = 'p';
		type1[1] = 'r';
		type1[2] = 'w';
		type1[3] = 'i';
		type1[4] = 'n';
		type1[5] = 'o';
		type1[6] = '\0';
		type1[7] = '\0';
		type1[8] = '\0';
		type1[9] = '\0';
		type1[10] = '\0';
		type1[11] = '\0';
	}
	else if(time1[i] >= 12.00 && time1[i] <= 19.59)
	{
		type1[0] = 'm';
		type1[1] = 'e';
		type1[2] = 's';
		type1[3] = 'i';
		type1[4] = 'm';
		type1[5] = 'e';
		type1[6] = 'r';
		type1[7] = 'i';
		type1[8] = 'a';
		type1[9] = 'n';
		type1[10] = 'o';
		type1[11] = '\0';
	}
	else if((time1[i] >= 20.00 && time1[i] <= 24.00) || (time1[i] >= 00.00 && time1[i] <= 04.59))
	{
		type1[0] = 'v';
		type1[1] = 'r';
		type1[2] = 'a';
		type1[3] = 'd';
		type1[4] = 'i';
		type1[5] = 'n';
		type1[6] = 'o';
		type1[7] = '\0';
		type1[8] = '\0';
		type1[9] = '\0';
		type1[10] = '\0';
		type1[11] = '\0';
	}
	
	type[i] = type1;
	
	
	printf("food:%s\n", meal[i]);
	printf("type:%s\n", type[i]);
	printf("calories:%d\n", calories[i]);
	printf("time:%.2f\n", time1[i]);
	

}


char password(char username[])
{
	
	int x;
	
	x = 1 + rand()%2;
	
	if(x == 1)
	{
		username[0] = 'J';
		username[1] = 'o';
		username[2] = 'H';
		username[3] = 'n';
	}
	else if(x == 2)
	{
		username[0] = 'j';
		username[1] = 'O';
		username[2] = 'h';
		username[3] = 'N';
	}
	
	return username;
	
}


void login()
{
	
	char his_password[5] = {0};
	
	printf("\tLOGIN\n\n");
	printf("Please enter your username:\t");
	scanf("%s", &username);
	printf("\n\n");
	do
	{
		if(strcmp(username, "John") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("Incorrect username.\nPlease enter the correct username:\t");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			scanf(" %s", &username);
			printf("\n\n");
		}
	}
	while(strcmp(username, "John") != 0);
	
	password(username);
 	
 	printf("Please enter your password:\t");
	scanf(" %s", &his_password);
		
	while(strcmp(his_password, username) != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("\nIncorrect password.\nPlease enter the correct password:\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		scanf(" %s", &his_password);
	}
		
	system("cls");
		
	if(strcmp(his_password, username) == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		printf("Correct password.\nLogin: Successful.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
 	
}
