class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    
    // Process days backward
    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        // Jump forward while temperatures[j] <= temperatures[i]
        while (j < n && temperatures[j] <= temperatures[i]) {
            if (answer[j] == 0) {
                j = n;  // no warmer day found ahead
            } else {
                j += answer[j];  // jump ahead by known days
            }
        }
        if (j < n) {
            answer[i] = j - i;
        }
    }
    return answer;
}

};