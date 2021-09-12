//从一个二维数组中寻找
//数组从左往右升序，从上往下升序

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

//从一个二维数组里面找
//   1   3    5   7
//   2   4    6   8
//   9   10   11  12
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), line = matrix[0].size();
    int i = 0, j = line - 1;
    if (row == 0)return false;
    //边界条件只有一个数的时候，所以j要大于等与0
    while (i < row && j >= 0) {

        if (matrix[i][j] > target) j--;
        else if (matrix[i][j] < target)i++;
        else return true;
    }
    return false;
}

/*二分查找*/
//一次二分
bool searchMatrix_binary_once(vector<vector<int>>& matrix, int target){
    int row = matrix.size(), line = matrix[0].size();
    int low = 0, high = row * line - 1;
    while (low < high) {
        int mid = low+(high-low>>1);
        int x = matrix[mid / line][mid % line]; 
        if (x < target) {
            low = mid + 1;
        }
        else if (x > target) {
            high = mid - 1;
        }
        else {
            return true;
        }

    }
    return false;
}


int main() {
    vector<vector<int>>nums{ {1,3,5,7},{2,4,6,8},{9,10,12,12} };
    int target = 6;
    cout << searchMatrix_binary_once(nums, target);
    return 0;
}