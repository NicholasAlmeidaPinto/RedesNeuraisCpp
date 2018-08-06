#ifndef CRedesNeurais_h
#define CRedesNeurais_h

#include "CDados.h"

#include <random>  // random()
#include <math.h>  //sqrt()

class CRedesNeurais : public CDados {	
	public:
		CRedesNeurais(){};               		//construtor
		~CRedesNeurais(){};                  	//destrutor

		//ALGORITMO DE APRENDIZADO
		double Randomico(double fMin = .0, double fMax = 1.0);
		void MostrarPeso(std::vector<double> pesos);
		void Testar(std::vector<double> pesos);  
		void Perceptron(double taxaAprendizado = 0.1, int epocas = 5000, int taxa_Minima = 100); // ja definido

		bool kInPular(int k, std::vector<int> pularPosicoes);
		double DistanciaEuclidiana(int j, int i, std::vector<int> pularPosicoes);
		int Maior_kNN(std::vector<int> resultado);
		bool kNN(int i, int K = 5, std::vector<int> pularPosicoes = {-1});

};
#endif