#include <stdio.h>
#include <stdlib.h>
#define row 6
#define col 7

void peak_finder_locations(int arr1[row][col], int storage);

int peak_finder(int arr1[row][col]);

/*
 AUTHOR: Suchith Chandan Reddy Pinreddy
 FILENAME: problem1.c
 SPECIFICATION: The problem is to find peaks in the multi-dimensional array which consist of elevation grids.
 FOR: CS 2413 Data Structures Section 002
*/

int main()
{
    int arr[][col]={{5039,5127,5238,5259,5248,5310,5299}, {5150, 5392, 5410, 5401, 5320, 5820, 5321},
    {5290,5560,5490,5421,5530,5831,5210}, {5110,5429,5430,5411,5459,5630,5319}, {4920,5129,4921,5821,4722,4921,5129},
    {5023,5129,4822,4872,4794,4862,4245}}; // multidimensional array
    int space = peak_finder(arr); //space calculate space for array that is storing the location of peaks
    peak_finder_locations(arr, space);

}
/*
 NAME: peak_finder
 PARAMETERS: int data type multi dimensional array arr1
 PURPOSE: The function computes how many peaks are there in elevation grid
 PRECONDITION: The function only takes multidimensional array with row size of 6 and column size of 7
 POSTCONDITION: The function will return the peaks in the elevation grid with the variable name of counter and
                the function will only return if the north, south, west, and east coordinates are smaller compared to a data point.
*/

int peak_finder(int arr1[row][col]){
    int counter = 0; //peaks counter
    for (int i = 1; i<row-1;i++){
        for (int j = 1; j < col-1; j++){
            if (arr1[i][j]>arr1[i-1][j]){
                if(arr1[i][j]>arr1[i+1][j]){
                    if(arr1[i][j]>arr1[i][j-1]){
                        if(arr1[i][j]>arr1[i][j+1]){
                            counter+=1;
                        }
                    }
                }
            }
        }
    }
    return counter;
}
/*
 NAME: peak_finder_locations
 PARAMETERS: int data type multi dimensional array arr2 and int data type number_peaks
 PURPOSE: The function computes the locations of the peaks.
 PRECONDITION: The function only takes multidimensional array with row size of 6 and column size of 7 and it also needs int data type variable.
 POSTCONDITION: The function will find the location of peaks if the north, south, west, and east coordinates are smaller compared to a data point and print
                the locations of peaks and how peaks does the elevation grid has.
*/

void peak_finder_locations(int arr2[row][col], int number_peaks){
    int x, y; //x and y are coordinates for rows and columns for peak locations
    //int peak;
    //int peak_index= 0;
    int index = 0; //index used to store in location array
    int locations[number_peaks*2];
    //int peaks[number_peaks];
    for (int i = 1; i<row-1;i++){
        for (int j = 1; j < col-1; j++){
            if (arr2[i][j]>arr2[i-1][j]){
                if(arr2[i][j]>arr2[i+1][j]){
                    if(arr2[i][j]>arr2[i][j-1]){
                        if(arr2[i][j]>arr2[i][j+1]){
                            //peak = arr2[i][j];
                            //peaks[peak_index]=peak;
                            //peak_index++;
                            x = i;
                            locations[index] = x;
                            index++;
                            y = j;
                            locations[index] = y;
                            index++;
                        }
                    }
                }
            }
        }

    }
    printf("%d peaks are found\n", number_peaks);
    for(int k = 0; k< index; k++){
        printf("The peak locations at row %d and column %d\n", locations[k], locations[k+1]);
        k++;
    }
}
/*
------->Answers:
------->2.c
3 peaks are found
The peak locations at row 2 and column 1
The peak locations at row 2 and column 5
The peak locations at row 4 and column 3
----------------------------------------------------------------------------------------------------------------------------------------------
------->2.d
-The Big O storage complexity for storing data is m*n since the data is stored in multi-dimensional array which in turn becomes O(n^2).
-The Big O of number of peaks is O(1) because for storing of peak I am using variables which is O(1).
-The Big O of locations of peaks is O(N) because I am using arrays which is generated peaks variable times 2 since every peak in array
 has 2 data points. So currently with three peaks I have an array of size 6 and it will decrease and increase automatically as peaks increase
 or decrease.
------->2.d.iii
- The Time complexity of the code is O(N^2) since my program is only using two nested for loop and an additional for loop making my program 2n^2+n <= O(n^2).
- 0 <= 2n^2 + n <= cn^2
- 0/n <= 2n^2/n^2 + n/n^2<= cn^2/n^2
- 0 <= 2 + 1/n <= c, make at n = 1
- 0 <= 3 <= c, so c = 3
- for c = 3 and n>= 1, 2n^2 + n is O(n^2)
- 2n^2 + n <= O(n^2)
*/
