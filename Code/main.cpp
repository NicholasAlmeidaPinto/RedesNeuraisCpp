#include "CSimulador.h"
using namespace std;

int main(){
	//CSimulador a;

	//a.Menu();

	///*
	cout << "----------------"<<endl;
	CRedesNeurais a;
	std::string nom1 = "../Dados/IrisTreinar.data";
	std::string nom2 = "../Dados/IrisTestar.data";
	a.Dados(nom1);
	a.DadosTeste(nom2);
	int contador = 0;
	//a.MostrarMatrix();
	//a.Perceptron(0.0000001, 5000);
	///*
	vector<int> pular = {12};
	for (int i = 0; i < 5; i++){
		pular[0] = i;
		contador = 0;
		for (int i = 0; i < 30; i++){
			if(a.kNN(i, 7, pular))
				contador++;}
		cout << "\nRemovido: " << setw(3) << i <<"  Porcentagem de acertos: " << contador*100/30 <<"%"<< endl;
	}
	//*/

	return 0;
}