LIBS= lib/bin/neuron.o lib/bin/network.o lib/bin/csv.o

default: pcnn

pcnn: $(LIBS)
	g++ lib/main.cpp -o pcnn.out $(LIBS)

lib/bin/csv.o: lib/bin/neuron.o lib/include/csv.h
	g++ -c lib/src/csv.cpp -o lib/bin/csv.o lib/bin/neuron.o

lib/bin/network.o: lib/bin/neuron.o lib/include/network.h
	g++ -c lib/src/network.cpp -o lib/bin/network.o lib/bin/neuron.o

lib/bin/neuron.o: lib/include/neuron.h
	g++ -c lib/src/neuron.cpp -o lib/bin/neuron.o

run:
	make clean
	make pcnn
	./pcnn.out -c data/test.csv

clean:
	rm $(LIBS)
	rm pcnn.out