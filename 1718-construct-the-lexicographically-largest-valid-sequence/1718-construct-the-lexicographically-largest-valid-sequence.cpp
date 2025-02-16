class Solution {
public:

    bool test(vector<int> & ans,map<int,bool> &takenNums,int length){
        /*
        for(int i = 0 ; i < length ; i++)
            cout << ans[i] << ", ";
        cout <<endl;
        */
        int indx=0;
        for(;indx<length && ans[indx] != -1;indx++); 
        if(indx==length)   return true;
        for (auto it = takenNums.rbegin(); it != takenNums.rend(); ++it) {
            int n = it->first;       
            bool isTaken = it->second; 
            if(isTaken) continue;
            if(n==1){
                takenNums[1] = true;
                ans[indx]=1;
                if(test(ans,takenNums,length))  return true;
                ans[indx]=-1;
                takenNums[1] = false;
            }
            else if((indx+n < length) && (ans[indx+n] == -1)){
                takenNums[n] = true;
                ans[indx] = n;ans[indx+n] = n;
                if(test(ans,takenNums,length))  return true;
                ans[indx] = -1;ans[indx+n] = -1;
                takenNums[n] = false;
            }
            
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector <int> ans(2*n-1,-1);
        map<int,bool> takenNums;
        for(int i = n; i > 0; i--)  takenNums[i] = false;
        test(ans,takenNums,2*n-1);
        return ans;
    }
};