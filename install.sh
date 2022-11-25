#!/bin/bash

make
mkdir -p ~/.local/bin
echo "Installing..."
mv caesar ~/.local/bin
if [ $? -eq 0 ]; then
	echo "Success!"
else
	echo "The \"mv\" command returned a non-zero code! Please retry with sudo."
fi