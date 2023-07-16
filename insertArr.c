#include <stdio.h> 

int insrt(int *arr,int *size,int cap,int ind,int element){
    if(*size>=cap){
        return -1;
    }
    else{
        for (int i = *size-1; i >= ind; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[ind]=element;
        (*size)+=1;
        return 1;
    }
}

int main(){
    int arr[100]={1,4,12,25,50};
    int size=5,element=18,ind=3,cap=sizeof(arr)/4;
    insrt(arr,&size,cap,ind,element);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    //printf("%d",cap);

    return 0; 
}