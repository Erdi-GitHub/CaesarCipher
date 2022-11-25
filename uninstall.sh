#!/bin/bash

read -p "Are you sure you want to uninstall Caesar? (Y/n) " -n 1 -r
if [[ $REPLY =~ ^[Yy]$ ]]; then
	echo
	echo "Uninstalling..."
	rm ~/.local/bin/caesar
	if [ $? -eq 0 ]; then
		echo "Uninstalled!"
	else
		echo "Error occurred! Is Caesar installed? Check ~/.local/bin/caesar"
	fi
else
	echo
fi

# ~/.local/bin