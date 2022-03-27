// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry every given person.

 

// Example 1:

// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)
// Example 2:

// Input: people = [3,2,2,1], limit = 3
// Output: 3
// Explanation: 3 boats (1, 2), (2) and (3)
// Example 3:

// Input: people = [3,5,3,4], limit = 5
// Output: 4
// Explanation: 4 boats (3), (3), (4), (5)
 

// Constraints:

// 1 <= people.length <= 5 * 104
// 1 <= people[i] <= limit <= 3 * 104

//My way
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
/*
    原本預設方法為: 排序過後的陣列找頭尾能配得上一艘船的,目前最重的人如果跟目前最輕的搭不上一艘船
    就獨立一艘船給目前最重的搭,走到陣列中間後再用頭尾兩個指標關係判斷是否有最中間的人沒搭到船
*/
int numRescueBoats(int* people, int peopleSize, int limit){
    qsort(people, peopleSize, sizeof(int), cmp);
    int numOfBoat = 0;
    int start = 0, end = peopleSize-1;
    while(start != end && end > start){
        if(people[start] + people[end] > limit){
            end--;
            numOfBoat++;
        } else {
            start++; end--; numOfBoat++;
        }
    }
    if(start == end){
        numOfBoat++;
    }
    return numOfBoat;
}

//Better way
/*
    跟排序陣列不一樣,選擇用額外記憶體空間配置去記錄每種重量的個數,後續找人的方式相同
    不過因為qsort的排序速度為O(nlogn)而記錄個數指需要n就可以做到相應效果
*/
int numRescueBoats(int* people, int peopleSize, int limit) {
    int max=people[0];
    int i,j;
    int res=0;
    
    for (i = 1; i < peopleSize; ++i){
        // Find max "weight".
        if (max < people[i]) max = people[i];
    }
    
    //     Create an array with size max, the size of this array
    // is independant of the people array's size.
    int bucket[max+1];
    
    // Initialize all the elements to zero.
    memset(bucket, 0, sizeof(bucket));
    
    for (i = 0; i < peopleSize; ++i) {
        //     Every "weight" corresponds to a index in the "bucket" array. 
        // If there are ten "people" of size five, then bucket[5] == 10.
        //     This also creates a sorted array that may have many indexes
        // with a value of zero (a "sparse array").
        ++bucket[people[i]];
    }
    
    i = 1; // A "person" has to weigh atleast one.
    j = max;
    
    for (;;){
         
        //     From the FRONT of the array, find the next index in "bucket" 
        // that is greater than zero. These are the "light people".
        while(i <= j && bucket[i] <= 0) ++i;
        
        //     From the END of the array, find the next index in "bucket" 
        // that is greater than zero. These are the "heavier people". 
        while(i <= j && bucket[j] <= 0) --j;
        
        //     If the "i" pointer is greater than the "j" pointer, then
        // the loop has finished.
        if(i > j) break;
        
        // Increment the response variable.
        ++res;
        
        //     If a "lighter person" can be added to a boat with a "heavier
        // person" then decrement the value at index "i".
        //     The logic is that "i" and "j" correspond to "weights of people",
        // and each "i" and "j" index in "bucket" are how many "people" there
        // are that "weigh" whatever "i" and "j" is.
		//     Example: If a "person" that "weighs" whatever "i" is can be 
		// added to a boat with a "heavier person", if "i" is 5 and bucket[5] == 1 
		// (there is one "person" with a "weight" of five) then it will be 
		// decremented and bucket[5] == 0 (one person with a "weight" of
		// five "shared a boat with a heavier person" so there is one less
		// "person" with a "weight" of five), the while loop above will increment
		// "i" until it finds an index in "bucket" that isn't zero. If, however, 
		// bucket[5] == 10, then the while loop above will not increment  "i" 
		// while there are still "people" that "weigh" five.
		if(i + j <= limit) --bucket[i];
        
        //     The "heaviest people" will always get a "boat". Every loop 
		// decrement the value at index "j".
        --bucket[j];
    }
    
    return res;
}