#include <bits/stdc++.h>
#include <iostream>
#include <string>
//
using namespace std;


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int P,N,i,input;
    long long int ans=0;
    cin >> P >> N;


    if (P==1) {
        map<int,int> numero;
        map<int,int>:: iterator it;
        for (i=0;i<N;++i) {
            cin >> input;
            it = numero.find(input);
            if(it != numero.end()){
                numero[input]++;
            }
            else {
                numero[input]=1;
            }
        }

        for (it = numero.begin(); it != numero.end(); it++)
        {
            for (i=0;i<it->second;++i) {
                ans+=(it->second-i-1);
            }
        }
        cout << ans << endl;

    } else if (P==2) {
        int distancia,ans_max=1,ans_number=N;
        int montanhas[N];
        for (i=0;i<N;++i) {
            cin >> montanhas[i];
        }

        for (i=0;i<N;++i) {
            for (distancia=1;(i-distancia >= 0) && (i+distancia < N);++distancia) {
                if (montanhas[i-distancia] < montanhas[i] && montanhas[i+distancia] <montanhas[i]) {
                    ans_number++;
                    ans_max = max(ans_max, distancia*2+1);
                } else {
                    distancia=N; //sair do ciclo
                }
            }
        }
        cout << ans_max << " " << ans_number << endl;
    }
}
