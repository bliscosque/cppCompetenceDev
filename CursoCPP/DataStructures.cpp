#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <array>

using namespace std;

class Compare {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

//OBS: ALL STL CONTAINERS ARE PASSED BY VALUE PER DEFAULT. O &arr faz passar por referencia
void updateArray(array<int, 6>& arr, int i, int val) {
    arr[i] = 11;
}

int main()
{
    array<int, 6> arr = { 1,2,3,6,7,8 };
    arr[0] = 10;
    updateArray(arr, 1, 11);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ",";
    }
    arr.fill(5); //preenche todos os elementos com 5
    cout << endl;
    for (int i = 0; i < arr.size(); i++) //array possui funcoes size()
    {
        cout << arr[i] << ",";
    }
    //Funcoes Importantes
    //get ith element
    //arr.at(i);  OR   arr[i];
    //primeiro e ultimo elemento
    //arr.front() e arr.back()



    //VECTOR - Pode ser redimensionado dinamicamente (dobra a capacidade quando precisa aumentar tamanho)
    cout << endl;
    vector<int> v;
    v.push_back(1); //add
    v.push_back(2);
    v.push_back(3);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << v.back() << endl << endl; //retorna ultimo elemento
    v.pop_back(); //remove ultimo elemento
    vector<int> v1(10, 1); //10 elementos, inicializados com 1
    for (auto x : v1) {
        cout << x << endl;
    }
    //outras funcoes imporrtantes de vector:
    // v.reserve(100) // reserva já os 100 elementos (capacity), para que nao fique "duplicando"
    //v.clear() --- remove todos os elementos
    //nao há metodos para, por exemplo, pop e push front, porque vector cresce somente para a direita
    //criar vector a partir de um range de array
    //int numbers[] = {10,20,30,40}
    //vector<int> third(numbers, numbers + 4);
    //inicializando com copia de vector
    //vector<int> fourth(third);
    //underlying capacity
    //arr.capacity()
    //get the max size (based on RAM)
    //arr.max_size()

    string a = "Thiago";
    string b = a + a;
    cout << b << endl;
    string c = b.substr(2, 4); //inicia pos 2, tamanho 4
    cout << c << endl;

    set<int> s; // unordered_set, uma implementacao de set nao ordenado
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(2);
    cout << s.count(2) << " " << s.count(4) << endl;//1 e 0 ---nao tem duplicados
    for (auto x : s) {
        cout << x << endl;
    }
    s.erase(2);
    cout << endl << s.count(2) << endl; //0

    multiset<int> ms; //tambem ha unordered_multiset
    ms.insert(3);
    ms.insert(2);
    ms.insert(5);
    ms.insert(2);
    cout << "MULTISET " << ms.count(2) << " " << ms.count(4) << endl;//2 e 0 ---tem duplicados
    ms.erase(3); //apaga todas as ocorrencias
    ms.erase(ms.find(2)); //apaga uma ocorrencia apenas

    map<string, int> m;
    m["monkey"] = 3;
    m["banana"] = 5;
    cout << endl << "MAP: " << m["monkey"] << m["novo_elem"] << " " << m.count("monkey") << endl; //novo_elem é adicionado com valor 0
    for (auto x : m)
        cout << x.first << " " << x.second << endl; //imprime chave e valor

    //working with iterator, algumas funcoes --- begin aponta para 1o elem, end aponta para APOS ultimo elemento
    //sort(v.begin(), v.end()); 
    //reverse(v.begin(), v.end()); 
    //random_shuffle(v.begin(), v.end());
    cout << endl << "ITERATORS!!!" << endl;
    set<int>::iterator it = s.begin();
    for (; it != s.end(); it++)
        cout << *it << endl;

    auto it2 = s.end(); //outra forma de declarar iterator
    it--; //aponta ao ultimo elemento
    cout << *it << endl; //exibe maior elemento (ultimo)

    auto it3 = s.find(2);
    if (it3 == s.end())
        cout << "elemento nao encontrado" << endl;

    //BITSET
    bitset<10> bs(string("0011001100"));
    cout << endl << "BITSET" << bs[2] << "Count: " << bs.count() << endl;

    //DEQUE -- size can be changes both sides 
    // espaço nao é, necessariamente, continuo
    deque<int> d;
    d.push_back(5);  // [5]
    d.push_back(2);  // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back();    // [3,5]
    d.pop_front();   // [5]

    //stack (pilha)
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(5);
    cout << "STACK: " << st.top();
    st.pop();
    cout << " " << st.top() << endl;

    //queue (fila)
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(5);
    cout << "QUEUE: " << q.front();
    q.pop();
    cout << " " << q.front() << endl;

    //priority_queue
    cout << "PRIORITY QUEUE" << endl;
    int arr2[] = { 10,15,20,13,6,90 };
    //priority_queue<int> heap; //por padrao, eh descendente
    //priority_queue<int, vector<int>, greater<int>> heap; //crescente -- o greater é um inbuilt comparator
    //outra opcao, com custom compare
    priority_queue<int, vector<int>, Compare> heap;
    for (int x : arr2) {
        heap.push(x);
    }
    while (!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }


    return 0;
}
