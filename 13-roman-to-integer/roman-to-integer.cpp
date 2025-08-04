class Solution {
public:
int getValue(char ch) {
        if (ch == 'I') return 1;
        if (ch == 'V') return 5;
        if (ch == 'X') return 10;
        if (ch == 'L') return 50;
        if (ch == 'C') return 100;
        if (ch == 'D') return 500;
        if (ch == 'M') return 1000;
        return 0;
        }

    int romanToInt(string s) {
        int result=0;

        for (int i = 0; i < s.length(); i++) {
            int value = getValue(s[i]);

            int nextValue = 0;

if (i + 1 < s.length()) {
    nextValue = getValue(s[i + 1]);
} else {
    nextValue = 0;
}

if (value < nextValue) {
    result -= value;
} else {
    result += value;
}


    }
    return result;

}
};