//Elsa Gonsiorowski
//October 7, 2011
//Rensselaer Polytechnic Institute

#ifndef _ptwHeader_h
#define _ptwHeader_h

#include "ross.h"

//ASSUPMTIONS
//- No gate uses its output as an input (doesn't send an event to itself)

//NOTES
//- never reallocate!


//file settings generated by preprocessor
//#define LINE_LENGTH 82       //15  82
//#define TOTAL_GATE_COUNT 211001  //25  211001
//#define NP_COUNT 24           //4   12   24
//#define LP_COUNT 8792           //7   17584  8792 //calculated from TOTAL_GATE_COUNT and NP
#define SOURCE_OUTPUTS 3305    //11  3305
#define SINK_INPUTS 3205
#define MAX_GATE_INPUTS 4    //4   4
//#define MAX_GATE_OUTPUTS 1   //5214


//Gate Types
#define GATE_TYPE_COUNT (12)
#define SOURCE_GATE (0)
#define SINK_GATE (1)
#define INPUT_GATE (2)
#define OUTPUT_GATE (3)
#define NOT_GATE (4)
#define DFF_GATE (5)
#define AND_GATE (6)
#define NAND_GATE (7)
#define OR_GATE (8)
#define NOR_GATE (9)
#define XOR_GATE (10)
#define XNOR_GATE (11)

#define SOURCE_ID (0)
#define SINK_ID (1)

//message types
#define SOURCE_MSG (0)
#define SETUP_MSG (1)
#define LOGIC_CARY_MSG (2)
#define LOGIC_CALC_MSG (3)
#define SINK_MSG (4)

//define logic type and value
typedef int BOOL;
typedef int LOGIC;
#define TRUE (1)
#define FALSE (0)
#define X (-1)
#define Z (2)


//sim settings
#define MESSAGE_PAD (0.4)


#endif
