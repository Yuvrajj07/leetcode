class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int>m;
    int book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;
        int s=0,ans=1;
        for (auto it:m){
            s+=it.second;
               ans=max(s,ans);
        }
        return ans;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */