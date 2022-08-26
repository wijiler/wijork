CC=gcc
S_DIR=Source
B_DIR=Build
build:
	$(CC) \
		-Wall \
		-o \
		$(B_DIR)/Ferengine \
		$(S_DIR)/main.cpp \
		-lSDL2 \
		-lSDL2_image \
		-lbass \
		-ldl
clean:
	rm -f $(B_DIR)/*
