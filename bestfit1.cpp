#include<bits/stdc++.h>
using namespace std;
int main(){
    int nb,np;
    int bs[100],ps[100],al[100];
    cout<<"enter number of block:";
    cin>>nb;
    cout<<"enter block size:";
    for(int i=0;i<nb;i++){
        cin>>bs[i];
    }
    cout<<"enter number of process:";
    cin>>np;
    cout<<"enter process:";
    for(int i=0;i<np;i++){
        cin>>ps[i];
        al[i]=-1;
    }
    for(int i=0;i<np;i++){
        int bestidx=-1;
        for(int j=0;j<nb;j++){
            if(bs[j]>=ps[i]){
                if(bestidx==-1||bs[j]<bs[bestidx]){


                bestidx=j;
            }
        }
    }
    if(bestidx!=-1){
        al[i]=bestidx;
        bs[bestidx]-=ps[i];
    }



}
cout<<"\nprocess no\tprocess size \tblock no\n";
for(int i=0;i<np;i++){
    cout<<""<<i+1<<"\t\t"<<ps[i]<<"\t\t";
    if(al[i]!=-1){
        cout<<al[i]+1;
    }
    else{
        cout<<"no allocated";

    }
     cout<<endl;


}


}
