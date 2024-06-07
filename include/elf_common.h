
#ifndef _ELF_COMMON_H_
#define _ELF_COMMON_H_

/* These constants are for the segment types stored in the image headers */
#define PT_NULL 0
#define PT_LOAD 1
#define PT_DYNAMIC 2
#define PT_INTERP 3
#define PT_NOTE 4
#define PT_SHLIB 5
#define PT_PHDR 6
#define PT_TLS 7           /* Thread local storage segment */
#define PT_LOOS 0x60000000 /* OS-specific */
#define PT_HIOS 0x6fffffff /* OS-specific */
#define PT_LOPROC 0x70000000
#define PT_HIPROC 0x7fffffff
#define PT_GNU_EH_FRAME (PT_LOOS + 0x474e550)
#define PT_GNU_STACK (PT_LOOS + 0x474e551)
#define PT_GNU_RELRO (PT_LOOS + 0x474e552)
#define PT_GNU_PROPERTY (PT_LOOS + 0x474e553)

/* ARM MTE memory tag segment type */
#define PT_AARCH64_MEMTAG_MTE (PT_LOPROC + 0x2)

#define PN_XNUM 0xffff

/* These constants define the different elf file types */
#define ET_NONE 0
#define ET_REL 1
#define ET_EXEC 2
#define ET_DYN 3
#define ET_CORE 4
#define ET_LOPROC 0xff00
#define ET_HIPROC 0xffff

/* This is the info that is needed to parse the dynamic section of the file */
#define DT_NULL 0
#define DT_NEEDED 1
#define DT_PLTRELSZ 2
#define DT_PLTGOT 3
#define DT_HASH 4
#define DT_STRTAB 5
#define DT_SYMTAB 6
#define DT_RELA 7
#define DT_RELASZ 8
#define DT_RELAENT 9
#define DT_STRSZ 10
#define DT_SYMENT 11
#define DT_INIT 12
#define DT_FINI 13
#define DT_SONAME 14
#define DT_RPATH 15
#define DT_SYMBOLIC 16
#define DT_REL 17
#define DT_RELSZ 18
#define DT_RELENT 19
#define DT_PLTREL 20
#define DT_DEBUG 21
#define DT_TEXTREL 22
#define DT_JMPREL 23
#define DT_ENCODING 32
#define OLD_DT_LOOS 0x60000000
#define DT_LOOS 0x6000000d
#define DT_HIOS 0x6ffff000
#define DT_VALRNGLO 0x6ffffd00
#define DT_VALRNGHI 0x6ffffdff
#define DT_ADDRRNGLO 0x6ffffe00
#define DT_ADDRRNGHI 0x6ffffeff
#define DT_VERSYM 0x6ffffff0
#define DT_RELACOUNT 0x6ffffff9
#define DT_RELCOUNT 0x6ffffffa
#define DT_FLAGS_1 0x6ffffffb
#define DT_VERDEF 0x6ffffffc
#define DT_VERDEFNUM 0x6ffffffd
#define DT_VERNEED 0x6ffffffe
#define DT_VERNEEDNUM 0x6fffffff
#define OLD_DT_HIOS 0x6fffffff
#define DT_LOPROC 0x70000000
#define DT_HIPROC 0x7fffffff

/* These constants define the permissions on sections in the memory image */
/* This info is needed when parsing the symbol table */
#define STB_LOCAL 0
#define STB_GLOBAL 1
#define STB_WEAK 2

#define STT_NOTYPE 0
#define STT_OBJECT 1
#define STT_FUNC 2
#define STT_SECTION 3
#define STT_FILE 4
#define STT_COMMON 5
#define STT_TLS 6

