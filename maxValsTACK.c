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
    int c=0;
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

int maxTablePush(struct stack *s,struct stack *s2,int elem){
    push(s,elem);
    if(isEmpty(s2)==1){
        push(s2,elem);
    }
    else if(elem>=s2->arr[s2->top]){
        push(s2,elem);
    }

}

int maxTablePop(struct stack *s,struct stack *s2){
    int val;
    val=pop(s);
    if(val==s2->arr[s2->top]){
        pop(s2);
    }

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
    int elem[]={2,1,3,1,4};
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    struct stack *s2=(struct stack *)malloc(sizeof(struct stack));
    s->size=20;
    s->top=-1;
    s->arr=(int *)malloc((s->size)*sizeof(int));
    s2->size=20;
    s2->top=-1;
    s2->arr=(int *)malloc((s->size)*sizeof(int));
    for(int i=0;i<5;i++){
        printf(".\n");
        maxTablePush(s,s2,elem[i]);
    }
    traverser(s);
    traverser(s2);
    maxTablePop(s,s2);
    maxTablePop(s,s2);
    maxTablePop(s,s2);
    traverser(s);
    traverser(s2);
    return 0; 
}