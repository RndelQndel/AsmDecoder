
#include "elf.h"
#include "elf_common.h"
#include <fstream> // Add this line

elf::elf(const std::string &filename) : filename(filename) {}

elf::~elf() {}

void elf::load() {
    if (filename.empty()) {
        return;
    }

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return;
    }

    // Read the ELF header
    file.read(reinterpret_cast<char *>(&header), sizeof(elf_header));

    // Read the program headers
    segments.resize(header.e_phnum);
    file.seekg(header.e_phoff);
    file.read(reinterpret_cast<char *>(segments.data()),
              sizeof(elf_segment) * header.e_phnum);

    // Read the section headers
    sections.resize(header.e_shnum);
    file.seekg(header.e_shoff);
    file.read(reinterpret_cast<char *>(sections.data()),
              sizeof(elf_section) * header.e_shnum);

    // Read the section string table
    elf_section &strtabSection = sections[header.e_shstrndx];
    std::vector<char> strtab(strtabSection.header.sh_size);
    file.seekg(strtabSection.header.sh_offset);
    file.read(strtab.data(), strtabSection.header.sh_size);

    // Read the symbol table
    for (auto &section : sections) {
        if (section.header.sh_type == SHT_SYMTAB ||
            section.header.sh_type == SHT_DYNSYM) {
            std::vector<elf_symbol_header> symbolHeaders(
                section.header.sh_size / sizeof(elf_symbol_header));
            file.seekg(section.header.sh_offset);
            file.read(reinterpret_cast<char *>(symbolHeaders.data()),
                      section.header.sh_size);

            for (const auto &symbolHeader : symbolHeaders) {
                elf_symbol symbol;
                symbol.header = symbolHeader;
                symbol.name = std::string(strtab.data() + symbolHeader.st_name);
                symbols[symbolHeader.st_value] = symbol;
            }
        }
    }

    file.close();
}
