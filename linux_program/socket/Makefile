SERVER_OBJ = server1.o

CLIENT_OBJ = client1.o 

INCLUDES =
LIBDIRS =
CFLAGS =
CC=gcc
ALL = server client

all: $(ALL)
server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o server $(SERVER_OBJ) $(LIBDIRS)

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o client $(CLIENT_OBJ) $(LIBDIRS)

clean: 
	rm -f *.o
	rm -f $(ALL)
	rm -f *_socket