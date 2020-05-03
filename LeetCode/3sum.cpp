// https://leetcode.com/problems/3sum/
// https://leetcode.com/problems/3sum/discuss/281302/JavaScript-with-lots-of-explanatory-comments!
// https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;

        // if the array size is < 3 then obv there's no solution
        if (nums.size() < 3)
        {
            return res;
        }

        /*
        * Sorting the array makes the question a lot simpler
        * And as the solution is anyway at O(n*n), we can afford this O(nlogn) computation
        */
        sort(nums.begin(), nums.end());

        // If the question gives a custom target, we can handle it here
        int target = 0;

        for (int i = 0; i < nums.size() - 2; ++i)
        {

            /*
            * i represents the leftmost number in our sorted set.
            * once this number exceeds the value of target, there is
            * no way that we add bigger numbers to the right of it to make
            * it add up to the required result
            */
            if (nums[i] > target)
            {
                break;
            }

            /*
            * skip all the duplicate values, as the might lead to duplicate tripletes
            * for instance [-2, -2, -2, 0, 4] with target 0 will give {{-2, -2, 4}, {-2, -2, 4}}
            */
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int front = i + 1;
            int rear = nums.size() - 1;

            while (front < rear)
            {
                int sum = nums[i] + nums[front] + nums[rear];

                if (sum == target)
                {
                    // Push the result into the array
                    res.push_back({nums[i], nums[front], nums[rear]});

                    /*
                    * keep moving the front and rear pointers forward and backwards, respectively
                    * until the are encountering duplicate values. Otherwise, we'll end up
                    * with duplicate sets in the result
                    * Example:
                    * An input array of [-2,0,0,2,2] would result in
				    * [[-2,0,2], [-2,0,2]].
                    */
                    while (front + 1 < nums.size() && nums[front] == nums[front + 1])
                        front++;
                    while (rear > 0 && nums[rear] == nums[rear - 1])
                        rear--;

                    // finally move the front and rear pointers to the next unique numbers
                    front++, rear--;
                }
                else if (sum < target)
                {
                    // if the sum was smaller than target, move the front pointer forward
                    front++;
                }
                else
                {
                    // if the sum was greater than the target, move the rear pointer back;
                    rear--;
                }
            }
        }
        return res;
    }
};