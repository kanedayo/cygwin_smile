SRC=smile.c
ICON=icon.rc
GCC=x86_64-w64-mingw32-gcc -mwindows
EXE=smile

all: $(EXE)
clean:
	rm -fr icon.o $(EXE).exe
icon.o: icon.rc
	windres.exe -i icon.rc $@
$(EXE): $(SRC) icon.o
	$(GCC) -o $@ $(SRC) icon.o
	@echo
	@echo "USAGE: ./$(EXE) file.txt #=> file_smile.txt"
	@echo
