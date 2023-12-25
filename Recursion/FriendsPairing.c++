#include<bits/stdc++.h>
using namespace std;
int friendsPairing(int n){
    if(n==0 ||n==1 || n==2)return n;
    return friendsPairing(n-1)+friendsPairing(n-1)*(n-1);
}
int main(){
    int n;
    cout<<"Enter No. of Friends : ";
    cin>>n;
    cout<<endl<<friendsPairing(n)<<endl;
    return 0;
}