#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<iostream>
#include <algorithm>

// BUBBLE SORT ALGORITHM

template <typename T>
void bubbleSort(T arr[], size_t arrSize){
    //Step 1: For i = 0 to N-1 repeat Step 2 
    for(int i = 0; i < arrSize; i++){
        //Step 2: For J = i + 1 to N – I repeat
        for(int j = i+1; j < arrSize; j++){
            //Step 3: if A[J] > A[i] 
            if(arr[j]>arr[i]){
                //Swap A[J] and A[i] 
                std::swap(arr[j], arr[i]);
            }
            //[End of Inner for loop]
        }
        //[End if Outer for loop]
    }
    //Step 4: Exit
}

// SELECTION SORT ALGORITHM

template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize);

template <typename T>
void selectionSort(T arr[], const int N){ 
    int POS, temp, pass=0;
    //Step 1: Repeat Steps 2 and 3 for K = 1 to N-1 
    for(int i = 0; i < N; i++){
        //Step 2: Call routine smallest(A, K, N,POS) 
        POS = Routine_Smallest(arr, i, N);
        temp = arr[i];
        //Step 3: Swap A[K] with A [POS] 
        arr[i] = arr[POS];
        arr[POS] = temp;
        //Count 
        pass++;
    }
    //[End of loop]
    //Step 4: EXIT
}

//Routine smallest (Array, Current Position, Size of Array)
template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize){
    int position, j;
    //Step 1: [initialize] set smallestElem = A[K]
    T smallestElem = A[K];
    //Step 2: [initialize] set POS = K
    position = K;
    //Step 3: for J = K+1 to N -1,repeat
    for(int J=K+1; J < arrSize; J++){
        if(A[J] < smallestElem){
            smallestElem = A[J];
            position = J;
        }
    }
    //Step 4: return POS
    return position;
}

// INSERTION SORT ALGORITHM

template <typename T>
void insertionSort(T arr[], const int N){
    int K = 0, J, temp;
    //Step 1: Repeat Steps 2 to 5 for K = 1 to N-1
    while(K < N){
        //Step 2: set temp = A[K]
        temp = arr[K];
        //Step 3: set J = K – 1
        J = K-1;
        //Step 4: Repeat while temp <=A[J]
        while (J >= 0 && temp <= arr[J]) {
            //set A[J + 1] = A[J]
            arr[J+1] = arr[J];
            //set J = J – 1
            J--;
            //[end of inner loop]
        }
        //Step 5: set A[J + 1] = temp
        arr[J+1] = temp;
        //[end of loop]
        K++;
    }
    //Step 6: exit
}

// COUNT VOTE FUNCTION

struct Candidate {
    std::string name;
    int votes;
};

void countVote(int vote[], Candidate candidates[], int totalSize) {
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
    for (int i = 0; i < totalSize; i++) {        
        int x = vote[i];
        if (x == 1) {
            c1++;
        } else if (x == 2) {
            c2++;
        } else if (x == 3) {
            c3++;
        } else if (x == 4) {
            c4++;
        } else if (x == 5) {
            c5++;
        }
    }

    std::cout << candidates[0].name << " total votes: " << c1 << std::endl;
    std::cout << candidates[1].name << " total votes: " << c2 << std::endl;
    std::cout << candidates[2].name << " total votes: " << c3 << std::endl;
    std::cout << candidates[3].name << " total votes: " << c4 << std::endl;
    std::cout << candidates[4].name << " total votes: " << c5 << std::endl;
}

#endif