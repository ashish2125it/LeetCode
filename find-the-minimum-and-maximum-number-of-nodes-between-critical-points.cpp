class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);

        // Edge case: Less than three nodes
        if (!head || !head->next || !head->next->next) return ans;

        ListNode* prev = head;              // First node
        ListNode* curr = head->next;        // Second node
        ListNode* next = curr->next;        // Third node
        vector<int> criticalPoints;         // Stores the positions of critical points

        int pos = 2;  // Current position in the list (1-based indexing)

        // Traverse the list
        while (next) {
            // Check if `curr` is a critical point
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(pos);
            }

            // Move pointers forward
            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }

        // If less than 2 critical points, return [-1, -1]
        if (criticalPoints.size() < 2) return ans;

        // Calculate minimum and maximum distances
        int minDist = INT_MAX;
        for (int i = 0; i < criticalPoints.size() - 1; i++) {
            minDist = min(minDist, criticalPoints[i + 1] - criticalPoints[i]);
        }
        int maxDist = criticalPoints.back() - criticalPoints.front();

        ans[0] = minDist;
        ans[1] = maxDist;

        return ans;
    }
};
