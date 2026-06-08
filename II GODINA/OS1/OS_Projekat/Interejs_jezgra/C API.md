Deklaracije date u fajlu syscall_c.hpp i one su sledece:

0x01 - [[mem_alloc]]
0x02 - [[mem_free]]
0x11 - [[thread_create]]
0x12 - [[thread_exit]]
0x13 - [[thread_dispatch]]
0x21 - [[sem_open]]
0x22 - [[sem_close]]
0x23 - [[sem_wait]]
0x24 - [[sem_signal]]
0x25 - [[sem_wait_n]]
0x26 - [[sem_signal_n]]
0x31 - [[time_sleep]]
0x41 - [[getc]]
0x42 - [[putc]]

Nit se kreira sa podrazumevanom velicinom steka i podrazumevanom velicinom vremenskog odreska. Ove konstante su deklarisane u hw.h a definisane u hw.lib.

Memorijski prostor koji je slobodan pocinje od adrese HEAP_START_ADDR, a zavrsava se na adresi HEAP_END_ADDR-1. Ove konstante kao i konstanta MEM_BLOCK_SIZE, deklarisane u hw.h a definisane u hw.lib
