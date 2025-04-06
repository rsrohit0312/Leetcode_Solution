class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks=0;
        int maxsofar=0;
        for(int i=0; i<arr.size(); i++)
        {
            maxsofar=max(maxsofar, arr[i]);
            if(maxsofar==i)
            chunks++;
        }
        return chunks;
        
    }
};