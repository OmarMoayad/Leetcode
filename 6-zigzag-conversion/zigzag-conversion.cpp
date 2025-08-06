class Solution {
public:
    string convert(string s, int numRows) {
         if (numRows == 1 || s.length() <= numRows) return s;

    string result = "";
    for (int row = 0; row < numRows; row++) {
        int step = 2 * (numRows - 1);
        for (int i = row; i < s.length(); i += step) {
            result += s[i];
            int secondChar = i + step - 2 * row;
            if (row != 0 && row != numRows - 1 && secondChar < s.length()) {
                result += s[secondChar];
            }
        }
    }
    return result;

    }
};