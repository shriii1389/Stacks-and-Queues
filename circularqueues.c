#include <stdio.h>
#include <stdlib.h>
#define size 5
int count=0;
void enque(int a[],int *front,int *rear,int n){
    if(size==count){
        printf("Queue Overflow. Not happening\n\n");
    }
    else{
        *rear=(*rear+1)%size;
        a[*rear]=n;
        if(*front==-1) (*front)++;
        count++;
    }
}
int deque(int a[],int *front,int *rear){
    if(count==0){
        printf("Queue underflow. Not happening\n\n");
    }
    else{
        int x=a[(*front)];
        *front=(*front+1)%size;
        count--;
        return x;
    }
    return -1;
}
void display(int a[],int front,int rear){
    if(count==0){
        printf("Nothing to print\n");
    }
    else{
        int c=count;
        for(int i=front;c>0;c--){
            printf("%d\t",a[i]);
            i=(i+1)%size;
        }
        printf("\n");
    }
}

int isempty(int front,int rear){
    if((front==-1)||(front>rear)) return 1;
    return 0;
}
int isfull(int front,int rear){
    if(rear=size-1) return 1;
    return 0;
}

void main(){
    int n,queue[size],front=-1,rear=-1;
    printf("Enter the number of elements: ");
    while(1){
        printf("Make a choice:\n 1)Enque \t 2)Deque \n 3)Display \t 0)Exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&n);
                enque(queue,&front,&rear,n);
                break;
            case 2:
                printf("%d is deleted\n",deque(queue,&front,&rear));
                break;
            case 3:
                display(queue,front,rear);
                break;
            case 0:
                printf("Bye!");
                exit(0);
                break;
            default:
                printf("Invalid choice\n\n");
                break;
        }
    }
}