/* sh_type */
#define SHT_NULL 0
#define SHT_PROGBITS 1
#define SHT_SYMTAB 2
#define SHT_STRTAB 3
#define SHT_RELA 4
#define SHT_HASH 5
#define SHT_DYNAMIC 6
#define SHT_NOTE 7
#define SHT_NOBITS 8
#define SHT_REL 9
#define SHT_SHLIB 10
#define SHT_DYNSYM 11
#define SHT_NUM 12
#define SHT_LOPROC 0x70000000
#define SHT_HIPROC 0x7fffffff
#define SHT_LOUSER 0x80000000
#define SHT_HIUSER 0xffffffff

/* sh_flags */
#define SHF_WRITE 0x1
#define SHF_ALLOC 0x2
#define SHF_EXECINSTR 0x4
#define SHF_RELA_LIVEPATCH 0x00100000
#define SHF_RO_AFTER_INIT 0x00200000
#define SHF_MASKPROC 0xf0000000

/* special section indexes */
#define SHN_UNDEF 0
#define SHN_LORESERVE 0xff00
#define SHN_LOPROC 0xff00
#define SHN_HIPROC 0xff1f
#define SHN_LIVEPATCH 0xff20
#define SHN_ABS 0xfff1
#define SHN_COMMON 0xfff2
#define SHN_HIRESERVE 0xffff

#define EI_MAG0 0 /* e_ident[] indexes */
#define EI_MAG1 1
#define EI_MAG2 2
#define EI_MAG3 3
#define EI_CLASS 4
#define EI_DATA 5
#define EI_VERSION 6
#define EI_OSABI 7
#define EI_PAD 8

#define ELFMAG0 0x7f /* EI_MAG */
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'
#define ELFMAG "\177ELF"
#define SELFMAG 4

#define ELFCLASSNONE 0 /* EI_CLASS */
#define ELFCLASS32 1
#define ELFCLASS64 2
#define ELFCLASSNUM 3

#define ELFDATANONE 0 /* e_ident[EI_DATA] */
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

#define EV_NONE 0 /* e_version, EI_VERSION */
#define EV_CURRENT 1
#define EV_NUM 2

#define ELFOSABI_NONE 0
#define ELFOSABI_LINUX 3

#ifndef ELF_OSABI
#define ELF_OSABI ELFOSABI_NONE
#endif

#define NT_PRSTATUS 1
#define NT_PRFPREG 2
#define NT_PRPSINFO 3
#define NT_TASKSTRUCT 4
#define NT_AUXV 6
/*
 * Note to userspace developers: size of NT_SIGINFO note may increase
 * in the future to accomodate more fields, don't assume it is fixed!
 */
#define NT_SIGINFO 0x53494749
#define NT_FILE 0x46494c45
#define NT_PRXFPREG 0x46e62b7f /* copied from gdb5.1/include/elf/common.h */
#define NT_PPC_VMX 0x100       /* PowerPC Altivec/VMX registers */
#define NT_PPC_SPE 0x101       /* PowerPC SPE/EVR registers */
#define NT_PPC_VSX 0x102       /* PowerPC VSX registers */
#define NT_PPC_TAR 0x103       /* Target Address Register */
#define NT_PPC_PPR 0x104       /* Program Priority Register */
#define NT_PPC_DSCR 0x105      /* Data Stream Control Register */
#define NT_PPC_EBB 0x106       /* Event Based Branch Registers */
#define NT_PPC_PMU 0x107       /* Performance Monitor Registers */
#define NT_PPC_TM_CGPR 0x108   /* TM checkpointed GPR Registers */
#define NT_PPC_TM_CFPR 0x109   /* TM checkpointed FPR Registers */
#define NT_PPC_TM_CVMX 0x10a   /* TM checkpointed VMX Registers */
#define NT_PPC_TM_CVSX 0x10b   /* TM checkpointed VSX Registers */
#define NT_PPC_TM_SPR 0x10c    /* TM Special Purpose Registers */
#define NT_PPC_TM_CTAR 0x10d   /* TM checkpointed Target Address Register */
#define NT_PPC_TM_CPPR 0x10e   /* TM checkpointed Program Priority Register */
#define NT_PPC_TM_CDSCR                                                        \
    0x10f                     /* TM checkpointed Data Stream Control Register  \
                               */
