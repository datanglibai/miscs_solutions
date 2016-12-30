#include "iostream";
#include <vector>;
#include <string>
using namespace std;

/*
test cases: 
[ 2, -1, 1, -2, -2 ] false
[ 1, 2, 3, 4, 5 ] true
The problem description in leet code is really easy to be misunderstood, it is not only checking the loop, but also checking directions.
Forwarding means all steps (value in nums) are all positive.
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
 
        if(nums.size() < 2) return false;
        
        vector<int> indexes;
        int nextIndex = 0;
        indexes.push_back(nextIndex);
        int length = nums.size();
        
        while(true)
        {
            nextIndex = (nextIndex + nums[nextIndex]) % length;
            if (nextIndex < 0) nextIndex += length;
            
            vector<int>::iterator iter = std::find(indexes.begin(), indexes.end(), nextIndex);
            if ( iter == indexes.end())
            {
                indexes.push_back(nextIndex);
                
            }
            else if (distance(indexes.begin(), iter) >= indexes.size() - 2)
                return false;
            else
            {
                bool forwading = nums[*iter] >0 ? true : false;
                for (vector<int>::iterator it = iter; it != indexes.end(); it++)
                {
                    if (forwading && nums[*it] < 0) return false;
                    if (!forwading && nums[*it] > 0) return false;                
                }
                return true;
            }
            
        }
        
    }
};
