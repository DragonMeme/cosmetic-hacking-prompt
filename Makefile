OUTPUT=hack.out
all:
	g++ -o $(OUTPUT) $$(ls src/*.cpp)
	chmod +x ./$(OUTPUT)
	./$(OUTPUT)

assemble:
	g++ -S src/main.cpp

clean:
	rm $(OUTPUT) *.s
