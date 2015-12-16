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
}ASSISTANT;

void ReadFromFileToAssistants();
int ReadAssistantLine(ASSISTANT*,FILE*);
void PrintAssistant(ASSISTANT*);

ASSISTANT *Assistants;
int AssistantCount;

void ReadFromFileToAssistants()
{
    FILE *fp;

    fp = fopen("assistants.txt","r");
    if(fp == NULL)
    {
        printf("File open error\n-assistants.txt");
        system("PAUSE");
        exit(10);//'0xA'
    }
    //printf("File opened");

	//define a place for assistants
	Assistants = malloc(0);
	AssistantCount = 0;

	AssistantCount++;
	Assistants = realloc(Assistants,AssistantCount*sizeof(ASSISTANT));
	int c;
	ReadFromFileToAssistants(Assistants,fp);
	PrintAssistant(Assistants);

 	ASSISTANT a;
	a.ID = "sdasd";
	PrintAssistant(&a);

}


void PrintAssistant(ASSISTANT *a)
{
	///simply print an assistant;
	printf("ID: %s \n",a->ID);
	printf("Name: %s \n",a->Name);
	printf("Surname: %s \n",a->Surname);
	printf("Filename: %s",a->Filename);
}

int ReadAssistantLine(ASSISTANT *a,FILE *fp)
{

	int c;
    int Length;

	//Get ID
	a->ID = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
        //o uzunlukta string yer aç
        a->ID = realloc(a->ID,Length*sizeof(char));
        //son satýrý kaydet
        a->ID[Length-1] = c;

    }
    //print id as we read
	//printf("%s",a->ID);


	//Get Name
    a->Name = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
		//o uzunlukta string yer aç
        a->Name = realloc(a->Name,Length*sizeof(char));
        //son karakteri kaydet
        a->Name[Length-1] = c;
    }
    //print id as we read
	//printf("%s",a->Name);

	//Get Surname
    a->Surname = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //uzunluðunu al
        Length++;
		//o uzunlukta string yer aç
        a->Surname = realloc(a->Surname,Length*sizeof(char));
        //son karakteri kaydet
        a->Surname[Length-1] = c;
    }
    //print id as we read
	//printf("%s",a->Surname);

	//Get Surname
    a->Filename = malloc(0*sizeof(char));
	Length = 0;
	//get a char from file
	c = getc(fp);
    while(c != 10 && c != EOF)
    {
        //uzunluðunu al
        Length++;
		//o uzunlukta string yer aç
        a->Filename = realloc(a->Filename,Length*sizeof(char));
        //son karakteri kaydet
        a->Filename[Length-1] = c;
		//get a char from file
		c = getc(fp);
    }
    //print id as we read
	//printf("%s",a->Filename);

	//append .csv to filename.
	Length+=4;
	a->Filename = realloc(a->Filename,Length*sizeof(char));
	a->Filename[Length-4]='.';
	a->Filename[Length-3]='c';
	a->Filename[Length-2]='s';
	a->Filename[Length-1]='v';
	//print as we append
	//printf("%s",a->Filename);

	//test return
	//c = 10;
	//printf("%c",c);

	return c;
}





int main()
{
    ReadFromFileToAssistants();

    system("PAUSE");
    return 0;
}



