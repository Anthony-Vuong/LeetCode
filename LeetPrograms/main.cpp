#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // index1 var
        int index1 = 0;
        // index2 var
        int index2 = 0;
        //temp var
        int tempRes = 0;
        //vector int array
        vector<int> indexes;

        //loop through array
            // save element 0 to index1 var
            //loop through remaining elements
                //if element n + element index1 var is equal to target
                    //save index n to index2 var
                    //break;

        for(int i = 0; i < nums.size(); ++i)
        {
            index1 = i;
            for(int j = 1; j < nums.size(); ++j)
            {
                index2 = j;
                tempRes = nums[i] + nums[j];
                if(tempRes == target)
                {
                    indexes.push_back(index1);
                    indexes.push_back(index2);
                    return indexes;
                }
            }
        }
        return indexes;
    }
};


int main()
{
    vector<int> nums{2, 7, 11, 15};
    vector<int> indexSol;
    int target = 9;

    Solution sol;

    indexSol = sol.twoSum(nums, target);

    cout << "[";

    for(int i = 0; i < indexSol.size(); i++)
    {
        if(i == 0)
        {
            cout << indexSol.at(i) << ", ";
        }
        else
        {
            cout << indexSol.at(i);
        }
    }

    cout << "]" << "\n";

    return 0;
}


