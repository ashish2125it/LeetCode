class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> ballColor;
        unordered_set<int> distinctColors;
        vector<int> result;

    for (const auto& query : queries) {
        int ball = query[0];
        int color = query[1];
        if (ballColor.find(ball) != ballColor.end()) {
            int oldColor = ballColor[ball];
            bool colorStillExists = false;
            for (const auto& pair : ballColor) {
                if (pair.second == oldColor && pair.first != ball) {
                    colorStillExists = true;
                    break;
                }
            }
            if (!colorStillExists) {
                distinctColors.erase(oldColor);
            }
        }
        ballColor[ball] = color;
        distinctColors.insert(color);
        result.push_back(distinctColors.size());
    }

    return result;
    }
};