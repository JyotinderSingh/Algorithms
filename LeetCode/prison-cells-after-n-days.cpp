// https://leetcode.com/problems/prison-cells-after-n-days/submissions/
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        vector<int> curr(cells.size());
        vector<vector<int>> seen;

        // We change N, because unless we do that, and if we rather try to use a for loop
        // from 0 to N - 1, this will lead to a situation where some weird corner cases can arise
        // For instance, if we are asked the state after 1 state change (not the best example to explain this
        // but it helps with the understanding), then we'll return the element
        // at the 1'th index, rather than the one at the 0th index (remember that the intial starting
        // state isn't being pushed in) if we decide to use the original value of N, and do an N & seen.size() operation.
        //
        // So rather than this, you can either use a while loop that decrements the value of N as it goes
        // or you can run another loop from 0 to N - 1 after the main for loop.
        while (N--)
        {
            for (int k = 1; k < cells.size() - 1; ++k)
            {
                // update current cell
                curr[k] = cells[k - 1] == cells[k + 1] ? 1 : 0;
            }

            // if you've seen this value before, it means you've just come back at the first element of the cycle
            // return the element at the (remaining number of iterations) % (cycle size) position
            if (seen.size() && seen.front() == curr)
                return seen[N % seen.size()];
            else
                seen.push_back(curr);

            //update the state
            cells = curr;
        }
        return cells;
    }
};