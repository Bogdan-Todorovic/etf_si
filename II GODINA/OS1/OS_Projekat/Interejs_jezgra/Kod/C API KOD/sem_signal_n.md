#Kod 
0x26

#Potpis 
```c
int sem_signal_n (sem_t id, unsigned n);
```

#Objasnjenje 
Operacija signal na semaforu sa datom ručkom, koja povećava vrednost semafora za n. Ukoliko postoje niti koje čekaju na semaforu, može doći do deblokiranja jedne ili više niti. U slučaju uspeha vraća 0, a u slučaju neuspeha vraća negativnu vrednost (kôd greške).