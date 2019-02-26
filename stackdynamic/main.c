#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>
#include <mem.h>

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

typedef float T;

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

int main()
{
#define size1 10
    MyStack *stack = createStack();
    char a[size1];
    int x = 0;
    int i = 0;
    int j = 0;
    int result = 0;

    fgets(a, size1, stdin);
    printf("----%s----", a);
    a[11] = ' ';
    for(i = 0; i < size1; i++)
    {
        printf("\nweee i = %d weee\n", i);
        x = 0;
        result = 0;
        j = i;
        if ((a[i] >= '0') && (a[i] <= '9'))
        {

            while (a[j] != ' ')
            {
                x = (int) a[j] - '0';
                result = result*10 + x;
  //            printf("<%d>?%d?$j = %d $\n", x, result, j);
                j++;
            }
            printf("\nresult = %d\n", result);
            i = j;
            printf("\ni = j = %d\n", i);
            push(stack, result);
  //          printf("$ j = %d$", j);
        }
        switch(a[i])
            case '+': push(stack, pop(stack) + pop(stack));

    }
    printStack(stack, printStackValue);


    return 0;
}

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
    printf("LOL");
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
        exit(STACK_UNDERFLOW);
    }
    T tmp = stack->data[--stack->top];
    STACK_OK(stack);
    return tmp;
}

T peek(const MyStack* stack)
{
    STACK_OK(stack);
    if (stack->top <= 0)
    {
        exit(STACK_UNDERFLOW);
    }
    STACK_OK(stack);
    return stack->data[stack->top-1];
}

void printStackValue(const T value)
{
    printf("%0.2f ", value);
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
