#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        ll max_profit = 0;
        int limit = min(n, b);
        
        for (ll k = 0; k <= limit; ++k) {
            ll modified_price_profit = (k * (2 * b - k + 1)) / 2;
            ll usual_price_profit = (n - k) * a;
            ll total_profit = modified_price_profit + usual_price_profit;
            max_profit = max(max_profit, total_profit);
        }
        
        cout << max_profit << "\n";
    }
    
    return 0;
}
