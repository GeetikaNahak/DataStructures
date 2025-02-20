#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int e,n;cin>>e>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end(),greater<int>());
  int k=0,i=0;
  while(e>0 && i<n){
    e-=a[i];
    k++;
    if(e<0)break;
    e-=a[i];
    k++;
    i++;
  }
  if(e>0)cout<<-1<<endl;
  
  else cout<<k<<endl;
 
}
