#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number of vertex:";
    cin>>n;
    int g[100][100];
    cout<<"adjacency matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    int s;
    cout<<"enter source:";
    cin>>s;
    int d[100],vi[100];
    for(int i=0;i<n;i++){
        d[i]=9999;
        vi[i]=0;
    }
    d[s]=0;
    for(int k=0;k<n-1;k++){
        int u=-1,mn=9999;
        for(int i=0;i<n;i++){
            if(!vi[i]&& d[i]<mn){
                mn=d[i];
                u=i;
            }
        }
        vi[u]=1;
    for(int v=0;v<n;v++){
        if(g[u][v]&&!vi[v]&&d[u]+g[u][v]<d[v]){
            d[v]=d[u]+g[u][v];
        }
    }
    }
    cout<<"\nvertex\t\t distance:";
    for(int i=0;i<n;i++){
        cout<<i<<"\t\t"<<d[i]<<endl;
    }


}

