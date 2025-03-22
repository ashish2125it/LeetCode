#define ll long long
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool solve(ll time, vector<int>& ranks, int cars) {
        ll car = 0;
        for (int i = 0; i < ranks.size(); i++) {
            ll rank = ranks[i];
            ll curr_cars = sqrt((double)time / rank);  // Avoid integer division issues
            car += curr_cars;
        }
        return car >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0, high = 1e14;  // Adjusted upper bound
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (solve(mid, ranks, cars)) {
                ans = mid;
                high = mid - 1;  // Try for smaller time
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
