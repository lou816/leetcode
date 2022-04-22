// Design a HashMap without using any built-in hash table libraries.

// Implement the MyHashMap class:

// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
// int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

// Example 1:

// Input
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// Output
// [null, null, null, 1, -1, null, 1, null, -1]

// Explanation
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // The map is now [[1,1]]
// myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
// myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
// myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
// myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
// myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
// myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
// myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

// Constraints:

// 0 <= key, value <= 106
// At most 104 calls will be made to put, get, and remove.

//My way

typedef struct node{
    int val;
    int key;
    struct node *next;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *hashMap = (MyHashMap*)malloc(sizeof(MyHashMap) * 100);
    for(int i = 0; i < 100; i++){
        hashMap[i].val = -1;
        hashMap[i].key = -1;
        hashMap[i].next = NULL;
    }
    return hashMap;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = key % 100;
    obj += index;
    while(obj->next){
        if(obj->next->key == key){
            obj->next->val = value;
            return;
        }
        obj = obj->next;
    }
    MyHashMap *temp = (MyHashMap*)malloc(sizeof(MyHashMap) * 1);
    temp->key = key;
    temp->val = value;
    temp->next = NULL;
    obj->next = temp;
    return;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index = key % 100;
    obj += index;
    while(obj){
        if(obj->key == key)
            return obj->val;
        obj = obj->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = key % 100;
    obj += index;
    while(obj->next){
        if(obj->next->key == key){
            MyHashMap *temp = obj->next;
            obj->next = temp->next;
            free(temp);
            return;
        }
        obj = obj->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    MyHashMap *head = obj;
    for(int i = 0; i < 99; i++){
        obj++;
        MyHashMap *curr = obj->next, *precurr;
        while(curr){
            precurr = curr->next;
            free(curr);
            curr = precurr;
        }
    }
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/