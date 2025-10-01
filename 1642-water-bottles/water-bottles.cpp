class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrink = numBottles;
        while(numBottles >= numExchange){
            totalDrink += numBottles/numExchange;
            numBottles = numBottles/numExchange + numBottles % numExchange;
        }
        return totalDrink;
    }
};