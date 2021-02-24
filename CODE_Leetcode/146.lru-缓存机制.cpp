/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include<unordered_map>
#include<list>
using namespace std;
struct Dlist{
    int val, key;
    Dlist* prev;
    Dlist* next;
    Dlist():key(0),val(0),prev(nullptr),next(nullptr){}
    Dlist(int k, int v):key(k),val(v),prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
    int cap,size; 
    unordered_map<int,Dlist*> loc;
    // 双向链表，存个头尾不过分吧
    Dlist* head;
    Dlist* tail; // 指向最后一个的后一个

public:
    LRUCache(int capacity):cap(capacity),size(0) {
        head = new Dlist();
        tail = new Dlist();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!loc.count(key))
            return -1;
        // 最近使用，移到头部，删除原位
        Dlist* root = loc[key];
        movetohead(root);
        return root->val;
    }
    
    void put(int key, int value) {
        // 这里需要一个add和一个remove
        // 当cap不满的时候我们就直接加到List和Hash中，原值不存在
        if(!loc.count(key)){
            
            // 先创建新节点，然后判断cap
            Dlist* root = new Dlist(key,value);
            // 容易忘记在hash表中添加
            loc[key] = root;
            // 这里不是move是add要记清楚
            addHead(root);
            size++;
            if(size > cap){
                Dlist* temp = removeTail();
                loc.erase(temp->key);
                // 防止内存泄露
                delete temp;
                --size;
            }
        }else{
            Dlist* root = loc[key];
            root->val = value;
            movetohead(root);
        }
    }

    void movetohead(Dlist* root){
        // 实际上是删除炒作：上一个的下一个和下一个的上一个
        // 实际上也是put操作：然后接在头后面
        deleteNode(root);
        addHead(root);
    }

    void deleteNode(Dlist* root){
        root->prev->next = root->next;
        root->next->prev = root->prev;
    }

    void addHead(Dlist* root){
        root->next = head->next;
        root->prev = head;
        root->next->prev = root;
        head->next = root;
    }
    Dlist* removeTail(){
        // 由于tail指向的是最后一个的后一个，实际上我们只要调用delete就行了
        Dlist* temp = tail->prev;
        deleteNode(temp);
        // return是为了delete方便删除
        return temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

