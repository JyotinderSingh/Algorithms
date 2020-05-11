// https://leetcode.com/problems/find-the-town-judge/

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> score(N, 0);
        for (int i = 0; i < trust.size(); ++i)
        {
            score[trust[i][0] - 1]--;
            score[trust[i][1] - 1]++;
        }
        for (int i = 0; i < score.size(); ++i)
        {
            if (score[i] == N - 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

////////// SLOW NAIVE//////////////////////
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<pair<int, int>> degrees(N, {0, 0});
        for (int i = 0; i < trust.size(); ++i)
        {
            degrees[trust[i][0] - 1].first++;
            degrees[trust[i][1] - 1].second++;
        }

        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees[i].first == 0 && degrees[i].second == N - 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};