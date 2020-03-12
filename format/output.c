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
}

void print_version()
{
    printf("Copyright (c) 2020 Liav A.\n");
}
