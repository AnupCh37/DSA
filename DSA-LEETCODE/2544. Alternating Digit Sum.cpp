class Solution {
public:
    int alternateDigitSum(int n) {
         stack<int>num;
         int sum=0;
        while(n!=0){
          num.push(n%10);
          n=n/10;
        }
        int i=0;
        while(!num.empty()){
         if(i%2==0)
        {
         sum+=num.top();  
        }
        else {
            sum-=num.top();
        }
        num.pop();
        i++;
        }
        return sum;
    }
};