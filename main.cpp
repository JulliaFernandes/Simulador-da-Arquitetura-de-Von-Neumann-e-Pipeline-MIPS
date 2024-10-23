#include "include.cpp"
#include "unidadeControle.cpp"

#define NUM_PERIFERICOS 5

int PC = 0;
int CLOCK = 0;

void LerInstrucoesDoArquivo(const string& nomeArquivo, int *registradores){
    
    // string nomeArquivo = "input.data"; 
    
    ifstream arquivo(nomeArquivo); 
    string linha;

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    while (getline(arquivo, linha)) {
        // stringstream ss(linha);
        UnidadeControle(registradores, linha);
    }

    arquivo.close(); // Fecha o arquivo
}

int main (){

    string nomeArquivo = "input.data"; 
    int * registradores = (int *) malloc(32 * sizeof(int)); 
    LerInstrucoesDoArquivo(nomeArquivo, registradores);

    // Periféricos
    bool perifericos[NUM_PERIFERICOS] = {false};

    // Memórias
    unordered_map<int, int> cache;
    vector<int> principal;
    vector<vector<int>> disco;

    cout << "PC: " << PC << " " << "CLOCK: " << CLOCK << endl;
    
    return 0;    
}









