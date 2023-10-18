#include <stdio.h>
#include <stdlib.h>
#define size 3
void push(int [],int *,int);
int pop(int [],int *);
int peep(int [],int *);
int seek(int [],int *);
void display(int [],int );

void push(int a[],int *top,int n){
    if(*top>=size){
        printf("Stack Overflow. Not happening\n\n");
    }
    else{
        ++*top;
        a[*top]=n;
    }
}

int pop(int a[],int *top){
    if(*top==-1){
        printf("Stack Underflow. Not happening\n\n");
    }
    else{
        int x=a[*top];
        *top--;
        return x;
    }
}
void display(int a[],int top){
    for(int i=0;i<top;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void main(){
    int n,stack[size],top=-1,x;
    printf("Enter the number of elements: ");
    while(1){
        printf("Make a choice:\n1)PUSH\t2)POP\n3)PEEP\t4)SEEK\n5)Display\t0)Exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&n);
                push(stack,&top,n);
                break;
            case 2:
                x=pop(stack,&top);
                break;
            case 3:
                peep(stack,&top);
                break;
            case 4:
                seek(stack,&top);
                break;
            case 5:
                display(stack,top);
                break;
            case 0:
                printf("Bye!");
                exit(0);
                break;
        }
    }
}