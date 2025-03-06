class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            // Check if this power should be used twice
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};