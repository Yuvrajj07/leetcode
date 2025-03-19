

//.................... USING DYNAMIC PROGRAMING................

//.....................TOP DOWN APPPROACH......................





class Solution {
public:
    int ans(int n,vector<int>&dp){
            if( n==1 || n==2){
                return n;
            }
            if(dp[n-1]!=-1) return dp[n-1];
            return dp[n-1]=ans(n-1,dp)+ans(n-2,dp);
            return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);  
            return ans(n,dp);    
    }    
};




// class Solution {
// public:
//     int ans(int n,vector<int>&dp){
//         if (n==1 || n==2){
//             return n;
//         }
//         if (dp[n]!=-1){
//             return dp[n];
//         }
//         // return 
//             dp[n]=ans(n-1,dp)+ans(n-2,dp);
//             return dp[n];
//     }
//     int climbStairs(int n) {
//         vector<int>dp(n+1,-1);  
//             return ans(n,dp);    
//     }    
// };





//..............BOTTOM UP-(TABULATION METHOD)...................

// class Solution {
// public:

//     int climbStairs(int n) {
//         vector<int>dp(n+1,-1);
//         if (n==1 || n==2 ) return n;
//         dp[1]=1;
//         dp[2]=2;
//         for (int i =3;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }    
// };


// ....................USING RECURSION -(TLE)................... 
// class Solution {
// public:
// int ans (int n,int t){
//     if (n==t){
//         return 1;
//     }
//     if (n>t){
//         return 0;
//     }
//     return (ans((n+1),t) + ans((n+2),t));
// }
//     int climbStairs(int n) {
//         return ans(0,n);
        
//     }
// };