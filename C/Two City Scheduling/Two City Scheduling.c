// A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

// Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

 

// Example 1:

// Input: costs = [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Explanation: 
// The first person goes to city A for a cost of 10.
// The second person goes to city A for a cost of 30.
// The third person goes to city B for a cost of 50.
// The fourth person goes to city B for a cost of 20.

// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
// Example 2:

// Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
// Output: 1859
// Example 3:

// Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
// Output: 3086
 

// Constraints:

// 2 * n == costs.length
// 2 <= costs.length <= 100
// costs.length is even.
// 1 <= aCosti, bCosti <= 1000


//My way

int cmp(const void* a, const void *b){
    const int* arr1 = (const int*)a;
    const int* arr2 = (const int*)b;
    return arr2[0] - arr1[0];
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int difference[costsSize][3];
    memset(difference,0,sizeof(int)*costsSize*3);
    for(int i = 0; i < costsSize; i++){
        if(costs[i][0] > costs[i][1]){
            difference[i][0] = costs[i][0]-costs[i][1];
            difference[i][1] = i;
            difference[i][2] = 1;
            continue;
        }
        difference[i][0] = costs[i][1]-costs[i][0];
        difference[i][1] = i;
        difference[i][2] = 0;
    }

    qsort(difference,costsSize,sizeof(difference[0]),cmp);
    for(int i = 0; i < costsSize; i++){
        printf("%d\t%d\t%d\n",difference[i][0],difference[i][1],difference[i][2]);
    }

    int totCost = 0;

    for(int i = 0, maxA = 0, maxB = 0; i < costsSize; i++){
        if(maxA >= costsSize/2){
            totCost += costs[difference[i][1]][1];
        } else if(maxB >= costsSize/2){
            totCost += costs[difference[i][1]][0];
        } else{
            totCost += costs[difference[i][1]][difference[i][2]];
            if(difference[i][2] == 0)
                maxA++;
            else
                maxB++;
        }
    }
    return totCost;
}