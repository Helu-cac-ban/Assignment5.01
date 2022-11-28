#include <iostream>
using namespace std;
struct Side {
	double length;
};
Side a[(int)1e4];
struct Polygon {
	int side;
	void Input_side() {
		cout << "Input number of polygon sides: ";
		cin >> side;
		while (side < 3) {
			cout << "Input number of polygon sides greater than 2:";
			cin >> side;
		}
	}
	void set_polygon()
	{
		for (int i = 1; i <= side; i++)
		{
			cout << "Input length of side[" << i << "]: ";
			cin >> a[i].length;
			if (a[i].length <= 0) {
				cout << "Error: Side doesn't exist => ";
				break;
			}
		}
	}
	double Max_length() {
		double max = 0;
		for (int i = 1; i <= side; i++)
		{
			if (max < a[i].length)
				max = a[i].length;
		}
		return max;
	}
	bool ExistingPossibility() {
		double max = Max_length();
		double sum = 0;
		for (int i = 1; i <= side; i++)
		{
			sum += a[i].length;
		}
		sum -= max;
		if (sum > max) return true;
		else return false;
	}
	double Perimeter() {
		double perimeter = 0;
		for (int i = 1; i <= side; i++)
		{
			perimeter += a[i].length;
		}
		return perimeter;
	}
};
int main(){
	Polygon p;
	p.Input_side();
	p.set_polygon();
	p.Max_length();
	if (p.ExistingPossibility() == 0)cout << "Polygon doesn't exist";
	else cout <<"Polygon perimeter: "<< p.Perimeter();
	return 0;
}
