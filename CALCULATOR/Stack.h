//
// Created by kuzne on 12/12/2017.
//

#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H
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
    assert(0);\
}\
}

typedef char T;

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
#endif //CALCULATOR_STACK_H
