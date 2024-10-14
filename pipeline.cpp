#include "include.cpp"

void WriteBack() {
// Escreve o resultado de volta nos registradores
}

void MemoryAccess(int resultado, int &registradores, int info1) {
// Leitura ou escrita na memória
  registradores[info1] = resultado;

  WriteBack();
}

void Execute(string instrucao, int info1, int info2, int info3, int &registradores) {
// Executa a operação na ULA
    if (instrucao == "="){   
        registradores[info1] = info2;
    }
    else{ 
        int resultado = ULA(registradores[info2], registradores[info3], instrucao);
        MemoryAccess(resultado, registradores, info1);
    } 
}

void InstructionDecode(string instrucao, int info1, int info2, int info3, int &registradores) {
// Decodifica a instrução e prepara a execução

    sleep(0.1);

    Execute(instrucao, info1, info2, info3, registradores);
}


void InstructionFetch(stringstream ss, string instrucao, int info1, int info2, int info3, int &registradores) { // Lê a instrução da memória

    string instrucao;
    int info1, info2, info3;
    int resultado = 0;
        
    ss >> instrucao >> info1 >> info2; 

    if(instrucao != '='){
        ss >> info3;
    }

    InstructionDecode(instrucao, info1, info2, info3, registradores);
}

