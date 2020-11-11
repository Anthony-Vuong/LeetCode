#include <iostream>
#include "Solution.hpp"
#include <vector>
#include <assert.h>

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

void runTests(){
    testsSpace tests[] = {
        test1_findLucky,
        test2_findLucky,
        test3_findLucky,
        test4_findLucky

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
