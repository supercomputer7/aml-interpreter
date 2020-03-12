#ifndef OUTPUT__H
#define OUTPUT__H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Format_Output {
    bool verbose;
    uint8_t verbose_level;
    bool hierarchical;
    bool linear;
} FormatOutput;

const FormatOutput* output_format();
void set_output_format(FormatOutput*);

void print_version();
void print_help();

#endif
