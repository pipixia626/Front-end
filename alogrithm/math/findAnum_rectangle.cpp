//在一个递增二维数组中，数组从左往右递增从上往下递增，给出一个数，查找这个数在不在里面

/*思路
从右上角开始
如果这个数等于target就退出
这个数比target大就剔除该列
如果这个数比target小就剔除该行

matrix       {1,2,8,9,
              2,4,9,12
              4,7,10,13
              6,8,11,15
             }
*/
#include <iostream>

bool find(int *matrix, int rows, int columns, int number)
{
    bool found = false;

    if (matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            if (matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row * columns + column] > number)
            {
                --columns;
            }
            else
                ++row;
        }
    }
    return found;
}