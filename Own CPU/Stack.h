//
// Created by kuzne on 11/06/2017.
//

#ifndef PROC_STACK_H
#define PROC_STACK_H

#include <stdio.h>

#define INIT_SIZE 4
#define MULTIPLIER 2
//#define  POISON tan(M_PI/2)
#define  POISON (-1000)

#define STACK_OVERFLOW  (-100)
#define STACK_UNDERFLOW (-101)
#define OUT_OF_MEMORY   (-102)

#define STACK_OK(stack)\
{\
if ((StackOK(stack)) == 0)\
{\
    printStack(stack, printStackValue);\
    exit(42);\
}\
}

typedef double T;

typedef struct Stack_tag {
    size_t kanary1;
    T *data;
    size_t size;
    size_t top;
    size_t kanary2;
} MyStack;

int StackOK(const MyStack* stack);

MyStack* createStack();

int deleteStack(MyStack * stack);

int resize(MyStack *stack);

int push(MyStack *stack, T value);

T pop(MyStack *stack);

T peek(const MyStack* stack);



void printStackValue(const T value);

int printStack(const MyStack *stack, void (*printStackValue)(const T));
#endif //PROC_STACK_H
