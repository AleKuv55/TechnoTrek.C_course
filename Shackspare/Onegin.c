//
// Created by kuzne on 10/09/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Header.h"

int change(const void* string1,const void* string2)
{

    return strcmp(*(char**)string1, *(char**)string2);
}

int changeverse(const void* string1, const void* string2)
{
    char* s1 = *(char**) string1;
    char* s2 = *(char**) string2;

    int x1 = strlen(s1);
    int x2 = strlen(s2);
   // int k;
   // k++;

  //  printf("k = %d x1 = %d  x2 = %d ",k,  x1 , x2);

    while((x1 > 0) && (x2 > 0))
    {
        while (ispunct(*(s1 + x1)) || isspace(*(s1 + x1) ))
            x1--;

        while (ispunct(*(s2 + x2)) || isspace(*(s2 + x2)) )
            x2--;

        if ( (*(s1 + x1)) == (*(s2 + x2)) ) {
            x1--;
            x2--;
        }
        else return *(s1 + x1) - *(s2 + x2);
    }
    return 0;
}


char* makebuf(FILE* pFile, int* lSize)
{



    long lei = 0; // long lei = leightofbuf(pFile);
    leightofbuf(pFile, &lei);

    char* buf = (char*)calloc(sizeof(char), lei); // выделение памяти для массива
    if (buf == 0)
    {
        printf("Error calloc in buf");
        exit(1);
    }

    fread(buf, sizeof(char), lei, pFile); // запись файла в массив

    *lSize = lei;
    return buf;
}

long leightofbuf(FILE* pFile, long* lei)
{
    fseek(pFile, 0, SEEK_END);
    //long Size = 0;
    *lei = ftell(pFile);
    rewind(pFile);
    //return lei;
}
char* makebuf(FILE* pFile, int* lSize)
{



    long lei = 0; // long lei = leightofbuf(pFile);
    leightofbuf(pFile, &lei);

    char* buf = (char*)calloc(sizeof(char), lei); // выделение памяти для массива
    if (buf == 0)
    {
        printf("Error calloc in buf");
        exit(1);
    }

    fread(buf, sizeof(char), lei, pFile); // запись файла в массив

    *lSize = lei;
    return buf;
}

long leightofbuf(FILE* pFile, long* lei)
{
    fseek(pFile, 0, SEEK_END);
    //long Size = 0;
    *lei = ftell(pFile);
    rewind(pFile);
    //return lei;
}

char** bufpoint(char* buffer, int* lSize, int* dlinabufpoint)
{
    int i = 0; // счетчик для прохождения по buffer
    int leit = 0; // dlina massiva ukazateley text[]

    for(i = 0; i < *lSize; i++){
        if (buffer[i] == '\n')
            leit++;
    }
    leit++;

    char** text = (char**)calloc(sizeof(char*), leit);
    if (text == NULL)
    {
        printf("Ошибка памяти на массив указателей");
        exit(2);
    }


    *dlinabufpoint = leit;

    return text;
}

int fillbufpoint(char* buffer, char** text, int* lSize)
{
    int i = 0; // счетчик для прохождения по buffer
    int j = 1; // счетчик эл-ов text[]

    text[0] = buffer;
    //i[3] = *(i+3)
    for( i = 0; i < *lSize; i++)
    {
        printf("%c", buffer[i]);
        if (buffer[i] == '\n')
        {
            text[j] = buffer + i + 1;//&buf[i+1]
            buffer[i] = '\0';
            j++;
            // printf("\n %p", text[j]);
        }
    }
    //strtok()
    return 4;
}
// void is bad

int printbuf(char** text, int dlinabufpoint)
{
    int o = 0;
    for ( o = 0; o < dlinabufpoint; o++)
    {
        printf("\n%s", text[o]);
    }
    return 5;
}
