# Makefile
COMPILER          = /usr/local/bin/gcc-13
COMPILER_FLAGS    = -o
TARGET            = dist/lua_executor
INCLUDE           = include/lua.h include/files.h
SOURCE_FILES      = src/main.c src/lua_run.c src/files.c

build: $(SOURCE_FILES)
	$(COMPILER) $(COMPILER_FLAGS) $(TARGET) $(SOURCE_FILES) -Iinclude -I/usr/local/include -L/usr/local/lib -llua
