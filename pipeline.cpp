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
 

ll sum(ll k){
    return (k*(k+1))/2;

}
ll sum( ll s , ll e){
    if(s<=1){
        return sum(e);
    }
    else{
        return sum(e)-sum(s-1);
    }
}
ll minSplitt(ll k , ll n){
    ll st =1;
    ll en = k;
    ll ans = 0;
    while(st <= en)
	{
		ll md = (st + en)/2;
		ll s = sum(md, en);
        if( s== n){
            ans += en-md+1;
            n -= s;
        }
        else if(s > n){
            st = md +1;
        }
        else{
            n = n - s;
            ans += (en-md+1);
            en = md -1;
        }
    }
    if(n==0) return ans ;
    else return ans +1;
}
int main()
{
    fast_cin();
    ll n,k;
    cin>>n>>k;
    if(n==1) cout<< 0;
    else if(n<=k) cout<< 1;
    else{
        k--;
        n--;
        if(sum(k) < n){
            cout<<-1;

        }
        else if(sum(k)== n) cout<<k<<endl;
        else{
            cout<<minSplitt(k,n);
        }
    }

    return 0;
}