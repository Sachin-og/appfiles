#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(vector<int> &vot) {
    int n = vot.size();
    vector<int> great(n);
    vector<int> prefSum(n);

    great[n-1] = vot[n-1];
    prefSum[0] = vot[0];
    int maxi = 0;
    for (int i = n-2; i >= 0; i--) {
        great[i] = max(vot[i], great[i+1]);
    }
    

    for (int i = 1; i < n; i++) {
        prefSum[i] = vot[i] + prefSum[i-1];
        if(vot[i]>vot[maxi]){
            maxi = i;
        }
    }
    for (int i = 0; i < n; i++) {
        int num_votes = vot[i];
        if (vot[i] >= great[0]&&i<=maxi) {
            cout << 0 << " ";
        } else {
            if(prefSum[i]>=great[0]){
                cout<<i<<" ";
            }
            else{
                cout<<i+1<<" ";
            }
        }
    }
    cout << endl;
    return;
}

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        int n, c;
        cin >> n >> c;
        vector<int> voters(n);
        for (int i = 0; i < n; i++) {
            cin >> voters[i];
        }
        voters[0] += c;  // Update the first element with additional votes
        solve(voters);
        //cout <<
    }
    return 0;
}
