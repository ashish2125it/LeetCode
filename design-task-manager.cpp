class TaskManager {
public:
    struct MaxHeapComparator {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        }
    };

    priority_queue<vector<int>, vector<vector<int>>, MaxHeapComparator> pq;
    unordered_map<int, int> mp; // Maps taskId -> priority
    unordered_map<int, int> U;  // Maps taskId -> userId

    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            if (task[1] >= 0) {
                mp[task[1]] = task[2];
                pq.push({task[2], task[1], task[0]}); // {priority, taskId, userId}
                U[task[1]] = task[0];
            }
        }
    }

    void add(int userId, int taskId, int p) {
        mp[taskId] = p;
        U[taskId] = userId;
        pq.push({p, taskId, userId});
    }

    void edit(int taskId, int ne) {
        if (mp.find(taskId) != mp.end()) {
            mp[taskId] = ne;
            pq.push({ne, taskId, U[taskId]});
        }
    }

    void rmv(int taskId) {
        if (mp.find(taskId) != mp.end()) {
            mp.erase(taskId);
            U.erase(taskId);
        }
    }

    int execTop() {
        while (!pq.empty() && (mp.find(pq.top()[1]) == mp.end() || mp[pq.top()[1]] != pq.top()[0])) {
            pq.pop(); // Remove stale entries
        }
        if (pq.empty()) return -1;

        int user = pq.top()[2];
        int task = pq.top()[1];
        pq.pop();
        mp.erase(task);
        U.erase(task);
        return user;
    }
};
