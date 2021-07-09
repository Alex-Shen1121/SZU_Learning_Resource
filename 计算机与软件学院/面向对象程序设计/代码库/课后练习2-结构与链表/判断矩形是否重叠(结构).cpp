#include<iostream>
using namespace std;
struct SPoint {
	int x, y;
};
struct SRect {
	SPoint p1, p2;
};
void swap(int& a, int& b)
{
	int temp;
	temp = b;
	b = a;
	a = temp;
}
void Reset(SRect& temp)
{
	int p1x, p1y, p2x, p2y;
	
	if (temp.p1.x > temp.p2.x)
	{
		swap(temp.p1.x, temp.p2.x);
		swap(temp.p1.y, temp.p2.y);
	}
	p1x = temp.p1.x;
	p1y = temp.p1.y;
	p2x = temp.p2.x;
	p2y = temp.p2.y;
	if (temp.p1.y > temp.p2.y)
	{
		temp.p1.y = p2y;
		temp.p2.y = p1y;
	}
}
int check(SRect a, SRect b)
{
	if (b.p2.x < a.p1.x || b.p1.y > a.p2.y || b.p1.x > a.p2.x || b.p2.y < a.p1.y)
		return -1;
	else
		return 1;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int check1;
		SRect Rect[2];
		cin >> Rect[0].p1.x >> Rect[0].p1.y >> Rect[0].p2.x >> Rect[0].p2.y
			>> Rect[1].p1.x >> Rect[1].p1.y >> Rect[1].p2.x >> Rect[1].p2.y;
		Reset(Rect[0]);
		Reset(Rect[1]);
		//вСоб->срио
		check1 = check(Rect[0], Rect[1]);
		if (check1 == 1)
			cout << "overlapped" << endl;
		else if (check1 == -1)
			cout << "not overlapped" << endl;
	}

	return 0;
}
