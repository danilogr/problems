#include <iostream>
#include <iomanip>

using namespace std;


int main()
{

	float n,m;

	cin >> n>>m;

	cout << "MEDIA = " << fixed << setprecision(5) <<  (3.5*n + 7.5*m)/11.0 << endl;


	return 0;
}
