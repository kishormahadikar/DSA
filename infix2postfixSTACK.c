#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

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

int stre(char c){
    if(c=='^'){
        return 2;
    }
    if(c=='*' || c=='/'){
        return 2;
    }
    if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

int isOp(char c){
    if(c=='*' || c=='/' || c=='+' || c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

char stacktop(struct stack *s){
    return s->arr[s->top];
}

int in2po(char *expr){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=50;
    s->arr=(char *)malloc(s->size*sizeof(char));
    char *final=(char *)malloc(strlen(expr)+1*sizeof(char));
    int i=0,j=0;
    while(expr[i]!='\0'){
        if(isOp(expr[i])==0){
            if(expr[i]=='(' || expr[i]==')'){
                i++;
            }
            else{
            final[j]=expr[i];
            i++;
            j++;}
        }
        else if(stre(expr[i])>stre(stacktop(s))){
            push(s,expr[i]);
            i++;
        }
        else{
            final[j]=pop(s);
            j++;
        }

    } 
    while(isEmpty(s)!=1){
        final[j]=pop(s);
        j++;
    }
    final[j]='\0';
    printf("%s",final);
      
}

int main(){;
    char arr[100];
    printf("Enter a string: ");
    gets(arr);
    int a;
    a= in2po(arr);
    return 0; 
}





