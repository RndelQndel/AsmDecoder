
#include "arm.h"
#include "elf_loader.h"

void print_usage(const char *name) {
    std::cerr << "Usage: " << name << " [-p path] [-a arch]\n";
}

int main(int argc, char **argv) {
    std::string filename;
    uint32_t parse_flags = 0, arch_val = 0;

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
        } else if (((arg == "-a") || (arg == "--arch")) && i + 1 < argc) {
            std::string arch = argv[++i];
            if (arch == "arm") {
                std::cout << "ARM architecture selected\n";
                arch_val = DECODER_ARCH_ARM;
            } else if (arch == "x86") {
                std::cout << "x86 architecture selected\n";
                arch_val = DECODER_ARCH_x86;
            } else if (arch == "powerpc") {
                std::cout << "PowerPC architecture selected\n";
                arch_val = DECODER_ARCH_POWERPC;
            } else {
                std::cerr << "Unsupported architecture: " << arch << "\n";
                return ERROR_INVALID_OPTION;
            }
        } else {
            print_usage(argv[0]);
            return ERROR_INVALID_OPTION;
        }
    }

    if (parse_flags & DECODER_OPTION_PATH) {
        elf_loader elf(filename);

        if (arch_val == DECODER_ARCH_ARM) {
            // ARM-specific code
        } else if (arch_val == DECODER_ARCH_x86) {
            // x86-64 specific code
        } else if (arch_val == DECODER_ARCH_POWERPC) {
            // PowerPC specific code
        } else {
            std::cerr << "Invalid architecture selected\n";
            return ERROR_INVALID_OPTION;
        }
    }

    return 0;
}
