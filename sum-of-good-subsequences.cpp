class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& array) {
       int dd = 1e9 + 7;
long long fans = 0;
vector<long long> cnt(100001, 0);
vector<long long> sss(100001, 0);

for (auto numbers : array) {
    long long cur_cnt = 1;
    long long cur_sum = numbers;
    
    if (numbers > 0) {
        cur_cnt = (cur_cnt + cnt[numbers - 1]) % dd;
    }
    if (numbers < 100000) {
        cur_cnt = (cur_cnt + cnt[numbers + 1]) % dd;
    }
    if (numbers > 0) {
        cur_sum = (cur_sum + sss[numbers - 1] + ((long long)cnt[numbers - 1] * numbers) % dd) % dd;
    }
    if (numbers < 100000) {
        cur_sum = (cur_sum + sss[numbers + 1] + ((long long)cnt[numbers + 1] * numbers) % dd) % dd;
    }
    
    fans = (fans + cur_sum) % dd;
    cnt[numbers] = (cnt[numbers] + cur_cnt) % dd;
    sss[numbers] = (sss[numbers] + cur_sum) % dd;
}

  return fans;

    }
};