class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int>freq;
        int maxfreq=0;
        for(char ch: s)
        {
           freq[ch]++;
           maxfreq=max(maxfreq,freq[ch]);
        }
        string result="";
        unordered_set<char> used;
        for(int i=s.size(); i>=0; i--)
        {
            char ch= s[i];
            if(freq[ch]==maxfreq && used.find(ch)==used.end())
            {
                result+=ch;
                used.insert(ch);
            }
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};