
#include "arm.h"
#include "elf_loader.h"

void print_elf_info(const elf_loader &elf) {
    std::cout << "====ELF File Successfully Loaded====\n";
    std::cout << "ELF file: " << elf.get_filename() << "\n";

    if (elf.get_is_64bit()) {
        std::cout << "64-bit ELF\n";
    } else {
        std::cout << "32-bit ELF\n";
    }

    if (elf.get_data() == ELFDATA2LSB) {
        std::cout << "Little-endian\n";
    } else if (elf.get_data() == ELFDATA2MSB) {
        std::cout << "Big-endian\n";
    }

    switch (elf.get_machine()) {
    case EM_ARM: {
        std::cout << "ARM\n";
        break;
    }
    case EM_RISCV: {
        std::cout << "RISC-V\n";
        break;
    }
    case EM_386: {
        std::cout << "x86\n";
        break;
    }
    case EM_X86_64: {
        std::cout << "x86-64\n";
        break;
    }
    default: {
        std::cout << "Unknown\n";
        break;
    }
    }

    std::cout << "====================================\n";
}

void print_usage(const char *name) {
    std::cerr << "Usage: " << name << " [-p path]\n";
}

int main(int argc, char **argv) {
    std::string filename;
    uint32_t parse_flags = 0;

    if (argc < 2) {
        print_usage(argv[0]);
        return ERROR_INVALID_OPTION;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (((arg == "-p") || (arg == "--path")) && i + 1 < argc) {
            filename = argv[++i];
            parse_flags |= DECODER_OPTION_PATH;
            std::cout << "Path: " << filename << "\n";
        } else {
            print_usage(argv[0]);
            return ERROR_INVALID_OPTION;
        }
    }

    if (parse_flags & DECODER_OPTION_PATH) {
        elf_loader elf(filename);

        elf.load();

        if (elf.get_is_loaded() == false) {
            std::cerr << "Failed to load ELF file\n";
            return ERROR_INVALID_FILE;
        } else {
            print_elf_info(elf);
        }

        // RUN DECODER
    }

    return 0;
}
