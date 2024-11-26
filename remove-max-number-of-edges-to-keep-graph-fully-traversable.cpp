#include <vector>
#include <algorithm>
using namespace std;

class DSU {
    vector<int> par, rank;
public:
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) par[i] = i;
    }

    int find_par(int node) {
        if (node == par[node]) return node;
        return par[node] = find_par(par[node]);
    }

    void union_find(int node1, int node2) {
        int U_par1 = find_par(node1);
        int U_par2 = find_par(node2);
        if (U_par1 != U_par2) {
            if (rank[U_par1] == rank[U_par2]) {
                par[U_par1] = U_par2;
                rank[U_par2]++;
            } else if (rank[U_par1] > rank[U_par2]) {
                par[U_par2] = U_par1;
            } else {
                par[U_par1] = U_par2;
            }
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        sort(e.begin(), e.end());
        reverse(e.begin(), e.end());

        DSU bob(n);
        DSU alice(n);

        int remove = 0;
        int alice_edge = 0, bob_edge = 0;

        for (int i = 0; i < e.size(); i++) {
            int type = e[i][0];
            int e1 = e[i][1];
            int e2 = e[i][2];

            if (type == 3) { // Common edge for both Alice and Bob
                if (alice.find_par(e1) == alice.find_par(e2) && bob.find_par(e1) == bob.find_par(e2)) {
                    remove++;
                } else {
                    if (alice.find_par(e1) != alice.find_par(e2)) {
                        alice.union_find(e1, e2);
                        alice_edge++;
                    }
                    if (bob.find_par(e1) != bob.find_par(e2)) {
                        bob.union_find(e1, e2);
                        bob_edge++;
                    }
                }
            } else if (type == 1) { // Edge for Alice
                if (alice.find_par(e1) == alice.find_par(e2)) {
                    remove++;
                } else {
                    alice.union_find(e1, e2);
                    alice_edge++;
                }
            } else if (type == 2) { // Edge for Bob
                if (bob.find_par(e1) == bob.find_par(e2)) {
                    remove++;
                } else {
                    bob.union_find(e1, e2);
                    bob_edge++;
                }
            }
        }

        // Both Alice and Bob must be fully connected
        if (alice_edge == n - 1 && bob_edge == n - 1) return remove;
        return -1;
    }
};
