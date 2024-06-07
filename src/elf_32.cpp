
#include "elf_32.h"
#include <fstream> // Add this line

void elf_32::load() {
    if (filename.empty()) {
        return;
    }

    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        return;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    file.read(reinterpret_cast<char *>(buffer.data()), size);
    file.close();

    memcpy((&header), buffer.data(), sizeof(elf_header_32));

    // Read the program headers
    segments_header.resize(header.e_phnum);
    memcpy(segments_header.data(), buffer.data() + header.e_phoff,
           sizeof(elf_segment_header_32) * header.e_phnum);

    // Read the section headers
    sections_header.resize(header.e_shnum);
    memcpy(sections_header.data(), buffer.data() + header.e_shoff,
           sizeof(elf_section_header_32) * header.e_shnum);

    // Read the section string table
    elf_section_header_32 &strtabSection = sections_header[header.e_shstrndx];
    std::vector<char> strtab(strtabSection.sh_size);
    memcpy(strtab.data(), buffer.data() + strtabSection.sh_offset,
           strtabSection.sh_size);

    // Read the sections
    for (auto &section : sections_header) {
        elf_section_32 sectionData;
        sectionData.header = &section;
        sectionData.data.resize(section.sh_size);
        memccpy(sectionData.data.data(), buffer.data() + section.sh_offset, 0,
                section.sh_size);
        sectionData.name = std::string(strtab.data() + section.sh_name);
        sections.push_back(sectionData);
    }

    // Read the symbols
}
