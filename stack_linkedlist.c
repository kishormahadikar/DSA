#include <stdio.h> 
#include <stdlib.h>

struct node{
    int data;
    //int top;
    struct node* next;
};

int isEmpty(struct node* ptr){
    if(ptr==NULL){
        return -1;
    }
    else{
        return 1;
    }
}

int isFull(struct node* ptr){
    struct node* test=(struct node*)malloc(sizeof(struct node));
    if(test==NULL){
        free(test);
        return -1;
    }
    else{
        free(test);
        return 1;
    }
}

struct node* push(struct node* ptr,int elem){
    if(isFull(ptr)!=-1){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=elem;
    new->next=ptr;
    return new;
    }
    else{
        printf("Couldn't add %d, stack overflow",elem);
    }
}

int pop(struct node** top){
    if(isEmpty((*top))!=-1){
        int x;
        x=(*top)->data;
        *top=(*top)->next;
        return x;

    }
    else{
        printf("No elements in list");
    }
    
}

struct node* peek(struct node* top, int ind){
    if(isEmpty(top)!=-1){
        for(int i=0;i<ind-1 && top!=NULL;i++){
            top=top->next;
        }
        if(top!=NULL){
          return top;
        }

    }
    else{
        printf("No elements in list");
    } 
}



void traverse(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
        
    }
    printf("\n");
}



int main(){
    struct node *top=NULL;
    int ind=3;
    struct node* temp;
    //top=(struct node*)malloc(sizeof(struct node));
    //printf("%d", isEmpty(top));
    top=push(top,28);
    top=push(top,18);
    top=push(top,15);
    top=push(top,7);
    //top=push(top,5);
    traverse(top);
    //printf("Popped %d \n",pop(&top));
    //traverse(top);
    temp=peek(top,ind);
    printf("The val at index %d is %d\n",ind,temp->data);
    // pop(&top);
    // traverse(top);
    
    return 0; 
}