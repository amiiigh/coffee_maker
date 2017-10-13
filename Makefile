a.out: main.o
	g++ *.o

main.o: main.cpp coffeemaker.o 
	g++ -c main.cpp 

coffeemaker.o: coffeemaker.cpp coffeemaker.h featuretree.o
	g++ -c coffeemaker.cpp

featuretree.o: featuretree.cpp featuretree.h featurenode.o alternativenode.o mandatorynode.o ornode.o optionalnode.o
	g++ -c featuretree.cpp

mandatorynode.o: mandatorynode.cpp mandatorynode.h featurenode.o
	g++ -c mandatorynode.cpp

ornode.o: ornode.cpp ornode.h featurenode.o
	g++ -c ornode.cpp

optionalnode.o: optionalnode.cpp optionalnode.h featurenode.o
	g++ -c optionalnode.cpp

alternativenode.o: alternativenode.cpp alternativenode.h featurenode.o
	g++ -c alternativenode.cpp

featurenode.o: featurenode.h featurenode.cpp;
	g++ -c featurenode.cpp


