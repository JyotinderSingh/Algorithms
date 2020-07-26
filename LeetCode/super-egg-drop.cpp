// https://leetcode.com/problems/super-egg-drop/



//////////////////////////////////////////////
/////// CORRECT APPROACH BUT GIVES TLE ///////
//////////////////////////////////////////////

class Solution
{
public:
    int superEggDrop(int totalEggs, int totalFloors)
    {
        vector<vector<int>> dp(totalEggs + 1, vector<int>(totalFloors + 1));
        for (int floor = 0; floor <= totalFloors; ++floor)
        {
            dp[1][floor] = floor;
        }

        int temp = 0;
        for (int eggs = 2; eggs <= totalEggs; ++eggs)
        {
            for (int floor = 1; floor <= totalFloors; ++floor)
            {
                dp[eggs][floor] = INT_MAX;

                for (int attemptFloor = 1; attemptFloor <= floor; ++attemptFloor)
                {
                    temp = 1 + max(dp[eggs - 1][attemptFloor - 1], dp[eggs][floor - attemptFloor]);
                    if (temp < dp[eggs][floor])
                    {
                        dp[eggs][floor] = temp;
                    }
                }
            }
        }
        return dp[totalEggs][totalFloors];
    }
};

//////////////////////////////////////////////
/////// CORRECT APPROACH BUT GIVES TLE ///////
//////////////////////////////////////////////

#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
class Solution
{
public:
    int superEggDrop(int totalEggs, int totalFloors)
    {
        /*
         We do +1 to index off of 1. So that the final answer that
         we want will be at cache[totalEggs][totalFloors]...remember
         we index off of 0 so this is for convenience
         cache[totalEggs][totalFloors] is literally the answer to the
         subproblem given those literal amounts...'totalEggs' and
         'totalFloors'
        */
        int cache[totalEggs + 1][totalFloors + 1];

        /*
         If we have 0 floors we need 0 trials, no matter the egg amount given
         If we have 1 floor we need 1 trial, no matter the egg amount given
        */
        for (int eggs = 1; eggs <= totalEggs; ++eggs)
        {
            cache[eggs][0] = 0;
            cache[eggs][1] = 1;
        }

        /*
          If we have 1 egg...no matter what floors we get, our approach will
          be to do 'floorAmount' drops...this is because we want to start from
          floor 1, drop...then go to floor 2, drop...and so on until we get to
          in the worst case 'floorAmount'
          
          Remember, we want to know the minimum amount of drops that will always
          work. So we want to MINIMIZE...to the absolute LEAST...worst...amount
          of drops so that our drop count ALWAYS works
          
          Any worse then the MINIMIZED WORST will be suboptimal
        */
        for (int floor = 1; floor <= totalFloors; floor++)
        {
            cache[1][floor] = floor;
        }

        /*
         Solve the rest of the subproblems now that we have the base cases defined for us
        */
        for (int eggs = 2; eggs <= totalEggs; ++eggs)
        {
            for (int floor = 2; floor <= totalFloors; ++floor)
            {
                /*
                 Initialize the value of this subporblem to a very large
                 value that will be easily overtaken and provide a hard upper
                 comparison wall
                */
                cache[eggs][floor] = INT_MAX;

                /*
                 We do a theoretical test on every floor from 1 to the 'floor'
                 amount for this subproblem
                */
                for (int attemptFloor = 1; attemptFloor <= floor; ++attemptFloor)
                {
                    /*
                     We want to know the cost of the 2 outcomes:
                     1.) We drop an egg and it breaks.
                         We move 1 floor down. We have 1 less egg.
                     2.) We drop an egg and it doesn't break.
                         We have this many floors left: 
                         the difference between the total floors and our current floor.
                         We have the same number of eggs.
                    */
                    int costOfWorstOutcome = max(cache[eggs - 1][attemptFloor - 1], cache[eggs][floor - attemptFloor]);

                    /*
                     After we get the cost of the WORST outcome we add 1 to that worst outcome
                     to simulate the fact that we are going to do a test from THIS subproblem.
                     The answer to this problem is 1 PLUS the cost of the WORST SITUATION that
                     happens after our action at this subproblem.
                    */
                    int accountingForDroppingAtThisSubproblem = 1 + costOfWorstOutcome;

                    /*
                     Did we reach a BETTER (lower) amount of drops that guarantee that we can
                     find the pivotal floor where eggs begin to break?
                    */
                    cache[eggs][floor] = min(cache[eggs][floor], accountingForDroppingAtThisSubproblem);
                }
            }
        }
        /*
         Remember we added +1 so we are indexed off of 1 now. We can reap our answer from
         cache[totalEggs][totalFloors] instead of cache[totalEggs - 1][totalFloors - 1]
        */
        return cache[totalEggs][totalFloors];
    }
};