class Solution {
public:
    unordered_map<string,vector<string> > dp;
    vector<string> helper(string s,vector<string>& wordDict){
        // base case
        if(s.length() == 0){
            return {""};
        }
        if(dp.count(s)) return dp[s];
        // recursive case
        vector<string> ChotaAns,BadaAns;
        for(auto word: wordDict){
            int wordLen = word.length();
            if(s.substr(0,wordLen) == word){
                ChotaAns = helper(s.substr(wordLen),wordDict);
                for(auto y: ChotaAns){
                    string spaceHai = y.length()?" ":"";
                    BadaAns.push_back(word+spaceHai+y);
                }
            }
        }
        return dp[s] = BadaAns;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans = helper(s,wordDict); 
        return ans;
    }
};