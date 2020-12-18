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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);
    void reverseString(vector<char>& s);
    vector<int> replaceElements(vector<int>& arr);
    string restoreString(string s, vector<int>& indices);





};

#endif // SOLUTION_HPP
