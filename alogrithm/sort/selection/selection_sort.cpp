#include <vector>
#include <iostream>

class selection_sort
{
public:
    void swap(std::vector<int> &arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void print_cout(std::vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << "->";
        }
        std::cout << std::endl;
    }

    void selectionSort(std::vector<int> &arr)
    {
        int i, j;
        for (i = 0; i < arr.size() - 1; i++)
        {
            //选择第i小的记录，并交换
            j = selectMinKey(arr, i);
            if (i != j)
                swap(arr, i, j);
        }
        print_cout(arr);
    }
    int selectMinKey(std::vector<int> &arr, int i)
    {
        int min;
        int j, k;
        //从第i个开始
        k = i;
        //设第i个为最小
        min = arr[i];
        for (j = i + 1; j < arr.size() - 1; j++)
        {
            if (arr[j] < min)
            {
                k = j;
                min = arr[j];
            }
        }
        return k;
    }

    void testSelect_sort(std::vector<int> &arr)
    {
        int i, j;
        for (i = 0; i < arr.size() - 1; i++)
        {
            j = testSelectMinKey(arr, i);
            if (i != j)  swap(arr,i,j);
        }
        print_cout(arr);
    }
  
    int testSelectMinKey(std::vector<int> &arr, int i)
    {
        int j, k, min;
        min = arr[i];
        k=i;
        for (j = i+1; j < arr.size() - 1; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                k = j;
            }
        }
        return k;
    }
};

int main()
{
    std::vector<int> datas = {4, 3, 7, 6, 1, 9};
    selection_sort s;
    s.testSelect_sort(datas);
   // s.selectionSort(datas);
}