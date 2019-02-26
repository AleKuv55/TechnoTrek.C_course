//
// Created by kuzne on 11/06/2017.
//
//OK

#include <malloc.h>
#include "CPU.h"

#define ISNULL(ptr)\
    if (ptr == NULL)\
        {\
            exit(OUT_OF_MEMORY) ;\
        }

struct CPU* CPU_Create()
{
    struct CPU* out = NULL;
    out = calloc(1, sizeof(struct CPU));
    ISNULL(out);

    out -> commands = calloc(COMSIZE, sizeof(double));
    ISNULL(out -> commands);

    (out -> StackIn) = createStack();
    (out -> StackBack) = createStack();

    out -> registrs = calloc(RAMSIZE, sizeof(double));
    ISNULL(out -> registrs);
    (*out).registrpointer = 0;

//    printf("LOL");
//    PROC_OK(out);
    return out;
}
struct CPU* CPU_Delete(struct CPU* proc)
{
    //CPU_OK(proc);
    free( proc -> commands );
    proc -> commands = NULL;
    deleteStack(proc -> StackIn);
    deleteStack(proc -> StackBack);
    free( proc -> registrs );
    proc -> registrs = NULL;
    proc -> registrpointer = 0;
    free(proc);
    return 0;
}

int ProcOK(struct CPU* proc)// Сделать качественно
{//проверка прог коммандс и регистр на ноль
    return StackOK(proc -> StackIn) &&
           StackOK(proc -> StackBack)&&
           proc -> commands &&
           proc ->registrs;
}

#define DEF_CMD(Com_Numb, Com, n)\
    if (commands[i] == Com_Numb)\
    {\
    CPU_##Com(proc, commands[i+1]);\
    i = i + n;\
    }\
    else

int CPU_DO( struct CPU* proc, FILE* pFILE)
{
//#define N 4
//    double commands[N] = {7, 20, 6, 1};
    double commands[1000];
    int i = 0;
    int N = 0;
    double chislo;
    for(i = 0; fscanf(pFILE, "%lg", &chislo) != EOF;i++)
    {
        commands[i] = chislo;
        N++;
    }



    for (i = 0; i < N;)
    {
        #include "Commands.h"
        ;
    }
}

#undef DEF_CMD

int CPU_OUT(struct CPU* proc, double num)
{
    double tmp = 0;
    printf("%lg\n", tmp = pop(proc->StackIn));
    push(proc->StackIn, tmp);
    return 0;
}
int CPU_PUSH_R_N(struct CPU* proc, int num)//pushax to stack, num - number of element registr[num]
{
    push(proc -> StackIn, proc -> registrs[num]);
    //proc -> registrs[num] = 0;
    return 0;// do
}
int CPU_POP_R_N(struct CPU* proc, int num)//popax from stack
{
    proc -> registrs[num] = pop(proc -> StackIn);
}
int CPU_PUSH(struct CPU* proc, double num)
{
    push((proc -> StackIn), num);
}
int CPU_POP(struct CPU* proc, double num)
{
    pop((proc -> StackIn));
}
int CPU_ADD(struct CPU* proc, double num)
{
    push(proc -> StackIn, pop(proc -> StackIn) + pop(proc -> StackIn));
}
int CPU_MULTIPLY(struct CPU* proc, double num)
{
    push(proc -> StackIn, pop(proc -> StackIn) * pop(proc -> StackIn));
}
int CPU_SUB(struct CPU* proc, double num)
{
    double a1 = 0;
    double a2 = 0;
    a2 = pop(proc -> StackIn);
    a1 = pop(proc -> StackIn);
    push(proc -> StackIn, a1 - a2);
}
int CPU_DIV(struct CPU* proc, double num)
{
    double a1 = 0;
    double a2 = 0;
    a2 = pop(proc -> StackIn);
    a1 = pop(proc -> StackIn);
    push(proc -> StackIn, a1 / a2);
}

int CPU_IN(struct CPU* proc, double num)
{
    double shislo = 0;
    scanf("%lf", &shislo);
    push(proc -> StackIn, shislo);
    return 0;
}
int printCPU(const struct CPU* proc)
{
    int i = 0;
    printf("========================================\n");
    printf("The Stack In\n");
    printStack(proc -> StackIn, printStackValue);
    printf("The Stack Out\n");
    printStack(proc -> StackBack, printStackValue);
    printf("Arrays of registrs\n");
    for (i = 0; i < RAMSIZE; i++)
    {
        printf("registr[%d] = %0.2lf, ", i, proc -> registrs[i]);
    }
    printf("========================================\n");

    return 0;
}



