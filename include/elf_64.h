
#ifndef _ELF_64_H_
#define _ELF_64_H_

#include "elf.h"

typedef struct _elf_header_64_ {
    uint8_t e_ident[16];  // ELF Identification
    uint16_t e_type;      // Object file type
    uint16_t e_machine;   // Machine type
    uint32_t e_version;   // Object file version
    uint64_t e_entry;     // Entry point virtual address
    uint64_t e_phoff;     // Program header table file offset
    uint64_t e_shoff;     // Section header table file offset
    uint32_t e_flags;     // Processor-specific flags
    uint16_t e_ehsize;    // ELF header size in bytes
    uint16_t e_phentsize; // Program header table entry size
    uint16_t e_phnum;     // Program header table entry count
    uint16_t e_shentsize; // Section header table entry size
    uint16_t e_shnum;     // Section header table entry count
    uint16_t e_shstrndx;  // Section header string table index
} elf_header_64, *p_elf_header_64;

typedef struct _elf_segment_header_64_ {
    uint32_t p_type;   // Segment type
    uint32_t p_flags;  // Segment flags
    uint64_t p_offset; // Segment file offset
    uint64_t p_vaddr;  // Segment virtual address
    uint64_t p_paddr;  // Segment physical address
    uint64_t p_filesz; // Segment size in file
    uint64_t p_memsz;  // Segment size in memory
    uint64_t p_align;  // Segment alignment
} elf_segment_header_64, *p_elf_segment_header_64;

typedef struct _elf_segment_64_ {
    elf_segment_header_64 *header;
    std::vector<uint8_t> data;
} elf_segment_64, *p_elf_segment_64;

typedef struct _elf_section_header_64_ {
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
} elf_section_header_64, *p_elf_section_header_64;

// Define a struct for the ELF section
typedef struct _elf_section_64_ {
    elf_section_header_64 *header; // Section header information
    std::string name;              // Section name
    std::vector<uint8_t> data;     // Section data
} elf_section_64, *p_elf_section_64;

typedef struct _elf_symbol_header_64_ {
    uint32_t st_name;  // Symbol name
    uint8_t st_info;   // Type and Binding attributes
    uint8_t st_other;  // Reserved
    uint16_t st_shndx; // Section table index
    uint64_t st_value; // Symbol value
    uint64_t st_size;  // Size of object
} elf_symbol_header_64, *p_elf_symbol_header_64;

typedef struct _elf_symbol_64 {
    elf_symbol_header_64 header; // Symbol header information
    std::string name;            // Symbol name
} elf_symbol_64, *p_elf_symbol_64;

class elf_64 : public elf {
  private:
    elf_header_64 header;
    std::string filename;

    std::vector<elf_segment_header_64> segments_header; // Program headers
    std::vector<elf_section_header_64> sections_header; // Section headers
    std::vector<elf_segment_64> segments;
    std::vector<elf_section_64> sections;
    std::map<uint64_t, elf_symbol_64> symbols; // Address to symbol

  public:
    elf_64(const std::string &file_path) : filename(file_path) {}
    ~elf_64() {}

    void load();
};

#endif // _ELF_64_H_