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

typedef struct{
    char *Name;
    char *Surname;
    char *Filename;
    WORK *Works;
}ASSITANT;

ASSITANT *Assitants;
int AssistantCount = 0;

void ReadFromFileToAssistants()
{
    AssistantCount = 0;

    FILE *fp;





}







int main()
{

    system("PAUSE");
    return 0;
}


