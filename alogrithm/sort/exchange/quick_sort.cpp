#include <iostream>
#include <vector>

class quick_sort
{
public:
    std::vector<int> Mysort(std::vector<int> &arr)
    {
        quickSort(arr, 0, arr.size() - 1);
        return arr;
    }

    void quickSort(std::vector<int> &arr, int left, int right)
    {
        if (left < right)
        {
            int point = partition(arr, left, right);
            quickSort(arr, left, point - 1);
            quickSort(arr, point + 1, right);
        }
    }
    int partition(std::vector<int> &arr, int left, int right)
    {
        //int first=arr[left];
        int first = RandomInRange(left, right);
        while (left < right)
        {
            while ((left < right) && arr[right] >= first)
            {
                right--;
            }
            swap(arr, left, right);
            while ((left < right) && arr[left] <= first)
            {
                left++;
            }
            swap(arr, left, right);
        }
        return left;
    }
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
    int RandomInRange(int min, int max)
    {
         return rand() % (max - min + 1) + min;
     
    }
};

int main()
{
    std::vector<int> datas = {3, 5, 7, 4, 6, 9};
    quick_sort q;
    q.Mysort(datas);
    q.print_cout(datas);
}