#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate stock span values
    vector<int> calculateSpan(vector<int>& prices) {
        // Your implementation goes here
    }
};

int main() {
    /*
    Stock Span Problem:
    The span of a stock's price on a given day i is the maximum number of 
    consecutive days (up to the current day) for which the stock price is 
    less than or equal to the price on day i.

    Example:
    Prices = [100, 80, 60, 70, 60, 75, 85]
    Spans  = [1,   1,  1,  2,  1,  4,  6]

    Explanation:
    Day 1 (100): No previous greater -> span = 1
    Day 2 (80):  No previous greater -> span = 1
    Day 3 (60):  No previous greater -> span = 1
    Day 4 (70):  Greater than one previous -> span = 2
    Day 5 (60):  No previous greater -> span = 1
    Day 6 (75):  Greater than four previous -> span = 4
    Day 7 (85):  Greater than six previous -> span = 6
    */

    Solution sol;
    
    // Test Case 1: Basic case
    vector<int> prices1 = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = sol.calculateSpan(prices1);
    
    cout << "Test Case 1:\n";
    cout << "Prices: ";
    for(int price : prices1) cout << price << " ";
    cout << "\nSpans:  ";
    for(int span : result) cout << span << " ";
    cout << "\n\n";

    // Test Case 2: Increasing sequence
    vector<int> prices2 = {10, 20, 30, 40, 50};
    result = sol.calculateSpan(prices2);
    
    cout << "Test Case 2 (Increasing sequence):\n";
    cout << "Prices: ";
    for(int price : prices2) cout << price << " ";
    cout << "\nSpans:  ";
    for(int span : result) cout << span << " ";
    cout << "\n\n";

    // Test Case 3: Decreasing sequence
    vector<int> prices3 = {50, 40, 30, 20, 10};
    result = sol.calculateSpan(prices3);
    
    cout << "Test Case 3 (Decreasing sequence):\n";
    cout << "Prices: ";
    for(int price : prices3) cout << price << " ";
    cout << "\nSpans:  ";
    for(int span : result) cout << span << " ";
    cout << "\n";

    return 0;
}