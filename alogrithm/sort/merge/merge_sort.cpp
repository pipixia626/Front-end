#include <vector>
#include <iostream>

class merge_sort
{
public:
    void print_cout(const std::vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << "->";
        }
        std::cout << std::endl;
    }
    void myMerge(std::vector<int> &arr)
    {
        //temp 数组占空间，虽然时间挺快的，但是空间上不利于大规模的数
        std::vector<int> temp(arr.size());
        mergeSort(arr, temp, 0, arr.size() - 1);
        print_cout(arr);
    }

    void mergeSort(std::vector<int> &arr, std::vector<int> temp, int left, int right)
    {
        if (left < right)
        {
            int mid = left + right >> 1;
            mergeSort(arr, temp, left, mid);      //左子数组
            mergeSort(arr, temp, mid + 1, right); //右子树组
            merge(arr, temp, left, mid, right);   //合并两个子数组
        }
    }
    void merge(std::vector<int> &arr, std::vector<int> temp, int left, int mid, int right)
    {
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
        {
            temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        }
        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while (j <= right)
        {
            temp[k++] = arr[j++];
        }
        //把数据复制回数组
        for (i = 0; i < k; i++)
        {
            arr[left + i] = temp[i];
        }
    }
};

int main()
{
    std::vector<int> datas = {4, 3, 7, 6, 1, 9};
    merge_sort m;
    m.myMerge(datas);
}