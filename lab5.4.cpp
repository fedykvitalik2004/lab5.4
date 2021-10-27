#include <iostream>
#include <cmath>

using namespace std;

double S(const int N)
{
	double S = 0;
	for (int k = 1; k <= N; k++)
		S += (1 + sqrt(1 + k * k)) / (k * k);
	return S;
}

double S1(const int N, const int k)
{
	if (k > N)
		return 0;
	else
		return ((1 + sqrt(1 + k * k)) / (k * k)) + S1(N, k + 1);
}

double S2(const int N, const int k)
{
	if (k < 1)
		return 0;
	else
		return ((1 + sqrt(1 + k * k)) / (k * k)) + S2(N, k - 1);
}

double S3(const int N, const int k, double t)
{
	t = t + (1 + sqrt(1 + k * k)) / (k * k);
	if (k >= N)
		return t;
	else
		return S3(N, k + 1, t);
}

double S4(const int N, const int k, double t)
{
	t=t + (1 + sqrt(1 + k * k)) / (k * k);
	if (k <= 1)
		return t;
	else
		return S4(N, k - 1, t);
}
int main()
{
	int N, k = 1;
    cout << "N="; cin >> N;

	cout << "(iter)         S=" << S(N) << endl;
	cout << "(rec up ++)   S1=" << S1(N, k) << endl;
	cout << "(rec up --)   S2=" << S2(N, N) << endl;
	cout << "(rec down ++) S3=" << S3(N, k, 0) << endl;
	cout << "(rec down --0 S4=" << S4(N, N, 0) << endl;

	return 0;
}
