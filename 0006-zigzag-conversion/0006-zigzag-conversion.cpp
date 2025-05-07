class Solution {
public:
    string convert(string s, int rows) {
        string op = "";
        int cols = s.length();
        char ans[1000][2000];
        memset(ans, 0, sizeof(ans)); // initialize all to null char
        int idx=0;    
        int i=0;
        bool st=false,en=false;
        int row=0,col=0;

        if (rows == 1) return s;  // edge case

        while (i<s.length()) {
            ans[row][col]=s[i];
            i++;
            if (row==0){
                st=true;
                en=false;
            } 
            else if(row==rows-1){
                en=true;
                st=false;
            }
            if (st){
                row++;
            } 
            else if(en){
                row--;
                col++;
            }
        }
        for (int i=0;i<rows;i++){
            for (int j=0;j<2000;j++){
                if (ans[i][j]!=0){
                    op+=ans[i][j];
                }
            }
        }

        return op;
    }
};

// class Solution {
// public:
//     string convert(string s, int rows) {
//         string op="";
//         int cols=s.length();
//         char ans[1000][100]={'0'};
//         int idx=0;    
//         int i =0;
//         bool st=false,en=false;
//         int row=0,col=0;
//         while (i<s.length()){
//             if (row==0){
//                 st=true;
//                 en=false;
//             }
//             if (row==rows-1){
//                 en=true;
//                 st=false;
//             }
//             if (st){
//                 ans[row][col]=s[i];
//                 i++;
//                 row++;

//             }
//             else if (en){
//                 row--;
//                 col++;
//                 ans[row][col]=s[i];
//                 i++;
//             }
//         }
//         for (int i=0;i<200;i++){
//             for (int j=0;j<200;i++){
//                 if (ans[i][j]!='0') op+=ans[i][j];
//             }
//         }

//         return op;

//     }
// };