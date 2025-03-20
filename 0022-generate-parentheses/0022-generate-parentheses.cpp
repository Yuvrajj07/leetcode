class Solution {
public:

    // void solve(string op, int open, int close, vector<string> &ans){
    //     if (open==0 &&close==0){
    //         ans.push_back(op);
    //         return ;
    //     }
    //     if (open==close){
    //         string op1=op;
    //         op1.push_back('(');
    //         solve(op1,open-1,close,ans);
    //     }
    //     else if (open==0){
    //         string op1=op;
    //         op1.push_back(')');
    //         solve(op1,open,close-1,ans);
    //     }
        
    //     else {
    //         string op1=op;
    //         string op2=op;
    //         op1.push_back('(');
    //         op2.push_back(')');
    //         solve(op1,open-1,close,ans);
    //         solve(op2,open,close-1,ans);
    //     }
        

    // }
    // vector<string> generateParenthesis(int n) {
    //     int open = n;
    //     int close = n;
    //     vector<string> ans;
    //     string op = "";
    //     solve(op, open, close, ans);
    //     return ans;
    // }
    void solve(int o,int c,string s,vector<string>&ans){
        if (o==0 && c==0){

            ans.push_back(s);
            return;
        }
        
        if (o==c){
            string s1=s;
            s1.push_back('(');
            solve(o-1,c,s1,ans);
        }
        else if (o==0){
            string s1=s;
            s1.push_back(')');
            solve(o,c-1,s1,ans);
        }
        else {
            string s1=s;
            string s2=s;
            s1.push_back('(');
            s2.push_back(')');
            solve(o-1,c,s1,ans);
            solve(o,c-1,s2,ans);           
        }
    }
    vector<string> generateParenthesis(int n) {
        int o=n;
        int c=n;
        string s="";
        vector<string>ans;
        solve(o,c,s,ans);
        return ans;
    }

};