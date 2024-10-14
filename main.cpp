#include "include.cpp"

int registradores[32]; 
int PC = 0;
int clock = 0;
// PC += 4;

// o primeiro dígito da instrução no arquivo é onde vai ser salvo (operações da ula)

void LerInstrucoesDoArquivo(const string& nomeArquivo, int * registradores){
    
    string nomeArquivo = "input.data"; 
    
    ifstream arquivo(nomeArquivo); 
    string linha;

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        
        
      
    }

    arquivo.close(); // Fecha o arquivo
}

int main (){
    
    registradores[0] = 10; // Armazena 10 no registrador 0
    registradores[1] = 20; // Armazena 20 no registrador 1
    int soma = registradores[0] + registradores[1]; // Soma

    return 0;    
}