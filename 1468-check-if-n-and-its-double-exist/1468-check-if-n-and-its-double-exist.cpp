class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       unordered_set<int>s;
       int c=0;
        for (int i=0;i<arr.size();i++){
            s.insert(arr[i]);
            if (arr[i]==0) c++;
        }
        bool chk=false;
        for (int i=0;i<arr.size();i++){
            
            int x= arr[i]*2;
            if (s.find(x)!=s.end() ){
                if (x==0 && c==1){
                    cout<<"hello";
                }
                else
                chk=true;
            }
        }
        if (chk) return true;
        return false;
    }
};