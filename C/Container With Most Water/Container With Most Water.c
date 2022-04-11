// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104

//My way

int maxArea(int* height, int heightSize){
    int *first = height, *last = first+heightSize-1, water = 0;
    //最大值預設為寬度最大的面積
    while(first < last){
        int high = *first < *last ? *first:*last;
        int w = (last - first) * high;
        if(w > water) water = w;
        //只有當兩條都比原本高還要高的時候才有可能會有更大的面積
        while(*first <= high && first < last) first++;
        while(*last <= high && first < last) last--;
    }
    return water;
}