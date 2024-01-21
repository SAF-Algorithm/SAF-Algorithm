#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > v(101, vector<int>(2, 0));
vector< vector<int> > memo(101, vector<int>(100001, -1));
int N, k, result = 0;

int search(int n, int weight){
    if(n==-1 || weight == 0){
        return 0;   //재귀 종료
    }

    if(memo[n][weight] != -1)
        return memo[n][weight];

    int value = search(n-1, weight);

    if(v[n][0] <= weight){
        int withItem = v[n][1] + search(n - 1, weight - v[n][0]); 
        result = max(withItem, value);
        // cout << "test: "<<v[n][0]<<", v[n][1] : "<<v[n][1]<<" result : "<<result<<"\n";
    }
    else 
        result = value;
    
    memo[n][weight] = result;
    return result;
}

int main(){
    cin >> N >> k;

    for(int i=0; i<N; i++){
        cin >> v[i][0] >> v[i][1];
        if(v[i][0] > k) v[i][1] = 0;
    }

    search(N-1, k);
    cout << result;
    
    return 0;
}