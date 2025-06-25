class Solution {
public:
    string generateTag(string s) {
        string result = "#";
        string word = "";
        bool firstWord = true;

        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (!word.empty()) {
                    for (char &c : word) c = tolower(c);

                    if (firstWord) {
                        result += word;
                        firstWord = false;
                    } else {
                        word[0] = toupper(word[0]);
                        result += word;
                    }

                    word = "";
                }
            } else {
                word += s[i];
            }
        }

        if (result.size() > 100) {
            result = result.substr(0, 100);
        }

        return result;
    }
};