class Solution {
public:
    bool _exist(vector<vector<char>>& board, string& word,int i=0,int j=0, int index=0) {
        if (i<0 || j <0 || i >= board.size() || j>=board[0].size())    return false;
        if(index==word.length()-1)   return board[i][j] == word[index];
        char temp = board[i][j];
        if (word[index] == board[i][j]){
            board[i][j] = '!';
            if ( _exist(board,word,i+1,j,index+1))      return true;
            if ( _exist(board,word,i,j+1,index+1))      return true;
            if ( _exist(board,word,i-1,j,index+1))      return true;
            if ( _exist(board,word,i,j-1,index+1))      return true;
        } 
        board[i][j] = temp;
        return false ;
    }
    bool exist(vector<vector<char>>& board, string word){
        if(word.length() > board.size() * board[0].size())  return false;
        
        //Checking if all charectors in the word are present in board [Optimization]
        bool chars[27] = {false};
        for(int i = 0; i < board.size();i++){
            for(int j =0 ; j < board[0].size();j++){
                chars[board[i][j] - 'A'] = true;
            }
        }
        for (int i = 0 ; i < word.length() ; i++){
            if (!chars[word[i]-'A'])   return false;
        }
        //

        for(int i = 0; i < board.size();i++){
            for(int j =0 ; j < board[0].size();j++){
                if (board[i][j] == word[0] && _exist(board,word,i,j,0))  return true;
            }
        }
        return false;
    }
};