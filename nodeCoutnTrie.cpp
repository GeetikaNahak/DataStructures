#include <bits/stdc++.h>
using namespace std;
int c=0;
class node{
  public:
  int fl;
  node* children[26];
  node(){
    fl=0;c++;
    for(int i=0;i<26;i++)children[i]=NULL;
  }
};

void insert(node* root,string s){
  node* c=root;
  for(int i=0;i<s.length();i++){
    int ind=s[i]-'a';
    if(!c->children[ind]){
      c->children[ind]=new node();
      
    }c=c->children[ind];
  }
  c->fl=1;
}

int main(){
  node* root=new node();
  insert(root,"hellocse");
  insert(root,"hellovignan");
  cout<<c-1<<endl;
}


/*
o/p:
14
*/