class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        string temp = "";

        for(char ch : s) {
            if(ch != ' ')
                temp += ch;
            else {
                if(!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            }
        }

        if(!temp.empty())
            words.push_back(temp);

        return words.back().length();
    }
};