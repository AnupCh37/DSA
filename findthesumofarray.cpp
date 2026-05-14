//Find the sum of array
#include<iostream>
#include<iterator>

int main() {
int arr[]={3,4,5,6,1,2,9,8,7};
int length=std::size(arr);
int sum=0;
for(int i=0;i<length;i++){
        sum+=arr[i];

}
std::cout<<"The sum of the array :"<<sum<<std::endl;
return 0;
}
//Space complexity-O(1)
//Time complexity-O(n)
