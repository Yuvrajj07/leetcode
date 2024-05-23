class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int,int>m;
        
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int s=0;
        for (auto it:m){
            s+=it.second;
            if (s>1){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */