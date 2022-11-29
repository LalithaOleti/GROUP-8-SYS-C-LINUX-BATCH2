#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "header.h"
#define BUFFER_SIZE 1000
void replaceAll(char *str, const char *search, const char *replace)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(search);

    // Fix: If oldWord and newWord are same it goes to infinite loop
    if (!strcmp(search, replace)) {
        return;
    }


    /*
     * Repeat till all occurrences are replaced. 
     */
     
    while ((pos = strstr(str, search)) != NULL)
    {
        // Backup current line
        strcpy(temp, str);

        // Index of current found word
        index = pos - str;

        // Terminate str after word found index
        str[index] = '\0';

        // Concatenate str with new word 
        strcat(str, replace);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(str, temp + index + owlen);
    }
    }
