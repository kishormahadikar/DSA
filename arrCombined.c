#include <stdio.h> 

void traverser(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void insertAt(int *arr, int *size, int cap){
    if(*size>cap){
        printf("Array is full");
    }
    else{
        int ind,elem;
        printf("Enter index to insert element: ");
        scanf("%d",&ind);
        printf("Enter element to insert: ");
        scanf("%d",&elem);
        for(int i=*size-1;i>=ind;i--){
            arr[i+1]=arr[i];
        }
        arr[ind]=elem;
    }

}

void delete(int *arr, int *size, int cap){
    if(*size>cap){
        printf("Array is full");
    }
    else{
        int ind;
        printf("Enter index to delete element: ");
        scanf("%d",&ind);
        for(int i=ind;i<*size;i++){
            arr[i]=arr[i+1];
        }
        (*size)-=1;
    }
}

void search(int *arr, int size){
    int low=0,high=size;
    int mid=(high+low)/2;
    int elem;
    printf("Insert the element you looking for\n");
    scanf("%d",&elem);
    if(arr[0]==elem){
         printf("Element %d found at ind 0",elem);
    }
    while (low<=high)
    {
        //printf("h-%d l-%d m-%d\n",high,low,mid);
        int mid=(high+low)/2;
        if(arr[mid]==elem){
            printf("Element %d found at ind %d",elem,mid);
            break;
        }
        else if(high==size && low==high-1 && arr[mid]!=elem){
            printf("%d Not found",elem);
            break;
        }
        else if(arr[mid]>elem){
            high=mid;
        }
        else if(arr[mid]<elem){
            low=mid;
        }
        
    }
    
}


int main(){
    int arr[10],size=5,cap=10;
    int op,redo=0;
    
    for(int i=0;i<5;i++){
        printf("Insert 5 elements %d\n",i+1);
        scanf("%d",&arr[i]);
    }
    while(redo==0){
    printf("Insert operation to perform:\n1.Insert\n2.Delete\n3.Search\n");
    scanf("%d",&op);
    if(op==1){
        traverser(arr,size);
        size+=1;
        insertAt(arr,&size,cap);
        traverser(arr,size);
    }
    if(op==2){
        traverser(arr,size);
        delete(arr,&size,cap);
        traverser(arr,size);
    }
    if(op==3){
        traverser(arr,size);
        search(arr,size);
    }
    printf("Press 0 to continue, Press 1 to stop\n");
    scanf("%d",&redo);

    } 
    return 0; 
}

