#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <stdbool.h>

long leightofbuf(FILE* pFile, long* lei);
char* makebuf(FILE* pFile, int* lSize);
int kol_vo_strok(char* buffer, int lSize);
int comparator(char* buffer, int* kolvo_strok, int* commands);

int main() {
    printf("%d", '\n');
    FILE* pFile = NULL;
    FILE* poutFile = NULL;

    int kolvo_strok = 0;
    pFile = fopen( "Ass.txt", "r");
    if (pFile == NULL)
    {
        fputs("Errorfile", stderr);
        exit(1);
    }
    poutFile = fopen( "Result.txt", "w");


    int lSize = 0;
    char* buffer = makebuf(pFile, &lSize); // создали массив
    fclose(pFile);

    kolvo_strok = kol_vo_strok(buffer, lSize);
    printf("\n kol-vo strok = %d \n", kolvo_strok);

    int* commands = calloc(lSize, sizeof(double));
    int j = 0;
    comparator(buffer, &kolvo_strok, commands);
    int k = 0;
    for(j = 0; j < 30; j++)
    {
        if (commands[j] != 0) k++;
        printf("commands[%d] = %d\n ", j, commands[j]);
    }//dump
    for(j = 0; j < kolvo_strok*2; j++)
    {
        if (commands[j] != 0) fprintf(poutFile, "%d ", commands[j]);
    }
    return 0;//zapis massiv v fail - funct
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

int kol_vo_strok(char* buffer, int lSize)
{
    int j = 0;
    int kolvo_strok = 0;
    for ( j = 0; j < lSize; j++)
    {
        if (buffer[j] == '\n')
            kolvo_strok++;
    }
    kolvo_strok++;
    return kolvo_strok;
}

int command(char* name, int* n)
{
#define DEF_CMD(Com_numb, Com, kol)\
        if (strcmp(name, #Com) == 0)\
        {\
            *n = kol;\
            return Com_numb;\
        }\
        else

#include "../proc/Commands.h"

#undef DEF_CMD
    if(false);
}

int comparator(char* buffer, int* kolvo_strok, int* commands)
{

    int j = 0;// счетчик массива commands
    int n = 0;// кол-во символов считанных ссканфом
    char a[10];
    int kolvosymb = 0;
    int jumper = 0;//прыгатель по символам
    int jj = 0;//счетчик цикла
    int returnscanf = 0;
    for (jj = 0; jj < (*kolvo_strok); jj++)
    {
        int nom = 0;//второй аргумент

        printf("~~~~~~\nmassiv \n%s\n~~~~~\n", buffer + jumper);
        sscanf(buffer + jumper, "%s %n", a, &kolvosymb);
        jumper = jumper + kolvosymb;
        commands[j] = command(a, &nom);

        printf ("stroka - %s\n", a);
        //printf("returnscanf = %d, kolvosymb = %d \nif{\n", returnscanf, kolvosymb);
        if (nom == 2)
        {
            sscanf(buffer + jumper, "%d %n", &commands[j + 1], &kolvosymb);

            jumper = jumper + kolvosymb;
            printf("commands[%d] = %d commands[%d] = %d\n", j, commands[j], j+1, commands[j+1]);
            j++;

            printf("j = %d \nif}\n", j);
        }
        j++;
    }
    return 0;
}
