/*Build Tree Using Preorder and Inorder*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int In[],int st,int en,int curr){
    for(int i=st;i<=en;i++){
        if(In[i]==curr)return i;
    }
    return -1;
}

Node* BuildTree(int Pre[],int In[],int st,int en){
    static int idx=0;
    if(st>en){
        return NULL;
    }
    int curr=Pre[idx];
    idx++;
    Node* node=new Node(curr);
    if(st==en){
        return node;
    }
    int pos=search(In,st,en,curr);
    node->left=BuildTree(Pre,In,st,pos-1);
    node->right=BuildTree(Pre,In,pos+1,en);
    return node;
}

void inorderPrint(Node* root){
    if(root==NULL)return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node* node=BuildTree(preorder,inorder,0,4);
    inorderPrint(node);
}

/*
output:
4 2 1 5 3 
*/