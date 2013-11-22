INCLUDE = -I ../mesinbaris -I ../ -I ../mystring -I ../mesinkarakter
all: data.c data.h mdata.c
	gcc data.c data.h mdata.c  ../mystring/mystring.o $(INCLUDE) -o data
	cp data mdata
