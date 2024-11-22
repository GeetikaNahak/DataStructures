#include<bits/stdc++.h>
using namespace std;

int minDistance(int dist[],int sptset[],int n){
  int mn=INT_MAX,mnI;
  for(int i=0;i<n;i++){
    if(!sptset[i] && dist[i]<=mn){
      mn=dist[i];mnI=i;
    }
  }return mnI;
}

void dijkstras(vector<vector<int>>& graph,int src,int n){
  int dist[n],sptset[n];
  for(int i=0;i<n;i++){
    dist[i]=INT_MAX;sptset[i]=0;
  }
  dist[src]=0;
  for(int l=0;l<n-1;l++){
    int u=minDistance(dist,sptset,n);
    sptset[u]=1;
    for(int v=0;v<n;v++){
      if(!sptset[v] && dist[u]!=INT_MAX && graph[u][v] && dist[u]+graph[u][v]<dist[v]){
        dist[v]=dist[u]+graph[u][v];
      }
    }
  }
  
  for (int i = 0; i < n; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}



int main(){
  int n=9;
  vector<vector<int>>graph= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    dijkstras(graph, 0,n);
    
}
