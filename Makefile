# Makefile
COMPILER          = gcc
COMPILER_FLAGS    = -o
TARGET            = dist/lua_executor
INCLUDE           = src/lua.h
SOURCE_FILES      = src/main.c src/lua.c

build: $(SOURCE_FILES)
	$(COMPILER) $(COMPILER_FLAGS) $(TARGET) $(SOURCE_FILES) -I$(INCLUDE) -I/usr/local/include -L/usr/local/lib -llua
