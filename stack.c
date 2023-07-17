#include <stdio.h> 
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
         //printf("Stack is empty\n");
        return 1;
    }
    //printf("Stack is not empty\n");
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        //printf("Stack is full in isfull\n");
        return 1;
    }
    return 0;
}

int push(struct stack *ptr,int elem){
    if(isFull(ptr)!=1){
        ptr->arr[(ptr->top)+1]=elem;
        ptr->top++;
        return 1;
    }
    printf("Stack is full, could not add element %d\n",elem);
    return 0;
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)!=1){
        int val= ptr->arr[ptr->top];
        ptr->top--;
        //printf("%d is top value\n",ptr->arr[ptr->top]);
        return val;
    }
    printf("Stack is empty\n");
    return -1;
    
}

void peak(struct stack *ptr,int ind){
    //int temp=ptr->top;
    int i;
    if(isEmpty(ptr)!=1 && ptr->top>=ind-1 && ind>0){
        i=ptr->top-ind+1;
        printf("Val present at %d index is %d\n",ind,ptr->arr[i]);
    }
    else{printf("underflow\n");}
    
    
}

void traverser(struct stack *ptr){
    for(int i=0;i<=ptr->top;i++){
        printf("%d ",ptr->arr[i]);
    }
    printf("\n");
}


int main(){
    struct stack *s;
    int popper;
    s->size=20;
    s->top=-1;
    s->arr=(int *)malloc((s->size)*sizeof(int));
    isEmpty(s);
    push(s,5);
    push(s,7);
    push(s,9);
    push(s,11);
    push(s,15);
    push(s,17);
    push(s,21);
    printf("Adding val to stack\n");
    // s->arr[0]=1;
    // s->top++;
    traverser(s);
    popper=pop(s);
    printf("%d popped\n",popper);
    peak(s,5);
    traverser(s);
    popper=pop(s);
    printf("%d popped\n",popper);
    traverser(s);
    popper=pop(s);
    printf("%d popped\n",popper);
    traverser(s);
    popper=pop(s);
    printf("%d popped\n",popper);
    traverser(s);
    popper=pop(s);
    printf("%d popped\n",popper);
    traverser(s);
    printf("%d is new top after pop",s->arr[s->top] );
   isFull(s);
    return 0; 
}