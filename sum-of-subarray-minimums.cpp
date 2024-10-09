#define ll long long
class Solution {
public:
    vector<int> next_smaller_index(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, n);
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty())
                s.push(i);
            else {
                while (!s.empty() && arr[i] < arr[s.top()])
                    s.pop();
                if (!s.empty())
                    ans[i] = s.top();
                s.push(i);
            }
        }
        return ans;
    }

    vector<int> prev_smaller_index(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (s.empty())
                s.push(i);
            else {
                while (!s.empty() && arr[i] <= arr[s.top()])
                    s.pop();
                if (!s.empty())
                    ans[i] = s.top();
                s.push(i);
            }
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        vector<int> next_index = next_smaller_index(arr, n);
        vector<int> small_index = prev_smaller_index(arr, n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i - small_index[i];
            int right = next_index[i] - i;
            ans = (ans + static_cast<ll>(left) * right * arr[i]) % mod;
        }

        return static_cast<int>(ans);
    }
};