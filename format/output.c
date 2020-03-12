#include <format/output.h>
#include <stdlib.h>
#include <string.h>

static FormatOutput* s_format_output;

const FormatOutput* output_format()
{
    return s_format_output;
}
void set_output_format(FormatOutput* inital_format_output)
{
    s_format_output = malloc(sizeof(FormatOutput));
    memcpy(s_format_output, inital_format_output, sizeof(FormatOutput));
}

void print_help()
{
    print_version();
    printf("usage: amldecode [options] [aml_binary]\n");
    printf("\n 'aml_binary' is a raw binary file contains DSDT & AML bytecode\n");

    printf("\nStandard options:\n");
    printf("-h or --help\tdisplay this help and exit\n");
    printf("-version\tdisplay version information and exit\n");
}

void print_version()
{
    printf("Userspace AML Interpreter version 0.1\n");
    printf("Copyright (c) 2020 Liav A.\n");
}
