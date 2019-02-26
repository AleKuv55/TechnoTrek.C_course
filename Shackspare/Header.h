//
// Created by kuzne on 10/09/2017.
//

#ifndef OPENCLOSEFILES_HEADER_H
#define OPENCLOSEFILES_HEADER_H

#endif //OPENCLOSEFILES_HEADER_H

char* makebuf(FILE* x, int* lSize);

int change(const void* string1 ,const void* string2);

int changeverse(const void* string1,const void* string2);

long leightofbuf(FILE* pFile, long* lei);

char** bufpoint(char* buffer, int* lSize, int* dlinabufpoint);

int fillbufpoint(char* buffer, char** text, int* lSize);

int printbuf(char** text, int dlinabufpoint);

