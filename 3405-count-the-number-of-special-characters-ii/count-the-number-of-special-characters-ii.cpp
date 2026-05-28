class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        unordered_map<char, int>firstUpper;
        unordered_map<char, int>lastLower;

        for(int i =0; i<n ; i++){
            char ch = word[i];
            if(islower(ch)){
                lastLower[ch] =i;
            }
            else{
                if(firstUpper.find(ch) == firstUpper.end()){
                    firstUpper[ch] =i;
                }
            }
            
        }

        int count =0;
        for(int i =0; i<n ;i++){
            char ch = word[i];

            if(isupper(ch)){
                char lower = tolower(word[i]);
                char upper = toupper(word[i]);
                if(lastLower.find(lower) != lastLower.end()){
                    if(lastLower[lower] < firstUpper[upper]){
                        count++;
                        lastLower.erase(lower);
                    }
                }
            }
        }
        return count;


        
    }
};