#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    int mxsm=INT_MIN,sum=0,start=0,s=0,end=0;
    for(int i=0;i<n;i++){
        if(sum<=0){
            sum=a[i];
            s=i;
        }
        else{
            sum+=a[i];
        }
        if(sum>mxsm){
            mxsm=sum;
            start=s;
            end=i;
        }
    }
    cout<<"max sum:"<<mxsm<<"\nsubarray:";
    for(int i=start;i<=end;i++){
        cout<<a[i]<<" ";
    }




}
