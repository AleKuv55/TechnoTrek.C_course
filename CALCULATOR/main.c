#include <ctype.h>
#include <mem.h>
#include "Stack.h"
#include "Stackint.h"

#define size1 100
#define ADD 1
#define SUB 2
#define MULTI 3
#define DIV 4

#define ACTION_WHIS_FIRST_MINUS \
                                (onlywords)[j] = '0';\
                                j++;\
                                (onlywords)[j] = ' ';\
                                j++;



int Transbezprior(char* expression , char* onlywords, MyStack* stack);
int TransinPol(char* expression , char* onlywords, MyStack* stack);
int Switch(char a, char b);
void perevodandpush(char * a, Mystackint* stackint, int i);

int main()
{
    MyStack* stack = createStack();
    char expression[size1];
    char onlywords[size1] = {};

    int i = 0, j = 0;
    int result = 0;

    fgets(expression, size1, stdin);

    printf("%s", expression);
    Transbezprior(expression, onlywords, stack);
    printStack(stack, printStackValue);
    printf("onlywords - %s", onlywords);


    //Вычисляем обратную польскую запись
    Mystackint* stackint = createStackint();
    int x = 0;
    for(i = 0; i < strlen(onlywords); i++)
    {
        //printf("\n i = %d \n", i);
        x = 0;
        result = 0;
        j = i;
        if ((onlywords[i] >= '0') && (onlywords[i] <= '9'))
        {

            while (onlywords[j] != ' ')
            {
                x = (int) onlywords[j] - '0';
                result = result * 10 + x;
                j++;
            }
            printf("\nresult = %d\n", result);
            i = j;
            printf("\ni = j = %d\n", i);
            pushint(stackint, result);
            //          printf("$ j = %d$", j);
        }
        float a1 = 0, a2 = 0, a3 = 0, a4 = 0;
        switch(onlywords[i]) {
            case '+': {
                pushint(stackint, popint(stackint) + popint(stackint));
                //printStack(stack, printStackValue);
                break;
            }
            case '*': {
                pushint(stackint, popint(stackint) * popint(stackint));
                //printStack(stack, printStackValue);
                break;
            }
            case '-': {
                a1 = popint(stackint);
                a2 = popint(stackint);
                pushint(stackint, a2 - a1);
                //printStack(stack, printStackValue);
                break;
            }
            case '/': {
                a3 = popint(stackint);
                a4 = popint(stackint);
                pushint(stackint, a4 / a3);
                //printStack(stack, printStackValue);
                break;
            }
            default: {

                break;
            }

        }}
    printStackint( stackint, printStackintValueint);
    printf("OTVET = %g", stackint -> data [stackint -> top -1]);


    return 0;
}

