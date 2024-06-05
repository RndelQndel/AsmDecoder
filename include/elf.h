
#ifndef _ELF_H_

#define _ELF_H_

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "common.h"

typedef struct _elf_header_ {
    uint8_t e_ident[16];  // ELF Identification
    uint16_t e_type;      // Object file type
    uint16_t e_machine;   // Architecture
    uint32_t e_version;   // Object file version
    uint32_t e_entry;     // Entry point virtual address
    uint32_t e_phoff;     // Program header table file offset
    uint32_t e_shoff;     // Section header table file offset
    uint32_t e_flags;     // Processor-specific flags
    uint16_t e_ehsize;    // ELF header size in bytes
    uint16_t e_phentsize; // Program header table entry size
    uint16_t e_phnum;     // Program header table entry count
    uint16_t e_shentsize; // Section header table entry size
    uint16_t e_shnum;     // Section header table entry count
    uint16_t e_shstrndx;  // Section header string table index
} elf_header, *p_elf_header;

typedef struct _elf_segment_header_ {
    uint32_t p_type;   // Segment type
    uint32_t p_flags;  // Segment flags
    uint64_t p_offset; // Segment file offset
    uint64_t p_vaddr;  // Segment virtual address
    uint64_t p_paddr;  // Segment physical address
    uint64_t p_filesz; // Segment size in file
    uint64_t p_memsz;  // Segment size in memory
    uint64_t p_align;  // Segment alignment
} elf_segment_header, *p_elf_segment_header;

typedef struct _elf_segment_ {
    elf_segment_header header;
    std::vector<uint8_t> data;
} elf_segment, *p_elf_segment;

typedef struct _elf_section_header_ {
    uint32_t sh_name;      // Section name
    uint32_t sh_type;      // Section type
    uint64_t sh_flags;     // Section attributes
    uint64_t sh_addr;      // Virtual address in memory
    uint64_t sh_offset;    // Offset in file
    uint64_t sh_size;      // Size of section
    uint32_t sh_link;      // Link to other section
    uint32_t sh_info;      // Additional information
    uint64_t sh_addralign; // Section alignment
    uint64_t sh_entsize;   // Entry size if section holds table
} elf_section_header, *p_elf_section_header;

// Define a struct for the ELF section
typedef struct _elf_section_ {
    elf_section_header header; // Section header information
    std::vector<uint8_t> data; // Section data
} elf_section, *p_elf_section;

typedef struct _elf_symbol_header_ {
    uint32_t st_name;  // Symbol name
    uint8_t st_info;   // Type and binding attributes
    uint8_t st_other;  // Reserved
    uint16_t st_shndx; // Section table index
    uint64_t st_value; // Symbol value
    uint64_t st_size;  // Size of object
} elf_symbol_header, *p_elf_symbol_header;

typedef struct _elf_symbol_ {
    elf_symbol_header header; // Symbol header information
    std::string name;         // Symbol name
} elf_symbol, *p_elf_symbol;

class elf {
  private:
    elf_header header;
    std::string filename;

    std::vector<elf_segment> segments;      // Program headers
    std::vector<elf_section> sections;      // Section headers
    std::map<uint64_t, elf_symbol> symbols; // Address to symbol

  public:
    elf(const std::string &filename);
    ~elf();

    void load();
};

#endif // _ELF_H_
