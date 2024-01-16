//Binary Tree and it's Operations

#include<stdio.h>
#include<stdlib.h>

typedef struct BT{
    int data;
    struct BT* left;
    struct BT* right;
}node;

node* newNode(int val){
    node* n=(node*)malloc(sizeof(node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    printf("\nInorder\n");
    inorder(root);
    printf("\nPreorder\n");
    preorder(root);
    printf("\nPostorder\n");
    postorder(root);
}