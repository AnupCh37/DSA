//Find the largest element it the array
#include<iostream>
#include<iterator>

int main()
{
   int arr[]= {3,6,5,7,67,2,1};
  int length = std::size(arr);
   int largest=0;
   for (int i=0; i<length;i++){
      if(arr[i]>largest){
      largest =arr[i];
   } }

   std:: cout<<"The largest element \n"<<largest <<std::endl;
    return 0 ;

}
