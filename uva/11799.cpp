//http://uva.onlinejudge.org/external/125/p12544.pdf
//#NOTSOLVED #TODO
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tree
{
    vector<int> connectedto;
} beetree;

int main(int argc, char *argv[])
{

    int T;

    //number of test cases
    cin >> T;
    int count = 1;

    do
    {
        int N,M;
        cin >> N >> M;
        int total = 0;

        beetree trees[N];
        vector<int>  count;
        vector<bool> colored;
        colored.resize(N,false);
        count.resize(N,0); 

        do
        {

            int from, to;
            cin >> from >> to;

            trees[from].connectedto.push_back(to);
            ++count[from];
            tress[to].connectedto.push_back(from);
            ++count[to];

            --M;
        } while(M);

        sort(count.begin(), count.end());
        
         


        cout << "Case " << count << ": " << (total) ? total : "impossible"  << endl;
        ++count;
        --T;
    } while (T);


    return 0;
}
