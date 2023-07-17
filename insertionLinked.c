#include <stdio.h> 
#include <stdlib.h>

struct Node{
   int data;
   struct Node *next; 
};

void linkedListTraverse(struct Node* ptr){
    while (ptr!=NULL)
    {
    printf("Element is %d\n",ptr->data);
    ptr=ptr->next;
    } 
    //printf("END\n"); 
}

struct Node* insertionAtBeginning(struct Node *head,int dataa){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=dataa;
    return ptr;
}

struct Node* insertionAtIndex(struct Node *head,int dataa,int index){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    ptr->data=dataa;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct Node* insertionAtEnd(struct Node *head,int dataa){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    //skip head till null
    while(p->next!=NULL){
        p=p->next;
    }
        p->next=ptr;
        ptr->data=dataa;
        ptr->next=NULL;
        return head; 
}

void insertionAfterNode(struct Node *node,int dataa){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=dataa;
    ptr->next=node->next;
    node->next=ptr;
    //return head;
}

int main(){
    struct Node *head,*second,*third,*four,*beg;
    int dataa=1;
    head = (struct Node *)malloc(sizeof(struct Node));
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    four= (struct Node *)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=14;
    second->next=third;
    third->data=21;
    third->next=four;
    four->data=28;
    four->next=NULL;

    linkedListTraverse(head);
    head=insertionAtBeginning(head,dataa);
    printf("After insertion at beginning\n");
    linkedListTraverse(head);
    head=insertionAtEnd(head,dataa);
    printf("After insertion at end\n\n");
    linkedListTraverse(head);
    head=insertionAtIndex(head,dataa,3);
    printf("After insertion at 3 ind\n\n");
    linkedListTraverse(head);
    insertionAfterNode(head,dataa);
    printf("After insertion at first node\n\n");
    linkedListTraverse(head);
    return 0; 
}