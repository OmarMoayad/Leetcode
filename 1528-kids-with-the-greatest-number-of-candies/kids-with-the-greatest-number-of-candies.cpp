class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcan=0;
        for(int i=0; i<candies.size();i++){
            
            if(candies[i]>=maxcan){
                maxcan=candies[i];
            }
        }
 vector<bool> result;
        for(int j=0; j<candies.size();j++){
         int greatestcan= extraCandies + candies[j];
            if(greatestcan>=maxcan){
                result.push_back(true);
            }
            else {
                result.push_back(false);
            }
        }
        return result;
    }
};