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

