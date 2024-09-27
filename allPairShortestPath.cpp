#include <bits/stdc++.h>
using namespace std;

int inf=INT_MAX;

void apsp(vector<vector<int>>&v,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(v[j][i]!=inf && v[i][k]!=inf)v[j][k]=min(v[j][k],v[j][i]+v[i][k]);
            }
        }
    }
}

void print(vector<vector<int>>&v,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]<inf)cout<<v[i][j]<<" ";
            else cout<<"- ";
        }cout<<endl;
    }
}

int main() {
    int n=4;
    vector<vector<int>>graph={
        {0, 5,inf,10},
        {inf,0,3,inf},
        {inf,inf,0,1},
        {inf,inf,inf,0}
    };
    print(graph,n);
    apsp(graph,n);
    print(graph,n);
    return 0;
}