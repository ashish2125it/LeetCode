class Solution {
public:
    bool isDivisible(int number, int divisor) {
        int product = 1;
        string numStr = to_string(number);
        for(int i = 0; i < numStr.length(); i++) {
            product *= (numStr[i] - '0');
        }
        return product % divisor == 0;
    }

    int smallestNumber(int start, int divisor) {
        while(true) {
            if(isDivisible(start, divisor)) return start;
            start++;
        }
        return -1;
    }
};
