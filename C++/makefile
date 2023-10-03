CC = g++
OPTIONS = -Wall -g
OUT = Gaslight-Sort
IN = Gaslight-Sort.cpp

all: $(OUT)

build:
	$(CC) $(OPTIONS) -o $(OUT) $(IN)

clown:
	$(CC) -fno-stack-protector $(OPTIONS) -o $(OUT) $(IN)

clean:
	@rm -rf $(OUT)