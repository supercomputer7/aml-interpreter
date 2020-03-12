#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <tables/dsdt.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Error: No file specified.\n");
        return -1;
    }

    int dsdt_fd = open(argv[1], O_RDONLY);
    if (dsdt_fd < 0) {
        perror(argv[1]);
        return -1;
    }
    if (!validate_dsdt(dsdt_fd)) {
        printf("Error: DSDT not valid, please load a DSDT file\n");
        return -1;
    }
    DSDT* aml = fetch_full_dsdt(dsdt_fd, determine_dsdt_size(dsdt_fd));
    free(aml);
    return 0;
}
