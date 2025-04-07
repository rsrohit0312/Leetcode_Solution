class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int finalsum=nums[0];
        int currentsum=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            
            if(nums[i]>nums[i-1])
              currentsum+=nums[i];

            else
            currentsum=nums[i];

           finalsum=max(finalsum, currentsum);   
        }
        return finalsum;

        
    }
};