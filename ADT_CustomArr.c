#include <stdio.h> 
#include <stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *arr,int total_size,int used_size){
    arr->ptr=(int *)malloc(total_size*sizeof(int));
    arr->total_size=total_size;
    arr->used_size=used_size;
}

void setVal(struct myArray *arr){
    int n;
    printf("You have %d available to use and starts at ptr %d\n",arr->total_size,arr->ptr);
    for(int i=0;i<arr->used_size;i++){
        printf("Enter val %d: ", i);
        scanf("%d",&n);
        *(arr->ptr+i)=n;
    }
}

void showVal(struct myArray arr){

    for(int i=0;i<arr.used_size;i++){
        printf("Val at index %d is %d\n",arr.ptr+i,*(arr.ptr+i));
    }
}

int main(){
    struct myArray m1;
    createArray(&m1,4,2);
    setVal(&m1);
    showVal(m1);
    return 0; 
}