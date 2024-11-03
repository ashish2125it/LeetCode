#define ll long long
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mo) {
        int n = mo.size(), m = mo[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

      
        priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>, greater<>> pq;
        pq.push({0, 0, 0, 0}); 
        vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(m, vector<ll>(2, LLONG_MAX)));
        dist[0][0][0] = 0;

        while (!pq.empty()) {
            auto [distance, x, y, move] = pq.top();
            pq.pop();

            ll cost = (move == 0) ? 1 : 2;

            for (int i = 0; i < 4; i++) {
                ll new_x = x + dx[i];
                ll new_y = y + dy[i];
                int new_move = move ^ 1; 
               
                if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m) {
                    ll new_distance = max(distance + cost, mo[new_x][new_y] + cost);

                    if (dist[new_x][new_y][new_move] > new_distance) {
                        dist[new_x][new_y][new_move] = new_distance;
                        pq.push({new_distance, new_x, new_y, new_move});
                    }
                }
            }
        }

      
        return min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    }
};
