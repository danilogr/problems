#include <iostream>
#include <string>

using namespace std;

//one
//two
//three





int main(int argc, char *argv[])
{

    int i;

    //word count
    cin >> i;

    string word;
    do
    {
        //get word
        cin >> word;

        if(word.length() == 5)
            cout << "3"<< endl;
        else
        {
            int count = 0;
            if( word[0] == 'o')
            {
                count += 1;
            } else if( word[0]  == 't')
            {
                count -= 1;
            } 

            if(word[1] == 'n')
            {
                count++;
            } else if (word[1] == 'w') {
                count--;
            }

            if(word[2] == 'e')
            {
              count++;
            } else if(word[2] == 'o'){
              count--;
            }

            if(count > 0)
                cout << "1" << endl;
            else
                cout << "2" << endl;

        }
        --i;
    } while(i);

    return 0;
}
