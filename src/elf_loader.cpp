
#include "elf_loader.h"

#include <fstream>

elf_loader::elf_loader(const std::string &file_path) : filename(file_path) {
    if (filename.empty()) {
        return;
    }

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return;
    }

    file.read(reinterpret_cast<char *>(&ident), sizeof(elf_ident));

    if (ident.e_ident[EI_MAG0] != ELFMAG0 ||
        ident.e_ident[EI_MAG1] != ELFMAG1 ||
        ident.e_ident[EI_MAG2] != ELFMAG2 ||
        ident.e_ident[EI_MAG3] != ELFMAG3) {
        return;
    }

    if (ident.e_ident[EI_CLASS] != ELFCLASS32 &&
        ident.e_ident[EI_CLASS] != ELFCLASS64) {
        return;
    }

    if (ident.e_ident[EI_CLASS] == ELFCLASS64) {
        is_64bit = true;
    } else {
        is_64bit = false;
    }

    if (is_64bit) {
        e = std::make_shared<elf_64>(filename);
    } else {
        e = std::make_shared<elf_32>(filename);
    }

    file.close();
}

elf_loader::~elf_loader() { e.reset(); }

void elf_loader::load() {
    if (e) {
        e->load();
        is_loaded = true;
    }
}
