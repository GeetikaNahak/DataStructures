#include<bits/stdc++.h>
using namespace std;

void bsearch(vector<int>&nums,int l,int r,int &target,int &ne){
  if(l>r)return;
  int m=(l+r)/2;
  if(nums[m]==target){
      ne=m;return;
  }
  if(nums[m]>target){
      ne=m;
      bsearch(nums,l,m-1,target,ne);return ;
  }
  
  bsearch(nums,m+1,r,target,ne);
}
int main() {
    int n;
    cin>>n;
    
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int target;
    cin>>target;
    int ne=n;
    bsearch(nums,0,n-1,target,ne);
    cout<<ne<<endl;
}