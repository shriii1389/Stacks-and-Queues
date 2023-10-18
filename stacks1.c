#include <stdio.h>
#include <stdlib.h>

typedef struct stacks
{
    int data;
    struct stacks *top;
}stack;

stack *push(stack *head,int a){
    stack *n= (stack *)(malloc(sizeof(stack)));
    n->data=a;
    n->top=head;
    head=n;
}

int main(){

}
