#include "Solution.hpp"
#include <vector>
#include <algorithm>

vector<int> Solution::findDuplicates(vector<int>& nums) {
    
    unsigned long long size{nums.size()};
    vector<int> dups;
    sort(nums.begin(), nums.end());
    
    for(int i{0}; i < size; ++i){
        if(i != size - 1 && nums.at(i) == nums.at(i+1)){
            
                dups.insert(dups.begin(), nums.at(i));
            
        }
    }
    
    return dups;
}