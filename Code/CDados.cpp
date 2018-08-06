#include "CDados.h"

using namespace std;

vector<vector<double>> CDados::CarregarEntrada(string nomeArquivo){

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

vector<double> CDados::CarregarSaida(string nomeArquivo){

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

void CDados::Dados(string nomeArquivo){
	ifstream infile(nomeArquivo);
	string line;

	getline(infile, line);
	int a;
	double d;
	a = stoi(line);

	while (! infile.eof()){
		vector<double> linha;

		/*
		getline(infile, line);
		istringstream iss(line);
		if (iss >> d) 		{saida.push_back(d);}
		//*/
		for (int i = 0; i < a; i++){
			getline(infile, line);
			istringstream iss(line);
			if (iss >> d)   {linha.push_back(d);}
		}
		///*
		getline(infile, line);
		istringstream iss(line);
		if (iss >> d) 		{saida.push_back(d);}//*/

		entrada.push_back(linha);
	}
	entrada.pop_back();
}

void CDados::DadosTeste(string nomeArquivo){
	ifstream infile(nomeArquivo);
	string line;

	getline(infile, line);
	int a;
	double d;
	a = stoi(line);

	while (! infile.eof()){
		vector<double> linha;

		/*
		getline(infile, line);
		istringstream iss(line);
		if (iss >> d) 		{saidaTeste.push_back(d);}
		//*/
		for (int i = 0; i < a; i++){
			getline(infile, line);
			istringstream iss(line);
			if (iss >> d)   {linha.push_back(d);}
		}
		///*
		getline(infile, line);
		istringstream iss(line);
		if (iss >> d) 		{saidaTeste.push_back(d);}
		//*/
		entradaTeste.push_back(linha);
	}
	entradaTeste.pop_back();
}

void CDados::MostrarMatrix(){
			for (int i = 0; i<entrada.size(); i++){
				for (int k= 0; k< entrada[0].size(); k++){
					std::cout<<std::setw(5) << entrada[i][k];
				}
				std::cout << std::setw(5) << saida[i] << "\n";
			}
		}