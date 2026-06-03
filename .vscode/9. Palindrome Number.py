#include<cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x>=0){
            int length =(x>0) ? (std::log10(x)+1):0;
            int num=x;
            long int rev=0,rem=0;
        while(num!=0){
             length--;
            rem=num%10;
            rev= (std::pow(10,length)) * rem+rev;
            num=num/10;
           
        }
        if(rev==x){
        return true;
        } 
        }
       return false ;
    }
};