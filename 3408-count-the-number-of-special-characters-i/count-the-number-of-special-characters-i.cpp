class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int>freq;

        for(char ch: word){
            freq[ch]++;
        }

        int cnt =0;
        for(auto it: freq){
            char ch = it.first;

            if(islower(ch)){
                if(freq.find(ch - 32) != freq.end())
                cnt++;
            }    
            else{
                if(freq.find(ch + 32) != freq.end())
                cnt++;
            }
        }
        return cnt/2;

        // heyy cutieee , i love u


        
    }
};