#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//<>

using namespace std;

int main()
{
    int part,N,M,input,i;
    long long int ans=0;

    cin >> part >> N >> M;

    if (part==1) {
        vector<int> Price;
        for (i=0;i<N;++i) {
            cin >> input;
            Price.push_back(input);
        }
        sort(Price.begin(), Price.end());
        for (i=0;i<M;++i) {
            ans += Price[i];
        }
        cout << ans << endl;
    }
    else if (part==2) {
        vector<int> inputs;
        vector<int> Price;
        vector<int> Number;
        int Price_size=0;
        for (i=0;i<N;++i) {
            cin >> input;
            inputs.push_back(input);
        }
        sort(inputs.begin(), inputs.end());

        Price.push_back(inputs[0]);
        Number.push_back(1);
        int last = inputs[0];

        for (i=1;i<N;++i) {
            if (inputs[i] != last) { //pusback
                Price.push_back(inputs[i]);
                Number.push_back(1);
                Price_size++;
            } else { //increment last
                Number.back()++;
            }
            last = inputs[i];
        }
        i=0;
        while (M>0) {
            if (Number[i] >= M) {
                ans += Price[i] * M;
                cout << ans << endl;
                return 0;
            } else {
                ans += Price[i] * Number[i];
                M -= Number[i];
                if ((Price[i] + 1 == Price[i+1]) && Price_size > i) {
                    Number[i+1] += Number[i];
                    i++;
                } else {
                    Price[0]++;
                }

            }
        }



        cout << ans << endl;
    }

    return 0;
}
