/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        this->m_board = board;
        this->m_path = vector<vector<bool> > (board.size(), vector<bool>(board[0].size(), false));
        
        bool res;
        for(int i = 0; i < board.size(); i++){
           for(int j = 0; j< board[0].size(); j++) {
               if(word[0] == board[i][j]){
                   res = res || dfs(i,j,"");
                   if(res == true){
                       break;
                   }
               }
           }
        }
        return res;
    }

    bool dfs(int i , int j, string pathStr){
        if(i >= m_board.size() || j >= m_board[0].size()){
            return false;
        }
        if(m_path[i][j] == true){
            return false;
        }
        if(word[pathStr.size()] != m_board[i][j]){
            return false;
        }
        pathStr.append(1, m_board[i][j]);
        m_path[i][j] = true;
        bool match = false;
        if(pathStr == word){
            return true;
        } else {
            match = dfs(i-1, j, pathStr) || dfs(i+1, j, pathStr) ||
            dfs(i, j-1, pathStr) || dfs(i, j+1, pathStr);
        }
        m_path[i][j] = false;
        pathStr.erase(pathStr.size()-1, 1);
        return match;
    }

    private:
        vector<vector<bool> > m_path;
        vector<vector<char> > m_board;
        string word;
};
// @lc code=end

