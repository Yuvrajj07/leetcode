class Solution {
public:
     int maxNum, target;
     unordered_map<int, bool> m;
    bool solve(int usedNumbers, int currentTotal) {
         if (m.count(usedNumbers)) return m[usedNumbers];
         for (int i = 1; i <= maxNum; ++i) {
                 if ((usedNumbers & (1 << i)) == 0) {
                    if (currentTotal + i >= target || !solve(usedNumbers | (1 << i), currentTotal + i)) {
                                    return m[usedNumbers] = true;
                    }                       
         }
    }
    return m[usedNumbers] = false;
}
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxNum = maxChoosableInteger;
        target = desiredTotal;
        int maxSum = (maxNum * (maxNum + 1)) / 2;
        if (maxSum < target) return false;
        if (target <= 0) return true;
        return solve(0, 0);  
    }
};

/*
1. Impossible to Reach Total?
If the sum of all numbers from 1 to maxChoosableInteger is less than desiredTotal, then it's impossible to reach it. So return false.

int maxSum = (maxNum * (maxNum + 1)) / 2;
if (maxSum < target) return false;
2. Bitmask to Track Used Numbers
We use an int called usedNumbers to encode the current state of used numbers:

Bit i is 1 if number i has been used.

This lets us efficiently track and memoize different game states.

\U0001f501 Recursive solve Function
Parameters:
usedNumbers: a bitmask representing which numbers are already picked.

currentTotal: the current total sum so far.

Logic:
bool solve(int usedNumbers, int currentTotal)
At each recursive call:

We loop through all numbers from 1 to maxChoosableInteger.

For each number i:

If i is not yet used (i.e., its bit in usedNumbers is 0),

We consider choosing i.

Two conditions where choosing i is a winning move:

If currentTotal + i >= desiredTotal: you win immediately.

If the opponent cannot win from the next state:

!solve(usedNumbers | (1 << i), currentTotal + i)
This means: "If I pick i now and the opponent cannot win from that point, then I win."

If any such move exists, the current player can force a win → return true.

If no move can guarantee a win, return false.

Memoization:
We save each state result in memo[usedNumbers] to avoid recalculating the same state.

*/