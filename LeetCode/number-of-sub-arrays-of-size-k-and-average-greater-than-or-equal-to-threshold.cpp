// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/submissions/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // we use a sliding window approach
        int count = 0;
        float avg = 0;
        for(int i = 0; i < k - 1; ++i) {
                avg += arr[i];
            }
        for(int i = k - 1; i < arr.size(); ++i) {
            avg += arr[i];
            if(avg / k >= threshold) {
                count++;
            }
            // remove the starting element i.e. current_pos - (k - 1)
            avg -= arr[i - k + 1];
            
        }
        return count;
    }
};