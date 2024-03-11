class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
          return 0;
        if (dividend == INT_MIN && divisor == -1)
          return INT_MAX;
        int q;
        q=dividend/divisor;
        return q;
    }
};
