
#include "arm.h"
#include "elf.h"

int main(int argc, char **argv) {
    std::string filename;
    uint32_t parse_flags = 0, arch_val = 0;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (((arg == "-p") || (arg == "--path")) && i + 1 < argc) {
            filename = argv[++i];
            parse_flags |= DECODER_OPTION_PATH;
        } else if (((arg == "-a") || (arg == "--arch")) && i + 1 < argc) {
            std::string arch = argv[++i];
            if (arch == "arm") {
                std::cout << "ARM architecture selected\n";
                arch_val = DECODER_ARCH_ARM;
            } else if (arch == "x86-64") {
                std::cout << "x86-64 architecture selected\n";
                arch_val = DECODER_ARCH_x86_64;
            } else if (arch == "powerpc") {
                std::cout << "PowerPC architecture selected\n";
                arch_val = DECODER_ARCH_POWERPC;
            } else {
                std::cerr << "Unsupported architecture: " << arch << "\n";
                return ERROR_INVALID_OPTION;
            }
        } else {
            std::cerr << "Usage: " << argv[0] << " [-p path]\n";
            return ERROR_INVALID_OPTION;
        }
    }

    if (parse_flags & DECODER_OPTION_PATH) {
        elf e(filename);
        e.load();

        if (arch_val == DECODER_ARCH_ARM) {
            // ARM-specific code
        } else if (arch_val == DECODER_ARCH_x86_64) {
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
