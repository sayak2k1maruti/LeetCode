class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        for(int i=0;i<n;i++){
            answers[i]+=1;
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[answers[i]]++;
        }
        for(auto i:mp){
            if(i.second>i.first){
                ans+=(i.first*(i.second/i.first));
                if(i.second%i.first!=0){
                    ans+=i.first;
                }
            }
            else{
                ans+=i.first;
            }
        }
        return ans;
    }
};