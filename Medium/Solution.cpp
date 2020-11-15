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

vector<int> Solution::countBits(int num) {
    unsigned int oneCount{0};
    int j{0};
    vector<int> binaryVec(num+1);
            
    for(int i{0}; i <= num; ++i){
        j = i;
        while(j > 0){
            if((j & 1) == 1){
                oneCount++;
            }
            j = j >> 1;
        }
        binaryVec.at(i) = oneCount;
        oneCount = 0;
    }

    return binaryVec;  

}