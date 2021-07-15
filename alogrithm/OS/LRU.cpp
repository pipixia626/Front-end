
/*运用你掌握的数据结果，设计和实现一个LRU(最近最少使用)缓存机制
LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 */
#include<iostream>
#include<unordered_map>
using namespace std;

struct  DLinkedNode
{
    int key,value;
    DLinkedNode*prev;
    DLinkedNode*next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};
class LRUCache{
    private:
    unordered_map<int,DLinkedNode*>cache;
    DLinkedNode*head;//伪头部
    DLinkedNode*tail;//伪尾部
    int size;
    int capacity;

    public:
    LRUCache(int _capacity):capacity(_capacity),size(0){
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->next=tail;
        tail->next=head;
    }

    int get(int key){
        if(!cache.count(key)){
            return -1;
        }
        //如果key存在，先通过哈希表定位，再移动到头部
        DLinkedNode*node=cache[key];
        moveToHead(node);
        return node->value;
    }
    void put(int key,int value){
        if(!cache.count(key)){
            //如果key不存在，创建一个新的节点
            DLinkedNode*node=new DLinkedNode(key,value);
            //添加进哈希表中
            cache[key]=node;
            //添加至双向链表的头部
            addToHead(node);
            ++size;
            if(size>capacity){
            //如果超出容量，则删除尾部节点
            DLinkedNode*removed=removeTail();
            cache.erase(removed->key);
            delete removed;
            --size;
            }
        }
        else{
            //如果key存在，先通过哈希表定位，再修改value,并移到头部
            DLinkedNode*node=cache[key];
            node->value=value;
            moveToHead(node);
        }
    }
    bool moveToHead(DLinkedNode*node){
          removeNode(node);
          addToHead(node);
          return true;
    }
    bool removeNode(DLinkedNode*node){
            node->prev->next=node->next;
            node->next->prev=node->prev;
    }
    bool addToHead(DLinkedNode*node){
            node->prev=head;
            node->next=head->next;
            head->next->prev=node;
            head->next=node;
    }
    DLinkedNode* removeTail(){
             DLinkedNode*node =tail->prev;
             removeNode(node);
             return node;
    }
};
