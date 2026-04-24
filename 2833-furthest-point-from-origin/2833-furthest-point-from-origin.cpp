class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cl=0,cr=0,c_=0;
        for(auto c : moves){
            switch(c){
                case 'R' : cr++;break;
                case 'L' : cl++;break;
                case '_' : c_++;break;                                
            }
        }
        return abs(cl-cr) + c_;
    }
};