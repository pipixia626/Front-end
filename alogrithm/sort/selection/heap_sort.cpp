#include <vector>
#include <iostream>

class heap_sort
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
};