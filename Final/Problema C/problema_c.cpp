#include <bits/stdc++.h>
#include <iostream>
#include <string>
//
using namespace std;

int main()
{
    int P,T;
    cin >> P >> T;


    if (P==1) {
        while (T > 0) {

            int N,M,i,input1,input2,s;
            bool possible = true;
            queue<int> q;

            cin >> N >> M;

            vector<int> adj[N];
            bool visited[N] = {false};
            int group[N];

            for (i=0;i<M;++i) {
                cin >> input1 >> input2;
                input1--; input2--;
                adj[input1].push_back(input2);
                adj[input2].push_back(input1);
            }

            visited[0] = true;
            group[0] = 1;
            q.push(0);

            while(!q.empty()) {
                s = q.front();
                q.pop();

                if (group[s] == 1) {
                    for (auto i : adj[s])
                    {
                        if (!visited[i])
                        {
                            visited[i] = true;
                            group[i] = 2;
                            q.push(i);
                        } else if (visited[i] && group[i] == group[s]) {
                            possible = false;
                            queue<int> q;
                        }
                    }
                } else if (group[s] == 2) {
                    for (auto i : adj[s]) {
                        if (!visited[i]) {
                            visited[i] = true;
                            group[i] = 1;
                            q.push(i);
                        } else if (visited[i] && group[i] == group[s]) {
                            possible = false;
                            queue<int> q;
                        }
                    }
                }

            }

            if (possible) {
                cout << "sim" << endl;
            } else {
                cout << "nao" << endl;
            }
        T--;
        }


    } else if (P==2) {



    }
}
