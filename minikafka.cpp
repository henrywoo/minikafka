#include <iostream>
#include <fstream>
#include <unistd.h>
#include "henry.h"

#include <sys/stat.h>
#include <fcntl.h>

high_resolution_clock::time_point p[128]={}, c[128]={};
int pcount=0;
int ccount=0;

void producer(const char *filePath){
  std::fstream os(filePath, ios_base::app|ios_base::out);
  os.rdbuf()->pubsetbuf(0, 0);
  while (os.is_open()) {
    os.seekp(0, os.end);
    os << (char)(pcount);
    p[pcount]=high_resolution_clock::now();
    if (++pcount==128)
      break;
  }
}

void consumer(const char *filePath){
  int fd = open(filePath, O_RDONLY);
  off_t offset=0;
  int len=1, numRead=0;
  char* buf = (char*)malloc(len+1);
  setvbuf(stdout,0,_IONBF,0);
  while (fd>0) {
    if (lseek(fd, offset, SEEK_SET) == -1) continue;
    int numRead = 0;
    while(numRead==0)
      numRead = read(fd, buf, len);
    if(numRead==1){
      ccount++;
      c[(int)buf[0]]=high_resolution_clock::now();
      if((int)(buf[0])==127) break;
    }else{break;}
    offset += numRead;
  }
  free(buf);
}

int main(int argc, char *argv[]) {
  const char* filePath = "/tmp/deadbeef.log";
  auto f1=async(launch::async, producer, filePath);
  auto f2=async(launch::async, consumer, filePath);
  f1.get();
  f2.get();
  int sum=0;
  for(int i=0;i<128;i++){
    auto int_ns = chrono::duration_cast<chrono::nanoseconds>(c[i] - p[i]);
    cout << i << ": " << int_ns.count() << "ns" << endl;
    sum+=int_ns.count();
  }
  cout << "average delay: " << sum/128 << "ns" << endl;
  assert(pcount==ccount and pcount==128);
  return 0;
}
