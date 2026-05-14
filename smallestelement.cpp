//Find the smallest element in the array
#include<iostream>
#include<iterator>

int main() {
     int arr [] = {2,4,-8,8,2,9,10,3,7};
     int arr_length = std::size(arr);
     int smallest = arr[0] ;
     for (int i=0 ; i<arr_length; i++){
        if(arr[i]<smallest){
           smallest = arr[i];
        }
     }
     std::cout <<"The smallest element of the array"<<smallest<<std::endl;
    return 0 ;
}

//space complexity = O()
//time complexity = O()
