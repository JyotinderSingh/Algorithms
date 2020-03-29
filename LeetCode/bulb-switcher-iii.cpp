// https://leetcode.com/problems/bulb-switcher-iii/
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        long long int sum = 0;
        long long int count = 0;
        for(long long int i = 0; i < light.size(); ++i) {
            sum += light[i];
            if(sum == (i + 1) * (i + 2) / 2) {
                count++;
            }
        }
        return count;
    }
};

