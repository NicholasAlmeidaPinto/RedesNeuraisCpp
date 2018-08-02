#include "CRedesNeurais.h"
using namespace std;

int main(){
	cout << "----------------"<<endl;
	CRedesNeurais a;
	std::string nom1 = "Dados/IrisTreinar.data";
	std::string nom2 = "Dados/IrisTestar.data";
	a.Dados(nom1);
	a.DadosTeste(nom2);
	//a.MostrarMatrix();
	a.Perceptron();
	a.MostrarPeso();
	a.Testar();

	return 0;
}