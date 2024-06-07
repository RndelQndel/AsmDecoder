
#ifndef _ELF_H_
#define _ELF_H_

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "common.h"
#include "elf_common.h"

typedef struct _elf_ident_ {
    uint8_t e_ident[16]; // ELF Identification
    uint16_t e_type;     // Object file type
    uint16_t e_machine;  // Machine type
    uint32_t e_version;  // Object file version
} elf_ident, *p_elf_ident;

class elf {
  public:
    virtual ~elf() = default;
    virtual void load() = 0;
};

#endif // _ELF_H_