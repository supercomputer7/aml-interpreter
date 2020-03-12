#ifndef AML_PACKAGE__H
#define AML_PACKAGE__H

#include <bytecode/defs.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct AML_PackageLength {
    uint8_t lead_byte;
    uint8_t byte_data[];
} __attribute__((__packed__)) AMLPackageLength;

int determine_package_length(const AMLArray*);

#endif
