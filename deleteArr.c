#include <stdio.h> 

int del(int *arr,int *size,int cap,int ind){

    
        for (int i = ind-1; i <*size; i++)
        {
            arr[i]=arr[i+1];
        }
        *size-=1;
        
    
}

void traverse(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}



int main(){
    int arr[100]={1,4,12,25,50};
    int size=5,element=18,ind=1,cap=sizeof(arr)/4;
    printf("before: ");
    traverse(arr,size);
    printf("\n ");
    del(arr,&size,cap,ind);
    traverse(arr,size);
    
    return 0; 
}
