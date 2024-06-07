
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
    bool is_64bit = false;
    bool is_loaded = false;

  public:
    elf_loader(const std::string &file_path);
    ~elf_loader();

    bool get_is_loaded() const { return is_loaded; }
    bool get_is_64bit() const { return is_64bit; }
    std::string get_filename() const { return filename; }
    uint8_t get_data() const { return ident.e_ident[EI_DATA]; }
    uint8_t get_osabi() const { return ident.e_ident[EI_OSABI]; }
    uint16_t get_type() const { return ident.e_type; }
    uint16_t get_machine() const { return ident.e_machine; }

    void load();
};

#endif // _ELF_LOADER_H_