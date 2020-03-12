#ifndef DSDT__H
#define DSDT__H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct ACPI_DSDT {
    char sig[4];
    uint32_t length;
    uint8_t revision;
    uint8_t checksum;
    char oem_id[6];
    char oem_table_id[8];
    uint32_t oem_revision;
    uint32_t creator_id;
    uint32_t creator_revision;
    uint8_t bytecode[];
} __attribute__((__packed__)) DSDT;

int determine_dsdt_size(int dsdt_fd);
bool validate_dsdt(int dsdt_fd);
void fetch_full_dsdt(int dsdt_fd, size_t dsdt_size);
const DSDT* dsdt_data();

#endif
