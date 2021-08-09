//将List和find()藉由find粘合起来
#include"mylist.h"
#include"mylist-iter.h"
void main(){
    List<int> mylist;
    for(int i=0;i<5;++i){
        mylist.insert_front(i);
        mylist.insert_end(i+2);
    }
    mylist.display();//{4,3,2,1,0,2,3,4,5,6}
    //ListIter<ListItem<int>> begin(mylist.front());->未实现
    ListIter<ListItem<int> > end;//default 0 ,null
    ListIter<ListItem<int> > iter;//default 0 ,null
    //find
}