// Design an iterator that supports the peek operation on an existing iterator in addition to the hasNext and the next operations.

// Implement the PeekingIterator class:

// PeekingIterator(Iterator<int> nums) Initializes the object with the given integer iterator iterator.
// int next() Returns the next element in the array and moves the pointer to the next element.
// boolean hasNext() Returns true if there are still elements in the array.
// int peek() Returns the next element in the array without moving the pointer.
// Note: Each language may have a different implementation of the constructor and Iterator, but they all support the int next() and boolean hasNext() functions.

 

// Example 1:

// Input
// ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
// [[[1, 2, 3]], [], [], [], [], []]
// Output
// [null, 1, 2, 2, 3, false]

// Explanation
// PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
// peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
// peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
// peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
// peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
// peekingIterator.hasNext(); // return False
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// All the calls to next and peek are valid.
// At most 1000 calls will be made to next, hasNext, and peek.
 

// Follow up: How would you extend your design to be generic and work with all types, not just integer?

//My way 
// struct Iterator {
//     // Returns true if the iteration has more elements.
//     bool hasNext();
//     // Returns the next element in the iteration.
//     int next();
// };

struct PeekingIterator {
    struct Iterator *iterator;
    int peekVal;
    bool hasPeeked;
};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = (struct PeekingIterator *)malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->peekVal = piter->iterator->next();
    piter->hasPeeked = true;
    return piter;
}
//
//此做法為把 hasPeeked 永遠設成true 判斷有無結尾
// struct PeekingIterator* Constructor(struct Iterator* iter) {
//     struct PeekingIterator* piter = (struct PeekingIterator *)malloc(sizeof(struct PeekingIterator));
//     piter->iterator = iter;
//     piter->peekVal = piter->iterator->next();
//     piter->hasPeeked = true;
//     return piter;
// }

// int peek(struct PeekingIterator* obj) {
//     return obj->peekVal;
// }

// int next(struct PeekingIterator* obj) {
//     int result = obj->peekVal;
//     if(obj->iterator->hasNext()){
//         obj->peekVal = obj->iterator->next();
//         obj->hasPeeked = true;
//     }else{
//         obj->hasPeeked = false;
//     }
//     return result;
// }

// bool hasNext(struct PeekingIterator* obj) {
//     if(obj->hasPeeked){
//         return true;
//     }
//     return obj->iterator->hasNext();
// }

int peek(struct PeekingIterator* obj) {
    if(!obj->hasPeeked){
        obj->peekVal = obj->iterator->next();
        obj->hasPeeked = true;
    }
    return obj->peekVal;
}

int next(struct PeekingIterator* obj) {
    if(obj->hasPeeked){
        obj->hasPeeked = false;
    }else{
        return obj->iterator->next();
    }
    return obj->peekVal;
}

bool hasNext(struct PeekingIterator* obj) {
    if(obj->hasPeeked){
        return true;
    }
    return obj->iterator->hasNext();
}

/**
 * Your PeekingIterator struct will be instantiated and called as such:
 * PeekingIterator* obj = peekingIteratorCreate(arr, arrSize);
 * int param_1 = peek(obj);
 * int param_2 = next(obj);
 * bool param_3 = hasNext(obj);
 * peekingIteratorFree(obj);
*/
