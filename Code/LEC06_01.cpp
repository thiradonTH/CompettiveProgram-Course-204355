#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    scanf("%d", &n);

    priority_queue<long, vector<long>, greater<long>> pq;

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
    long cost = 0;
    while(pq.size() >= 2){
        int i, j;

        i = pq.top();
        pq.pop();
        j = pq.top();
        pq.pop();

        cost += i + j;
        pq.push(i + j);
    }

    printf("%ld", cost);

    
    


    return 0; 
}