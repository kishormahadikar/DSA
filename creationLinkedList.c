#include <stdio.h> 
#include <stdlib.h>

struct Node{
    
   struct Node *prev; 
   int data;
   struct Node *next; 
};

void linkedListrevTraverse(struct Node* ptr){
   
    //printf("%d",ptr->data);
    printf("\n");
    //printf(".");
    while (ptr!=NULL)
    {
    //    printf(".");
    printf("Element is %d\n",ptr->data);
    ptr=ptr->prev;
    } 
    //printf("END\n"); 
}

void linkedListTraverse(struct Node* ptr){
    do
    {
    printf("Element is %d\n",ptr->data);
    ptr=ptr->next;
    } while (ptr->next!=NULL);
    printf("Element is %d\n",ptr->data);
    
    //printf("Element ibhs %d\n",ptr->data);
    linkedListrevTraverse(ptr);
    //printf("END\n"); 
}



int main(){
    struct Node *head,*second,*third,*four,*beg;
    int dataa=1;
    head = (struct Node *)malloc(sizeof(struct Node));
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    four= (struct Node *)malloc(sizeof(struct Node));
    head->prev=NULL;
    head->data=7;
    head->next=second;
    second->prev=head;
    second->data=14;
    second->next=third;
    third->prev=second;
    third->data=21;
    third->next=four;
    four->prev=third;
    four->data=28;
    four->next=NULL;

    linkedListTraverse(head);
    
    //linkedListrevTraverse(head);
   
    return 0; 
}