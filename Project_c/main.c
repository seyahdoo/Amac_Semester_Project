#include <stdio.h>
#include <stdlib.h>

#define ASSISTANTINFOTEXTFILE "assistants.txt"

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

void ReadAssistantsFromFile();
int ReadAssistantLine(ASSISTANT*,FILE*);
void PrintAssistant(ASSISTANT*);

void ReadAssistantWorks();
int GotoNextLine(FILE*);

ASSISTANT *Assistants;
int AssistantCount;


int main()
{
    printf("enter to read asistants");
    ReadAssistantsFromFile();
    printf("exit from read asistants\n");

    ReadAssistantWorks();



    printf("\n");
    system("PAUSE");
    return 0;
}

int GotoNextLine(FILE *fp)
{
    //eol = 10

    int c;
    do
    {
        c = getc(fp);
    }while (!(c==10 || c==EOF));

    return c;
    //fseek()
    //ftell
}

void ReadAssistantWorks()
{
    int c,i;

    FILE *fp;

    //for_each?

    //for every Assistant
    for(i=0;i<AssistantCount;i++)
    {
        printf("\nGetting %s's work schedule", Assistants[i].Name);

        printf("%s",Assistants[i].Filename);
        //open file for that assistant
        fp = fopen(Assistants[i].Filename,"r");
        if(fp == NULL)
        {
            printf("File open error\n- Assistant %s's schedule file named %s",Assistants[i].Name,Assistants[i].Filename);
            getch();
            //system("PAUSE"); system pause is a very very bad idea.
            exit(10);//'0xA'
        }
        //printf("File opened");

        c = GotoNextLine(fp);
        c = GotoNextLine(fp);


        char Start_hour = 0;
        char End_Hour = 0;
        char Start_Minute = 0;
        char End_Minute = 0;

        //Start hour first digit
        c = getc(fp);
        Start_hour += (10*(c-'0'));

        //Start hour second digit
        c = getc(fp);
        Start_hour += (c-'0');

        //printf("%d",Start_hour);

        c = getc(fp); // [Dot]

        //Start Minute First digit
        c = getc(fp);
        Start_Minute += (10*(c-'0'));

        //Start Minute second digit
        c = getc(fp);
        Start_Minute += c-'0';

        //printf("%d",Start_Minute);

        c = getc(fp); // [Space]
        c = getc(fp); // [-]
        c = getc(fp); // [Space]

        //End Hour First digit
        c = getc(fp);
        End_Hour += (10*(c-'0'));

        //End Hour second digit
        c = getc(fp);
        End_Hour += c-'0';

        //printf("%d",End_Hour);

        c = getc(fp); //[Dot]

        //End Minute First digit
        c = getc(fp);
        End_Minute += (10*(c-'0'));

        //End Minute second digit
        c = getc(fp);
        End_Minute += c-'0';

        //printf("%d",End_Minute);

        c = getc(fp); //[;]






        fclose(fp);
    }


    printf("\n finished reading asssistant works from file");
    exit(1);

}

void PrintAssistant(ASSISTANT *a)
{
	///simply print an assistant;
	printf("\n");
	printf("ID: %s \n",a->ID);
	printf("Name: %s \n",a->Name);
	printf("Surname: %s \n",a->Surname);
	printf("Filename: %s \n",a->Filename);
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
        //Calculate Length
        Length++;
        //Allocate for string
        char *temp = realloc(a->ID,(Length+1)*sizeof(char));
        if (temp == NULL)
        {
            printf("Memory error.");
        }
        a->ID = temp;


        //Get the last Character
        a->ID[Length-1] = c;
    }

    //End the string
    a->ID[Length] = NULL;

    //print as we read
	printf("%s\n",a->ID);

	//Get Name
    a->Name = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //Calculate Length
        Length++;
		//Allocate for string
        char *temp = realloc(a->Name,(Length+1)*sizeof(char));
        if (temp == NULL)
        {
            printf("Memory error.");
        }
        a->Name = temp;

        //Get the last Character
        a->Name[Length-1] = c;
    }

    //End the string
    a->Name[Length] = NULL;

    //print as we read
	printf("%s\n",a->Name);

	//Get Surname
    a->Surname = malloc(0*sizeof(char));
	Length = 0;
    while((c = getc(fp))!= ' ')
    {
        //Calculate Length
        Length++;
		//Allocate for string
        char *temp = realloc(a->Surname,(Length+1)*sizeof(char));
        if (temp == NULL)
        {
            printf("Memory error.");
        }
        a->Surname = temp;

        //Get the last Character
        a->Surname[Length-1] = c;
    }

    //End the string
    a->Surname[Length] = NULL;

    //print as we read
	printf("%s",a->Surname);

	//Get Surname
    a->Filename = malloc(0*sizeof(char));
	Length = 0;
	//get a char from file
	c = getc(fp);
    while(c != 10 && c != EOF)
    {
        //Calculate Length
        Length++;
		//Allocate for string
        char *temp = realloc(a->Filename,(Length+1)*sizeof(char));
        if (temp == NULL)
        {
            printf("Memory error.");
        }
        a->Filename = temp;

        //Get the last Character
        a->Filename[Length-1] = c;
		//get a char from file
		c = getc(fp);
    }

    //print as we read
	//printf("%s",a->Filename);

	//append .csv to filename.
	Length+=4;

	//allocate for it
	char *temp = realloc(a->Filename,(Length+1)*sizeof(char));
    if (temp == NULL)
    {
        printf("Memory error.");
    }
    a->Filename = temp;

    //finally, write
	a->Filename[Length-4]='.';
	a->Filename[Length-3]='c';
	a->Filename[Length-2]='s';
	a->Filename[Length-1]='v';

	//End the string
    a->Filename[Length] = NULL;

	//print as we append
	//printf("%s",a->Filename);

	//test return
	//c = 10;
	//printf("%c",c);

    //test todo: delete this
    //PrintAssistant(a);

    //Satır sonunu dön.
	return c;
}

void ReadAssistantsFromFile()
{
    FILE *fp;

    //Open the file to read
    fp = fopen(ASSISTANTINFOTEXTFILE,"r");
    if(fp == NULL)
    {
        printf("File open error\n- Assistant storage file");
        system("PAUSE");
        exit(10);//'0xA'
    }
    printf("File opened");

	//define a place for assistants
	Assistants = malloc(0);
	AssistantCount = 0;

    int c;

    //read assistants from file line to line
	do
    {
        //Keep Count of Assistants
        AssistantCount++;
        //printf("AssistantCount++");

        //Allocate for assistants
        Assistants = realloc(Assistants,AssistantCount*sizeof(ASSISTANT));
        //printf("Assistants = realloc(Assistants,AssistantCount*sizeof(ASSISTANT));");

        //Read one assistant
        c = ReadAssistantLine(&Assistants[AssistantCount-1],fp);
        //printf("c = ReadAssistantLine(&Assistants[AssistantCount-1],fp);");

        //printf("\n%d",c);
        //PrintAssistant(&Assistants[AssistantCount-1]);
    }while (c != EOF);//if is the end of file

}


