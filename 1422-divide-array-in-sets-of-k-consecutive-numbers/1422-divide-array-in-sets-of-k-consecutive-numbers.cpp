class Solution {
public:
    bool isPossibleDivide(vector<int>& v, int s) {

       map<int,int>m;
        for (auto it :v){
            m[it]++;
        }

        while (!m.empty()){
            int x=s;
            int prev=-1;
            if(m.size()<x) return false; 
                for (auto it:m){
                    int z= it.first;
                    if (prev==-1 || prev ==z-1){
                        m[z]--;
                        if (m[z]==0) m.erase(z);
                        prev=z;
                    }
                    else return false;
                    x--;
                    if (x==0) break;
                }
        }
        return true;   
    }
};