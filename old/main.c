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
    int Length;
    
	//Get ID
	a.ID = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
        //o uzunlukta string yer aç
        a.ID = realloc(a.ID,Length*sizeof(char));
        //son satýrý kaydet
        a.ID[Length-1] = c;

    }
    //print id as we read
	//printf("%s",a.ID);
	
	
	//Get Name
    a.Name = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
		//o uzunlukta string yer aç
        a.Name = realloc(a.Name,Length*sizeof(char));
        //son karakteri kaydet
        a.Name[Length-1] = c;   
    }
    //print id as we read
	//printf("%s",a.Name);
	
	//Get Surname
    a.Surname = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
		//o uzunlukta string yer aç
        a.Surname = realloc(a.Surname,Length*sizeof(char));
        //son karakteri kaydet
        a.Surname[Length-1] = c;   
    }
    //print id as we read
	//printf("%s",a.Surname);
	
	//Get Surname
    a.Filename = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
		//o uzunlukta string yer aç
        a.Filename = realloc(a.Filename,Length*sizeof(char));
        //son karakteri kaydet
        a.Filename[Length-1] = c;   
    }
    //print id as we read
	//printf("%s",a.Filename);
	
	
	
	
	
	
	
	




}







int main()
{
    ReadFromFileToAssistants();

    system("PAUSE");
    return 0;
}



