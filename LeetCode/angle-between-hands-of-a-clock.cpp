// https://leetcode.com/problems/angle-between-hands-of-a-clock/
// https://leetcode.com/problems/angle-between-hands-of-a-clock/discuss/502738/JavaPythonC%2B%2B-Simple-Math-on-Clock-angles

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double hour_angle = (hour % 12 * 30) + (minutes * 0.5);
        double minute_angle = minutes * (360 / 60);
        double diff = abs(hour_angle - minute_angle);
        return diff > 360 - diff ? 360 - diff : diff;
    }
};