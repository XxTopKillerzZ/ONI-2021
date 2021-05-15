#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//<>
using namespace std;

int main()
{
    int part,N,X,i,j,input;
    cin >> part >> N >> X;



    if (part==1) {
        int A_Mod[N-1] = {0};
        int B_Mod[N-1] = {0};
        int ans = 0;

        for (i=0;i<N;++i) {
           cin >> input;
           A_Mod[input % X]++;
        }

        for (i=0;i<N;++i) {
           cin >> input;
           B_Mod[input % X]++;
        }

        for (i=0;i<X;++i) {
            for (j=0;j<X;++j) {
                if ((j+i) % X == 0) {
                    ans += A_Mod[i] * B_Mod[j];
                }
            }
        }
        cout << ans << endl;
    }
    else if (part==2) {



    }

    return 0;
}
