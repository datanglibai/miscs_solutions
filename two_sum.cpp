class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        bool found = false;
        for (int i = 0; i < nums.size()&&!found; i++)
        {
           //if(nums[i] > target) continue;
           for(int j = i +1;j < nums.size(); j++)
           {
               if(nums[i] + nums[j]==target)
               {
                   result[0] = i;
                   result[1] = j;
                   found = true;
                   break;
               }
               
           }
            
        }
        return result;
        
    }
};
