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

//Not Working
//Does't pass this test case:
//[32,69,37,79,4,33,29,33,45,1,99,90,56,24,76], k = 10s
int Solution::maxScore(vector<int>& cardPoints, int k) {
             
    int sum1{0};  //first card, front: next k-1 cards
    int sum2{0};  //first card, end: next k-1 cards
    int sum3{0};  //last card, front: next k-1 cards
    int sum4{0};  //last card, end: next k-1 cards
        
    unsigned long long numCards{cardPoints.size()};  // # of cards
    
    int firstCard{cardPoints.at(0)}; 
    int lastCard{cardPoints.at(numCards-1)};
    
    for(int i{1}; i < k; i++){
        sum1 = sum1 + cardPoints.at(i);             //first cards 
        sum2 = sum2 + cardPoints.at(numCards-i);    //last cards
    }
    
    sum1 = sum1 + firstCard;
    sum2 = sum2 + firstCard;
    
    
    if(sum1 < sum2){
        sum1 = sum2;
    }
    
    for(int i{1}; i < k; i++){
        sum3 = sum3 + cardPoints.at(i-1);           //first cards 
        sum4 = sum4 + cardPoints.at(numCards-(i+1));    //last cards
    }
    
    sum3 = sum3 + lastCard;
    sum4 = sum4 + lastCard;
    
    
    if(sum3 < sum4){
        sum3 = sum4;
    }
    
    if(sum1 < sum3){
        return sum3;
    }
    
    return sum1;
}