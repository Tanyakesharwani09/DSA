class Solution {
public:
    int totalMoney(int n) {
        int completeWeeks = n/7;
        int remainingWeeks = n%7;

        int part1 = (28*completeWeeks) + ((completeWeeks*(completeWeeks - 1))/2)*7;
        int part2 =(remainingWeeks * (remainingWeeks + 1))/2 + (completeWeeks)*remainingWeeks;

        return part1 + part2;
    }
};