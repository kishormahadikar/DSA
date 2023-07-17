#include <stdio.h> 
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


void nodeTraverse(struct node *ptr){
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
}

struct node* insertAtBeginning(struct node* ptr){
    struct node *p=ptr;
    int elem;
    printf("Enter an element: ");
    scanf("%d",&elem);
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=elem;
    head->next=ptr;
    return head;
    
}

struct node* insertAtMid(struct node* ptr){
    struct node *p=ptr;
    int elem,index;
    printf("Enter an element: ");
    scanf("%d",&elem);
    printf("Enter an index: ");
    scanf("%d",&index);
    struct node* new=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    temp=p->next;
    p->next=new;
    new->data=elem;
    new->next=temp;
    return ptr;
    
}

struct node* insertAtEnd(struct node* ptr){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    struct node *p=ptr;
    int elem,index;
    printf("Enter an element: ");
    scanf("%d",&elem);
    struct node* temp;
    for(int i=0;p->next!=NULL;i++){
        p=p->next;
    }
    p->next=new;
    new->data=elem;
    new->next=NULL;
    return ptr;
    
}

struct node* deleteAtBeginning(struct node* ptr){
    struct node *p=ptr;
    p=ptr->next;
    free(ptr);
    return p;
    
}
struct node* deleteAtMid(struct node* ptr){
    struct node *p=ptr;
    int index;
    printf("Enter an index: ");
    scanf("%d",&index);
    struct node* temp;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    temp=p->next;
    p->next=temp->next;
    //free(ptr);
    return p;
    
}

struct node* deleteAtEnd(struct node* ptr){
    struct node *p=ptr;
    struct node *pn=p->next;
    struct node* temp;
    for(int i=0;pn->next!=NULL;i++){
        p=p->next;
        pn=pn->next;
    }
    p->next=NULL;
    return ptr;
    
}


int main(){
    struct node *head, *first,*second;
    int s;
    head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=first;
    first->data=2;
    first->next=second;
    second->data=3;
    second->next=NULL;
    nodeTraverse(head);
    printf("\n");
    printf("Enter the operation u wanna perform\n1.Insert\n2.Delete\n");
    scanf("%d",&s);
    if(s==1){
       int io;
       printf("1.Insert at start\n2.Insert in between\n3.Insert at end\n");
       scanf("%d",&io);
       if(io==1){
       head= insertAtBeginning(head);
       }
       else if(io==2){
       head= insertAtMid(head);
       }
       else if(io==3){
       head= insertAtEnd(head);
       }
       nodeTraverse(head);
    }
    if(s==2){
       int io;
       printf("1.Delete at start\n2.Delete in between\n3.Delete at end\n");
       scanf("%d",&io);
       if(io==1){
       head= deleteAtBeginning(head);
       }
       else if(io==2){
       head= deleteAtMid(head);
       }
       else if(io==3){
       head= deleteAtEnd(head);
       }
       nodeTraverse(head);
    }
    
    return 0; 
} 