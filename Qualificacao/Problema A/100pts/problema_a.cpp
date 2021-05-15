#include <iostream>
#include <string>
//
using namespace std;

int main()
{
    int part;

    cin >> part;

    int N,K,input,i,j,l;
    cin >> N >> K;
    int A[N];
    for (int i=0;i<N;++i) {
        cin >> A[i];
    }

    if (part==1) {
        for (i=0;i<N;++i) {
            cin >> input;
            A[i] += input * K;
        }
        for (i=0;i<N-1;++i) {
            cout << A[i] << " ";
        }
        cout << A[N-1] << endl;

    }
    else if (part==2) {
        int sum_tmp,ans=0;
        int sum[N]; //Soma acumulada
        for (i=0;i<=N;++i) {
            if (i!=0) {
                sum[i] = A[i] + sum[i-1];
            } else {
                sum[0] = A[0];
            }
        }

        for (i=0;i<N-3*K;++i) {
            for (j=i+K;j<N-2*K;++j) {
                for (l=j+K;l<N-K;++l) {
                    sum_tmp = (sum[i+K]-sum[i]) + (sum[j+K]-sum[j]) + (sum[l+K]-sum[l]);
                    ans = max(ans,sum_tmp);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
