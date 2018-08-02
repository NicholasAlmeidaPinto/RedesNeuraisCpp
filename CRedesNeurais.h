#ifndef CRedesNeurais_h
#define CRedesNeurais_h

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class CRedesNeurais {
	private:
		std::vector<std::vector<double>> entrada;       				//vector para dados de entrada
		std::vector<double> saida;         								//vector para dados de saída

		std::vector<std::vector<double>> entradaTeste;       			//vector para dados de entrada de teste
		std::vector<double> saidaTeste;         						//vector para dados de saída de teste

		std::vector<double> pesos;         								//vector dos pesos
		double taxaAprendizado = 0.1;
		int epocas = 5000;
	
	public:
		CRedesNeurais(){};               		//construtor
		~CRedesNeurais(){};                  	//destrutor

		double Randomico(double fMin = .0, double fMax = 1.0);
		//ENTRADA DE DADOS DE ARQUIVO DE DISCO
		std::vector<std::vector<double>> CarregarEntrada(std::string nomeArquivo);
		std::vector<double> CarregarSaida(std::string nomeArquivo);

		void Entrada(std::string nomeArquivo)      {entrada = CarregarEntrada(nomeArquivo);}		//abrir arquivo e colocar dados no vetor entrada
		void Saida(std::string nomeArquivo)        {saida = CarregarSaida(nomeArquivo);}            //colocar dados no vetor saida
		void Dados(std::string nomeArquivo); 														//colocar dados no de entrada e saida

		void EntradaTeste(std::string nomeArquivo) {entradaTeste = CarregarEntrada(nomeArquivo);}
		void SaidaTeste(std::string nomeArquivo)   {saidaTeste = CarregarSaida(nomeArquivo);}   
		void DadosTeste(std::string nomeArquivo); 

		//ALGORITMO DE APRENDIZADO
		bool Erro(double u, int i);
		void Perceptron(); // ja definido

		void Testar();  

		void MostrarMatrix(){
			for (int i = 0; i<entrada.size(); i++){
				for (int k= 0; k< entrada[0].size(); k++){
					std::cout<<std::setw(5) << entrada[i][k];
				}
				std::cout << std::setw(5) << saida[i] << "\n";
			}
		}
		void MostrarPeso(){
			std::cout << "\nPesos: ";
			for (int i = 0; i < pesos.size(); i++)
				std::cout << pesos[i] << "  ";
			std::cout << "\n";
		}

};
#endif