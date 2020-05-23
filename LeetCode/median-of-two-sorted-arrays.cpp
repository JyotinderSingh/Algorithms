// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://github.com/mission-peace/interview/blob/master/src/com/interview/binarysearch/MedianOfTwoSortedArrayOfDifferentLength.java
// https://www.youtube.com/watch?v=LPFhl65R7ww
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        // if nums1 length is greater than switch them so that nums1 is smaller than nums2.
        if (nums1.size() > nums2.size())
        {
            //
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();

        // First partition position can before any element
        int low = 0;
        // Last partition position can be after the (x - 1)'th element
        int high = x;

        while (low <= high)
        {
            int partitionX = low + ((high - low) / 2);

            /*
            * We want to partition the arrays in such a way that 
            * partitionX + partitionY = (total no. of elements) / 2
            * [as partition value is indirectly also equal to number of elements 
            * on the left of that point]
            * we add a 1 to x+y just to make the calculation a little easier in both the cases
            * of even and odd number of total elements
            */
            int partitionY = ((x + y + 1) / 2) - partitionX;

            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX)
            {

                /*
                * We have partitioned array at correct place
                * Now get max of left elements and min of right elements to get 
                * the median in case of even length combined array size
                * or get max of left for odd length combined array size.
                */
                if ((x + y) % 2 == 0)
                {
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                }
                else
                {
                    return (double)max(maxLeftX, maxLeftY);
                }
            }
            else if (maxLeftX > minRightY)
            {
                // we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            }
            else
            {
                // we are too far on left side for partitionX. Go on right side.
                // i.e. maxLeftY > minRightX
                low = partitionX + 1;
            }
        }
        return -1;
    }
};