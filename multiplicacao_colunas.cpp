#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LINHAS = 500, COLUNAS = 500, X = 500;

void gerarMatriz(vector<vector<int>>& matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void multiplicarPorColuna(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int j = 0; j < X; ++j) {
        for (int i = 0; i < LINHAS; ++i) {
            C[i][j] = 0;
        }
        for (int k = 0; k < COLUNAS; ++k) {
            for (int i = 0; i < LINHAS; ++i) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    srand(time(0));

    vector<vector<int>> matrizA(LINHAS, vector<int>(COLUNAS));
    vector<vector<int>> matrizB(COLUNAS, vector<int>(X));
    vector<vector<int>> matrizC(LINHAS, vector<int>(X, 0));

    gerarMatriz(matrizA, LINHAS, COLUNAS);
    gerarMatriz(matrizB, COLUNAS, X);

    clock_t inicio = clock();
    multiplicarPorColuna(matrizA, matrizB, matrizC);
    clock_t fim = clock();

    cout << "Tempo de execução (ordem por coluna): " 
         << (double)(fim - inicio) / CLOCKS_PER_SEC << " segundos" << endl;

    return 0;
}
