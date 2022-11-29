#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "header.h"
#include<unistd.h>

#define BUFFER_SIZE 1000
void inputString()
{
FILE * fPtr;
FILE * fTemp;
FILE * fnew;
char newpath[100];
char path[100];
printf("Enter path of source file: ");
scanf("%s", path);
    
  fPtr  = fopen(path, "r"); 
  if(NULL!=fPtr)
  {
  fseek(fPtr,0,SEEK_END);
  int size=ftell(fPtr);
  if(0==size)
  {
  printf("file is empty");
  exit(0);
  }
  }
  fclose(fPtr);
  

char oldWord[100], newWord[100];
char buffer[BUFFER_SIZE];
int wordexist=0;
    printf("Enter word to replace: ");
    scanf("%s", oldWord);
     fPtr  = fopen(path, "r"); 
    while(fgets(buffer,BUFFER_SIZE,fPtr))
    {
    char *ptr=strstr(buffer,oldWord);
    if(ptr!=NULL)
    {
     wordexist=1;
   break;

     }
    
     }
     fclose(fPtr);
     if(wordexist==1)
     {
     
   printf("Replace  with: ");
    scanf("%s", newWord);
    }
    else
    {
    printf("word doesn't exist");
   exit(0);
    
    }
    printf("Enter path of destination file: ");
    scanf("%s", newpath);
    /*  Open all required files */
   


    /*
     * Read line from source file and write to destination 
     * file after replacing given word.
     */
     fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w+");
    fnew=fopen(newpath,"w+");
     
    

     if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given word.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
            // Replace all occurrence of word from current line
        replaceAll(buffer, oldWord, newWord);

        // After replacing write it to temp file.
        fputs(buffer, fTemp);
   
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
   //remove(path);

    /* Rename temp file as original file */
    //rename("replace.tmp", path);
    rename("replace.tmp",newpath);

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.\n", oldWord, newWord);
fclose(fnew);
}


   
    
