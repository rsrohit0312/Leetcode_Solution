class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count =0, prefixsum=0;
        unordered_map<int, int>remainder_count;
        remainder_count[0]=1;

        for(int num : nums)
        {
           prefixsum+=num;

           int remainder=prefixsum % k;
           if(remainder<0) remainder+=k;
           if(remainder_count.find(remainder)!= remainder_count.end())
                {
                count+=remainder_count[remainder];
                }
           
           remainder_count[remainder]++;
        }
        return count;
        
    }
};