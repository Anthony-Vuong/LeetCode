#include <iostream>
#include "Solution.hpp"
#include <vector>
#include <assert.h>
#include <algorithm>

typedef void (*testsSpace)();
using namespace std;

// Functions prototypes
void runTests();

void myAssert(int x, int y){
    if(x == y){
        cout << " Passed " << endl;
    }
    else{
        cout << " Failed " << endl;
    }
}

void myVectorAssert(vector<int>& vec1, vector<int>& vec2){
    if(std::equal(vec1.begin(), vec1.end(), vec2.begin())){
        cout << " Passed " << endl;
    }
    else{
        cout << " Failed " << endl;
    }
}

void test1_findLucky(){
    Solution s;
    vector<int> arr{2, 2, 3, 4};
    int result{0};
    result = s.findLucky(arr);
    myAssert(result, 2);
}

void test2_findLucky(){
    Solution s;
    vector<int> arr{7, 7, 7, 7, 7, 7, 7};
    int result{0};
    result = s.findLucky(arr);
    myAssert(result, 7);
}

void test3_findLucky(){
    Solution s;
    vector<int> arr{1, 2, 2, 3, 3, 3};
    int result{0};
    result = s.findLucky(arr);
    myAssert(result, 3);
}

void test4_findLucky(){
    Solution s;
    vector<int> arr{2, 2, 2, 3, 3};
    int result{0};
    result = s.findLucky(arr);
    myAssert(result, -1);
}

void test5_twoSum(){
    Solution s;
    vector<int> arr{2, 7, 11, 15};
    vector<int> sol{0, 2};
    vector<int> resultVec;
    int target{9};
    resultVec = s.twoSum(arr, target);
    myVectorAssert(sol, resultVec);
}

void runTests(){
    testsSpace tests[] = {
        test1_findLucky,
        test2_findLucky,
        test3_findLucky,
        test4_findLucky,
        test5_twoSum
    };
    
    for(int i{0}; i < sizeof(tests)/sizeof(tests[0]); ++i){
        cout << "Test " << i+1;
        tests[i]();
    }

}

int main()
{
    runTests();
	return 0;
}
