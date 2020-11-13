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

void test1_dupsInArray(){
    Solution s;
    vector<int> arr{4,3,2,7,8,2,3,1};
    vector<int> sol{3, 2};
    vector<int> result;
    result = s.findDuplicates(arr);
    myVectorAssert(result, sol);
}

void runTests(){
    testsSpace tests[] = {
        test1_dupsInArray,
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
