//
// Created by kuzne on 12/12/2017.
//

#include "Stack.h"
#include <malloc.h>
#include <math.h>
#include <assert.h>
#include <mem.h>

MyStack* createStack()
{
    MyStack* out = NULL;
    out = malloc(sizeof(MyStack));
    if (out == NULL)
    {
        exit(OUT_OF_MEMORY);
    }

    out->size = INIT_SIZE;
    out->data = calloc(INIT_SIZE, sizeof(T));
    if (out->data == NULL)
    {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out -> kanary1 = POISON;
    out -> kanary2 = POISON;
    out -> top = 0;
//    printf("LOL");
    STACK_OK(out);
    return out;
}

int StackOK(const MyStack* stack)
{
    return (stack->kanary1 == POISON) &&
           (stack->kanary2 == POISON) &&
           (stack->top >= 0) &&
           (stack->size > 0) &&
           (stack->top <= stack->size);
}

int deleteStack(MyStack * stack)
{
    STACK_OK(stack);
    free((stack)->data);
    stack->data = NULL;
    free(stack);
    stack = NULL;
    return 0;
}

int resize(MyStack *stack)
{
    STACK_OK(stack);
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, sizeof(T)*stack->size);
    if (stack->data == NULL)
    {
        printf("lookresize");
        exit(STACK_UNDERFLOW);
    }
    STACK_OK(stack);
    return 0;
}

int push(MyStack *stack, T value)
{
    STACK_OK(stack);
    if (stack->top >= stack->size)
    {
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;

    STACK_OK(stack);
    return 0;
}

T pop(MyStack *stack)
{
    STACK_OK(stack);
    if (stack->top == 0)
    {
        printf("lookpop STACK_UNDERFLOW");
        exit(STACK_UNDERFLOW);
    }
    T tmp = stack -> data[--stack -> top];
    STACK_OK(stack);
    return tmp;
}

T peek(const MyStack* stack)
{
    STACK_OK(stack);
    if (stack->top < 0)//deleto ==0
    {
        printf("lookpeek");
        exit(STACK_UNDERFLOW);
    }
    STACK_OK(stack);
    return stack->data[stack->top-1];
}

void printStackValue(const T value)
{
    printf("%c ", value);
}

int printStack(const MyStack *stack, void (*printStackValue)(const T))
{
    printf("========================================\n");
    int i;
    int len = stack->top - 1;
    printf("stack %s [%p] {\n\ttop = %d \n\tdata[%d] = %p  \n { \n",
           (StackOK(stack) ? "ok" : "ERROR"), stack, stack->top,
           stack->size, stack->data);

    for (i = 0; i < stack->size ; i++)
    {
        if (i <= len)
        {
            printf("\t*data[%d] = ", i);
            printStackValue(stack->data[i]);
            printf("\n");
        }
        else
        {
            printf("\t data[%d] = ", i);
            printStackValue(stack->data[i]);
            printf("\n");
        }

    }
    printf("\n } }\n");
    printf("========================================\n");

    return 0;
}

