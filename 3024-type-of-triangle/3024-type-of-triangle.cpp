class Solution {
public:
    string triangleType(vector<int>& v) {
        int x=v[0],y=v[1],z=v[2];
        if (x==y && y==z){
            return "equilateral";
        }
        else if ((x==y || y==z || x==z  ) && (x+y>z && y+z>x && x+z>y) ){
            return "isosceles";
        }
        else if ( (x+y>z && y+z>x && x+z>y)) return "scalene";
        else return "none";
    }
};