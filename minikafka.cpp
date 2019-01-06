#include <iostream>
#include <fstream>
#include <unistd.h>
#include "henry.h"

#include <sys/stat.h>
#include <fcntl.h>

void producer(const char *filePath){
  std::fstream os(filePath, ios_base::app|ios_base::out);
  int count=0;
  os.rdbuf()->pubsetbuf(0, 0);
  while (os.is_open()) {
    os.seekp(0, os.end);
    os << char('a'+count++);
    count%=26;
    sleep(1);
  }
}

void consumer(const char *filePath){
  int fd = open(filePath, O_RDONLY);
  off_t offset=0;
  int len=64;
  char* buf = (char*)malloc(len+1);
  setvbuf(stdout,0,_IONBF,0);
  while (fd>0) {
    if (lseek(fd, offset, SEEK_SET) == -1)
      break;
    int numRead = read(fd, buf, len);
    if(numRead>0){
      buf[numRead]=0;
      printf("%s",buf);
    }
    memset((void*)buf,0,len+1);
    offset += numRead;
    sleep(1);
  }
  free(buf);
}

int main(int argc, char *argv[]) {
  const char* filePath = "/tmp/deadbeef.log";
  auto f1=async(launch::async, producer, filePath);
  auto f2=async(launch::async, consumer, filePath);
  f2.get();
  return 0;
}
