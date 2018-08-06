#include "CSimulador.h"

using namespace std;
void CSimulador::Menu(){
	CRedesNeurais maLe;
	string nome; 
	int i; 
	int k; 

	while (true){
		system("clear");
		cout << "--------------------------"
			<<"\n-----MACHINE LEARNING-----"
			<<"\n--------------------------" << endl;
		cout << "1-Arquivo Disco de entrada" 
			<<"\n2-Arquivo Disco de teste"
			<<"\n3-Algoritmos" << endl;
		cin >> i;
		switch(i){
			case 1:
				cout << "Nome: ";
				getline(cin, nome);
				maLe.Dados(nome);
				break;
			case 2:
				cout << "Nome: ";
				getline(cin, nome);
				maLe.Dados(nome);
				break;
			case 3:
				system("clear");
				cout << "--------------------------"
				<<"\n-----MACHINE LEARNING-----"
				<<"\n--------------------------" << endl;
			cout << "-------ALGORITMOS---------";
				cout <<"\n1 - Perceptron" 
				   	 <<"\n2 - KNN - k-Nearest Neighbors"
				   	 <<"\nEscolha --> ";
				   	 cin >> k;
				   	 switch ( k ){
				   	 	case 1:
				   	 		maLe.Perceptron();
				   	 		break;
				   	 	case 2:
				   	 		int contador = 0;
				   	 		for (int i = 0; i < 30; i++){
								if(maLe.kNN(i,7))
									contador++;}
									cout << "\nPorcentagem de acertos: " << contador*100/30 <<"%"<< endl;
				   	 		break;
				   	 }
			case 4:
				break;
		}
	}
}