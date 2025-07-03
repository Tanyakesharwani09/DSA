class Solution {
public:
    string intToRoman(int num) {
        // string romanSymbol[]= {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        // int value[]={1000, 900 , 500, 400, 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4, 1};

        vector<pair<int , string>>storeIntRoman = {
            {1000 ,"M"} , {900 ,"CM"},{500,"D"} ,{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };

        string ans="";
        for(int i =0; i<13; i++){
            while(num>=storeIntRoman[i].first){
                ans = ans + storeIntRoman[i].second;
                num = num - storeIntRoman[i].first;
            }
        }
        return ans ;
    }
};