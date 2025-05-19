class Solution {
public:
    string triangleType(vector<int>& v) {
        int a=v[0],b=v[1],c=v[2];
        if(a+b<=c || a+c<=b || b+c<=a ) return "none";
        if (a==b && b==c){
            return "equilateral";
        }
        else if (a==b || b==c || a==c ) return "isosceles";  
        else return "scalene";
    }
};