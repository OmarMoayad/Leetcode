class Solution {
public:
    int hIndex(vector<int>& citations) {
         int n = citations.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (citations[i] < citations[j]) {
                    int temp = citations[i];
                    citations[i] = citations[j];
                    citations[j] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (citations[i] < i + 1) {
                return i;
            }
        }

        return n;
    
    }
};