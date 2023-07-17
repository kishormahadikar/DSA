#include <stdio.h> 
#include <stdlib.h>

struct stack{ 
    int top;
    int size;
    char *arr;
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

int push(struct stack *ptr,char elem){
    if(isFull(ptr)!=1){
        printf(". \n");
        ptr->arr[(ptr->top)+1]=elem;
        ptr->top++;
        return 1;
    }
    printf("Stack is full, could not add element %c\n",elem);
    return 0;
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)!=1){
        char val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    printf("Stack is empty\n");
    return -1;
    
}

int parenthesis(char *expr){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    //printf(". \n");
    s->top=-1;
    s->size=50;
    s->arr=(char *)malloc(s->size*sizeof(char));
    //printf(". \n");
    for(int i=0;expr[i]!='\0';i++){
        if(isFull(s)!=1 && expr[i]=='(' ){
            push(s,expr[i]);
        }
        else if(expr[i]==')' ){
            if(isEmpty(s)!=1){
                pop(s);
            }
            else{
                printf("UNBalanced 1.1");
                return -1;
                break;
                
            }
        }
    }
    if(isEmpty(s)==1){
        printf("Balanced");
        return 1;
    }
    else{
         printf("UNBalanced");
        return -1;
    }
}

int main(){
    struct stack *sm=(struct stack*)malloc(sizeof(struct stack));
    char arr[100];
    printf("Enter a string: ");
    gets(arr);
    int a;
    a= parenthesis(arr);
    return 0; 
}


