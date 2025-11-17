make all:
	g++ -std=c++17 -Wall -I./ -Icore -ILayers -INetworkEngineCore -IUI \
    	./main.cpp ./UI/Menu.cpp \
    	-o neuralNetworkEngine