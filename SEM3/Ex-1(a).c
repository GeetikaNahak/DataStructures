/*implementing dynamic array*/

#include<stdio.h>
int main(){
    int *arr;
    int size=5;int i;
    arr=(int*)malloc(size*sizeof(int));
    
    for(i=0;i<size;i++){
        printf("\nEnter no. %d :",i+1);
        scanf("%d",(arr+i));
    }
    printf("\nIncreasing size...\n");
    size+=1;
    arr=(int*)realloc(arr,size*sizeof(int));
    printf("\nEnter no. %d :",i+1);
    scanf("%d",(arr+i));
    int k=i+1;
    for(i=0;i<k;i++){
        printf("\n%d ",*(arr+i));
    }printf("End");
}

/*
output:
Enter no. 1 :1
Enter no. 2 :2
Enter no. 3 :3
Enter no. 4 :4
Enter no. 5 :5
Increasing size...

Enter no. 6 :6
1 
2 
3 
4 
5 
6 End
*/