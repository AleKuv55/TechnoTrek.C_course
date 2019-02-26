//
// Created by kuzne on 12/13/2017.
//

#ifndef CALCULATOR_STACKINT_H
#define CALCULATOR_STACKINT_H
#include <stdio.h>

#define INIT_SIZE 4
#define MULTIPLIER 2
//#define  POISON tan(M_PI/2)
#define  POISON (-1000)

#define STACK_OVERFLOW  (-100)
#define STACK_UNDERFLOW (-101)
#define OUT_OF_MEMORY   (-102)

#define STACK_OKint(stack)\
{\
if ((StackOKint(stack)) == 0)\
{\
    printStackint(stack, printStackintValueint);\
    assert(0);\
}\
}

typedef float F;

typedef struct Stack_tagint {
    size_t kanary1;
    F *data;
    size_t size;
    size_t top;
    size_t kanary2;
} Mystackint;

int StackOKint(const Mystackint* stack);

Mystackint* createStackint();

int deleteStackint(Mystackint * stack);

int resizeint(Mystackint *stack);

int pushint(Mystackint *stack, F value);

F popint(Mystackint *stack);

F peekint(const Mystackint* stack);



void printStackintValueint(const F value);

int printStackint(const Mystackint *stack, void (*printStackintValueint)(const F));
#endif //CALCULATOR_STACKINT_H
