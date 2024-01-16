/*Build Tree using given PostOrder and InOrder sequence*/

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

Node* BuildTree(int Post[],int In[],int st,int en){
    static int idx=4;
    if(st>en){
        return NULL;
    }
    int curr=Post[idx];
    idx--;
    Node* node=new Node(curr);
    if(st==en){
        return node;
    }
    int pos=search(In,st,en,curr);
    node->right=BuildTree(Post,In,pos+1,en);
    node->left=BuildTree(Post,In,st,pos-1);
    
    return node;
}

void inorderPrint(Node* root){
    if(root==NULL)return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    Node* node=BuildTree(postorder,inorder,0,4);
    inorderPrint(node);
}

/*
output:
4 2 1 5 3 
*/