
#include "elf_loader.h"

#include <fstream>

elf_loader::elf_loader(const std::string &file_path) : filename(file_path) {
    is_64bit(is64bit);
    if (is64bit) {
        e = std::make_shared<elf_64>(filename);
    } else {
        e = std::make_shared<elf_32>(filename);
    }
}

elf_loader::~elf_loader() { e.reset(); }

uint32_t elf_loader::is_64bit(bool &is64bit) {
    if (filename.empty()) {
        return (ERROR_INVALID_FILE);
    }

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return (ERROR_INVALID_FILE);
    }

    file.read(reinterpret_cast<char *>(&ident), sizeof(elf_ident));

    if (ident.e_ident[EI_CLASS] == ELFCLASS64) {
        is64bit = true;
    } else {
        is64bit = false;
    }

    file.close();

    return (ERROR_SUCCESS);
}
