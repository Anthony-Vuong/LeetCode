#include "Solution.hpp"
#include <vector>


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

