
#ifndef _ELF_32_H_

#define _ELF_32_H_

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "common.h"

typedef struct _elf_header_32_ {
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
} elf_header_32, *p_elf_header_32;

typedef struct _elf_segment_header_32_ {
    uint32_t p_type;   // Segment type
    uint32_t p_offset; // Segment file offset
    uint32_t p_vaddr;  // Segment virtual address
    uint32_t p_paddr;  // Segment physical address
    uint32_t p_filesz; // Segment size in file
    uint32_t p_memsz;  // Segment size in memory
    uint32_t p_flags;  // Segment flags
    uint32_t p_align;  // Segment alignment
} elf_segment_header_32, *p_elf_segment_header_32;

typedef struct _elf_segment_32_ {
    elf_segment_header_32 *header;
    std::vector<uint8_t> data;
} elf_segment_32, *p_elf_segment_32;

typedef struct _elf_section_header_32_ {
    uint32_t sh_name;      // Section name
    uint32_t sh_type;      // Section type
    uint32_t sh_flags;     // Section attributes
    uint32_t sh_addr;      // Virtual address in memory
    uint32_t sh_offset;    // Offset in file
    uint32_t sh_size;      // Size of section
    uint32_t sh_link;      // Link to other section
    uint32_t sh_info;      // Additional information
    uint32_t sh_addralign; // Section alignment
    uint32_t sh_entsize;   // Entry size if section holds table
} elf_section_header_32, *p_elf_section_header_32;

// Define a struct for the ELF section
typedef struct _elf_section_32_ {
    elf_section_header_32 *header; // Section header information
    std::string name;              // Section name
    std::vector<uint8_t> data;     // Section data
} elf_section_32, *p_elf_section_32;

typedef struct _elf_symbol_header_32_ {
    uint32_t st_name;  // Symbol name
    uint32_t st_value; // Symbol value
    uint32_t st_size;  // Symbol size
    uint8_t st_info;   // Symbol type and binding
    uint8_t st_other;  // Symbol visibility
    uint16_t st_shndx; // Section index
} elf_symbol_header_32, *p_elf_symbol_header_32;

typedef struct _elf_symbol_32 {
    elf_symbol_header_32 header; // Symbol header information
    std::string name;            // Symbol name
} elf_symbol_32, *p_elf_symbol_32;

class elf_32 {
  private:
    elf_header_32 header;
    std::string filename;

    std::vector<elf_segment_header_32> segments_header; // Program headers
    std::vector<elf_section_header_32> sections_header; // Section headers
    std::vector<elf_segment_32> segments;
    std::vector<elf_section_32> sections;
    std::map<uint32_t, elf_symbol_32> symbols; // Address to symbol

  public:
    elf_32(const std::string &filename);
    ~elf_32();

    void load();
};

#endif // _ELF_32_H_
