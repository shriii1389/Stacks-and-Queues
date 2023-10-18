#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int priority;
    struct node *next;
}node;

node *ascending(node *head,int a,int priority){
    node *n=(node*)malloc(sizeof(node)); //First node.
        n->data=a;
        n->priority=priority;
        n->next=NULL;
    if(head==NULL){
        head=n;
        return head;
    }
    else if(head->priority>priority){
        n->next=head;
        head=n;
        return head;
    }
    node *temp=head;
    while((temp->next)!=NULL && (temp->next)->priority<priority){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
    return head;
}
int frontdeletion(node *head){
    if (head==NULL){
        printf("Nothing to delete\n"); 
        return -1;
    }
    node *temp=head;
    head=head->next;
    int a=temp->data;
    printf("%d is deleted\n",a);
    free(temp);
    return a;        
}

void display(node *head){
    node *temp=head;
    if(temp==NULL){
        printf("Nothing to print\n");
    }
    else{
        printf("\nElements of the list are\n");
        while(temp!=NULL){
            printf("%d->%d\n",temp->priority,temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int data(node *head, int priority){
    node *temp=head;
    for(int i=0;i<priority;i++){
        if(temp!=NULL) temp=temp->next;
        else{
            printf("The priority doesn't exist in the queue\n");
            return 0;
        }
    }
    if(temp!=NULL) return temp->data;
    else return 0;
}

void main(){
    node *queue=NULL;
    int choice=1,num,priority;
    while(choice){
        printf("What do you want to do?\n1)enque\t2)Deque\n3)Data from the priority\t4)Display\n0)Exit\n");
        scanf("%d",&choice);
        switch (choice){
        case 1:    
            printf("Enter an element: ");
            scanf("%d",&num);
            printf("Enter the priority for this: ");
            scanf("%d",&priority);
            queue=ascending(queue,num,priority);
            break;
        case 2:
            frontdeletion(queue);
            break;
        case 4:
            display(queue);
            break;
        case 3:
            printf("Enter the priority you want to search\n");
            scanf("%d",&priority);
            printf("The element is %d",data(queue,priority));
            break;
        case 0:
            printf("Bye!!\n");
            choice=0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}