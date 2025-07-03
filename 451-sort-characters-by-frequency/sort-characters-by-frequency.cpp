class Solution {
public:
    string frequencySort(string s) {
        vector<int>freqTable(128 ,0);
        for(auto ch:s) freqTable[ch]++;

        auto cmp =[&](char a , char b){
            if(freqTable[a] == freqTable[b]) return a<b;
            return freqTable[a] > freqTable[b];
        };
        sort(s.begin() , s.end() , cmp);

        return s;



    }
};