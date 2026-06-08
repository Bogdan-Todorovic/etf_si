#Kod 
0x02

#Potpis 
```c
int mem_free (void*);
```

#Objasnjenje 
Oslobađa prostor prethodno alociran pomoću mem_alloc. Vraća 0 u slučaju uspeha, negativnu vrednost u slučaju greške (kôd greške). Argument mora imati vrednost vraćenu iz mem_alloc. Ukoliko to nije slučaj, ponašanje je nedefinisano: jezgro može vratiti grešku ukoliko može da je detektuje ili manifestovati bilo kakvo drugo predvidivo ili nepredvidivo ponašanje.