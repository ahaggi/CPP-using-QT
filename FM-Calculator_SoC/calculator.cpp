#include "calculator.h"


noe::noe(){
    operand = memory = 0;
    opr = PLUS;
}
//      Number key presses are handled here
//      Updates the number in memory and on display
void noe::keyPressed(int i){
    operand = operand*10 + i;
    emit valueChanged(operand);
}
//      Operator key presses are handled here
//      Calculates intermediate values and final result
void noe::keyPressed(QString str){
    memory += opr*operand;
    operand = 0;
    if(str == "+"){
        opr = PLUS;
    }
    else if( str == "-"){
        opr = MINUS;
    }
    else if( str == "="){
        operand = memory;
        memory = 0;
        opr = PLUS;
        emit valueChanged(operand);
    }
    else {
        // The user pressed "C"
        memory = operand = 0;
        opr = PLUS;
        emit valueChanged(operand);
    }
}
