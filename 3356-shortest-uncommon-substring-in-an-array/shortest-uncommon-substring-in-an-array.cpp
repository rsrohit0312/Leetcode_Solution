class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        map<string, int> mp;

        for (int i = 0; i < n; i++) {
            string s = arr[i];
            set<string> uniqsubs;

            for (int j = 0; j < s.size(); j++) {
                string temp = "";
                for (int k = j; k < s.size(); k++) {
                    temp += s[k];
                    uniqsubs.insert(temp);
                }
            }

            for (const string& sub : uniqsubs) {
                mp[sub]++;
            }
        }
        vector<string> answer(n);
        for (int i = 0; i < n; i++) {
            string s = arr[i];
            string best = "";

            for (int j = 0; j < s.size(); j++) {
                string temp = "";
                for (int k = j; k < s.size(); k++) {
                    temp += s[k];

                    if (mp[temp] == 1) {
                        if (best.empty() || temp.size() < best.size() ||
                            (temp.size() == best.size() && temp < best)) {
                            best = temp;
                        }
                    }
                }
            }

            answer[i] = best;
        }
        return answer;
        
    }
};