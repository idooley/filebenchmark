

file_create_write : file_create_write.cpp	
	g++ -std=c++11 file_create_write.cpp -o file_create_write

run : file_create_write
	./file_create_write

clean : 
	rm -f file_create_write a.out *~ test.txt