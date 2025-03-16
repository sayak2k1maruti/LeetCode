class Solution {
public:
    bool canBeRepaired(vector<int> & ranks,long long time,int cars){
        // r*n^2 < time
        // n^2 < time/r
        // n < sqrt(time/r)
        int rqCars = 0;
        for(auto &r : ranks){
            int i = sqrt(time/r);
            rqCars += i;
            if(rqCars >= cars)   return true;
        }
        return rqCars>=cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        int minRank = *min_element(ranks.begin(),ranks.end());
        long long time = (long long)minRank * (long long)cars * (long long)cars;
        long long startT = 1,endT = time, ans = 0;
        while(startT <= endT){
            // cout << startT << " " << endT << endl;
            long long mid = startT + (endT - startT)/2;
            if(canBeRepaired(ranks,mid,cars)){
                endT = mid-1;
                ans = mid;
            }else{
                startT = mid+1;
            }
        }
        return ans;
    }
};