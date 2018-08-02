#include "CRedesNeurais.h"
using namespace std;

int main(){
	cout << "----------------"<<endl;
	CRedesNeurais a;
	std::string nom1 = "../Dados/Or.txt";//arquivo para treinar pesos
	std::string nom2 = "../Dados/Or.txt";//arquivo para testar  pesos
	a.Dados(nom1);
	a.DadosTeste(nom2);
	//a.MostrarMatrix();
	a.Perceptron();
	a.MostrarPeso();
	a.Testar();

	return 0;
}
