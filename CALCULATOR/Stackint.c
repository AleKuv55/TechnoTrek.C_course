//
// Created by kuzne on 12/13/2017.
//

#include "Stackint.h"
#include <malloc.h>
#include <math.h>
#include <assert.h>
#include <mem.h>

Mystackint* createStackint()
{
    Mystackint* out = NULL;
    out = malloc(sizeof(Mystackint));
    if (out == NULL)
    {
        exit(OUT_OF_MEMORY);
    }

    out->size = INIT_SIZE;
    out->data = calloc(INIT_SIZE, sizeof(F));
    if (out->data == NULL)
    {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out -> kanary1 = POISON;
    out -> kanary2 = POISON;
    out -> top = 0;
//    printf("LOL");
    STACK_OKint(out);
    return out;
}

int StackOKint(const Mystackint* stack)
{
    return (stack->kanary1 == POISON) &&
           (stack->kanary2 == POISON) &&
           (stack->top >= 0) &&
           (stack->size > 0) &&
           (stack->top <= stack->size);
}

int deleteStackint(Mystackint * stack)
{
    STACK_OKint(stack);
    free((stack)->data);
    stack->data = NULL;
    free(stack);
    stack = NULL;
    return 0;
}

int resizeint(Mystackint *stack)
{
    STACK_OKint(stack);
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, sizeof(F)*stack->size);
    if (stack->data == NULL)
    {
        printf("lookresizeint");
        exit(STACK_UNDERFLOW);
    }
    STACK_OKint(stack);
    return 0;
}

int pushint(Mystackint *stack, F value)
{
    STACK_OKint(stack);
    if (stack->top >= stack->size)
    {
        resizeint(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;

    STACK_OKint(stack);
    return 0;
}

F popint(Mystackint *stack)
{
    STACK_OKint(stack);
    if (stack->top == 0)
    {
        printf("lookpopint STACK_UNDERFLOW");
        exit(STACK_UNDERFLOW);
    }
    F tmp = stack -> data[--stack -> top];
    STACK_OKint(stack);
    return tmp;
}

F peekint(const Mystackint* stack)
{
    STACK_OKint(stack);
    if (stack->top < 0)//deleto ==0
    {
        printf("lookpeekint");
        exit(STACK_UNDERFLOW);
    }
    STACK_OKint(stack);
    return stack->data[stack->top-1];
}

void printStackintValueint(const F value)
{
    printf("%0.2f", value);
}

int printStackint(const Mystackint *stack, void (*printStackintValueint)(const F))
{
    printf("========================================\n");
    int i;
    int len = stack->top - 1;
    printf("stack %s [%p] {\n\ttop = %d \n\tdata[%d] = %p  \n { \n",
           (StackOKint(stack) ? "ok" : "ERROR"), stack, stack->top,
           stack->size, stack->data);

    for (i = 0; i < stack->size ; i++)
    {
        if (i <= len)
        {
            printf("\t*data[%d] = ", i);
            printStackintValueint(stack->data[i]);
            printf("\n");
        }
        else
        {
            printf("\t data[%d] = ", i);
            printStackintValueint(stack->data[i]);
            printf("\n");
        }

    }
    printf("\n } }\n");
    printf("========================================\n");

    return 0;
}
