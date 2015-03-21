CC=gcc
CFLAGS = -g -ggdb
FILES=myvulnerable.c myexploit.c

all: myexploit myvulnerable

myvulnerable: myvulnerable.c
	$(CC) -o $@ $< $(CFLAGS)
	sudo chown root myvulnerable
	sudo chmod u+s myvulnerable

myexploit: myexploit.c
	$(CC) -o $@ $< $(CFLAGS)
	sudo chown root myexploit
	sudo chmod u+s myexploit

clean: 
	$(RM) myvulnerable myexploit

