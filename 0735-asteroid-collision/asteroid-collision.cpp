class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int asteroid : asteroids)
        {
            while(!st.empty() && st.top()>0 && asteroid<0)
            {
                if(abs(asteroid)> st.top())
                {
                   st.pop();
                }
                else if(abs(asteroid)==st.top())
                {
                   st.pop();
                   asteroid=0;
                   break;
                }
                else
                {
                    asteroid=0;
                    break;
                }
            }
            if(asteroid!=0)
            {
                st.push(asteroid);
            }
        }
         vector<int> result(st.size());
        for(int i=st.size()-1; i>=0; --i)
        {
             result[i]=st.top();
             st.pop();
        }
        return result;
    }
};