all: normal replica mutualinfo

normal: E-vs-beta-Normal.cc
	g++ -Wall -O3 E-vs-beta-Normal.cc -o normal
	
replica: Em-vs-beta-Replica.cc
	g++ -Wall -O3 Em-vs-beta-Replica.cc -o replica

mutualinfo: Mutual-info-vs-beta.cc
	g++ -Wall -O3 \
	`pkg-config --cflags --libs gsl tabdatrw-0.3 interp2dpp` \
	Mutual-info-vs-beta.cc -o mutualinfo
	
.PHONY: clean

clean:
	rm -f normal replica mutualinfo *.o 
