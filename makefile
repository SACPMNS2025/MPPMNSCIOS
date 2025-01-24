MAKEFLAGS += --no-print-directory
CC=gcc-12

main: mppmns.exe
	@make -B mppmns.exe 2>/dev/null
	./mppmns.exe
	python3 check.py

mppmns.exe: mppmns.c mpparams.h
	$(CC) -o mppmns.exe mppmns.c -g -Wall -Wextra -O3 -funswitch-loops -funroll-loops -fno-tree-vectorize -fwhole-program

	

table5:
	@mv mpparams.h tmpparams.h 2>/dev/null || true
	@echo 1024 bit primes
	@cp tableparams/mpparams_1024_2.h mpparams.h
	@echo s = 2
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_1024_3.h mpparams.h
	@echo s = 3
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_1024_4.h mpparams.h
	@echo s = 4
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@$(CC) -o gmpopenssl.exe gmpopenssl.c -g -Wall -Wextra -O3 -funswitch-loops -funroll-loops -fno-tree-vectorize -fwhole-program -D LOG2P=1024 -lgmp -lcrypto && ./gmpopenssl.exe
	@echo
	@echo 2048 bit primes
	@cp tableparams/mpparams_2048_2.h mpparams.h
	@echo s = 2
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_2048_3.h mpparams.h
	@echo s = 3
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_2048_4.h mpparams.h
	@echo s = 4
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@$(CC) -o gmpopenssl.exe gmpopenssl.c -g -Wall -Wextra -O3 -funswitch-loops -funroll-loops -fno-tree-vectorize -fwhole-program -D LOG2P=2048 -lgmp -lcrypto && ./gmpopenssl.exe
	@echo
	@echo 4096 bit primes
	@cp tableparams/mpparams_4096_2.h mpparams.h
	@echo s = 2
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_4096_3.h mpparams.h
	@echo s = 3
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_4096_4.h mpparams.h
	@echo s = 4
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@$(CC) -o gmpopenssl.exe gmpopenssl.c -g -Wall -Wextra -O3 -funswitch-loops -funroll-loops -fno-tree-vectorize -fwhole-program -D LOG2P=4096 -lgmp -lcrypto && ./gmpopenssl.exe
	@echo
	@echo 6144 bit primes
	@cp tableparams/mpparams_6144_2.h mpparams.h
	@echo s = 2
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_6144_3.h mpparams.h
	@echo s = 3
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_6144_4.h mpparams.h
	@echo s = 4
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@$(CC) -o gmpopenssl.exe gmpopenssl.c -g -Wall -Wextra -O3 -funswitch-loops -funroll-loops -fno-tree-vectorize -fwhole-program -D LOG2P=6144 -lgmp -lcrypto && ./gmpopenssl.exe
	@echo
	@echo 8192 bit primes
	@cp tableparams/mpparams_8192_2.h mpparams.h
	@echo s = 2
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_8192_3.h mpparams.h
	@echo s = 3
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@cp tableparams/mpparams_8192_4.h mpparams.h
	@echo s = 4
	@make -B mppmns.exe >/dev/null
	@./mppmns.exe
	@$(CC) -o gmpopenssl.exe gmpopenssl.c -g -Wall -Wextra -O3 -funswitch-loops -funroll-loops -fno-tree-vectorize -fwhole-program -D LOG2P=8192 -lgmp -lcrypto && ./gmpopenssl.exe
	@rm mpparams.h
	@mv tmpparams.h mpparams.h 2>/dev/null || true
