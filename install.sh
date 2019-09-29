gcc -c src/nautilus_terminal.c -o src/nautilus-terminal.o -fPIC $(pkg-config libnautilus-extension --cflags)
gcc -shared src/nautilus-terminal.o -o /usr/lib/nautilus/extensions-3.0/nautilus-terminal-extension.so $(pkg-config libnautilus-extension --libs)
FILE=/usr/bin/x-terminal-emulator
if [ ! -f "$FILE" ]; then
	ln -sf /usr/bin/$1 /usr/bin/x-terminal-emulator
fi
