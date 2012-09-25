test-ppm: ppm.c test-ppm.c ppm.h
	cc -o $@ -std=gnu99 test-ppm.c ppm.c
