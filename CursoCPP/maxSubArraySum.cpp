#include "stdc++.h" //adicionei manualmente o header, ja que o VS nao vem com ele
using namespace std;

//Competitive Programmer’s Handbook - Antti Laaksonen - Chapter 2
//alg 1 - O n^3
void maxSubArray1(int mat[]) {
	int best = 0;
	int n = sizeof(mat);
	for (int a = 0; a < n; a++)
	{
		for (int b = a; b < n; b++)
		{
			int sum = 0;
			for (int k = a; k <= b; k++) {
				sum += mat[k];
			}
			best = max(best, sum);
		}
	}
	cout << "Best sum: " << best;
}

//Alg2 - On^2
void maxSubArray2(int mat[]) {
	int best = 0;
	int n = sizeof(mat);
	for (int a = 0; a < n; a++)
	{
		int sum = 0;
		for (int b = a; b < n; b++)
		{
			sum += mat[b];
			best = max(best, sum);
		}
	}
	cout << "Best sum: " << best;
}

//Alg3 - On - The idea is to calculate, for each array position, the maximum sum of a subarray that ends at that position.
void maxSubArray3(int mat[]) {
	int best = 0, sum = 0;
	int n = sizeof(mat);
	for (int k = 0; k < n; k++)
	{
		sum = max(mat[k], sum + mat[k]);
		best = max(best, sum);
		cout << "alg3. k:" << k << " sum: " << sum << " best: " << best << endl;
	}
	cout << "Best sum: " << best;
}

int main() { 
	int mat[] = { -1,2,4,-3,5,2,-5,2 };
	maxSubArray1(mat);
	cout << endl;
	maxSubArray2(mat);
	cout << endl;
	maxSubArray3(mat);
}
