// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward.

// For example, 121 is a palindrome while 123 is not.
 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -231 <= x <= 231 - 1
 

// Follow up: Could you solve it without converting the integer to a string?

//My way

bool isPalindrome(int x){
    if(x < 0){
        return false;
    }
    if(x < 10){
        return true;
    }

    long long int maxLenValue = 1, len = 0;
    for(; maxLenValue <= x; maxLenValue*=10, len++){}
    maxLenValue/=10;
    printf("%lld\t%d\n",maxLenValue,len);
    int rightInt = 1;
    for(int i = 0; i < len/2; i++){
        rightInt*=10;
    }
    rightInt = x%rightInt;
    printf("%d\n",rightInt);
    int numOfDigit = 1;
    int leftInt = 0;
   for(int i = 0; i < len/2; i++){
       leftInt += x/maxLenValue*numOfDigit;
       x -= x/maxLenValue*maxLenValue;
       maxLenValue/=10;
       numOfDigit*=10;
   }

   printf("%d\t%d\n",rightInt,leftInt);
   if(leftInt == rightInt){
       return true;
   } else{
       return false;
   }
}

// Better way
// 用array裝每個位數的值確認映射

// bool isPalindrome(int x) {
    
//     int digits[10];
    
//     if (x<0) {
//         return false;
//     }
    
//     int maxIndex = 0;
//     while(x!=0) {
//         digits[maxIndex] = x % 10;
//         x /= 10;
//         maxIndex++;
//     }
    
//     int i=0, j=maxIndex -1;
    
//     while (i<j) {
//         if (digits[i] != digits[j]) {
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }