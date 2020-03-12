#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <tables/dsdt.h>
#include <unistd.h>

int determine_dsdt_size(int dsdt_fd)
{
    DSDT* buffer = malloc(sizeof(DSDT));
    lseek(dsdt_fd, 0, SEEK_SET);
    read(dsdt_fd, buffer, sizeof(DSDT));
    free(buffer);
    return buffer->length;
}
bool validate_dsdt(int dsdt_fd)
{
    bool valid = false;
    DSDT* buffer = malloc(sizeof(DSDT));
    lseek(dsdt_fd, 0, SEEK_SET);
    read(dsdt_fd, buffer, sizeof(DSDT));
    if (!strncmp(buffer->sig, "DSDT", 4))
        valid = true;
    free(buffer);
    return valid;
}
struct ACPI_DSDT* fetch_full_dsdt(int dsdt_fd, size_t dsdt_size)
{
    DSDT* buffer = malloc(dsdt_size);
    lseek(dsdt_fd, 0, SEEK_SET);
    read(dsdt_fd, (char*)&buffer, dsdt_size);
    return buffer;
}