#define NT_PPC_PKEY 0x110     /* Memory Protection Keys registers */
#define NT_PPC_DEXCR 0x111    /* PowerPC DEXCR registers */
#define NT_PPC_HASHKEYR 0x112 /* PowerPC HASHKEYR register */
#define NT_386_TLS 0x200      /* i386 TLS slots (struct user_desc) */
#define NT_386_IOPERM 0x201   /* x86 io permission bitmap (1=deny) */
#define NT_X86_XSTATE 0x202   /* x86 extended state using xsave */
/* Old binutils treats 0x203 as a CET state */
#define NT_X86_SHSTK 0x204        /* x86 SHSTK state */
#define NT_S390_HIGH_GPRS 0x300   /* s390 upper register halves */
#define NT_S390_TIMER 0x301       /* s390 timer register */
#define NT_S390_TODCMP 0x302      /* s390 TOD clock comparator register */
#define NT_S390_TODPREG 0x303     /* s390 TOD programmable register */
#define NT_S390_CTRS 0x304        /* s390 control registers */
#define NT_S390_PREFIX 0x305      /* s390 prefix register */
#define NT_S390_LAST_BREAK 0x306  /* s390 breaking event address */
#define NT_S390_SYSTEM_CALL 0x307 /* s390 system call restart data */
#define NT_S390_TDB 0x308         /* s390 transaction diagnostic block */
#define NT_S390_VXRS_LOW 0x309    /* s390 vector registers 0-15 upper half */
#define NT_S390_VXRS_HIGH 0x30a   /* s390 vector registers 16-31 */
#define NT_S390_GS_CB 0x30b       /* s390 guarded storage registers */
#define NT_S390_GS_BC 0x30c /* s390 guarded storage broadcast control block */
#define NT_S390_RI_CB 0x30d /* s390 runtime instrumentation */
#define NT_S390_PV_CPU_DATA 0x30e /* s390 protvirt cpu dump data */
#define NT_ARM_VFP 0x400          /* ARM VFP/NEON registers */
#define NT_ARM_TLS 0x401          /* ARM TLS register */
#define NT_ARM_HW_BREAK 0x402     /* ARM hardware breakpoint registers */
#define NT_ARM_HW_WATCH 0x403     /* ARM hardware watchpoint registers */
#define NT_ARM_SYSTEM_CALL 0x404  /* ARM system call number */
#define NT_ARM_SVE 0x405          /* ARM Scalable Vector Extension registers */
#define NT_ARM_PAC_MASK 0x406     /* ARM pointer authentication code masks */
#define NT_ARM_PACA_KEYS 0x407    /* ARM pointer authentication address keys */
#define NT_ARM_PACG_KEYS 0x408    /* ARM pointer authentication generic key */
#define NT_ARM_TAGGED_ADDR_CTRL                                                \
    0x409 /* arm64 tagged address control (prctl()) */
#define NT_ARM_PAC_ENABLED_KEYS                                                \
    0x40a                         /* arm64 ptr auth enabled keys (prctl()) */
#define NT_ARM_SSVE 0x40b         /* ARM Streaming SVE registers */
#define NT_ARM_ZA 0x40c           /* ARM SME ZA registers */
#define NT_ARM_ZT 0x40d           /* ARM SME ZT registers */
#define NT_ARM_FPMR 0x40e         /* ARM floating point mode register */
#define NT_ARC_V2 0x600           /* ARCv2 accumulator/extra registers */
#define NT_VMCOREDD 0x700         /* Vmcore Device Dump Note */
#define NT_MIPS_DSP 0x800         /* MIPS DSP ASE registers */
#define NT_MIPS_FP_MODE 0x801     /* MIPS floating-point mode */
#define NT_MIPS_MSA 0x802         /* MIPS SIMD registers */
#define NT_RISCV_CSR 0x900        /* RISC-V Control and Status Registers */
#define NT_RISCV_VECTOR 0x901     /* RISC-V vector registers */
#define NT_LOONGARCH_CPUCFG 0xa00 /* LoongArch CPU config registers */
#define NT_LOONGARCH_CSR 0xa01    /* LoongArch control and status registers */
#define NT_LOONGARCH_LSX                                                       \
    0xa02 /* LoongArch Loongson SIMD Extension registers                       \
           */
