class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n = int(a.size());
        vector <long long> pref(n + 1 , 0);
        pref[0] = 0LL;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i - 1];
        }
        long long need = accumulate(a.begin() , a.end() , 0LL) - x;
        if (pref[n] == x) {
            return n;
        }
        if (x > pref[n]) {
            return -1;
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int s = i + 1 , e = n;
            int L = -1;
            while (s <= e) {
                 int m = (s + e) / 2;
                 if (pref[m] - pref[i] == need) {
                     L = m;
                     break;
                 } else if (pref[m] - pref[i] < need) {
                      s = m + 1;
                 } else {
                      e = m - 1;
                 }
            }
            if (L != -1) {
                ans = min(ans , i + n - L);
            }
        }
        if (ans == INT_MAX) {
            ans = -1;
        }
        return ans;
    }
};