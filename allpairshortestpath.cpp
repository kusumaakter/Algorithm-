#include<bits/stdc++.h>
using namespace std;
#define  INF 99999
#define MAX 20
void floydwarshall(int dist[MAX][MAX],int v){

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    cout<<"\n shortest distance matrix:";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dist[i][j]==INF){
                cout<<"INF  ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }

        }
        cout<<endl;
    }
  }

int main(){
    int v;
    int g[MAX][MAX];
    cout<<"Enter number of vertex:";
    cin>>v;
    cout<<"enter adjacency matrix :";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>g[i][j];
        }
    }
    floydwarshall(g,v);

}
