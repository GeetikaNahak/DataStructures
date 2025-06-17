#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,q;cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    while(q--){
      int s,e;cin>>s>>e;
      s=s-1;e=e-1;
      int &mx=*max_element(v.begin()+s,v.begin()+e);
      cout<<mx<<endl;
    }
    return 0;
}