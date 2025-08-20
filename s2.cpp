#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Error opening file!\n";
        return 1;
    }
    
    int n;
    inputFile >> n;
    int BT[n], TAT[n], WT[n], process_id[n];
    for (int i = 0; i < n; i++) {
        process_id[i] = i + 1;
        inputFile >> BT[i];
    }
    inputFile.close();

    cout << "\nProcess\t\tBurst Time\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<process_id[i]<<"\t\t"<<BT[i]<<"\n";
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (BT[i] > BT[j]) {
                swap(BT[i], BT[j]);
                swap(process_id[i], process_id[j]);
            }
        }
    }
    
    int TT = 0;
    for (int i = 0; i < n; i++) {
        TT += BT[i];
        TAT[i] = TT;
    }
    
    int TWT = 0, TTAT = 0;
    for (int i = 0; i < n; i++) {
        WT[i] = TAT[i] - BT[i];
        TWT += WT[i];
        TTAT += TAT[i];
    }

    cout << "\nGantt Chart:\n";
    cout << "|";
    for (int i = 0; i < n; i++) {
        cout << " P" << process_id[i] << " |";
    }
    cout << "\n0";
    for (int i = 0; i < n; i++) {
        cout << "\t" << TAT[i];
    }

    cout << "\nAverage Waiting Time: " << (float)TWT / n << endl;
    cout << "Average Turnaround Time: " << (float)TTAT / n << endl<<endl;

    return 0;
}
