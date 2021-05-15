#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//<>
using namespace std;

int main()
{
    int part;
    cin >> part;



    if (part==1) {
        int N,M,S,i,j,ans=0,input;
        cin >> N >> M >> S;
        bool present[S+1] = {false};

        for (i=0;i<N;++i) {
            for (j=0;j<M;++j) {
                cin >> input;
                if (!present[input] && input != 0) {
                    present[input] = true;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else if (part==2) {



    }

    return 0;
}
