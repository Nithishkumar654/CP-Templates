/* Author: S. Nithish Kumar :: nithish654 :: */
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int n = rand(2, 25);

    cout << n << '\n';
    for(int i = 0; i < n; i++){
        cout << rand(1, 100) << " \n"[i == n - 1];
    }
}