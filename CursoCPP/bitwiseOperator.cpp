#include "stdc++.h" 
using namespace std;

int getIthBit(int n, int i) {
	int mask = (1 << i);
	return (n & mask) > 0 ? 1 : 0;
}
void setOthBit(int &n, int i) {
	int mask = (1 << i);
	n = (n | mask);
}
void clearIthBit(int &n, int i) {
	int mask = ~(1 << i);
	n = n & mask;
}
void updateIthBit(int& n, int i, int v) {
	clearIthBit(n, i);
	int mask = (v << i);
	n = n | mask; //sets the right value
}
void clearLastIBits(int& n, int i) {
	//mask with last i positions=0 and 1 as others
	//-1 = ~0
	int mask = (-1 << i);
	n = n & mask;
}
void clearBitsInRange(int& n, int i, int j) {
	//mask as 1111 0000 1111 
	int a = (~0) << (j + 1); //parte esqueda da mascara
	int b = (1 << i) - 1;//parte direita da mascara
	int mask = a | b;
	n = n & mask;
}
void replaceBits(int& n, int i, int j, int m) {
	clearBitsInRange(n, i, j);
	int mask = (m << i);
	n = n | mask;
}
int count_bits(int n) {
	int count = 0;
	while (n > 0) {
		int last_bit = (n & 1);
		count += last_bit;
		n >> 1;
	}
	return count;
}
int count_bits_hack(int n) {
	int ans=0;
	while (n > 0) {
		//removes the last set bit from the current number
		n = n & (n - 1);
		ans++;
	}
	return ans;
}
int convertToBinary(int n) {
	int ans = 0;
	int p = 1;//power
	while (n > 0) {
		int last_bit = (n & 1);
		ans += p * last_bit;

		p = p * 10;
		n = n >> 1;
	}
	return ans;
}

int main() {
	//& -> and
	//| -> or
	//^ -> xor
	//~ -> not
	//<< -> binary left shift
	//>> -> binary right shift

	//para saber elemento nao duplicado de uma matriz (ex: 2,2,3,3,5) = 5 (unico elemento nao duplicado)
	//fazer XOR entre todos os elementos, ja que (x XOR x)=0
	
	//se a matriz tiver 2 elementos nao duplicados, o resultado do XOR sera XOR desses 2 elementos nao dup.
	//ver posicao do set bit no XOR -> juntar elementos originais com set bit na mesma posicao e fazer novo XOR
	//obtera com isso um dos numeros. Fazendo XOR desse numero com o XOR dos 2, obtem o segundo numero
	//solucao do problema anterior (2N+2)
	vector<int> arr = { 1,3,5,4,3,1,5,7 };
	int result = 0;
	for (int i = 0; i < arr.size(); i++) {
		result = result ^ arr[i];
	}
	//position do set bit
	int pos = 0;
	int temp = result;
	while((temp&1)==0) {
		pos++;
		temp = temp >> 1;
	}
	//filtrando numeros que tem set bits
	int setA = 0;
	int setB = 0;
	int mask = (1 << pos);
	for (int i = 0; i < arr.size(); i++) {
		if ((arr[i] & mask) > 0) {
			setA = setA ^ arr[i];
		}
		else {
			setB = setB ^ arr[i];
		}
	}
	cout << "NumA: " << setA << endl;
	cout << "NumB: " << setB << endl;


	//Unique numbers 3N+1
	//Somar bits de cada posicao do numero. O numero estara no formato 3N+1, sendo que o +1 sera apenas para numero nao repetido
	//Fazer cada bit%3 para saber esse restante, que será o numero


	
	//OddOrEven
	int num = 111;
	if (num & 1) {
		cout << "Odd" <<endl;
	}
	else cout << "Even" << endl;

	int num2 = 8;
	if ((num2 & (num2 - 1)) == 0) { //1000 & 0111 = 0000
		cout << "num2 is power of 2" << endl;
	}
	else {
		cout << "num2 is not a power of 2" << endl;
	}

	int n = 5;
	int i = 2;
	cout << "BIT: " << i << " de: " << n <<" = " << getIthBit(n, i) << endl;
	clearIthBit(n, i);
	cout << "Clear 2 bit: " << n << endl;
	setOthBit(n, i);
	cout << "Set 2 bit: " << n << endl;
	updateIthBit(n, 6, 1);
	setOthBit(n, i);
	cout << "Update 6 bit to 1: " << n << endl;
	clearLastIBits(n, 4);
	cout << "Clear last 4 bits: " << n << endl;

	cout << "Convert 10 to binary: " << convertToBinary(10) << endl;


	return 0;
}