class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {

            // Partition the array from left to right and
            // find where the selected pivot belongs
            int pivotFinalRestingPosition = partition(nums, left, right);

            // Call the quicksort to the left and the right
            // of the pivot
            quickSort(nums, left, pivotFinalRestingPosition - 1);
            quickSort(nums, pivotFinalRestingPosition + 1, right);
        }
    }

    int partition(vector<int> &nums, int left, int right)
    {

        // We're choosing the pivot as the right most item
        int pivot = nums[right];

        // i will keep track of the section smaller than
        // the pivot, so that in the end we can sandwich the
        // pivot between the section less than it and the section
        // greater than it
        int i = left - 1;

        // j will scan for us
        for (int j = left; j < right; ++j)
        {
            if (nums[j] <= pivot)
            {

                // Move i forward so that we can swap the value at j
                // into the tail of the items less than the pivot
                i++;

                // Execute the swap. We "throw" the item at j back into
                // the section of items less than the pivot
                swap(nums[i], nums[j]);
            }
        }

        // Swap the pivot value right after the section of items less than
        // the pivot. i keeps the tail of this section
        swap(nums[i + 1], nums[right]);

        return i + 1; // Return the pivot's final resting place
    }
};