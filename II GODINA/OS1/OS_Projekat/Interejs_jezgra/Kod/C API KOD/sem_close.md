 #Kod 
 0x22
 
#Potpis 
``` c
int sem_close (sem_t handle);
```

#Objasnjenje 
Oslobađa semafor sa datom ručkom. Sve niti koje su se zatekle da čekaju na semaforu se deblokiraju, pri čemu njihov wait vraća grešku. U slučaju uspeha vraća 0, a u slučaju neuspeha vraća negativnu vrednost (kôd greške).