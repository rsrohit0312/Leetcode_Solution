class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0, currentsum=0;
        unordered_map<int, int>prefixsumcount;
        
        for(int num : nums)
        {
           currentsum+=num;

           if(currentsum==k) count++;
           if(prefixsumcount.find(currentsum-k)!=prefixsumcount.end())
           {
            count+=prefixsumcount[currentsum-k];
           }
           prefixsumcount[currentsum]++;
           
        }
        return count;

        
    }
};