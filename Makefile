raycaster: src/main.c include/raycaster.h include/raycaster.c include/include.h
	gcc -o raycaster src/main.c include/raycaster.h include/raycaster.c \
		include/include.h
clean: raycaster
	rm raycaster
