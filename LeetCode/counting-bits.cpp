// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        
        /* Brian Kernighan’s Algorithm
        * 1  Initialize count: = 0
        *
        * 2  If integer n is not zero
        *   (a) Do bitwise & with (n-1) and assign the value back to n
        *       n: = n&(n-1)
        *   (b) Increment count by 1
        *   (c) go to step 2
        *
        * 3  Else return count
        */
        vector<int> res;
        for(int i = 0; i <= num; ++i){
            int n = i;
            int count = 0;
            while(n){
                n &= (n - 1);
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};

////////////////////////////////////////////////

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num);
        res.push_back(0);
        for (int i = 1; i <= num; ++i)
        {
            res[i] = res[i / 2] + i % 2;
        }
        return res;
    }
};

//////////////////////////////////////////////