#define NT_LOONGARCH_LASX                                                      \
    0xa03 /* LoongArch Loongson Advanced SIMD Extension registers */
#define NT_LOONGARCH_LBT                                                       \
    0xa04 /* LoongArch Loongson Binary Translation registers */
#define NT_LOONGARCH_HW_BREAK                                                  \
    0xa05 /* LoongArch hardware breakpoint registers */
#define NT_LOONGARCH_HW_WATCH                                                  \
    0xa06 /* LoongArch hardware watchpoint registers */

/* Note types with note name "GNU" */
#define NT_GNU_PROPERTY_TYPE_0 5

/* These constants define the various ELF target machines */
#define EM_NONE 0
#define EM_M32 1
#define EM_SPARC 2
#define EM_386 3
#define EM_68K 4
#define EM_88K 5
#define EM_486 6 /* Perhaps disused */
#define EM_860 7
#define EM_MIPS 8 /* MIPS R3000 (officially, big-endian only) */
/* Next two are historical and binaries and
   modules of these types will be rejected by
   Linux.  */
#define EM_MIPS_RS3_LE 10 /* MIPS R3000 little-endian */
#define EM_MIPS_RS4_BE 10 /* MIPS R4000 big-endian */

#define EM_PARISC 15        /* HPPA */
#define EM_SPARC32PLUS 18   /* Sun's "v8plus" */
#define EM_PPC 20           /* PowerPC */
#define EM_PPC64 21         /* PowerPC64 */
#define EM_SPU 23           /* Cell BE SPU */
#define EM_ARM 40           /* ARM 32 bit */
#define EM_SH 42            /* SuperH */
#define EM_SPARCV9 43       /* SPARC v9 64-bit */
#define EM_H8_300 46        /* Renesas H8/300 */
#define EM_IA_64 50         /* HP/Intel IA-64 */
#define EM_X86_64 62        /* AMD x86-64 */
#define EM_S390 22          /* IBM S/390 */
#define EM_CRIS 76          /* Axis Communications 32-bit embedded processor */
#define EM_M32R 88          /* Renesas M32R */
#define EM_MN10300 89       /* Panasonic/MEI MN10300, AM33 */
#define EM_OPENRISC 92      /* OpenRISC 32-bit embedded processor */
#define EM_ARCOMPACT 93     /* ARCompact processor */
#define EM_XTENSA 94        /* Tensilica Xtensa Architecture */
#define EM_BLACKFIN 106     /* ADI Blackfin Processor */
#define EM_UNICORE 110      /* UniCore-32 */
#define EM_ALTERA_NIOS2 113 /* Altera Nios II soft-core processor */
#define EM_TI_C6000 140     /* TI C6X DSPs */
#define EM_HEXAGON 164      /* QUALCOMM Hexagon */
#define EM_NDS32                                                               \
    167                   /* Andes Technology compact code size                \
                             embedded RISC processor family */
#define EM_AARCH64 183    /* ARM 64 bit */
#define EM_TILEPRO 188    /* Tilera TILEPro */
#define EM_MICROBLAZE 189 /* Xilinx MicroBlaze */
#define EM_TILEGX 191     /* Tilera TILE-Gx */
#define EM_ARCV2 195      /* ARCv2 Cores */
#define EM_RISCV 243      /* RISC-V */
#define EM_BPF 247        /* Linux BPF - in-kernel virtual machine */
#define EM_CSKY 252       /* C-SKY */
#define EM_LOONGARCH 258  /* LoongArch */
#define EM_FRV 0x5441     /* Fujitsu FR-V */

#endif // _ELF_COMMON_H_