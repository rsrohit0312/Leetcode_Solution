class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        stack<int>st;
        for(int nums: nums2)
        {
            while(!st.empty() && nums>st.top())
            {
               mp[st.top()]=nums;
               st.pop();
            }
            st.push(nums);
        }
        while(!st.empty())
        {
            mp[st.top()]=-1;
            st.pop();
        }
        vector<int>ans;
        for(int nums :nums1)
        {
            ans.push_back(mp[nums]);
        }
        return ans;

        
    }
};