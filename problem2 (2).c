#include <stdio.h>
#include <stdlib.h>

int substring_finder(char substring[], char original_string[]);
/*
 AUTHOR: Suchith Chandan Reddy Pinreddy
 FILENAME: problem2.c
 SPECIFICATION: The problem is to find substring in the sentence.
 FOR: CS 2413 Data Structures Section 002
*/
int main()
{

    char sub[] = "carrot";
    char s[] = "Bob likes cars and carrots";
    int substring_counter = substring_finder(sub, s);
    printf("Search for '%s' in '%s' - location %d\n",sub, s, substring_counter);

}
/*
 NAME: substring_finder
 PARAMETERS: char data type string named substring and original_string.
 PURPOSE: The function computes if substring exist in a sentence.
 PRECONDITION: The function only takes char data type of strings
 POSTCONDITION: The function will return the location of start of substring location if substring exist the sentence which is an int data and
                the function will return -1 if there is no substring exists.
*/
int substring_finder(char substring[], char original_string[]){
    int sub_index = 0;
    int substring_len = 0;
    int start_location = 0;
    while(substring[substring_len]!='\0'){
        substring_len++;
    }
    for (int i = 0; original_string[i]!= '\0';i++){
        if (substring[sub_index]==original_string[i]){
            sub_index++;
            if (substring[0]==original_string[i]){
                start_location = i;
            }
            if (sub_index==substring_len){
                break;
            }
        }
        else{
            sub_index=0;
            start_location = -1;
        }
    }
    return start_location;
}
/*
------->Answers:
------->2.b or 2.d.i:
Search for 'carrot' in 'Bob likes cars and carrots' - location 19
---------------------------------------------------------------------------------------------------------------------------------------------------
------->2.d.ii.1:
The worst case substring and string example would be for brute force is string = "Hello, my name is suchith" and the substring = "suchith" which makes
string - substring since the substring matches at end of the string which will make the program to run entirely which will make my program 2n since there
are only two separate loops running the program. The big O complexity for my program would Big O (N) since I am only using two separate loop making it
2n but typically brute force algorithm has big O(n^2) since it has to check everything in the worst case scenario.
----------------------------------------------------------------------------------------------------------------------------------------------------------
------->2.d.ii.2:
The best case for optimized solution is when substring appears in the beginning of string for example string = "Suchith is my name" and the substring = "Suchith"
which makes substring - string since it is in the beginning of the string which will make the program run the first instance which will make the the program
O(1) since it is in the beginning of the string. The big O complexity for best case in optimized solution is O(1) since it will check word by word and in
that word it will see if the letter matches or not instead of checking every character which makes O(1).
*/
