//00
// Created by kuzne on 11/06/2017.
//

#ifndef PROC_CPU_H
#define PROC_CPU_H

#define RAMSIZE 100
#define COMSIZE 100
#include "Stack.h"

struct CPU
{
    double* commands;
    //int command_pointer;
    MyStack* StackIn;
    MyStack* StackBack;
    double* registrs;
    int registrpointer;
}proc;

enum CMD
{
#define DEF_CMD(num, com, n) \
    com = num,

#include "Commands.h"

    end_cmd

#undef DEF_CMD

};

#endif //PROC_CPU_H

struct CPU* CPU_Create();

int CPU_OUT(struct CPU* proc, double num);

int CPU_IN(struct CPU* proc, double num);

int CPU_DO( struct CPU* proc, FILE* pFILE);

int CPU_PUSH(struct CPU* proc, double num);

int CPU_POP(struct CPU* proc, double num);

int CPU_ADD(struct CPU* proc, double num);

int CPU_MULTIPLY(struct CPU* proc, double num);

int CPU_SUB(struct CPU* proc, double num);

int CPU_DIV(struct CPU* proc, double num);

int CPU_PUSH_R_N(struct CPU* proc, int num);

int CPU_POP_R_N(struct CPU* proc, int num);

void printCPUValue(const T value);

int printCPU(const struct CPU* proc);