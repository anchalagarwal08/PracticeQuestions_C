#ifndef _STACK_H_
#define _STACK_H_
typedef struct Stack stack;
struct Stack
{
    int data[100];
    int top;
    int end;
    int size;
};

void push(int item, stack *s);
int pop(stack *s);
int peek(stack *s);
#endif
