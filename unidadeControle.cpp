#include "include.cpp"

void UnidadeControle(char opcode, stringstream ss, string instrucao, int info1, int info2, int info3, int &registradores) {

    switch(opcode) {

        case '+': // ADD
        InstructionFetch(instrucao, info1, info2, info3, registradores);
        break;
        
        case '-': // SUB
        InstructionFetch(instrucao, info1, info2, info3, registradores);
        break;

        case '*': // MULT
        InstructionFetch(instrucao, info1, info2, info3, registradores);
        break;

        case '/': // DIV
        InstructionFetch(instrucao, info1, info2, info3, registradores);
        break;

        case '=': // SAVE REG - = 2 (dig do registrador) 10 (valor)
        InstructionFetch(instrucao, info1, info2, info3, registradores);
        break;
    }
}