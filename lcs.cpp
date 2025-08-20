#include <bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int mxln = 0;
    int endindx = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > mxln) {
                    mxln = dp[i][j];
                    endindx = i;
                }
            } else {
                dp[i][j] = 0;  // এখানে রাখতে হবে
            }
        }
    }

    if (mxln == 0) return "";
    return s1.substr(endindx - mxln, mxln);
}

int main() {
    string s1, s2;
    cout << "enter string1: ";
    cin >> s1;
    cout << "enter string2: ";
    cin >> s2;
    string res = lcs(s1, s2);
    cout << "longest common substring: " << res << endl;
}
