#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float R;

	cin >> R;
	cout << "A=" << fixed<< setprecision(4) << 3.14159*R*R << endl;

	return 0;
}
