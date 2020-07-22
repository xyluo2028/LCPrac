#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() < 2) return numbers[0];
        if (numbers.size() == 2) return (numbers[0] > numbers[1] ? numbers[1] : numbers[0]);
        int end = numbers.size()-1;
        int start = 0;
        return BiSearch(numbers, start, end);
    }

    int minArrayOffical(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return numbers[low];
    }

private:
    int BiSearch(vector<int>& numbers, int iter1, int iter2) {
        cout << iter1 << ", " << iter2 << endl;
        int mid = 0.5 * iter1 + 0.5 * iter2;
        if (iter1 >= mid || iter2 <= mid) {
            if (numbers[iter2] < numbers[mid]) return numbers[iter2];
            else return numbers[0];
        }
        if (numbers[mid] < numbers[mid - 1]) return numbers[mid];
        else if (numbers[mid] > numbers[iter2]) {
            iter1 = mid;
            return BiSearch(numbers, iter1, iter2);
        }
        else if (numbers[mid] < numbers[iter1]) {
            iter2 = mid;
            return BiSearch(numbers, iter1, iter2);
        }
        else {
            int result1 = BiSearch(numbers, mid, iter2);
            int result2 = BiSearch(numbers, iter1, mid - 1);
            return (result1 > result2 ? result2 : result1);
            //return BiSearch(numbers, iter1, iter2 - 1);
        }
    }
};

int main() {
    Solution solve;
    vector<int> test = {2,2,2,0,2,2,2,2};
    //vector<int> test = { 3,4,5,1,3 };
    int result = solve.minArray(test);
    cout << result << endl;
}
