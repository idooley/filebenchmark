#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h>

int main() {
  struct timeval start, end;
  int numIters = 120;
  
  long maxTimeMillis = 0;

  for (int i = 0; i < numIters; i++) {
    gettimeofday(&start, NULL);
    std::ofstream myfile;
    myfile.open ("test.txt");
    myfile << "Writing this to a file.\n";
    myfile.flush();
    myfile.close();
    gettimeofday(&end, NULL);
    long duration = end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec;
    long durationMillis = duration / 1000;
    maxTimeMillis = std::max(maxTimeMillis, durationMillis);

    usleep(1000000);
  }

  std::cout << "num iterations: \t" << numIters << std::endl; 
  std::cout << "max time encountered to open/write/flush/close a short file: \t" << maxTimeMillis << "\t ms " << std::endl;

}
