/*Implementing Single Linked List and it's Operations(Menu-based)*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* head=NULL;
struct node* newNode(int val){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;
    return n;
}
void createLL(){
    head=NULL;
    printf("\nEnter No. of nodes");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        printf("\nEnter value of node %d : ",i+1);
        scanf("%d",&val);
        struct node* n=newNode(val);
        if(head==NULL){
            head=n;
        }
        else{
            struct node* n=newNode(val);
            struct node* t=head;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=n;
        }
    }
}
void insert(){
    printf("\nEnter value to be inserted");
    int val;scanf("%d",&val);
    printf("\n1.insertAtHead\n2.insertAtTail\n3.insesrtAtPosition\nchoose:");
    int c;scanf("%d",&c);
    switch (c)
    {
    case 1:
        if(head==NULL)head=newNode(val);
        else{
            struct node* t=head;
            struct node* h=newNode(val);
            h->next=head;
            head=h;
        }
        break;
    case 2:
        struct node* t=head;
        while(t->next!=NULL)t=t->next;
        t->next=newNode(val);
    break;
    case 3:
        int pos;
        scanf("%d",&pos);
        int k=0;
        t=head;
        struct node* t2=t;
        while(k<pos&&t->next!=NULL){
            t2=t;
            t=t->next;k++;
        }
        struct node* n=newNode(val);
        n->next=t;
        t2->next=n;
    break;

    default:
        break;
    }
}
void delete(){
    printf("\n1.DeleteAtHead\n2.DeleteAtTail\n2.DeleteAtPosition\nChoose :");
    int c;
    scanf("%d",&c);
    if(head==NULL)return;
    struct node* t=head;
    switch(c){
        case 1:
            head=t->next;
            free(t);
        break;
        case 2:
            
            while(t->next->next!=NULL){
               
                t=t->next;
            }
            t->next=NULL;
        break;
        case 3:
            printf("\nEnter Pos\n");
            int p;scanf("%d",&p);
            int r=0;
            t=head;
            while(r<p-1&&t->next->next!=NULL){
                r++;
                t=t->next;
            }
            struct node* k=t->next;
            t->next=t->next->next;
            free(k);
        break;
        default:break;
            
            
    }
}
void display(){
    struct node* t=head;printf("\n");
    while(t!=NULL){
        printf("%d->",t->data);
        t=t->next;
    }printf("NULL\n");
}
int main(){
    int c;
    struct node* head=NULL,*tail;
    while(1){
        printf("\n1.Create Linked List");
        printf("\n2.Insert node");
        printf("\n3.Delete Node");
        printf("\n4.Display Linked List");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:createLL();
            break;
            case 2:insert();
            break;
            case 3:delete();
            break;
            case 4:display();
            break;
            default:exit(0);
        }
        printf("\nEnd\n");
    }
}