#include<stdio.h>


void merge(int*,int,int,int);
void mergeSort(int *arr,int l,int h){
	if(l<h){
		int m=(l+h)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,h);
		merge(arr,l,m,h);
	}
}

void merge(int* a,int l,int m,int h){
	int v[h-l+1];
	int i=l,j=m+1,k=0;
	while(i<=m && j<=h){
		if(a[i]<a[j])v[k++]=a[i++];
		else v[k++]=a[j++];
	}
	while(i<=m)v[k++]=a[i++];
	while(j<=h)v[k++]=a[j++];
	k=0;
	for(i=l;i<=h;i++){
		a[i]=v[k++];
	}
}

int main(){
	int a[]={1,5,7,8,9,4,3,2};
	mergeSort(a,0,7);
	for(int i=0;i<8;i++){
		printf("%d ",a[i]);
	}
}