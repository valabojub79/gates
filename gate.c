//Elsa Gonsiorowski
//October 7, 2011
//Rensselaer Polytechnic Institute

//This file represents a specific gate library implementation

#include <stdio.h>

#include "gates_model.h"
#include "gate.h"

int SOURCE_func(vector input, vector output){
    return 0;
}

int SINK_func(vector input, vector output){
    int i;
    for(i = 0; i < input->size; i++){
        //printf("Received a %d, supposedly from gate with id %d.\n", input->array[i].value, input->array[i].gid);
    }
    return 0;
}

int INPUT_func(vector input, vector output){
    int change_flag = FALSE;
    if (output->array[0].value != input->array[0].value) {
        change_flag = TRUE;
    }
    
    //size is expected to be 1
    int i;
    for (i = 0; i < input->size; i++) {
        output->array[i].value = input->array[i].value;
    }
    
    return change_flag;
}

int OUTPUT_func(vector input, vector output){
    int change_flag = FALSE;
    if (output->array[0].value != input->array[0].value) {
        change_flag = TRUE;
    }
    
    //size is expected to be 1
    int i;
    for (i = 0; i < input->size; i++) {
        //output->array[i].value = input->array[i].value;
    }
    
    return change_flag;
}

int NOT_func(vector input, vector output){
    int change_flag = FALSE;
    if (output->array[0].value == input->array[0].value) {
        change_flag = TRUE;
    }
    
    //size is expected to be 1
    int i;
    for(i = 0; i < input->size; i++){
        output->array[i].value = LOGIC_NOT(input->array[i].value);
    }
    
    return change_flag;
}

int DFF_func(vector input, vector output){
    int change_flag = FALSE;
    if (output->array[0].value != input->array[0].value) {
        change_flag = TRUE;
    }
    
    //size is expected to be 1
    int i;
    for (i = 0; i < input->size; i++) {
        output->array[i].value = input->array[i].value;
    }
    
    return change_flag;
}

int AND_func(vector input, vector output){
    int i;
    for(i = 0; i < input->size; i++){
        if (!input->array[i].value) {
            if (output->array[0].value == FALSE) {
                return FALSE;
            } else {
                output->array[0].value = FALSE;
                return TRUE;
            }
        }
    }
    if (output->array[0].value == TRUE) {
        return FALSE;
    } else {
        output->array[0].value = TRUE;
        return TRUE;
    }
}

int NAND_func(vector input, vector output){
    int and_change = AND_func(input, output);
    NOT_func(output, output);
    return LOGIC_NOT(and_change);
}

int OR_func(vector input, vector output){
    int i;
    for (i = 0; i < input->size; i++) {
        if (input->array[i].value) {
            if (output->array[0].value == TRUE) {
                return FALSE;
            } else {
                output->array[0].value = TRUE;
                return TRUE;
            }
        }
    }
    if (output->array[0].value == FALSE) {
        return FALSE;
    } else {
        output->array[0].value = FALSE;
        return TRUE;
    }
}

int NOR_func(vector input, vector output){
    int or_change = OR_func(input, output);
    NOT_func(output, output);
    return LOGIC_NOT(or_change);
}

int XOR_func(vector input, vector output){
    int i, count;
    for (i = 0, count = 0; i < input->size; i++) {
        if (input->array[i].value) {
            count++;
        }
    }
    
    if (output->array[0].value != count % 2) {
        output->array[0].value = count % 2;
        return TRUE;
    }
    return FALSE;
}

int XNOR_func(vector input, vector output){
    int xor_change = XOR_func(input, output);
    NOT_func(output, output);
    return LOGIC_NOT(xor_change);
}

gate_func function_array[GATE_TYPE_COUNT] = {
    &SOURCE_func,
    &SINK_func,
    &INPUT_func,
    &OUTPUT_func,
    &NOT_func,
    &DFF_func,
    &AND_func,
    &NAND_func,
    &OR_func,
    &NOR_func,
    &XOR_func,
    &XNOR_func,
};
