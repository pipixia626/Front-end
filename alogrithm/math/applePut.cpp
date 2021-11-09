#include<iostream>
#include<vector>
using namespace std;

int main(){
    int apple,plate;
    cin>>apple>>plate;

    if (apple < 0 || apple > 10 || plate < 1 || plate > 10) {
		cout << "wrong input" << endl;
	}

    vector<vector<int>>ivec(11,vector<int>(11,0));
    for(int i=0;i<11;++i){
        ivec[0][i]=1;//没有苹果的盘子，所有盘子都为空
        ivec[i][1]=1;//只有一个盘子
    }
    //i:是苹果，j是盘子
    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            if(i>=j)//盘子数量小于苹果数量
            {   
                //某个盘子为空+每个盘子都放一个
                //含有空的方案数，即至少有一个盘子空着
                ivec[i][j]=ivec[i][j-1]+ivec[i-j][j];
            }
            else{
                ivec[i][j]=ivec[i][i];
            }
        }
    }
    return ivec[apple][plate];
}