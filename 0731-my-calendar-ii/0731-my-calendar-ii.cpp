class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int,int>m;
    bool book(int start, int end) {
               m[start]++;
        m[end]--;
        int s=0;
        for (auto it:m){
            s+=it.second;
            if (s>2){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */