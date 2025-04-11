class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    vector<int> ple(n), nle(n);
    stack<int> st;

    // Calculate Previous Less Element (PLE)
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        ple[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear stack for next iteration
    while (!st.empty()) st.pop();

    // Calculate Next Less Element (NLE)
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        nle[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Calculate the result
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - ple[i];
        long long right = nle[i] - i;
        res = (res + arr[i] * left % MOD * right % MOD) % MOD;
    }

    return res;
        
    }
};