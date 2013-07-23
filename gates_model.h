//Elsa Gonsiorowski
//October 7, 2011
//Rensselaer Polytechnic Institute

//General structs, defs, and vars for the model

#ifndef _gates_model_h
#define _gates_model_h

#include "ross.h"
#include "run_config.h"

//define logic type and value
typedef int BOOL;
typedef int LOGIC;
#define TRUE (1)
#define FALSE (0)
#define X (-1)
#define Z (2)

#define LOGIC_NOT(x) ((x) + 1) % 2

//message types
#define SOURCE_MSG (0)
#define SETUP_MSG (1)
#define LOGIC_CARY_MSG (2)
#define LOGIC_CALC_MSG (3)
#define SINK_MSG (4)
#define CLOCK_MSG (5)
#define WAVE_MSG (6)

//sim settings
#define MESSAGE_PAD (0.4)

//Model structs
typedef struct pair_t {
    unsigned int gid;
    unsigned int value;
} pair;

typedef struct vector_t {
    int size;
    int alloc;
    pair array[];
} *vector;

typedef struct {
    int type;
    pair data;
} message;

typedef int (*gate_func)(vector input, vector internal, vector output);

extern gate_func function_array[];
extern int gate_input_size[];
extern int gate_internal_size[];
extern int gate_output_size[];

typedef struct {
    
    //gate specific information
    unsigned int gate_type;
    
    //variables for linking gates
    vector inputs;
    vector internals;
    vector outputs;
    
    int received_events;
    int calc;

    BOOL wave_print;
    char wave_id;
    
} gate_state;

//Command Line Arguments
extern unsigned int source_interval;
extern unsigned int sink_interval;

//Global vars accessed by main and driver
extern tw_lptype gates_lps[];
extern char global_input[][LINE_LENGTH+1];
extern int wave_gids[];
extern FILE * wave_out_file;

//Duplcation mapping functions
inline int instance_node(unsigned int);
inline int node_instance(unsigned int);
inline int instance_id(unsigned int);
inline int instance_x(unsigned int);
inline int instance_y(unsigned int);
inline int instance_0(unsigned int);

//Custom Mapping functions
void gates_custom_linear_mapping_setup(void);
tw_lp * gates_custom_linear_mapping_to_local(tw_lpid lpid);
tw_peid gates_custom_linear_mapping_to_pe(tw_lpid gid);

void gates_custom_round_robin_mapping_setup(void);
tw_lp * gates_custom_round_robin_mapping_to_local(tw_lpid lpid);
tw_peid gates_custom_round_robin_mapping_to_pe(tw_lpid gid);

#endif
