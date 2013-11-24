//http://uva.onlinejudge.org/external/125/p12550.pdf
//Thanks to a friend that told me that RuntimeError exceptions include DivisionByZero! I got stuck in this problem because of it
//#NOTSOLVED #WRONGANSWER
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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
        unsigned int total[d1];
        int count=0;
        unsigned int tmp;
        while( ss >> tmp)
            total[count++] =tmp;

        if(count < d1)
        {

            int a=1,b=1;

            // -3 -2 -1 0
            // v1 v2 v3 v4
            // 0   1  2  3
            //
            // v4 = a*v3 + b*v2
            // v3 = a*v2 + b*v1
            // a*v3 = v4 - b*v2 --> a*v3 = v4 - (v3*v2 - a*v2*v2)/v1 --> (a*v3 +a*v2*v2 )/v1 = v4 - v3*v2 --> a(v3 - v2^2)/v1 = v4 - v3*v2 --> a = (v1*v4  - v2*v3)/(v3*v1 - v2*v2)
            // b*v1 = v3 - a*v2 --> b = (v3 - a*v2)/v1

            --count;

            //binary search for zeros

            //last one is zero? (first and second are zeros)
            if(total[count] == 0)
            {
                a = b =0;
            }
            else
                //'first' one is zero
                if(total[0] == 0)
                {
                    //v3 = a*v2 + b*v1 = a*v2 --> a = v3/v2
                    a =  total[2]/total[1];
                    //v4 = a*v3 + b*v2 --> (v4 - b*v2)/v3
                    b = (total[3] - a*total[1])/total[2];
                }
                else //no zeros :(
                {
                    a = (total[0]*total[3] - total[1]*total[2])/(total[2]*total[0] - total[1]*total[1]);
                    b = (total[2] - a*total[1])/total[0];
                }


            //generate remaining data
            for(int i=count; i < d1; ++i)
            {
                total[i] = (a*total[i-1] + b*total[i-2]);
                if(total[i] < total[i-1]) //shitty way of dealing with overflows
                    total[i] = P+1;
            }

        }

        // result
        if(P >= total[D])
        {
            cout << "The spider may fall!" << endl;
        } else {

            if(P <= total[0])
                cout << "The spider is going to fall!" << endl;
            else
            {
                int distance = 1;
                while(distance <= D-1 && total[D - distance++] > P);
                --distance;

                cout << distance << endl; 
            }
        }
    }

    return 0;
}
