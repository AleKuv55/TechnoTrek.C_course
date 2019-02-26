#include <stdio.h>
#include <assert.h>
#include "CPU.h"

//#include "Enum.h
#define PUSH 1
#define POP 2
#define ADD 3
int main()
{
    int a[10];
    int i = 0;
    FILE* pFILE =NULL;
    pFILE = fopen("Result.txt", "r");
    assert( pFILE );
    struct CPU* proc = CPU_Create();
    CPU_DO(proc, pFILE);

    printCPU(proc);
    return 0;
}



