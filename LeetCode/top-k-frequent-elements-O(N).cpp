// https://leetcode.com/problems/top-k-frequent-elements/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
		// create a frequency map
        for (int i = 0; i < nums.size(); ++i)
        {
            freq[nums[i]]++;
        }
        vector<pair<int, int>> elements;
		// copy the elements into an array for quickselect procedure
        for (auto &p : freq)
        {
            elements.push_back(make_pair(p.first, p.second));
        }
        int n = elements.size();
        int finalIndexOfChosenPivot;
        int left = 0, right = n - 1;
        while (left <= right)
        {
			// choose a random pivot
            int chosenPivotIndex = (rand() % (right - left + 1)) + left;
			// get that pivot element's final position in the array
            finalIndexOfChosenPivot = partition(elements, left, right, chosenPivotIndex);

			// basic binary search
			
			/*
			* if the final position of the pivot is n - k, that means all the elements to the right
			* of the pivot (K in number), are the answer
			* This is because after partitioning, all elements to the left have freq < freq[pivot]
			* and all elements to the right of the pivot have freq >= freq[pivot]
			*/
            if (finalIndexOfChosenPivot == n - k)
            {
                break;
            }
            else if (finalIndexOfChosenPivot > n - k)
            {
                right = finalIndexOfChosenPivot - 1;
            }
            else
            {
                left = finalIndexOfChosenPivot + 1;
            }
        }
        vector<int> res(k);

        int x = 0;
        for (int i = finalIndexOfChosenPivot; i < n; ++i)
        {
            res[x++] = elements[i].first;
        }
        return res;
    }
	// The same strategy as quicksort
    int partition(vector<pair<int, int>> &elements, const int &left, const int &right, const int &pivotIndex)
    {

        auto pivotValue = elements[pivotIndex];
        swap(elements[pivotIndex], elements[right]);
        int lesserItemsTailIndex = left - 1;

        for (int i = left; i < right; ++i)
        {
			// compare with respect to the frequency
            if (elements[i].second < pivotValue.second)
            {
                lesserItemsTailIndex++;
                swap(elements[lesserItemsTailIndex], elements[i]);
            }
        }
		
		// swap pivot back to its final position
        lesserItemsTailIndex++;
        swap(elements[lesserItemsTailIndex], elements[right]);

        return lesserItemsTailIndex;
    }
};

