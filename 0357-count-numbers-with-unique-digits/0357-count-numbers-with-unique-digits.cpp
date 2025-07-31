class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
          if (n == 0) return 1;

    int total = 10; // For n = 1, we have 10 numbers: 0 to 9
    int uniqueDigits = 9;
    int available = 9;

    for (int i = 2; i <= n && available > 0; ++i) {
        uniqueDigits *= available;
        total += uniqueDigits;
        --available;
    }

    return total;
    }
};