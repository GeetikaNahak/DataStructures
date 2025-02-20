#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n,m;cin>>n>>m;
  int h;cin>>h;
  vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int j=n-1;
  for(int i=m-1;i>=0;i--){
    int k=h;
    while(j>=0 &&k>=v[j] ){
      k-=v[j];
      j--;
    }
    
  }
   cout<<j+1<<endl;
 
}
