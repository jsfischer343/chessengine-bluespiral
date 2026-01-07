all:
	g++ uci.cc cli.cc positiontree.cc position.cc main.cc -o bluespiral
static:
	g++ uci.cc cli.cc positiontree.cc position.cc main.cc -o bluespiral -static
windows32:
	i686-w64-mingw32-g++ uci.cc cli.cc positiontree.cc position.cc main.cc -o bluespiral_w32.exe  -static
windows64:
	x86_64-w64-mingw32-g++ uci.cc cli.cc positiontree.cc position.cc main.cc -o bluespiral_w64.exe -static
debug:
	g++ -g uci.cc cli.cc positiontree.cc position.cc main.cc -o bluespiral
test:
	g++ -g uci.cc cli.cc positiontree.cc position.cc ../testing/test.cc -o bluespiral_test
benchmark:
	g++ -g uci.cc cli.cc positiontree.cc position.cc ../testing/benchmark.cc -o bluespiral_benchmark
clean:
	rm bluespiral -f
	rm bluespiral_test -f
	rm bluespiral_benchmark -f
	rm bluespiral_w32.exe -f
	rm bluespiral_w64.exe -f
	rm massif* -f
