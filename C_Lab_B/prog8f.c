#include<stdio.h>


double cos_rec(double x,long p,long i,double term,int sign){
    if(p==1000){
        return (sign*term);
    }
    double ans = (sign*term);
    term*=(x/++i)*(x/++i);
    sign*=-1;
    return ans+cos_rec(x,p+1,i,term,sign);
}

int main(){
    long i=0;
    double term=1,ans=0,n;
    int sign =1;
    scanf("%lf",&n);
    printf("%lf",cos_rec(n,0,i,term,sign));
    return 0;
}