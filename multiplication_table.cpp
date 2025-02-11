#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

ll count(ll a, ll n , ll m){
    ll ans =0 ;
    forn(i,n){
        ll p = i+1;
        if(p*m < a){
            ans += m;
        }
        else{
            if(a%p)
            ans += a/p;
            else ans += (a/p -1);
        }
    }
    return ans ;
}
int main()
{
    fast_cin();
    ll n , m, k;
    cin >>n >>m >>k;
    ll s =1;
    ll e = n*m;
    while(s<= e){
        ll mid = (s+e)/2;
        ll cnt = count(mid , n, m);
        ll cnt2 = count(mid+1, n,m);
        if(cnt < k&& cnt2 >=k){
            cout<<mid<<endl;
            break;
        }
        else if(cnt2 < k){
            s = mid +1 ;
            }
        else{
            e = mid -1;
        }
    }
    return 0;
}