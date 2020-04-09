int kadane(int arr[], int num)
{
    int max_till_here = arr[0], max_so_far = 0;
    for (int i = 1; i < num; ++i)
    {
        max_till_here = max(arr[i], max_till_here + arr[i]);
        max_so_far = max(max_so_far, max_till_here);
    }
    return max_so_far;
}

int maxMoney(int arr[], int num)
{
    // case 1: in case the max sum is found without wrapping
    int max_non_wrapping = kadane(arr, num);

    // case 2: in case the maximum sum is found with wrapping
    // approach:
    // The elements which contribute to the maximum sum are arranged
    // such that wrapping is there.
    // Examples: {10, -12, 11}, {12, -5, 4, -8, 11}.
    // In this case, we change wrapping to non-wrapping. Let us see how.
    // Wrapping of contributing elements implies non wrapping of non contributing elements,
    // so find out the sum of non contributing elements and subtract this sum from the total sum.
    // To find out the sum of non contributing, invert sign of each element
    // and then run Kadane’s algorithm.
    // Our array is like a ring and we have to eliminate the
    // maximum continuous negative
    // that implies maximum continuous positive in the inverted arrays.
    int array_sum = 0;
    for (int i = 0; i < num; ++i)
    {
        array_sum += arr[i];
        // inverting the element to build the inverted array alongside.
        arr[i] = -arr[i];
    }
    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    int max_wrap = array_sum + kadane(arr, num);
    return max(max_non_wrapping, max_wrap);
}