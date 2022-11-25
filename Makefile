all:
	@echo "Building..."
	@g++ src/main.cpp -o caesar
	@echo "Done!"

exe:
	@echo "Building exe..."
	@g++ src/main.cpp -o caesar.exe
	@echo "Done!"
