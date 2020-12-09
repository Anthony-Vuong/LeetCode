#include "Solution.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


int Solution::findLucky(vector<int>& arr) {
    int i{0};
    int lucky_num{-1};
    int counts[500];
    
    for(int j{1}; j < 500; ++j){
        counts[j] = 0;
    }
    
    while(i < arr.size()){
        counts[arr.at(i)] += 1;
        i++;
    }
    

    for(i = 1; i < 500; ++i){
        if(i == counts[i] && i > lucky_num){
            lucky_num = i;
        }
    }
    
    return lucky_num;
}

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    //vector int array
    vector<int> indexes;
    // index1 var
    int index1 = 0;
    // index2 var
    int index2 = 0;
    //temp var
    int tempRes = 0;
    // vector size
    int vecSize = nums.size();

    for(int i = 0; i < vecSize; ++i)
    {
        index1 = i;
        for(int j = 1; j < vecSize; ++j)
        {
            index2 = j;
            tempRes = nums[i] + nums[j];
            if(tempRes == target && j != i)
            {
                indexes.push_back(index1);
                indexes.push_back(index2);
                return indexes;
            }
        }
    }
    return indexes;
}

int Solution::numIdenticalPairs(vector<int>& nums) {
    int goodPairs{0};
    
    for(int i{0}; i < nums.size(); ++i){
        for(int j{i+1}; j < nums.size(); ++j ){
            if(i < j && nums.at(i) == nums.at(j)){
                goodPairs = goodPairs + 1;
            }
        }
    }
    return goodPairs;
}

int Solution::maxProduct(vector<int>& nums) {
    int i{0};
    int j{0};
    
    sort(nums.begin(), nums.end());
    
    i = nums.at(nums.size() - 1);
    j = nums.at(nums.size() - 2);
    
    return (i - 1) * (j - 1);
}


bool Solution::judgeCircle(string moves) {
    int i{0};
    int len = moves.length();
    int UD{0};
    int LR{0};
    
    while(i < len){
        switch(moves[i]){
            case 'U':
                UD++;
                break;
            case 'D':
                UD--;
                break;
            case 'L':
                LR--;
                break;
            case 'R':
                LR++;
                break;
            default:
                break;
        }
        i++;
    }
    if(LR == 0 && UD == 0){
        return true;
    }
    
    return false;
}

vector<int> Solution::runningSum(vector<int>& nums) {
    int sum{0};
    int len = nums.size();
    
    for(int i{0}; i < len; i++){
        sum += nums.at(i);
        nums.at(i) = sum;
    }
    
    return nums;
    
}

int Solution::countNegatives(vector<vector<int>>& grid) {
        
    int negatives{0};

    for(int i{0}; i < grid.size(); ++i){
        for(int j{0}; j < grid.at(i).size(); ++j){
            if(grid.at(i).at(j) < 0){
                negatives++;
            }            
        }
    }

    return negatives;

}

vector<int> Solution::luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> luckyNums;
    int max{0};
    int min{matrix.at(0).at(0)};
    int m = matrix.size();          //# of vectors
    int n = matrix.at(0).size();    //size of each vector
    int mins[m];
    int maxs[n];
    
    //min finder
    for(int i{0}; i < m; ++i){   
        min = matrix.at(i).at(0);
        for(int j{0}; j < n; ++j){
            if(matrix.at(i).at(j) < min){
                min = matrix.at(i).at(j);
            }
        }
        mins[i] = min;
    }
    
    for(int i{0}; i < n; ++i){
        max = matrix.at(0).at(i);
        for(int j{0}; j < m; ++j){
            if(matrix.at(j).at(i) > max){
                 max = matrix.at(j).at(i);
            }
        }
        maxs[i] = max;
    }
    
    
    for(int i{0}; i < m; ++i){
        for(int j{0}; j < n; ++j){
            if(mins[i] == maxs[j]){
                luckyNums.push_back(mins[i]);
            }
        }
    }
           
    return luckyNums;
    
}


//COMPLETE, BUT VERY SLOW
 vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size();
    int s2 = nums2.size();
    vector<int> dups;
    
    
    for(int i{0}; i < s1; ++i){
        for(int j{0}; j < s2; ++j){
            if(nums1.at(i) == nums2.at(j) && find(dups.begin(), dups.end(), nums1.at(i)) == dups.end()){
                dups.push_back(nums1.at(i));
            }
        }
    }
    return dups;
}

//COMPLETE, BUT VERY SLOW
vector<bool> Solution::kidsWithCandies(vector<int>& candies, int extraCandies) {
    int len = candies.size();
    vector<bool> maxCandies(len);
    
    for(int i{0}; i < len; ++i){
        maxCandies.at(i) = true;
    }

    
    for(int i{0}; i < len; ++i){
        for(int j{0}; j < len; ++j){
            if(j == i && j != len-1){
                j++;
            }
            int currMaxCandies = candies.at(i) + extraCandies;
            if(currMaxCandies < candies.at(j)){
                maxCandies.at(i) = false;
                break;
            }
        }
    }
    
    return maxCandies;
}

void Solution::reverseString(vector<char>& s) {
    
    char temp;
    unsigned long long len{s.size()};
    
    cout << s.size();
    
    for(int i{0}; i < len / 2; ++i){
        temp = s.at(i);
        s.at(i) = s.at((len-1) - i);
        s.at((len-1) - i) = temp;
    }
}

vector<int> Solution::replaceElements(vector<int>& arr) {
        
    unsigned long long len{arr.size()};
    int max{0};
    
    for(int i{0}; i < len; ++i){
        if(i == len -1){
            arr[i] = -1;
            break;
        }
        for(int j{i+1}; j < len; ++j){
            if(arr[j] > max){
                max = arr[j];
            }
        }
        arr[i] = max;
        max = 0;
    }
    return arr;
}

