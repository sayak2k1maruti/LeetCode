class Solution {
public:
    string backtrack(string pattren,int index,string num,bool *usedDigit){
        if(index > pattren.length())    return num;
        //cout << num << endl;
        for(int digit = 1;digit <= 9; digit ++){
            if(usedDigit[digit])    continue;
            if ((index!=0) && (pattren[index-1] == 'I') && (num[index-1]-'0' > digit)) continue;
            if ((index!=0) && (pattren[index-1] == 'D') && (num[index-1]-'0' < digit)) continue;
            usedDigit[digit] = true;
            string ans = backtrack(pattren,index+1,num+to_string(digit),usedDigit);
            if(ans.length()) return ans;
            usedDigit[digit] = false;
        }
        return "";
    }
    string smallestNumber(string pattern) {
        string number = "";
        bool usedDigit[10] = {false};
        return backtrack(pattern,0,number,usedDigit);
    }
};