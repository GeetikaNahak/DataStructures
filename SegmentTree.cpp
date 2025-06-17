#include <bits/stdc++.h>
using namespace std;

vector<int>stMax;
vector<int>stMin;
void buildMax(vector<int>&arr,int node,int start,int end){
  if(start==end){
    stMax[node]=arr[start];
    return;
  }
  int mid=(start+end)/2;
  buildMax(arr,2*node+1,start,mid);
  buildMax(arr,2*node+2,mid+1,end);
  stMax[node]=max(stMax[2*node+1],stMax[2*node+2]);
}

int queryMax(int node,int start,int end,int left,int right){
  if(left<=start && right>=end)return stMax[node];
  if(start>right || end<left)return INT_MIN;
  int mid=(start+end)/2;
  return max(queryMax(2*node+1,start,mid,left,right),queryMax(2*node+2,mid+1,end,left,right));
}

void buildMin(vector<int>&arr,int node,int start,int end){
  if(start==end){
    stMin[node]=arr[start];
    return;
  }
  int mid=(start+end)/2;
  buildMin(arr,2*node+1,start,mid);
  buildMin(arr,2*node+2,mid+1,end);
  stMin[node]=min(stMin[2*node+1],stMin[2*node+2]);
}

int queryMin(int node,int start,int end,int left,int right){
  if(left<=start && right>=end)return stMin[node];
  if(start>right || end<left)return INT_MAX;
  int mid=(start+end)/2;
  return min(queryMin(2*node+1,start,mid,left,right),queryMin(2*node+2,mid+1,end,left,right));
}





int main() 
{
    int n,q;cin>>n>>q;
    vector<int>v(n);
    stMax.resize(n * 4, INT_MIN); 
    stMin.resize(n * 4, INT_MAX);
    for(int i=0;i<n;i++)cin>>v[i];
    buildMax(v,0,0,n-1);
    buildMin(v,0,0,n-1);
    while(q--){
      int l,r;cin>>l>>r;
      cout<<queryMax(0,0,n-1,l,r)<<endl;
      cout<<queryMin(0,0,n-1,l,r)<<endl<<endl;
    }
    return 0;
}