// https://leetcode.com/problems/flood-fill/
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int src = image[sr][sc];
        if (image[sr][sc] != newColor)
        {
            flood(image, sr, sc, src, newColor);
        }
        return image;
    }

    void flood(vector<vector<int>> &image, int sr, int sc, int src, int newColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != src)
        {
            return;
        }
        image[sr][sc] = newColor;
        int moveX[] = {-1, 1, 0, 0}, moveY[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i)
        {
            flood(image, sr + moveX[i], sc + moveY[i], src, newColor);
        }
    }
};