#include "Solution.hpp"
#include <vector>
#include <algorithm>
#include <string>


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
    int min{0};
    int m = matrix.size();          //# of vectors
    int n = matrix.at(0).size();    //size of each vector
    int mins[n];
    int maxs[m];

    
    // 3  7  8
    // 9  11 13
    // 15 16 17
    
    // 1 1 1
    // 1 2 1
    // 1 2 3
    
    for(int i{0}; i < m; ++i){
        //min finder
        for(int j{0}; j < n; ++j){
            if(matrix.at(i).at(j) > min){
                min = i;
            }
        }
        mins[i] = min;
    }
    
    for(int i{0}; i < m; ++i){
        //min finder
        for(int j{0}; j < n; ++j){
            if(matrix.at(i).at(j) > min){
                min = i;
            }
        }
        mins[i] = min;
    }
   
    
    
    return luckyNums;
    
}

