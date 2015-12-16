#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    int i=4;
    char *gunler[] = {"PAZARTESI","SALI","CARSAMBA","PERSEMBE","CUMA"};
    char gunIsmi[10];
    long int lid;
    
    FILE * sinavTakvimi;
    
    sinavTakvimi = fopen("examschedule.csv","r");
    
    //lid = fseek (sinavTakvimi, 0L, SEEK_END); 
    //lid = ftell(sinavTakvimi);
    
    if(!sinavTakvimi) 
            printf("'examschedule.csv' isimli dosya acilamadi !\n");
    
    else{
         while(i<5){
               while(!feof(sinavTakvimi)){
                     //while(sinavt)
                     
                     printf("%c\n",fgetc(sinavTakvimi)); 
                     
                     //if(strcmp(gunler[i],gunIsmi) == 0){
                        //printf("%s",gunIsmi);                           
                                        //         }
                                               }
                    }
                    
                    i++;
                    
         }
    
    fclose(sinavTakvimi);
    
    getch();
    }
