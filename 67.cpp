class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool expDigit = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // Digit
            if (isdigit(c)) {
                digit = true;

                if (exp)
                    expDigit = true;
            }

            // Decimal point
            else if (c == '.') {
                // Dot is not allowed after e/E
                if (dot || exp)
                    return false;

                dot = true;
            }

            // e or E
            else if (c == 'e' || c == 'E') {
                // e needs a number before it
                if (exp || !digit)
                    return false;

                exp = true;
                expDigit = false;
            }

            // Sign
            else if (c == '+' || c == '-') {
                // Sign is allowed only at beginning
                // or immediately after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            // Invalid character
            else {
                return false;
            }
        }

        return digit && expDigit;
    }
};