OUTPUT=hack.out
all:
	g++ -o $(OUTPUT) $$(ls src/*.cpp)
	chmod +x ./$(OUTPUT)
	./$(OUTPUT)

clean:
	rm $(OUTPUT)