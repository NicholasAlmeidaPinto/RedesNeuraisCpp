#include "CRedesNeurais.h"
#include <sstream> // round()
#include <fstream> // ler dados disco
#include <random>  // random()

using namespace std;

vector<vector<double>> CRedesNeurais::CarregarEntrada(string nomeArquivo){

	vector<vector<double>> dados;

	ifstream infile(nomeArquivo);
	string line;

	getline(infile, line);
	int a;
	a = stoi(line);

	while (! infile.eof()){
		vector<double> linha;

		for (int i = 0; i < a; i++){
			getline(infile, line);
			istringstream iss(line);
			double d;
			if (iss >> d) {linha.push_back(d);}
		}
		dados.push_back(linha);
	}
	dados.pop_back();
	return dados;
}

vector<double> CRedesNeurais::CarregarSaida(string nomeArquivo){

	vector<double> dados;
	double d;

	ifstream infile(nomeArquivo);
	string line;

	while (! infile.eof()){
		getline(infile, line);
		istringstream iss(line);
		if (iss >> d) {dados.push_back(d);}
	}
	return dados;
}

void CRedesNeurais::Dados(string nomeArquivo){
	ifstream infile(nomeArquivo);
	string line;

	getline(infile, line);
	int a;
	double d;
	a = stoi(line);

	while (! infile.eof()){
		vector<double> linha;

		for (int i = 0; i < a; i++){
			getline(infile, line);
			istringstream iss(line);
			if (iss >> d)   {linha.push_back(d);}
		}
		getline(infile, line);
		istringstream iss(line);
		if (iss >> d) 		{saida.push_back(d);}

		entrada.push_back(linha);
	}
	entrada.pop_back();
}

void CRedesNeurais::DadosTeste(string nomeArquivo){
	ifstream infile(nomeArquivo);
	string line;

	getline(infile, line);
	int a;
	double d;
	a = stoi(line);

	while (! infile.eof()){
		vector<double> linha;

		for (int i = 0; i < a; i++){
			getline(infile, line);
			istringstream iss(line);
			if (iss >> d)   {linha.push_back(d);}
		}
		getline(infile, line);
		istringstream iss(line);
		if (iss >> d) 		{saidaTeste.push_back(d);}

		entradaTeste.push_back(linha);
	}
	entradaTeste.pop_back();
}

double CRedesNeurais::Randomico(double fMin, double fMax) // deixar random antre 0 e 1
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool CRedesNeurais::Erro(double u, int i){
	if (u == saida[i])
		return true;
	else 
		return false;
}

void CRedesNeurais::Perceptron(){
	for (int i = 0; i< entrada[0].size(); i++){
		pesos.push_back(Randomico());
	}
	int n_epocas = 0;
	bool erro;

	while (true){
		erro = false;
		for (int i = 0; i < entrada.size(); i++){
			double u = .0;
			double erro_aux;

			for (int k = 0; k < entrada[0].size(); k++)			{ u+=pesos[k] * entrada[i][k];}

			if (not Erro(round(u),i)){
				erro_aux = saida[i] - round(u);
				for (int k = 0; k < entrada[0].size(); k++) 	{ pesos[k] += taxaAprendizado*erro_aux*entrada[i][k];}
				erro = true;
			}
		}
		n_epocas+=1;
		
		if (not erro){
			cout << "Limite de erro\nEpocas: " << n_epocas;
			break;
		}
		if (n_epocas > epocas){
			cout << "Limite de tempo\nEpocas: " << n_epocas;
			break;
		}
	}
}

void CRedesNeurais::Testar(){
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