// https://leetcode.com/problems/restore-ip-addresses/submissions/

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> restoredIPs;

        // will store the partial segments of the IP address being formed
        vector<string> addressSegments;
        restoreIPs(restoredIPs, addressSegments, 0, s);
        return restoredIPs;
    }

    void restoreIPs(vector<string> &restoredIPs, vector<string> &addressSegments, int buildIndex, string &rawString)
    {

        // if you have got 4 segments completed, and the buildIndex 1 past the last possible index of string s.
        if (addressSegments.size() == 4 && buildIndex == rawString.size())
        {

            // Push the finished IP address, by combining all the addressSegments
            restoredIPs.push_back(addressSegments[0] + "." + addressSegments[1] + "." + addressSegments[2] + "." + addressSegments[3]);
            return;
        }
        else if (addressSegments.size() == 4 || buildIndex >= rawString.size())
        {
            // In case you already have 4 address segments but you aren't done parsing the entire string
            // or you are out of characters to parse, but still haven't gotten 4 segments
            // return/backtrack as this isn't a valid path
            return;
        }

        // Generate segments to try, a segment can be 1 to 3 characters long
        for (int segLength = 1; segLength <= 3; ++segLength)
        {

            // get the segment in the form a string
            string segment = rawString.substr(buildIndex, segLength);
            // get the integer equivalent of the segment
            int segmentValue = stoi(segment);

            // check if the segment is valid, if it isn't - break out of the current path
            if (segmentValue > 255 || (segLength >= 2 && segment[0] == '0'))
            {
                break;
            }

            // push in the current segment
            addressSegments.push_back(segment);

            // recurse forward to parse the rest of the string, and build the rest of the IP
            restoreIPs(restoredIPs, addressSegments, buildIndex + segLength, rawString);

            // pop out the current segment, and continue with other possibilities
            addressSegments.pop_back();
        }
    }
};