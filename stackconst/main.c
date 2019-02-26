//
// Created by kuzne on 10/19/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define STACK_MAX_SIZE 20
typedef int T;

#define STACK_OVERFLOW  (-100)
#define STACK_UNDERFLOW (-101)

typedef struct Stack_tag
{
    T data[STACK_MAX_SIZE];
    size_t size;
} MyStack;

void push(MyStack *stack, const T value)
{
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}//выход за пределы массива

T pop(MyStack *stack) {
    if (stack->size == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->size--;
    return stack->data[stack->size];
}

void printStackValue(const T value) {
    printf("%d", value);
}

void printStack(const MyStack *stack, void (*printStackValue)(const T)) {
    int i;
    int len = stack->size - 1;
    printf("stack %d > ", stack->size);
    for (i = 0; i < len; i++) {
        printStackValue(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0) {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}

int main() {
    MyStack stack;
    stack.size = 0;
    int i = 0   ;

    for (i = 0; i < 100; i++) {
        push(&stack, i);
    }
    _getch();
}

