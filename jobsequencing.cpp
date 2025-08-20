#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter no of job:";
    cin>>n;
    char job[100];
    int d[100],p[100];
    cout<<"job,deadline,profit:"<<endl;
    for(int i=0;i<n;i++){
        cin>>job[i]>>d[i]>>p[i];
    }

    // sort by profit descending
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i]<p[j]){
                swap(p[i],p[j]);
                swap(d[i],d[j]);
                swap(job[i],job[j]);
            }
        }
    }

    // find maximum deadline
    int mxd = 0;
    for(int i=0;i<n;i++){
        mxd = max(mxd, d[i]);
    }

    char res[100];
    bool slot[100]={false};
    for(int i=0;i<mxd;i++){
        res[i]='-';
    }

    // job scheduling
    for(int i=0;i<n;i++){
        for(int j=d[i]-1;j>=0;j--){
            if(!slot[j]){
                slot[j]=true;
                res[j]=job[i];
                break;
            }
        }
    }

    cout<<"job scheduled: ";
    for(int i=0;i<mxd;i++){
        if(res[i]!='-'){
            cout<<res[i]<<" ";
        }
    }
    cout<<endl;

}
