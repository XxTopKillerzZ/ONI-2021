#include <bits/stdc++.h>
#include <iostream>
#include <string>
//
using namespace std;

int main()
{
    int P,N,K,i,j;
    cin >> P >> N >> K;


    if (P==1) {
        int input[N];
        int ans[N];
        bool flag = false;
        vector<pair<int,int>> episode;
        vector<pair<int,int>>::iterator it;
        for (i=0;i<N;++i) {
            cin >> input[i];
            episode.push_back(make_pair(input[i],i));
        }
        sort(episode.begin(), episode.end());

        for (i=0;i<N;++i) {
            it = lower_bound(episode.begin() , episode.end(), make_pair(input[i],0) );
            if (it - episode.begin() == 0) {
                ans[i] = -1;
            } else {
                flag = false;
                for (j=it - episode.begin()-1; j>=0; --j) {
                    if (abs(i-(episode[j].second)) <= K) {
                        ans[i] = episode[j].first;
                        flag = true;
                        j=0; //acabar ciclo
                    }
                }
                if (!flag) {
                   ans[i] = -1;
                }
            }
        }
        for (i=0;i<N-1;++i) {
            cout << ans[i] << " ";
        }
        cout << ans[N-1] << endl;


    } else if (P==2) {




    }
}
