//http://uva.onlinejudge.org/external/125/p12550.pdf
//Thanks to a friend that told me that RuntimeError exceptions include DivisionByZero! I got stuck in this problem because of it
//Thanks again to all friends that helped me with this one. One of the problems was with memory allocation (look earlier versions of the code
//to see how we changed the allocation from dynamic to static)
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int S[10010];

int main(int argc, char *argv[])
{

    string line;

    //reads each line at once
    while(getline(cin,line))
    {
        stringstream ss(line);

        int P,D;
        ss >> D;
        ss >> P;

        //read data
        const int d1 = D+1;
        int count=0;
        int tmp;

        while( ss >> tmp)
            S[count++] =tmp;

        if(count < d1)
        {

            int a=1,b=1;

            // -3 -2 -1 0
            // v1 v2 v3 v4
            // 0   1  2  3
            //
            // * v4 = a*v3 + b*v2
            // * v3 = a*v2 + b*v1
            // a*v3 = v4 - b*v2 --> a*v3 = v4 - (v3*v2 - a*v2*v2)/v1 --> (a*v3 +a*v2*v2 )/v1 = v4 - v3*v2 --> a(v3 - v2^2)/v1 = v4 - v3*v2 --> a = (v1*v4  - v2*v3)/(v3*v1 - v2*v2)
            // b*v1 = v3 - a*v2 --> b = (v3 - a*v2)/v1

            //binary search for zeros

            //last one is zero? (first and second are zeros)
            if(S[count-1] == 0)
            {
                a = b =0;

            }
            else
            {
                //'first' one is zero
                if(S[0] == 0)
                {
                    //v1 v2 v3 v4
                    //v3 = a*v2 + b*v1 = a*v2 --> a = v3/v2
                    a =  S[2]/S[1];
                    //v4 = a*v3 + b*v2 --> (v4 - b*v2)/v3
                    b = (S[3] - a*S[2])/S[1];
                }
                else //no zeros :(
                {
                    int div = (S[2]*S[0] - S[1]*S[1]);  
                    if(div != 0)
                    {
                        a = ((S[0]*S[3]) - (S[1]*S[2]))/div;   
                        b = (S[2] - a*S[1])/S[0];
                    } else {
                        a = S[2]/S[1];
                        b = 0;
                    }
                }
            }

            //generate remaining data
            for(int i=count; i < d1; ++i)
            {
                S[i] = (a*S[i-1] + b*S[i-2]);
                if(S[i] < S[i-1]) //shitty way of dealing with overflows
                    S[i] = P+1;
            }



        }

        // result
        if(P >= S[D])
        {
            cout << "The spider may fall!" << endl;
        } else {

            if(P < S[0])
                cout << "The spider is going to fall!" << endl;
            else
            {
                int step =0;
                while(step < D && P >= S[step])
                    step++;

                cout << D - step + 1 << endl;
            }
        }
    }

    return 0;
}
