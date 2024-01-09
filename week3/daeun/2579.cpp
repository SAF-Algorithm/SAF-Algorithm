#include <iostream>
#include <vector>
using namespace std;
vector<int> v (301);
vector< vector<int> > mark(301, vector<int>(2, -1));


int search(int n, int prec){

    if(n==0) return mark[0][prec] = v[0];
    if(n==1) {
        if(prec==1) return mark[1][prec] = v[1];
        else return mark[1][prec] = v[1] + v[0];
    }

    if(mark[n][prec]!=-1) return mark[n][prec];

    if(prec)
        return mark[n][prec] = v[n] + search(n-2, 0);
    else
        return mark[n][prec] = v[n] +  max(search(n-1, 1), search(n-2, 0));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    cout << search(n-1, 0);
    return 0;
}

// 12
// 0
// 1
// 1
// 100
// 100
// 1
// 1
// 1
// 1
// 1
// 100
// 100

// output: 305
// answer: 403