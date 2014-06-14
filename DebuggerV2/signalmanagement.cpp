#include "signalmanagement.h"

char signalManagement::getBytesQuantityFromCode(int code){
    switch (code) {
        case 0:
            return (char)0;
        case 1: // instruction
            return (char)3;
        case 10: // reg1
            return (char)3;
        case 11: //reg2
            return (char)3;
        case 12: //extendedInstr
            return (char) 3;
        case 24: // data_b_o
            return (char) 3;
        case 25: // out (EXE)
            return (char)3;
        case 26: // dataFromMem
            return (char)3;
        case 27: // dataFromImm
            return (char)3;
        case 29: // dataToRegFile
            return (char)3;
        case 34: //IAdd
            return (char)3;
        default:
            if(code > 63){
                return 3;
            }
            return (char) 0;
    }
}

int signalManagement::getCodeBasedIndex(int index){
    switch (index) {
        case 0: // clock;
            return 0;
        case 1: // ID: Instruction
            return 1;
        case 2: // ID: Iadd
            return 34;
        case 3: // ID: aluOp
            return 2;
        case 4: // isJump
            return 3;
        case 5: // isNotConditional
            return 4;
        case 6: // isEqual
            return 5;
        case 7: // memWrite
            return 6;
        case 8: // wbi
            return 7;
        case 9: // memRead
            return 8;
        case 10: // aluSrc
            return 9;
        case 11: // reg1
            return 10;
        case 12: // reg2
            return 11;
        case 13: // extendedInstr
            return 12;
        case 14: // regAddrr1
            return 13;
        case 15: // regAddrr2
            return 14;
        case 16: // regDst
            return 15;
        case 17: // is_jump_o
            return 16;
        case 18: // branch_eq_o
            return 17;
        case 19: // branch_inc_o
            return 18;
        case 20: // zero
            return 19;
        case 21: // jump_address
            return 20;
        case 22: // wbi_o
            return 21;
        case 23: // M_o
            return 22;
        case 24: // regAddr_o
            return 23;
        case 25: // data_b_o
            return 24;
        case 26: // out
            return 25;
        case 27: // dataFromMem
            return 26;
        case 28: // dataFromImm
            return 27;
        case 29: // regAddrOut
            return 28;
        case 30: // wbi
            return 31;
        case 31: // dataToRegFile
            return 29;
        case 32: // WeRegFile
            return 30;
         case 33: //reg 0
            return 83;
        default:
            return index;
    }
}

QString signalManagement::getStringFromCode(int code){
    switch(code){
        case 1:
            return "Instruction";
        case 34:
            return "Iadd";
        default:
            return "somthing";
    }
}
