#include <iostream>
#include <string>
//<>
using namespace std;

int main()
{
    int part;

    cin >> part;

    int N,K,input;
    cin >> N >> K;
    int A[N];
    for (int i=0;i<N;++i) {
        cin >> A[i];
    }

    if (part==1) {
        for (int i=0;i<N;++i) {
            cin >> input;
            A[i] += input * K;
        }
        for (int i=0;i<N-1;++i) {
            cout << A[i] << " ";
        }
        cout << A[N-1] << endl;

    }
    else if (part==2) {





    }

    return 0;
}
