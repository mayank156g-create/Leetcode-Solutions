class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;

        // Skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // Sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Skip leading zeros
        while (i < n && s[i] == '0')
            i++;

        string digits;

        while (i < n && isdigit(s[i])) {
            digits += s[i];
            i++;
        }

        if (digits.empty())
            return 0;

        long long num = 0;

        for (char c : digits) {
            num = num * 10 + (c - '0');

            if (sign == 1 && num > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;
        }

        return sign * num;
    }
};