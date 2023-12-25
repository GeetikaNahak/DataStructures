#include<bits/stdc++.h>
using namespace std;

int tillingWays(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return tillingWays(n-1)+tillingWays(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<tillingWays(n)<<endl;
}