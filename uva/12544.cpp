#include <iostream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{

    int T;

    //number of test cases
    cin >> T;
    int count = 1;
    do
    {
        int N;
        //number of students
        cin >> N;

        int spd,max = -1;
        do
        {

            cin >> spd;
            if(spd > max)
               max = spd; 

            --N;
        } while(N);



        cout << "Case " << count << ": " << max << endl;
        ++count;
        --T;
    } while (T);


    return 0;
}
