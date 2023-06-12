#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
// ELF header structure
typedef struct {
unsigned char e_ident[16];
uint16_t e_type;
uint16_t e_machine;
uint32_t e_version;
uint64_t e_entry;
uint64_t e_phoff;
uint64_t e_shoff;
uint32_t e_flags;
uint16_t e_ehsize;
uint16_t e_phentsize;
uint16_t e_phnum;
uint16_t e_shentsize;
uint16_t e_shnum;
uint16_t e_shstrndx;
} ElfHeader;
// Print error message to stderr and exit with status code 98
void errorExit(const char *message) {
fprintf(stderr, "%s\n", message);
exit(98);
}
int main(int argc, char *argv[]) {
// Check if the correct number of arguments is provided
if (argc != 2) {
errorExit("Usage: elf_header elf_filename");
}
// Open the file
int fd = open(argv[1], O_RDONLY);
if (fd == -1) {
errorExit("Error opening the file");
}
// Read the ELF header
ElfHeader header;
if (read(fd, &header, sizeof(ElfHeader)) != sizeof(ElfHeader)) {
errorExit("Error reading the ELF header");
}
// Check if the file is an ELF file
if (memcmp(header.e_ident, "\x7F""ELF", 4) != 0) {
errorExit("Not an ELF file");
}
// Print the information from the ELF header
printf("Magic: ");
for (int i = 0; i < 16; i++) {
printf("%02x ", header.e_ident[i]);
}
printf("\n");
printf("Class: ");
if (header.e_ident[4] == 1) {
printf("ELF32\n");
} else if (header.e_ident[4] == 2) {
printf("ELF64\n");
} else {
printf("Invalid class\n");
}
printf("Data: ");
if (header.e_ident[5] == 1) {
printf("2's complement, little endian\n");
} else if (header.e_ident[5] == 2) {
printf("2's complement, big endian\n");
} else {
printf("Invalid data encoding\n");
}
printf("Version: %u\n", header.e_version);
printf("OS/ABI: %u\n", header.e_ident[7]);
printf("ABI Version: %u\n", header.e_ident[8]);
printf("Type: %u\n", header.e_type);
printf("Entry point address: 0x%lx\n", header.e_entry);
// Close the file
if (close(fd) == -1) {
errorExit("Error closing the file");
}
return 0;
}
