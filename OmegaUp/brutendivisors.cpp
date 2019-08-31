#include <bits/stdc++.h>
using namespace std;
#define printVector(v) printf("Vector:\n"); \
    for(int ii = 0; ii < v.size(); ++ii){ \
        printf("%d\t", v[ii]); } \
        printf("\n");

#define MAXP 1001
#define MAXN 1000000

bool primes[1001];
int fakeDP[] = {0, 1, 2, 4, 8, 16, 30, 60, 96, 160, 270 };
vector<int> p;
// vector<long long> DP(MAXN+1);
void initPrimes(){
    for(int i = 2; i < 1001; ++i)
        primes[i] = 1;

    for(int i = 2; i < 1001; ++i){
        if(primes[i]){
            for(int j = i*i; j < 1001; j+=i){
                primes[j] = 0;
            }
        }
    }
    for(int i = 2; i < 1001; i++){
        if(primes[i])
            p.push_back(i);
    }
}

long long getPDivisors( int N ){
    if(N <= 10)
        return (long long) fakeDP[N];
    long long sum = 0, prod = 1, t = 0, ex = 1;
    for(int i = 0; i < p.size(); ++i){
        sum = 0;
        while( (t = floor( N*1.0/(pow(p[i], ex)) )) > 0 ){
            sum += t;
            ex++;
        }
        ex = 1;
        ++sum;
        prod *= sum;
        prod %= 987654321;
    }
    return prod % 987654321;
}

//Creo que no sirve mi DP porque se tarda bastantes segundos al inicio para calcular
// void initDP(){
//     for(int i = 0; i < MAXN; ++i){
//         DP[i] = getPDivisors(i);
//         // printf("%lld\t ", DP[i]);
//     }
// }

int main(){
    initPrimes();
    // initDP();
    int N;

    scanf("%d", &N);
    // for(N = 0; N < 11; ++N)
        printf("%lld\n", getPDivisors(N));
    return 0;
}
