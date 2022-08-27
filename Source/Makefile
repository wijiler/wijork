CC=gcc
B_DIR=Build
irrklangopt= -I"../irrklang/include" -L"/usr/lib" ../irrklang/bin/linux/libIrrKlang.so -pthread
lstdc = -L/usr/lib64 -lstdc++
build:
	$(CC) \
		-Wall \
		-o \
		../$(B_DIR)/ExampleGame \
		main.cpp \
		-lSDL2 \
		-lSDL2_image \
		$(irrklangopt) \
		$(lstdc) \
		-std=c++17 \
		-ldl
clean:
	rm -f $(B_DIR)/*
