class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //next greater element problem    
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);

        for(int i = n-1; i>=0; i--){
            int t = temperatures[i];
            
            while(!st.empty()){
                if(st.top().first > t){
                    //cout<<"INside "<<t<<endl;
                    ans[i] = st.top().second - i;
                    break;
                }
                st.pop();
            }
            st.push({t, i});
        }

        return ans;
    }
};
