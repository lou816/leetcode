// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

// Example 1:

// Input
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// Output
// [null, null, null, true, false, null, true, null, false]

// Explanation
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // return True
// myHashSet.contains(3); // return False, (not found)
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // return True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // return False, (already removed)
 

// Constraints:

// 0 <= key <= 106
// At most 104 calls will be made to add, remove, and contains.

//My way

typedef struct hash{
    int val;
    struct hash *next;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet *hashTable = (MyHashSet*)malloc(sizeof(MyHashSet) * 1000);
    for(int i = 0; i < 1000; i++){
        hashTable[i].val = -1;
        hashTable[i].next = NULL;
    }
    return hashTable;
}

void myHashSetAdd(MyHashSet* obj, int key) {   
    int index = key % 1000;
    obj += index;
    while(obj->next){
        if(obj->next->val == key){
            return;
        }
        obj = obj->next;
    }
    MyHashSet *temp = (MyHashSet*)malloc(sizeof(MyHashSet) * 1);
    temp->val = key;
    obj->next = temp;
    temp->next = NULL;
}

void myHashSetRemove(MyHashSet* obj, int key) {
        
    int index = key % 1000;
    obj += index;
    while(obj->next){
        if(obj->next->val == key){
            MyHashSet *temp = obj->next;
            obj->next = temp->next;
            free(temp);
            return;
        }
        obj = obj->next;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {

    int index = key % 1000;
    obj += index;
    while(obj->next){
        if(obj->next->val == key)
            return true;
        obj = obj->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    MyHashSet *head = obj;
    for(int i = 0; i < 999; i++){
        obj ++;
        MyHashSet *curr = obj->next, *precurr;
        while(curr){
            precurr = curr->next;
            free(curr);
            curr = precurr;
        }
    }
    free(head);
    return;
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/