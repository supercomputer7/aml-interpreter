#include <bytecode/package.h>

int determine_package_length(const AMLArray* package_scope)
{
    if (package_scope[0] != ScopeOp)
        return -1;
    AMLPackageLength* package = (AMLPackageLength*)&package_scope[1];
    size_t lead_bytes_count = package->lead_byte >> 6;
    if (lead_bytes_count == 0)
        return package->lead_byte & 0x3F;
    size_t length = package->lead_byte & 0xF;
    for(size_t index = 0; index < lead_bytes_count; index++)
        length |= package->byte_data[index] << (4 + (8 * index));
    return length;
}
