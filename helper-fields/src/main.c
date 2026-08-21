#include <stdio.h>
#include "packet_header.h"

int main(void) {
    packet_header_t header = {0};

    header.tcp_header.src_port = 0x1234;
    header.tcp_header.dest_port = 0x5678;
    header.tcp_header.seq_num = 0x9ABCDEF0;

    printf("Packet header size: %zu bytes\n", sizeof(packet_header_t));

    for (int i = 0; i < 8; i++) {
        printf("raw[%d] = 0x%02X\n", i, header.raw[i]);
    }

    return 0;
}