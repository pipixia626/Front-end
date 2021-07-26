#include <iostream>
#include <vector>

class Solution
{

public:
    void print_cout(const std::vector<int> datas)
    {
        for (auto it : datas)
        {
            std::cout << it << std::endl;
        }
    }
    void myMerge(std::vector<int> &datas)
    {
        std::vector<int> temp(datas.size());
        mergeSort(datas, temp, 0, datas.size() - 1);
        print_cout(datas);
    }

    void mergeSort(std::vector<int> &datas, std::vector<int> temp, int left, int right)
    {
        if (left < right)
        {
            int mid = left + right >> 1;
            mergeSort(datas, temp, left, mid);
            mergeSort(datas, temp, mid + 1, right);
            merge(datas, temp, left, mid, right);
        }
    }

    void merge(std::vector<int> &datas, std::vector<int> &temp, int left, int mid, int right)
    {

        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
        {
            temp[k++] = datas[i] <= datas[j] ? datas[i++] : datas[j++];
        }

        while (i <= mid)
        {
            temp[k++] = datas[i++];
        }
        while (j <= right)
        {
            temp[k++] = datas[j++];
        }

        for (i = 0; i < k; i++)
        {
            datas[left + i] = temp[i];
        }
    }
};
