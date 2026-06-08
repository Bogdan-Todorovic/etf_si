#Kod 
0x01

#Potpis
```c
void* mem_alloc (size_t size);
```

#Objasnjenje

Alocira prostor od (najmanje) size bajtova memorije, zaokruženo i poravnato na blokove veličine MEM_BLOCK_SIZE. Vraća pokazivač na deo alociranog prostora od kojeg do kraja datog prostora ima (najmanje) size bajtova u slučaju uspeha, a null u slučaju neuspeha. MEM_BLOCK_SIZE je celobrojna konstanta veća od ili jednaka 64, a manja od ili jednaka 1024.