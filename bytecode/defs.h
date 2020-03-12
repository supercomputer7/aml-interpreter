#ifndef AML_DEFS__H
#define AML_DEFS__H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef char AMLArray;

enum Prefixes {
    StringPrefix = 0x0D,
    BytePrefix = 0xA,
    WordPrefix = 0xB,
    DwordPrefix = 0xC,
    QWordPrefix = 0xE
};

enum Opcodes {
    ScopeOp = 0x10,
    AliasOp = 0x06,
    ExtOpPrefix = 0x5B,
    ZeroOp = 0x0,
    OneOp = 0x1,
};

enum ExtendedOpcodes {
    RevisionOp = 0x30
};

#endif
