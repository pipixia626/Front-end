#include <vector>
#include <iostream>

class insert_sort
{
public:
    void print_cout(std::vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << "->";
        }
        std::cout << std::endl;
    }

    void insertSort(std::vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int value = arr[i];
            int position = i;
            while (position > 0 && arr[position - 1] > value)
            {
                arr[position] = arr[position - 1];
                position--;
            }
            arr[position] = value;
        }
        print_cout(arr);
    }

    void test(std::vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int position = i;
            int value = arr[position];
            while (position > 0 && arr[position - 1] > value)
            {
                arr[position] = arr[position - 1];
                position--;
            }
            arr[position] = value;
        }
        print_cout(arr);
    }
};
int main()
{

    std::vector<int> datas = {4, 3, 7, 6, 1, 9};
    insert_sort ins;
    //ins.insertSort(datas);
    ins.test(datas);
}