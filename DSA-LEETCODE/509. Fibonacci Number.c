class Solution{
    public :
        int fib(int n, int a = 0, int b = 1){
            if (n == 0) return a;
else if (n == 1) return b;
else return fib(n - 1, b, a + b);
}
}
;