#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        int q;
        cin >> q;

        vector<int> prefix_s(n + 1, 0), prefix_t(n + 1, 0);

        // Compute prefix sums for 's' and 't'
        for (int i = 1; i <= n; ++i) {
            prefix_s[i] = prefix_s[i - 1] + (s[i - 1] == '1');
            prefix_t[i] = prefix_t[i - 1] + (t[i - 1] == '1');
        }

        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l; // Convert to 0-based indexing
            // Get the number of '1's in the substring s[l...r]
            int ones_in_s = prefix_s[r] - prefix_s[l];
            // Get the number of '1's in the substring t[l...r]
            int ones_in_t = prefix_t[r] - prefix_t[l];

            // Calculate the total number of elements in the range [l...r]
            int length = r - l;

            // The maximum number of '1's we can have in s[l...r] is:
            // The minimum between the length of the substring and the total number of '1's in both s and t
            int max_ones = min(length, ones_in_s + ones_in_t);
            cout << max_ones << '\n';
        }
    }

    return 0;
}
