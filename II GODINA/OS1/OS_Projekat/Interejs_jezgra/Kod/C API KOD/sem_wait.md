#Kod 
0x23

#Potpis 
```c
int sem_wait(sem_t id);
```

#Objasnjenje 
Operacija wait na semaforu sa datom ručkom. U slučaju uspeha vraća 0, a u slučaju neuspeha, uključujući i slučaj kada je semafor dealociran dok je pozivajuća nit na njemu čekala, vraća negativnu vrednost (kôd greške).