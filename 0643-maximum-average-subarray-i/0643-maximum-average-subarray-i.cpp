// APPLTING SLIDING WINDOW

class Solution {
public:
    double findMaxAverage(vector<int>& v, int size) {
        int i =0,j=0,sum =0,n=v.size();
        double mx=-999999.999;
	while (j<n){
		if (j-i+1<size) {
			sum = sum+v[j];
			//cout<<j<<"  -->  when size condition is not meet "<<sum<<endl;
			j++;
		}
		else if (j-i+1==size){
			sum = sum +v[j];
//			mx=max(sum,mx);
            if (mx<sum) mx = sum;

			//cout<<j<<"  -->   "<<mx<<endl;
			sum =sum -v[i];
			i++;
			j++;
			
		}
	}
	return mx/size;
    }
};