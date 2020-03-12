#include <fcntl.h>
#include <format/output.h>
#include <format/params.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tables/dsdt.h>
#include <unistd.h>

int handle_cmd_arguments(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Error: No parameters specified.\n");
        return -1;
    }

    int dsdt_fd = open(argv[argc - 1], O_RDONLY);
    if (dsdt_fd < 0) {
        perror(argv[argc - 1]);
        print_help();
        return -1;
    }

    if (!validate_dsdt(dsdt_fd)) {
        printf("Error: DSDT not valid, please load a DSDT file\n");
        return -1;
    }
    fetch_full_dsdt(dsdt_fd, determine_dsdt_size(dsdt_fd));
    return 0;
}
