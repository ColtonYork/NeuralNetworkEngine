make all:
	g++ -std=c++17 -Wall -I./ -Icore -ILayers -INetworkEngineCore -IUI \
    	$(shell find . -name "*.cpp") \
    	-o neuralNetworkEngine