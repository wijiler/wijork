CC=gcc
S_DIR=Source
B_DIR=Build
build:
	$(CC) \
		-Wall \
		-o \
		$(B_DIR)/Ferengine \
		$(S_DIR)/main.c \
		-lSDL2 \
		-lSDL2_image \
		-ldl
clean:
	rm -f $(B_DIR)/*
