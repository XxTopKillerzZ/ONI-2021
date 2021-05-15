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
        i=0;
        while (i<M) {
            ans += Price[0];
            Price[0]++;
            sort(Price.begin(), Price.end());
            i++;
        }

        cout << ans << endl;


    }

    return 0;
}
