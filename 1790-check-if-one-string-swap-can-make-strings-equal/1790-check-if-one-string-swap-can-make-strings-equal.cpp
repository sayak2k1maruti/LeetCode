class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        if(n==1)    return s1==s2;
        int mismatchCount = 0;
        int mismatchIndex[n];
        for(int i = 0 ; i < n ; i++){
            if(s1[i] != s2[i])
                mismatchIndex[mismatchCount++] = i;
        }
        //cout << mismatchCount << " " << mismatchIndex[0] << " " <<mismatchIndex[1] << endl;
        if(mismatchCount==0) return true;
        if(mismatchCount > 2) return false;
        
        return (s1[mismatchIndex[0]] == s2[mismatchIndex[1]]) && (s1[mismatchIndex[1]] == s2[mismatchIndex[0]]) ;
    }
};