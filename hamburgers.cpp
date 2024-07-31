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
 

bool canMake(v64 have , v64 price, v64 per, ll r, ll mid){
    v64 req(3);
    forn(i,3){
        ll reqP = (mid*per[i]-have[i])*price[i] <=0?0:(mid*per[i]-have[i])*price[i] ;
        req[i] = reqP;
        r -= reqP;
    }
   if(r>= 0){
    return true;
    
   }
   else{
    return false;
   }
}
int main()
{
    fast_cin();
    string recipe;
    cin >> recipe;
    v64 have(3);
    cin>>have[0]>>have[1]>>have[2];
    v64 price(3);
    cin>>price[0]>>price[1]>>price[2];
    ll r;
    cin>>r;
    v64 perpc(3);
    forn(i,recipe.length()){
        if(recipe[i]=='B') perpc[0]++;
        if(recipe[i]=='C') perpc[2]++;
        if(recipe[i]=='S') perpc[1]++;
    }
    ll maxbur =0;
    if(perpc[0]){
    maxbur = (have[0]+r/price[0])/perpc[0];
    }
    else if(perpc[1]){
    maxbur = (have[1]+r/price[1])/perpc[1];
    }
    else{
    maxbur = (have[2]+r/price[2])/perpc[2];
    }
   
    ll s = 0;
    ll e = maxbur;
    ll mid = maxbur/2;
    ll ans = 0;
    while(s<=e){
        mid = (s+e)/2;
        if(canMake(have , price, perpc, r, mid)){
            ans = max(ans , mid);
            s= mid+1;
        }
        else{
            e = mid -1;
        }
    }
    cout<<ans <<endl;
    return 0;
}