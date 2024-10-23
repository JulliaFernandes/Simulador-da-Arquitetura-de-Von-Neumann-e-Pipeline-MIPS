#include "include.cpp"
#include "ula.cpp"

void WriteBack(int resultado, int *registradores, int info1) {
    registradores[info1] = resultado;
    cout << "\nResultado = " << resultado << endl;
    // Escreve o resultado de volta nos registradores
}

void MemoryAccess(int resultado, int *registradores, int info1) {
    // Leitura ou escrita na memória
    WriteBack(resultado, registradores, info1);
}

void Execute(char instrucao, int info1, int info2, int info3, string info4, int *registradores) {

    int soma = 0, registradorAtual = info1;
    
    // Executa a operação na ULA
    if (instrucao == '='){   
        registradores[info1] = info2;
    }
    else if(instrucao == '@'){
        for(int i = 0; i < info3; i++){
            soma += registradores[registradorAtual];
            registradorAtual++;
            if(registradorAtual > info2){
                registradorAtual = info1;
            }
        }
        MemoryAccess(soma, registradores, info1);
        CLOCK++;
    }
    else if((instrucao != '&') && (instrucao != '@') && (instrucao != '?') ){
        int resultado = ULA(registradores[info2], registradores[info3], instrucao);
        MemoryAccess(resultado, registradores, info1);
        CLOCK++;
    } 
    else if (instrucao == '?') {
        cout << registradores[info1] << " " << info4 << " " << registradores[info2] << ": ";
        if (info4 == "<") {
            if (registradores[info1] < registradores[info2]){
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }         
        } 
        else if (info4 == ">") {
            if (registradores[info1] > registradores[info2]){
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }  
        } 
        else if (info4 == "=") {
            if (registradores[info1] == registradores[info2]){
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        } 
        else if (info4 == "!") {
            if (registradores[info1] != registradores[info2]){
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        }
        CLOCK++;
    }
}


void InstructionDecode(char instrucao, int info1, int info2, int info3, string info4, int *registradores) {
// Decodifica a instrução e prepara a execução
    sleep(0.1);
    Execute(instrucao, info1, info2, info3, info4, registradores);
}

void InstructionFetch(int *registradores, string linha) { // Lê a instrução da memória

    char instrucao;
    int info1=0, info2=0, info3=0;
    int resultado = 0;
    string info4="";

    stringstream ss(linha);        
    ss >> instrucao >> info1;

    if (instrucao != '&'){
        ss >> info2; 
    } 
    if ((instrucao != '=' ) && (instrucao != '?')) {
        ss >> info3;
    }
    if (instrucao == '?') {
        ss >> info4;
    }
    
    
    InstructionDecode(instrucao, info1, info2, info3, info4, registradores);
    PC++;
    
}

