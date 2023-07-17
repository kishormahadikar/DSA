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
        //printf(". \n");
        ptr->arr[(ptr->top)+1]=elem;
        ptr->top++;
        return 1;
    }
    printf("Stack is full, could not add element %c\n",elem);
    return 0;
}

int pop(struct stack *ptr,char c){
    if(isEmpty(ptr)!=1){
        //printf("en\n");
        char val= ptr->arr[ptr->top];
        ptr->top--;
        //printf("%c %c\n",val,c);
        if(val==c){
            //printf("1\n");
            return 1;
        }
        else{
            //printf("-1\n");
            return -1;
        }
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
        if( expr[i]=='(' || expr[i]=='{' || expr[i]=='[' ){
            if(isFull(s)!=1){
                push(s,expr[i]);
            }
            
        }
        else if(isEmpty(s)!=1 && (expr[i]==')' || expr[i]=='}' || expr[i]==']') ){
            if(expr[i]==')'){
               int checker;
               checker = pop(s,'(');
               if(checker==-1){
               printf("UNBalanced 1.pop");
               break;
               }
            }
            if(expr[i]=='}'){
               int checker;
               checker = pop(s,'{');
               if(checker==-1){
               printf("UNBalanced 1.pop");
               break;
               }
            }
            if(expr[i]==']'){
               int checker;
               checker = pop(s,'[');
               if(checker==-1){
               printf("UNBalanced 1.pop");
               break;
               }
            }
            
            }
            
            else if((expr[i]==')' || expr[i]=='}' || expr[i]==']') && isEmpty(s)==1  ){
                printf("UNBalanced empty");
                return -1;
                break;
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
