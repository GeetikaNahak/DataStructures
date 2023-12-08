#include<stdio.h>
typedef struct node{
    int data;
    struct node* next;
}node;
int main(){
    printf("Menu driven program for Linked list");
    while(1){
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Reverse\n");
        printf("4.print\n");
        printf("5.Search\n");
        printf("Enter your choice\n");
        int c;
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Reverse();
            break;
        case 5:
            Search();
            break;
        case 4:
            print();
            break;
        
        default:exit(0);
            
        }
    }
}