// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        /*
        * The main point to be kept in mind is that the k'th largest element
        * will be present at the (n - k)'th position in the array 
        * Keep track of the 'left' and 'right' space in which the 
        * k'th largest element can possible be, we will use these bounds
        * to know what section to actually partition around a chosen pivot
        */

        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // While the bounds stay valid continue doing directed partitioning
        while (left <= right)
        {
            // Pick a random pivot in bounds [left, right]
            int chosenPivotIndex = (rand() % (right - left + 1)) + left;

            /*
            * Execute the actual partitioning and get back the final position
            * of the pivot we choose after the partitioning is over
            */
            int finalIndexOfChosenPivot = partition(nums, left, right, chosenPivotIndex);

            // What does the 'finalIndexOfChosenPivot' tell us?
            if (finalIndexOfChosenPivot == n - k)
            {
                /*
                * Found. The pivot is on index n - k. This is literally its final position
                * if the array we were given had been sorted. See how we saved work? We don't
                * need to sort the whole array
                */
                return nums[finalIndexOfChosenPivot];
            }
            else if (finalIndexOfChosenPivot > n - k)
            {
                /*
                * k'th largest must be in the left partition. We "overshot" and need to
                * go left (and we do this by narrowing the right bound)
                */
                right = finalIndexOfChosenPivot - 1;
            }
            else
            {
                /*
                * k'th largest must be in the right partition. We "undershot" and need to
                * go right (and we do this by narrowing the left bound)
                */
                left = finalIndexOfChosenPivot + 1;
            }
        }

        // return 0 written just to avoid warnings
        return 0;
    }

    /*
    * So this subroutine is exactly what we do in QuickSort - partition around the value
    * that the 'pivotIndex' holds
    * Result is [items < pivot....pivot....items > pivot]
    */
    int partition(vector<int> &nums, int left, int right, int pivotIndex)
    {
        // Grab the value at the index we passed in
        int pivotValue = nums[pivotIndex];

        int lesserItemsTailIndex = left;

        /* Move the item at 'pivotIndex' OUT OF THE WAY. We are about to
        * bulldoze through the partition space and we don't want it in
        * the way
        */
        swap(nums[pivotIndex], nums[right]);

        for (int i = left; i < right; ++i)
        {
            if (nums[i] < pivotValue)
            {
                swap(nums[i], nums[lesserItemsTailIndex]);
                lesserItemsTailIndex++;
            }
        }

        swap(nums[lesserItemsTailIndex], nums[right]);
        return lesserItemsTailIndex;
    }
};