int TransinPol(char* expression , char* onlywords, MyStack* stack)
{
    int i = 0, j = 0;
    if ((expression)[i] == '-')
    {
        ACTION_WHIS_FIRST_MINUS;
        i = i + 2;
    }
    for (i; i < strlen(expression); i++)
    {
        if (isdigit(expression[i]))
        {
            while (isdigit(expression[i]))
            {
                //Switch(expression[i], onlywords[j]);
                onlywords[j] = expression[i];
                j++;
                i++;
            }
            onlywords[j] = ' ';
            j++;
        }
        if (stack -> top != 0)
        {
            int k = i;//
            while ( ( (expression[i] == '+') || (expression[i] == '-') ) &&//krome()
                    ( peek(stack) == '+' || peek(stack) == '-' ||  peek(stack) == '/' || peek(stack) == '*' ) )
            {
                onlywords[j] = pop(stack);
                j++;
                onlywords[j] = ' ';
                j++;
                push(stack, expression[i]);
                i++;
            }
            while ( ( (expression[i] == '*') || (expression[i] == '/') ) &&
                    ( peek(stack) == '*' || peek(stack) == '/' ) )
            {
                onlywords[j] = pop(stack);
                j++;
                onlywords[j] = ' ';
                j++;
                push(stack, expression[i]);
                i++;
            }
            switch(expression[i])
            {
                case '+': {
                    push(stack, '+');
                    break;
                }
                case '*': {
                    push(stack, '*');
                    break;
                }
                case '-': {

                    push(stack, '-');
                    break;
                }
                case '/': {
                    push(stack, '/');
                    break;
                }
                default: {
                    break;
                }
            }
            i = k;
        }
        else
        {
            switch(expression[i])
            {
                case '+': {
                    push(stack, '+');
                    break;
                }
                case '*': {
                    push(stack, '*');
                    break;
                }
                case '-': {
                    push(stack, '-');
                    break;
                }
                case '/': {
                    push(stack, '/');
                    break;
                }
                default: {
                    break;
                }
            }
        }
        if (expression[i] == '(')
        {
            push(stack, '(');

            if ((expression)[i+1] == '-')
            {
                i++;
                ACTION_WHIS_FIRST_MINUS;
                i = i + 1;
            }
        }
        if (expression[i] == ')')
        {
            while (stack -> data[stack -> top - 1] != '(')
            {
                onlywords[j] = pop(stack);
                j++;
                onlywords[j] = ' ';
                j++;
            }
            pop(stack);
        }


    }
    while (stack -> top != 0)
    {
        onlywords[j] = pop(stack);
        j++;
        onlywords[j] = ' ';
        j++;
    }
}
int Switch(char a, char b) {

    switch (a) {
        case '1': {
            b = '1';
            //j++;
        }
        case '2': {
            b = '2';
            //j++;
        }
        case '3': {
            b = '3';
            //j++;
        }
        case '4': {
            b = '4';
            //j++;
        }
        case '5': {
            b = '5';
            //j++;
        }
        case '6': {
            b = '6';
            //j++;
        }
        case '7': {
            b = '7';
            //j++;
        }
        case '8': {
            b = '8';
            //j++;
        }
        case '9': {
            b = '9';
            //j++;
        }
        case '0': {
            b = '0';
            //j++;
        }

    }
    return 0;
}
void perevodandpush(char * a, Mystackint* stackint, int i)
{
    int result = 0;
    int j = i;
    int x = 0;
    if ((a[i] >= '0') && (a[i] <= '9'))
    {

        while (a[j] != ' ')
        {
            x = (int) a[j] - '0';
            result = result * 10 + x;
            //printf("<%d>?%d?$j = %d $\n", x, result, j);
            j++;
        }
        printf("\nresult = %d\n", result);
        i = j;
        printf("\ni = j = %d\n", i);
        pushint(stackint, result);
    }
}
int Transbezprior(char* expression , char* onlywords, MyStack* stack)
{
    int i = 0, j = 0;
    if ((expression)[i] == '-')
    {
        ACTION_WHIS_FIRST_MINUS;
        //i = i + 1;
    }
    for (i; i < strlen(expression); i++)
    {
        if (isdigit(expression[i]))
        {
            while (isdigit(expression[i]))
            {
                //Switch(expression[i], onlywords[j]);
                onlywords[j] = expression[i];
                j++;
                i++;
            }
            onlywords[j] = ' ';
            j++;
        }
        if (stack -> top != 0)
        {
            int k = i;//
            while ( ( (expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*') || (expression[i] == '/') ) &&
                    ( peek(stack) == '+' || peek(stack) == '-' ||  peek(stack) == '/' || peek(stack) == '*' ) )
            {
                onlywords[j] = pop(stack);
                j++;
                onlywords[j] = ' ';
                j++;
                push(stack, expression[i]);
                i++;
            }
            /*while ( ( (expression[i] == '*') || (expression[i] == '/') ) &&
                    ( peek(stack) == '*' || peek(stack) == '/' ) )
            {
                onlywords[j] = pop(stack);
                j++;
                onlywords[j] = ' ';
                j++;
                push(stack, expression[i]);
                i++;
            }*/
            switch(expression[i])
            {
                case '+': {
                    push(stack, '+');
                    break;
                }
                case '*': {
                    push(stack, '*');
                    break;
                }
                case '-': {

                    push(stack, '-');
                    break;
                }
                case '/': {
                    push(stack, '/');
                    break;
                }
                default: {
                    break;
                }
            }
            i = k;
        }
        else
        {
            switch(expression[i])
            {
                case '+': {
                    push(stack, '+');
                    break;
                }
                case '*': {
                    push(stack, '*');
                    break;
                }
                case '-': {
                    push(stack, '-');
                    break;
                }
                case '/': {
                    push(stack, '/');
                    break;
                }
                default: {
                    break;
                }
            }
        }
        if (expression[i] == '(')
        {
            push(stack, '(');

            if ((expression)[i+1] == '-')
            {
                ACTION_WHIS_FIRST_MINUS;
                //i = i + 1;
            }
        }
        if (expression[i] == ')')
        {
            while (stack -> data[stack -> top - 1] != '(')
            {
                onlywords[j] = pop(stack);
                j++;
                onlywords[j] = ' ';
                j++;
            }
            pop(stack);
        }


    }
    while (stack -> top != 0)
    {
        onlywords[j] = pop(stack);
        j++;
        onlywords[j] = ' ';
        j++;
    }
}
 /*  MyStack* stack = createStack();
    MyStack* stackoperac = createStack();
    char a[size1];
    int x = 0;
    int i = 0;
    int j = 0;
    int result = 0;

    fgets(a, size1, stdin);
    //push(stack, 0);
    printf("Stroka----%s----", a);
    for(i = 0; i < size1; i++)
    {
        //printf("\n i = %d \n", i);
        x = 0;
        result = 0;
        j = i;
        if ((a[i] >= '0') && (a[i] <= '9'))
        {

            while (a[j] != ' ')
            {
                x = (int) a[j] - '0';
                result = result * 10 + x;
                j++;
            }
            printf("\nresult = %d\n", result);
            i = j;
            printf("\ni = j = %d\n", i);
            push(stack, result);
            //          printf("$ j = %d$", j);
        }
        switch(a[i])
        {
            case '+':
            {
                push(stackoperac, ADD);
                printStack(stackoperac, printStackValue);
                break;
            }
            case '*':
            {
                push(stackoperac, MULTI);
                printStack(stackoperac, printStackValue);
                break;
            }
            case '-':
            {
                push(stackoperac, SUB);
                printStack(stackoperac, printStackValue);
                break;
            }
            case '/':
            {
                push(stackoperac, DIV);
                printStack(stackoperac, printStackValue);
                break;
            }
            default:
            {

                break;
            }

        }


    }
    printStack(stack, printStackValue);
    for ( i = 0; stackoperac -> top != 1; i++)
    {
        Switch(pop(stackoperac));
    }
*/
 /*int Switch(int a, MyStack* stack)
{
    T a1 = 0, a2 = 0, a3 = 0, a4 = 0;

    switch(a)
    {
        case ADD:
        {
            push(stack, pop(stack) + pop(stack));
            printStack(stack, printStackValue);
            break;
        }
        case MULTI:
        {
            push(stack, pop(stack) * pop(stack));
            printStack(stack, printStackValue);
            break;
        }
        case SUB:
        {
            a1 = pop(stack);
            a2 = pop(stack);
            push(stack, a2 - a1);
            printStack(stack, printStackValue);
            break;
        }
        case DIV:
        {
            a3 = pop(stack);
            a4 = pop(stack);
            push(stack, a4 / a3);
            printStack(stack, printStackValue);
            break;
        }
        default:
        {

            break;
        }

    }
    return 0;
}*/