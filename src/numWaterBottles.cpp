
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int exch;
        while (numBottles > numExchange) {
            exch = numBottles / numExchange;
            numBottles = numBottles%numExchange + exch;
            result += exch;
        }
        return result;
    }
};
