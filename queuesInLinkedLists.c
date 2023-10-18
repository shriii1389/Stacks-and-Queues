#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;

node *enque(node *head,int *front, int *rear, int a){
    node *n= (node *)(malloc(sizeof(node)));
    n->data=a;
    n->next=head;
    return n;
}

node *deque(node *head,int *front, int *rear){
    if (head==NULL){
        printf("Nothing to delete\n"); 
        return NULL;
    }
    node *temp=head;
    head=head->next;
    int a=temp->data;
    printf("%d is deleted\n",a);
    free(temp);
    return head;        
}

void display(node *head,int front, int rear){
    node *temp=head;
    if(temp==NULL){
        printf("Nothing to print\n");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void main(){
    int n,front=-1,rear=-1;
    node *queue=NULL;
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