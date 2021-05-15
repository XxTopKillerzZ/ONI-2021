#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//<>
using namespace std;

int main()
{
    int part,N,X,i,j,input,ans=0;
    cin >> part >> N >> X;



    if (part==1) {
        int A_Mod[N-1] = {0};
        int B_Mod[N-1] = {0};

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
        int A[N];
        for (i=0;i<N;++i) {
           cin >> A[i];
        }
        int B[N];
        for (i=0;i<N;++i) {
           cin >> B[i];
        }
        int Nec[N];

        for (i=0;i<N;++i) {
            if (B[i] == A[i]) {
                Nec[i] = 0;
            }
            else if ((B[i]-A[i]) % X == 0) {
                Nec[i] = ((B[i]-A[i]) / X);
            }
        }

        while (true) {
            int biggest=0;
            for (i=0;i<N;++i) {
                if (Nec[i] > Nec[biggest]) {
                    biggest = i;
                }
            }
            if (Nec[biggest] == 0) {
                break;
            }
            ans++;
            Nec[biggest]--;
            for (i=biggest; i>0;) {
                if (Nec[i-1] > 0) {
                    Nec[i-1]--;
                    i--;
                } else {
                    i=0;
                }
            }
            for (i=biggest;i<N-1;) {
                if (Nec[i+1] > 0) {
                    Nec[i+1]--;
                    i++;
                } else {
                    i=N;
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}
