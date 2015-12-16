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
    char *ID;
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

    fp = fopen("assistants.txt","r");
    if(!fp)
    {
        printf("File open error\n assistants.txt");
        exit(1);
    }
    printf("File opened");


    int c;
    ASSITANT a;
    //Get ID
    int Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
        //o uzunlukta string yer aç
        a.ID = realloc(a.ID,Length*sizeof(char));
        //son satýrý kaydet
        a.ID[Length-1] = c;

    }
    
    printf("%s",a.ID);

	




}







int main()
{
    ReadFromFileToAssistants();

    system("PAUSE");
    return 0;
}



