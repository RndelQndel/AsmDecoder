
#ifndef _ELF_LOADER_H_
#define _ELF_LOADER_H_

#include "elf.h"
#include "elf_32.h"
#include "elf_64.h"

#include <memory>

class elf_loader {
  private:
    std::shared_ptr<elf> e;
    std::string filename;
    elf_ident ident = {
        0,
    };
    bool is64bit = false;

  public:
    elf_loader(const std::string &file_path);
    uint32_t is_64bit(bool &is_64bit);
    ~elf_loader();
};

#endif // _ELF_LOADER_H_