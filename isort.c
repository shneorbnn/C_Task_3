#include <stdio.h>
#include <stdlib.h>






void shift_element(int *arr, int i){
    int a=i;
    int firstIndexSave=*(arr+i);
    for(int j=a;j>=0;j--){
        if(j==0){
            *arr=firstIndexSave;
        }else{
            *(arr+j)=*(arr+j-1);
        }
    }    
}



void insertion_sort(int* array , int len){
    int n=0;
    int stop=0;
    int smaller;
    int length=len;
    int indexSmaller;
    
    while(stop<length-1){
        
            smaller=*(array+n);
            int index=0;
            
        for(int j=n;j<length;j++){//                find the smallest value && index
            if(*(array+j)<=smaller){
                smaller=*(array+j);
                indexSmaller=index;            
      
     }
     index++;
}

shift_element(array+n,indexSmaller);

    stop++;
    n++;
}



}





void arrayPrint(int *array, int arrayLength){
        printf("your array is: ");
    for(int i=0;i<arrayLength;i++){
    if(i==(arrayLength-1)){
        printf("%d\n",array[i]);
    }else{
    printf("%d,",array[i]);
    }
 }
}

void main(){
    int arrayLength=50;
    int *array = (int*)malloc((arrayLength)*sizeof(int)); 
   for(int i = 0; i<arrayLength; i++)
   {
      array[i] = rand() % 50;
   }
printf("random 50 numbers.\n");
arrayPrint(array,arrayLength);
insertion_sort(array,arrayLength);
arrayPrint(array,arrayLength);
   free(array);
}