class Solution {
public:
    bool isNumber(string s) {
        bool bSign = false;
        bool bDot = false;
        bool bDigit = false;

        bool bExponent = false;
        bool bExponentSign = false;
        bool bExponentDigit = false;

        for (auto symbol: s) {
            if ((symbol >= '0') && (symbol <= '9')) {
                if (bExponent) {
                    bExponentDigit = true;
                } else {
                    bDigit = true;
                }
            } else if (symbol == '.') {
                if (!bDot) {
                    if (bExponent) {
                        return false;
                    } else {
                        bDot = true;
                    }
                } else {
                    return false;
                }
            } else if ((symbol == '-') || (symbol == '+')) {
                if (bExponent) {
                    if (!bExponentSign && (!bExponentDigit)) {
                        bExponentSign = true;
                    } else {
                        return false;
                    }
                } else {
                    if ((!bSign) && (!bDigit) && (!bDot)) {
                        bSign = true;
                    } else {
                        return false;
                    }
                }
            } else if ((symbol == 'e') || (symbol == 'E')) {
                if (!bExponent) {
                    bExponent = true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (bExponent && (!bExponentDigit)) {
            return false;
        }

        return bDigit;
    }
};