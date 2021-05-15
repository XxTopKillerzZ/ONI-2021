#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//<>
using namespace std;


bool Backtrack(int N, int M, int S) {



}

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
        int N,M,Q,i,j,k,A,B,C;
        cin >> N >> M >> Q;
        int Foto[N][M] = {0};
        for (i=1;i<=Q;++i) {
            cin >> A >> B >> C;

            for (j=0;j<C;++j) {
                for (k=A-1;k<B;++k) {
                    if (Foto[j][k] == 0) {
                        Foto[j][k] = i;
                    }
                }
            }



        }

        for (i=N-1;i>0;--i) {
            for (j=0;j<M-1;++j) {
                cout << Foto[i][j] << " ";
            }
            cout << Foto[i][M-1] << endl;
        }
        for (j=0;j<M-1;++j) {
            cout << Foto[0][j] << " ";
        }
        cout << Foto[0][M-1];

    }
    else if (part==3) {
        int N,M,S,i,j,k,l,ans=0,smallest,biggest,top;
        vector<vector<int>> buildings;
        cin >> N >> M >> S;
        int Foto[N][M];
        int visited[S] = {0}; //Index 0 based
        for (i=N-1;i>=0;--i) {
            for (j=0;j<M;++j) {
                cin >> Foto[i][j];
            }
        }
        for (i=N-1;i>=0;--i) {
            for (j=M-1;j>=0;--j) {
                if (!visited[Foto[i][j]) { //Start search
                    smallest=j;
                    biggest=j
                    top=N;

                    for (k=i;k>=0;--k) {
                        for (l=j;j>=0;--j) {
                            if (Foto[i][j] == Foto[k][l]) {
                                smallest=min(smallest,l);
                                biggest=max(biggest,l);
                                top=max(top, k);
                            }
                        }
                    }
                    ans++;
                    buildings.push_back({,,});

                }
            }
        }

    }

    return 0;
}
