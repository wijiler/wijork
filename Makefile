CC=gcc
S_DIR=Source
B_DIR=Build
irrklangopt= -I"irrklang/include" -L"/usr/lib" irrklang/bin/linux/libIrrKlang.so -pthread
build:
	$(CC) \
		-Wall \
		-o \
		ExampleGame \
		$(S_DIR)/main.cpp \
		-lSDL2 \
		-lSDL2_image \
		$(irrklangopt) \
		-ldl
clean:
	rm -f $(B_DIR)/*
