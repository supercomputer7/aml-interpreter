#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <tables/dsdt.h>
#include <unistd.h>

static DSDT* s_dsdt;

int determine_dsdt_size(int dsdt_fd)
{
    DSDT* buffer = calloc(1, sizeof(DSDT));
    off_t current_position = lseek(dsdt_fd, 0, SEEK_CUR);
    lseek(dsdt_fd, 0, SEEK_SET);
    read(dsdt_fd, buffer, sizeof(DSDT));
    int length = buffer->length;
    lseek(dsdt_fd, current_position, SEEK_SET);
    free(buffer);
    return length;
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
bool fetch_full_dsdt(int dsdt_fd, size_t dsdt_size)
{
    s_dsdt = malloc(dsdt_size);
    off_t current_position = lseek(dsdt_fd, 0, SEEK_CUR);
    lseek(dsdt_fd, 0, SEEK_SET);
    if (read(dsdt_fd, s_dsdt, dsdt_size) != (ssize_t)dsdt_size)
        return false;
    lseek(dsdt_fd, current_position, SEEK_SET);
    return true;
}
const DSDT* dsdt_data()
{
    return s_dsdt;
}
