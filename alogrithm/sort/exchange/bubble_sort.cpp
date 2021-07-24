#include <iostream>
#include <vector>

class bubble_sort
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
    // 优化之后，用change判断上一次有没有扫描出来
    void bubbleSort(std::vector<int> &arr, int n)
    {
        int i, j;
        bool change = true;
        for (i = n - 1; i > 1 && change; i--)
        {
            change = false;
            for (j = 0; j < i; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr, j, j + 1);
                    change = true;
                }
            }
        }
    }

};

// void test(std::vector<int>&datas,int n){
//     int i,j;
//     bool change=true;
//     for(int i=n-1;i>1&&change;i--){
//         change=false;
//         for(int j=0;j<i;j++){
//             if(datas[j]>datas[j+1]){
//                 swap(datas,j,j+1);
//                 change=true;
//             }
//         }
//     }
// }
int main()
{
    std::vector<int> datas = {4, 3, 7, 6, 1, 9};
    bubble_sort bubble;
    bubble.bubbleSort(datas, datas.size());
    bubble.print_cout(datas);
}
