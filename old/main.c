#include <stdio.h>
#include <stdlib.h>


typedef enum{
	
	Free,
	Lab,
	Other
	
}WORKTYPE;

typedef struct{
	
	char Hour;
	char Minutes;
	char Day;
	char Month;
	int Year;
	
}TIME;

typedef struct{
	WORKTYPE Worktype;
	TIME StartTime;
	TIME EndTime;
	int Duration;//as minutes
}WORK;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	
		
	
	
	
	return 0;
}
