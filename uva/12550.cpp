//http://uva.onlinejudge.org/external/125/p12550.pdf
//#NOTSOLVED# #RUNTIMEERROR#
#include <iostream>
#include <string>
#include <sstream>
#include <climits>

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
      unsigned int *total= new unsigned int[d1];
      int count=0;
      unsigned int tmp;
      while( ss >> tmp)
          total[count++] =tmp;

      if(count < d1)
      {

        int a=1,b=1;

        //try to understand the pattern
        if(count >= 4)
        {
          if(total[0] == 0)   //simple case (a*v1 + b*v2, where v2 = 0)
          {
            a = total[2] / total[1]; //total[2]  = a * total[1] + b * total[0]
            // total[n] = a*total[n-1] +b*total[n-2]
            b = (total[3] - a*total[2])/total[1];
          } else { // 'complex case'
          
          }
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
                while(distance <D-1 && total[D - distance++] > P);
                --distance;

                cout << distance << endl; 
              }
      }

      delete[] total;
   }

    return 0;
}
