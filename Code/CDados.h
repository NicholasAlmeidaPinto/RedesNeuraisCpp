#ifndef CDados_h
#define CDados_h

#include <vector>
#include <string>
#include <sstream> // round() stringstream
#include <fstream> // ler dados disco
#include <iomanip> //setw()
#include <iostream>//cout

class CDados {
	protected:
		std::vector<std::vector<double>> entrada;       				//vector para dados de entrada
		std::vector<double> saida;         								//vector para dados de saída

		std::vector<std::vector<double>> entradaTeste;       			//vector para dados de entrada de teste
		std::vector<double> saidaTeste;         						//vector para dados de saída de teste

	public:
		//ENTRADA DE DADOS DE ARQUIVO DE DISCO
		std::vector<std::vector<double>> CarregarEntrada(std::string nomeArquivo);
		std::vector<double> CarregarSaida(std::string nomeArquivo);

		void Entrada(std::string nomeArquivo)      {entrada = CarregarEntrada(nomeArquivo);}		//abrir arquivo e colocar dados no vetor entrada
		void Saida(std::string nomeArquivo)        {saida = CarregarSaida(nomeArquivo);}            //colocar dados no vetor saida
		void Dados(std::string nomeArquivo); 														//colocar dados no de entrada e saida

		void EntradaTeste(std::string nomeArquivo) {entradaTeste = CarregarEntrada(nomeArquivo);}
		void SaidaTeste(std::string nomeArquivo)   {saidaTeste = CarregarSaida(nomeArquivo);}   
		void DadosTeste(std::string nomeArquivo); 

		void MostrarMatrix();
};

#endif