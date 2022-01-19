#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
	char nome[100];
	int idade;
} t_pessoa;

struct Pessoa2 { ///no c++, nao precisa do typedef
private:
	char nome[100];
	int idade;
public:
	Pessoa2(int idade) {
		this->idade = idade;
	}
	void setIdade(int idade) {
		this->idade = idade;
	}
	int getIdade() {
		return this->idade;
	}
};

class Animal {
public:
	char nome[100];
	int idade;
};

void altNum(int* num) { //passagem por referencia
	*num = 11;
}

void foo(int aux[]) {
	aux[0] = 100;
}

int main1(int argc, char *argv[]) {
	int i = 10;
	cout << ++i << endl;
	i = 10;
	cout << i++ << endl;

	int vetor[100];
	int vetor2[] = { 1,2,3 };
	for (int i = 0; i < 100; i++) {
		vetor[i] = i * 10;
	}
	for (int i = 0; i < 100; i++) {
		cout << vetor[i] << " "; 
	}
	cout << endl << "tamanho do vetor: " << sizeof(vetor) << endl; //1 inteiro tem 4 bytes

	char nome[] = "Thiago"; //lembrando que string termina com '\0'
	cout << nome << "tamanho: "<< strlen(nome) << endl;
	cout << nome << " " << strcmp(nome, "Thiago") << endl; //retorna 0 se forem iguais


	//ponteiros
	int var = 10;
	int* pvar = &var;
	cout << endl << *pvar << " " << pvar << endl;

	altNum(&var); //passagem de funcionao por referencia
	cout << endl << "new var: " << var << endl;

	int* vet = new int[2];
	*(vet + 0) = 0; //equivalente a vet[0]
	*(vet + 1) = 1; //equivalente a vet[1]
	cout << "vetor pos 1: " << vet[1] << endl;

	foo(vet);
	cout << "vetor pos 0: " << vet[0] << endl;

	for (int i = 0; i < sizeof(vet) / sizeof(int); i++) {
		cout << vet[i] << " ";
	}

	cout << endl << endl;
	int* parray = &vet[0];
	i = 0;
	while (i < 2) {
		cout << *parray << " ";
		parray++;
		i++;
	}

	delete[] vet; //desaloca memoria do vetor

	//constantes -> precisa declarar e já inicializar
	const double PI = 3.14;
	const char* const p4 = "Thiago"; //tanto o conteiro como o valor do ponteiro sao constantes

	//structs --- membros publicos por padrao
	t_pessoa p;
	strcpy_s(p.nome, "Thiago");
	p.idade = 35;
	cout << endl << "STRUCTS" << endl;
	cout << "nome: " << p.nome <<endl;
	cout << "idade: " << p.idade;
	
	Pessoa2 p2(10);

	cout << endl << p2.getIdade() << endl << endl;

	Animal animais[3] = {
		{"Joana", 7},
		{"Ares", 10},
		{"Chico", 3},
	};
	cout << animais[0].nome << endl;
	cout << animais[1].nome << endl;
	cout << animais[2].nome << endl;


	return 0;
}
