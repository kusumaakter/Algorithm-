#include<bits/stdc++.h>
using namespace std;
int binsearch(int a[],int l,int h,int x){
    if(l>h) return 0;
    int mid=(l+h)/2;
    if(x==a[mid]) return mid+1;
    else if(x<a[mid]) return binsearch(a,l,mid-1,x);
    else return binsearch(a,mid+1,h,x);

}
int main(){
    cout<<"enter number of data:";
    int n,x;cin>>n;
    int a[n];
    cout<<"enter dataset:";
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    cout<<"enter the number to search:";
    cin>>x;
    sort(a,a+n);
     cout << "Sorted Data set: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    int result=binsearch(a,0,n-1,x);
    if(result!=0){
        cout<<"element found at possition"<<result<<"."<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }

}
