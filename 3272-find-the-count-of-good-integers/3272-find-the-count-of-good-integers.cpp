#define ll long long
class Solution {

public:

    map<int,ll> factMap;

    ll fact(ll n){
        if(factMap[n])  return factMap[n];
        if(n < 2)   return factMap[n] = 1;
        return factMap[n] = n * fact(n-1);
    }

    ll numOfCombination(int* digitMap,int n){
        ll count = fact(n);
        for(int i = 0 ; i <= 9; i++){
            if( digitMap[i] )
                count /= fact(digitMap[i]);
        }
        return count;
    }
    void allCombination(set<string>& combinations,int n,string &temp){
        if(temp.size() == n) {
            combinations.insert(temp);
            return;
        }
        for(char c='0'; c <= '9'; c++){
            temp.push_back(c);
            allCombination(combinations,n,temp);
            temp.pop_back();
        }
    }

    ll s2i(string &s){
        ll ans = 0;
        for(auto &c : s){
            ans = ans*10 + (c-'0');
        }
        return ans;
    }

    vector<ll> allPallindromeCombination(int n,int k){
        int half = ceil((float)n/(float)2);
        set<string> allCombos;
        vector<ll> allCombsNumber;
        string temp;
        allCombination(allCombos,half,temp);
        for(auto s : allCombos){
            for(int i = n/2-1; i >=0 ; i--){
                s += s[i];
            }
            if(s[0] != '0'){
                ll num = s2i(s);
                if(num % k == 0)   allCombsNumber.push_back(num); 
            }
            
        }
        return allCombsNumber;
    }

    string makeHash(int* digitMap){
        string hash = "";
        for(int i = 0 ; i <= 9 ; i++){
            if(digitMap[i]){
                for(int j = 0 ; j < digitMap[i]; j++)   hash += to_string(i);
            }
        }
        return hash;
    }

    long long countGoodIntegers(int n, int k) {
        ll start = pow(10,n-1);
        ll end = pow(10,n);
        //cout << start << " " << end << " ";
        ll count = 0;
        ll mul = ceil((float)start/(float)k);

        unordered_set<string> usedNumComb;

        vector<ll> allPallindroms = allPallindromeCombination(n,k);

        for(auto &num : allPallindroms){
            //cout << num << end


            int digitMap[10] = {0};

            for(ll i=num;i >0;i/=10){
                digitMap[i%10]++;
            }

            string numHash = makeHash(digitMap);
            if(usedNumComb.find(numHash) !=  usedNumComb.end()) continue;
            usedNumComb.insert(numHash);


            ll count1 = numOfCombination(digitMap,n);
            ll swz = 0;//starting with zero 

            if(digitMap[0]){
                digitMap[0]--;
                swz = numOfCombination(digitMap,n-1);
            }
            count += (count1-swz);

        }
        return count;
    }
};