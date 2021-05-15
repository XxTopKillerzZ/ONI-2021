#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//
using namespace std;

int main()
{
    int part,N,M,input,i;
    long long int ans=0;
    vector<int> Price;

    cin >> part >> N >> M;

    for (int i=0;i<N;++i) {
        cin >> input;
        Price.push_back(input);
    }
    sort(Price.begin(), Price.end());


    if (part==1) {
        for (i=0;i<M;++i) {
            ans += Price[i];
        }
        cout << ans << endl;
    }
    else if (part==2) {
        map<int, int> Appearences;
        map<int, int>::iterator it;

        int last = 0;
        for (int i=0;i<N;++i) {
            if (last == Price[i]) {
                Appearences[Price[i]]++;
            } else {
                Appearences[Price[i]] = 1;
            }
            last = Price[i];
        }

        while (M>0) {
            if (Appearences.begin()->second >= M) {
                ans += Appearences.begin()->first * M;
                cout << ans;
                return 0;
            } else {
                ans += Appearences.begin()->first * Appearences.begin()->second;

                M-=Appearences.begin()->second;
                it = Appearences.find(Appearences.begin()->first+1);
                if (it != Appearences.end()) {
                    it->second += Appearences.begin()->second;
                }
                else {
                    Appearences.insert(std::make_pair(Appearences.begin()->first+1, 1));
                }
                it=Appearences.find(Appearences.begin()->first);
                Appearences.erase(it);
            }
        }


        cout << ans << endl;


    }

    return 0;
}
