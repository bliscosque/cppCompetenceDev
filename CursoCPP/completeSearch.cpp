#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> subset;
int n = 3;

void searchSubSets(int k) {
	if (k == n) { //chegou no "fim da arvore... imprimindo resultados"
		cout << endl << "sol: ";
		for (auto i : subset) cout << i << " ";
	}
	else {
		searchSubSets(k + 1); //k is not included
		subset.push_back(k);
		searchSubSets(k + 1); //k is included
		subset.pop_back();
	}
}

vector<int> permutations;
bool chosen[100];
void searchPermutations() {
	if (permutations.size() == n) { //chegou no "fim das permutacoes... imprimindo resultados"
		cout << endl << "sol: ";
		for (auto i : permutations) cout << i << " ";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutations.push_back(i);
			searchPermutations();
			chosen[i] = false;
			permutations.pop_back();
		}
	}
}

int main3() {
	//generate all subsets of [0,1,2] -> n=3 //ALG1
	cout << "\n\nSubsets alg 1(recursion): " << endl;
	searchSubSets(0);

	cout << "\n\nSubsets alg 2: " << endl;
	//generate all subsets, alg2
	for (int b = 0; b < (1 << n); b++) {
		vector<int> subset;
		for (int i = 0; i < n; i++) {
			if (b & (1 << i)) subset.push_back(i);
		}
		cout << endl << "sol: ";
		for (auto i : subset) cout << i << " ";
	}

	//generate all permutations of [0,1,2] -> n=3 //ALG1
	cout << "\n\nPermutations alg 1(recursion): " << endl;
	searchPermutations();

	//generate all permutations of [0,1,2] -> n=3 //ALG2 - using STDLIB
	cout << "\n\nPermutations alg 2(stdlib): " << endl;
	vector<int> perm = { 0,1,2 };
	do {
		cout << endl << "sol: ";
		for (auto i : perm) cout << i << " ";
	} while (next_permutation(perm.begin(), perm.end()));

	return 0;
}