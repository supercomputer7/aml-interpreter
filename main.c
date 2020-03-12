#include <format/output.h>
#include <format/params.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc >= 2) {
        if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
            print_help();
            return 0;
        } else if (!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v")) {
            print_version();
            return 0;
        }
    }
    return handle_cmd_arguments(argc, argv);
}
