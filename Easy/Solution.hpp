#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution
{
public:
    public:
    int findLucky(vector<int>& arr);
    vector<int> twoSum(vector<int>& nums, int target);
    int numIdenticalPairs(vector<int>& nums);
    int maxProduct(vector<int>& nums);
    bool judgeCircle(string moves);
    vector<int> runningSum(vector<int>& nums);
    int countNegatives(vector<vector<int>>& grid);
    vector<int> luckyNumbers (vector<vector<int>>& matrix);


};

#endif // SOLUTION_HPP
