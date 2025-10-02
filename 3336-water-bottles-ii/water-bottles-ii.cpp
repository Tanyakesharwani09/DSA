class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrink = numBottles;
        while(numBottles >= numExchange){
            totalDrink +=1;
            numBottles = numBottles - numExchange +1;
            numExchange++;
        }
        return totalDrink;
    }
};