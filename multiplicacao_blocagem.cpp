#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LINHAS = 500, COLUNAS = 500, X = 500;
const int TAMANHO_BLOCO = 50;

void gerarMatriz(vector<vector<int>>& matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void multiplicarComBlocagem(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int i0 = 0; i0 < LINHAS; i0 += TAMANHO_BLOCO) {
        for (int j0 = 0; j0 < X; j0 += TAMANHO_BLOCO) {
            for (int k0 = 0; k0 < COLUNAS; k0 += TAMANHO_BLOCO) {
                for (int i = i0; i < min(i0 + TAMANHO_BLOCO, LINHAS); ++i) {
                    for (int j = j0; j < min(j0 + TAMANHO_BLOCO, X); ++j) {
                        int soma = 0;
                        for (int k = k0; k < min(k0 + TAMANHO_BLOCO, COLUNAS); ++k) {
                            soma += A[i][k] * B[k][j];
                        }
                        C[i][j] += soma;
                    }
                }
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
    multiplicarComBlocagem(matrizA, matrizB, matrizC);
    clock_t fim = clock();

    cout << "Tempo de execução com blocagem: " 
         << (double)(fim - inicio) / CLOCKS_PER_SEC << " segundos" << endl;

    return 0;
}
