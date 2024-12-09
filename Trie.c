#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	struct Node* children[10];
	int fl;
}node ;

node* createNode(){
	node* newNode=(node*)malloc(sizeof(node));
	newNode->fl=0;
	for(int i=0;i<10;i++){
		newNode->children[i]=NULL;
	}
	return newNode;
}

void insert(node* root,char* nu){
	node* c=root;
	for(int i=0;i<strlen(nu);i++){
		int ind=nu[i]-'0';
		if(c->children[ind]==NULL){
			c->children[ind]=createNode();
		}
		c=c->children[ind];
	}
	if(c->fl==1)return;
	c->fl=1;
	printf("%s\n",nu);
}

void dfs(node* root,char path[],int k){
	if(root->fl){
		path[k]='\0';
		printf("%s\n",path);

	}
	for(int i=0;i<10;i++){
		if(root->children[i]!=NULL){
			path[k]='0'+i;
			dfs(root->children[i],path,k+1);
		}
	}
}

void printNu(node* root){
	char path[100];
	dfs(root,path,0);

}

int main(){
	struct Node* root=createNode();
	int n;
	scanf("%d",&n);
	while(n--){
		
		char str[1000000];
		scanf("%s",str);
		for(int i=0;i<strlen(str);i++){
			insert(root,str);
		}

	}
	// printNu(root);
	return 0;
}
