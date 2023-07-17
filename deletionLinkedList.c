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

struct Node* deleteFirst(struct Node *head){
    struct Node *p=head;
    p=head->next;
    free(head);
    return p;
}

struct Node* deleteMid(struct Node *head,int index){
    struct Node* p=head;
    for(int i=0;i!=index-1;i++){
        p=p->next;
    }
    struct Node* q=p->next;
    p->next=q->next;
    free(q);
    return head;
}

struct Node* deleteLast(struct Node *head){
    struct Node*p=head;
    struct Node*q=head->next;
    while (q->next!=NULL)
    {
        p->next;
        q->next;
    }
    
    p->next=NULL;
    free(q);
    return head;
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
    head=deleteFirst(head);
    printf("After deleting first\n");
    linkedListTraverse(head);
    head=deleteMid(head,2);
    printf("After deleting ind 2\n");
    linkedListTraverse(head);
    head=deleteLast(head);
    printf("After deleting last\n");
    linkedListTraverse(head);
    
    return 0; 
}