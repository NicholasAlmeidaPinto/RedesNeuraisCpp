#include "CRedesNeurais.h"

using namespace std;

double CRedesNeurais::Randomico(double fMin, double fMax) // deixar random antre 0 e 1
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
void CRedesNeurais::MostrarPeso(vector<double> pesos){
			std::cout << "\nPesos: ";
			for (int i = 0; i < pesos.size(); i++)
				std::cout << pesos[i] << "  ";
			std::cout << "\n";
		}

void CRedesNeurais::Testar(vector<double> pesos){
	double u;
	int count = 0;
	for (int i = 0; i < entradaTeste.size(); i++){
		u = 0;
		for (int k = 0; k < entradaTeste[0].size(); k++){
			u+= entradaTeste[i][k] * pesos[k];
		}
		if (round(u) == saida[i]){
			count++;
		}
	}
	cout << "\nAcertos: " << count;
	cout << "\nPorcentagem de acertos: " << count*100/entradaTeste.size() << "%" << endl;
}

void CRedesNeurais::Perceptron(double taxaAprendizado, int epocas, int taxa_Minima){
	vector<double> pesos;
	int n_epocas = 0;
	int taxa = 0;
	bool erro;
	double previsao = .0;
	double erro_aux;

	for (int i = 0; i< entrada[0].size(); i++){ //inciar vetor pesos com valores randomicos
		pesos.push_back(Randomico());
	}

	while (true){
		taxa = 0;
		erro = false;
		for (int i = 0; i < entrada.size(); i++){

			previsao = .0;
			for (int k = 0; k < entrada[0].size(); k++)			{ previsao+=pesos[k] * entrada[i][k];}

			if (not (round(previsao) == saida[i])){ //se previsao for igual ao desejado para todos os dados, sai do loop
				erro_aux = saida[i] - round(previsao);
				for (int k = 0; k < entrada[0].size(); k++) 	{ pesos[k] += taxaAprendizado*erro_aux*entrada[i][k];} //corrige vetor pesos
				erro = true; //rodar novamente o loop while
			}
			else
				taxa++; //posteriormente comparar com taxa_Minima e sair do loop
		}
		n_epocas+=1;
		
		if (not erro){ //condicoes para parar o loop: erro nulo, tempo e taxa minima
			cout << "Limite de erro\nEpocas: " << n_epocas << endl;
			break;
		}
		if (n_epocas > epocas){
			cout << "Limite de tempo\nEpocas: " << n_epocas << endl;
			break;
		}
		if (taxa == taxa_Minima){
			cout << "Limite de taxa minima \nEpocas: " << n_epocas << endl;
			break;
		}
		//MostrarPeso(pesos);
		Testar(pesos);
	}
}

bool CRedesNeurais::kInPular(int k, vector<int> pularPosicoes){ //ver se k percente ao vetor pular
	for (int i = 0; i < pularPosicoes.size(); i++)
		if (k == pularPosicoes[i])
			return true;
	return false;
}

double CRedesNeurais::DistanciaEuclidiana(int j, int i, vector<int> pularPosicoes){ //retorna a distancia entre analisado e entrada
	double distancia = 0.0;
	for (int k = 0; k < entrada[j].size(); k++)
		if (not kInPular(k, pularPosicoes)) //pular certas colunas
			distancia+=(entradaTeste[i][k] - entrada[j][k])*(entradaTeste[i][k] - entrada[j][k]);
	return sqrt(distancia);
}
int CRedesNeurais::Maior_kNN(vector<int> resultado){ //retorna o valor mais repetido em um vetor
	vector<int> tipos{0};
	vector<int> contador;

	bool existe = false;
	for (int i = 0; i < resultado.size(); i++){ // monta um vetor com todos os valores distintos
		for (int k = 0; k < tipos.size(); k++)
			if (tipos[k] == resultado[i])
				existe = true; 
		if (not existe)
			tipos.push_back(resultado[i]);
	}

	contador.resize(tipos.size());
	for (int i = 0; i < tipos.size(); i++)		//conta quantas vezes cada valor distinto aparece no vetor analisado
		for (int k = 0; k < resultado.size(); k++)
			if (tipos[i] == resultado[k])
				contador[i]++;
	

	int u = 0, posicao;
	for (int i = 0; i < contador.size(); i++){	//analisa qual valor repetiu mais pelo contador
		if ( u < contador[i]){
			u = contador[i];
			posicao = i;
		}
	}
	return tipos[posicao];
}

bool CRedesNeurais::kNN(int i, int K, vector<int> pularPosicoes){ // i: posicao da entradaTeste analisado
	vector<double> distancias;	// armazena as distancias
	vector<int> value;	   		// armazena os valores de cada distancia
	vector<int> resultado; 		// armazena os valores das K menores posicoes
	double menorDistancia, maiorDistancia = 0.0;
	int contador_K = 0, posicao;
	resultado.resize(K);

	for (int j = 0; j < entrada.size(); j++){
		distancias.push_back( DistanciaEuclidiana(j, i, pularPosicoes));
		value.push_back(saida[j]);
	}

	for (int j = 0; j < distancias.size(); j++) 		// pegar o maior valor das distancias
		if (maiorDistancia < distancias[j]){
			maiorDistancia = distancias[j];				// iniciar u com o maior valor possivel -- evitar erro dependendo da dimensao das distancias
			posicao = j;
		}

	while (contador_K < K){ 							// pegar as K menores distancias e seus valores 
		menorDistancia = maiorDistancia;
		for (int j = 0; j < distancias.size(); j++){
			if (menorDistancia > distancias[j]) { 
				menorDistancia = distancias[j];						//pegar a menor distancia
				resultado[contador_K] = value[j]; 		//pegar o valor da resposta da distancia
				posicao = j;							//pegar a posicao do vetor para posteriormente apagar esse dado
			}
		}	
		distancias.erase(distancias.begin() + posicao); //excluir valor dos vetores para nao ser comparado posteriormente
		value.erase(value.begin() + posicao);
		contador_K++;
	}

	int resposta = Maior_kNN(resultado);
	//cout << "\n"<<setw(3) << i << ": " << setw(2) << saidaTeste[i] << "-->" << setw(2) << resposta;

	if (resposta == saidaTeste[i])
		return true;
	else
		return false;
}