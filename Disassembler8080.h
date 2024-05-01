#ifndef INTEL8080_DISASSEMBLER_DISASSEMBLER8080_H
#define INTEL8080_DISASSEMBLER_DISASSEMBLER8080_H

#include <cstdio>

int disassembler(unsigned char* buffer, int pc)
{
    unsigned char* code = &buffer[pc];
    int opBytes = 1;
    printf("0x%04x", pc);

    switch (*code) {
        case 0x00:
        case 0x10:
        case 0x20:
        case 0x30:
        case 0x08:
        case 0x18:
        case 0x28:
        case 0x38:
            printf("NOP");
            break;

        case 0x01:
            printf("LXI\tB, #$0x%02x%02x", code[2], code[1]);
            opBytes = 3;
            break;
        case 0x02:
            printf("STAX\tB");
            break;
        case 0x03:
            printf("INX\tB");
            break;
        case 0x04:
            printf("INR\tB");
            break;
        case 0x05:
            printf("DCR\tB");
            break;
        case 0x06:
            printf("MVI\tB, #$0x%02x", code[1]);
            opBytes = 2;
            break;
        case 0x07:
            printf("RLC");
            break;
        case 0x09:
            printf("DAD\tB");
            break;
        case 0x0A:
            printf("LDAX\tB");
            break;
        case 0x0B:
            printf("DCX\tB");
            break;
        case 0x0C:
            printf("INR\tT");
            break;
        case 0x0D:
            printf("DCR\tC");
            break;
        case 0x0E:
            printf("MVI\tC, #$0x%02x", code[1]);
            opBytes = 2;
            break;
        case 0x0F:
            printf("RRC");
            break;

        case 0x11:
            printf("LXI\tD, #$0x%02x%02x", code[2], code[1]);
            opBytes = 3;
            break;
        case 0x12:
            printf("STAX\tD");
            break;
        case 0x13:
            printf("INX\tD");
            break;
        case 0x14:
            printf("INR\tD");
            break;
        case 0x15:
            printf("DCR\tD");
            break;
        case 0x16:
            printf("MVI\tB, #$0x%02x", code[1]);
            opBytes = 2;
            break;
        case 0x17:
            printf("RAL");
            break;
        case 0x19:
            printf("DAD\tD");
            break;
        case 0x1A:
            printf("LDAX\tD");
            break;
        case 0x1B:
            printf("DCX\tD");
            break;
        case 0x1C:
            printf("INR\tE");
            break;
        case 0x1D:
            printf("DCR\tE");
            break;
        case 0x1E:
            printf("MVI\tE, #$0x%02x", code[1]);
            opBytes = 2;
            break;
        case 0x1F:
            printf("RAR");
            break;

        case 0x21:
            printf("LXI\tH, #$0x%02x%02x", code[2], code[1]);
            opBytes = 3;
            break;
        case 0x22:
            printf("SHLD\t #$0x%02x%02x", code[2], code[1]);
            opBytes = 3;
            break;
        case 0x23:
            printf("INX\tH");
            break;
    }

    printf("\n");
    return opBytes;
}

#endif //INTEL8080_DISASSEMBLER_DISASSEMBLER8080_H
