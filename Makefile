test-ppm: ppm.c test-ppm.c ppm.h
	gcc -o $@ -std=gnu99 test-ppm.c ppm.c

make-gaussian-kernel: ppm.c make-gaussian-kernel.c ppm.h
	gcc -o $@ -std=gnu99 make-gaussian-kernel.c ppm.c -lm
