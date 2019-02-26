#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Header.h"

int main() {
    FILE* pFile = NULL;


    pFile = fopen( "file.txt", "r");
    if (pFile == NULL)
    {
        fputs("Ошибка файла", stderr);
        exit(1);
    }

    int lSize = 0;
    char* buffer = makebuf(pFile, &lSize); // создали массив
    fclose(pFile);

    int leit = 0;// размер массива указателей
    char ** text = bufpoint(buffer, &lSize, &leit);


    int e4 = fillbufpoint(buffer, text, &lSize);//заполняем массив указаетелей

  //  qsort(text , leit, sizeof(char*), change);

    qsort(text, leit, sizeof(char*), changeverse);

    printf("\n");
    int e5 = printbuf(text, leit);
   // printf("%d", changeverse(text, text+1));
    //
    return 0;

}



/* int a = 0;
  char* versebuf = (char*)calloc(sizeof(char), lSize);
  for(a = 0; a < lSize; a++)
  {
      versebuf[a] = buffer[lSize - a];
  }
    ispunct(char)
  int verseleit = 0;
  char **versetext = bufpoint(versebuf, &lSize, &verseleit);

  fillbufpoint(versebuf, versetext, &lSize);

  qsort(versetext, verseleit, sizeof(char*), change);
*/