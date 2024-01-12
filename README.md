# JavaVeRegexKullanimi

<img width="863" alt="Ekran Resmi 2023-03-14 23 41 20" src="https://user-images.githubusercontent.com/75799790/225132293-c25d5b6f-52de-434f-92c7-5a68a7fdc40d.png">


#### Makefile dosyası:

```javascript

all: compile run

compile:
	gcc	-I ./include/	-o	./lib/Dosya.o	-c ./src/Dosya.c
	gcc	-I ./include/	-o	./lib/Kisi.o	-c  ./src/Kisi.c
	gcc	-I ./include/	-o	./lib/Oyun.o 	-c ./src/Oyun.c
	gcc -I ./include/	-o ./bin/Test	./lib/Dosya.o 	./lib/Kisi.o 	./lib/Oyun.o 	./src/Test.c
run:
	./bin/Test
```
