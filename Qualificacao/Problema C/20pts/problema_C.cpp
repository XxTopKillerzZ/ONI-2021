#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//<>
using namespace std;

int main()
{
    int part,N,X,i,j,input,last,ans=0;

    cin >> part >> N >> X;

    vector<int> A;
    vector<int> A_clean;
    map<int, int> Appearance_A;
    int A_size=0;
    //map<int, int>::iterator A_it;

    vector<int> B;
    vector<int> B_clean;
    map<int, int> Appearance_B;
    int B_size=0;
    //map<int, int>::iterator B_it;

    map<int, int>::iterator it;

    for (i=0;i<N;++i) {
        cin >> input;
        A.push_back(input);
    }
    sort(A.begin(), A.end());
    last = 0;
    for (int i=0;i<N;++i) {
        if (A[i]!=last) {
            A_clean .push_back(A[i]);
            A_size++;
            Appearance_A[A[i]] = 1;
        } else {
            Appearance_A[A[i]]++;
        }
        last = A[i];
    }
    A.clear();

    for (i=0;i<N;++i) {
        cin >> input;
        B.push_back(input);
    }
    sort(B.begin(), B.end());
    last = 0;
    for (int i=0;i<N;++i) {
        if (B[i]!=last) {
            B_clean .push_back(B[i]);
            B_size++;
            Appearance_B[B[i]] = 1;
        } else {
            Appearance_B[B[i]]++;
        }
        last = B[i];
    }
    B.clear();


    if (part==1) {
        for (i=0;i<A_size;++i) {
            for (j=0;j<B_size;++j) {
                if ((A_clean[i]+B_clean[j]) % X == 0) {
                    ans += Appearance_A[A_clean[i]] * Appearance_B[B_clean[j]];
                }
            }
        }
        cout << ans << endl;

    }
    else if (part==2) {



    }

    return 0;
}
