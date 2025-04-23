class Solution {
public:
    int solve (int i ,int n , int mask,vector<vector<int>>&dp){
        if (i>n) return 1;
        if (dp[i][mask]!=-1) return dp[i][mask];
        int ans=0;
         for (int num=1;num<=n;num++) {
            int bit=1<<(num-1);
            if ((mask & bit)==0 && (num%i==0 || i%num==0)){
                ans+=solve(i+1,n,mask | bit,dp);
            }
        }
       return  dp[i][mask]=ans;
    }
    int countArrangement(int n) {
        int max_mask=1<<n;
        vector<vector<int>>dp(n+1,(vector<int>(max_mask,-1)));
        return solve(1,n,0,dp);
    }
};


/*

We can use bitwise operations to:

Check if a number is used: mask & (1 << (num - 1))
Mark a number as used: mask | (1 << (num - 1))


\U0001f9ea Dry Run: solve(1, 3, mask = 0)
Step 1: pos = 1, mask = 000
Try placing 1: 1 % 1 == 0 ✅ → new mask = 001 → solve(2, 3, 001)

Try placing 2: 2 % 1 == 0 ✅ → new mask = 010 → solve(2, 3, 010)

Try placing 3: 3 % 1 == 0 ✅ → new mask = 100 → solve(2, 3, 100)

We branch into 3 recursive calls.

Step 2: pos = 2, mask = 001 (1 used)
Try 2: not used and 2 % 2 == 0 ✅ → mask = 011 → solve(3, 3, 011)

Try 3: not used and 3 % 2 ❌, 2 % 3 ❌ → skip

➡️ Continue with solve(3, 3, 011)

Step 3: pos = 3, mask = 011 (1,2 used)
Try 3: not used and 3 % 3 == 0 ✅ → mask = 111 → solve(4, 3, 111)

pos > n → return 1 ✅

✔️ One valid arrangement found: [1, 2, 3]

Now we backtrack…

Step 2: pos = 2, mask = 010 (2 used)
Try 1: not used, 2 % 1 == 0 ✅ → mask = 011 → already solved → 1

Try 3: not used, 3 % 2 ❌, 2 % 3 ❌ → skip

✔️ Another valid arrangement: [2, 1, 3]

Step 2: pos = 2, mask = 100 (3 used)
Try 1: 1 % 2 == 1 ❌, 2 % 1 == 0 ✅ → mask = 101 → solve(3, 3, 101)

Try 2: 2 % 2 == 0 ✅ → mask = 110 → solve(3, 3, 110)

Step 3: pos = 3, mask = 101 (1,3 used)
Try 2: not used, 2 % 3 ❌, 3 % 2 ❌ → skip

\U0001f501 returns 0

Step 3: pos = 3, mask = 110 (2,3 used)
Try 1: 1 % 3 ❌, 3 % 1 == 0 ✅ → mask = 111 → already solved → 1

✔️ Another valid arrangement: [3, 2, 1]

✅ Final Result:
Valid arrangements:

[1, 2, 3]

[2, 1, 3]

[3, 2, 1]

So the total is 3.

*/