class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>remainderindex;
        remainderindex[0]=-1;
        int prefixsum=0;
        for(int i = 0; i < nums.size(); i++)
        {
            prefixsum += nums[i];
            int remainder= prefixsum % k;
            if(remainder<0) remainder+=k;
            if(remainderindex.find(remainder)!=remainderindex.end())
            {
                if(i-remainderindex[remainder]>=2)
                {
                    return true;
                }
            }
                else
                {
                    remainderindex[remainder]=i;
                }
            
        }
        return false;
        
    }
};