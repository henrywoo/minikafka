#pragma once

// Stream
#include <fstream>
#include <iostream>
#include <sstream> // stringstream, i/ostringstream

// STL
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Memory Management
#include <memory>

// Time
#include <chrono>

// Assert
#include <cassert>
#include <cmath>

// Exception
#include <exception>

// Multithread
#include <condition_variable>
#include <future>
#include <mutex>
#include <thread>
#include <shared_mutex>

// Numerics
#include <climits>
#include <cmath>
#include <cstring> // strlen

#include <numeric> // accumulate, iota
#include <iterator>                //ostream_iterator

using namespace std;
using namespace std::chrono;


////#include <experimental/filesystem> // C++-standard header file name, C++17
////#ifdef _WIN32
////#include <filesystem> // Microsoft-specific implementation header file name
////namespace fs=std::experimental::filesystem::v1;
////#else
////namespace fs = experimental::filesystem;
////#endif


// Boost
//#define BOOST_ALL_DYN_LINK
//#define BOOST_FILESYSTEM_DYN_LINK
//#include <boost/filesystem.hpp>
//using namespace boost::filesystem;
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/composite_key.hpp>

using VB = vector<bool>;
using VVB = vector<VB>;
using VS = vector<string>;
using VC = vector<char>;
using VVS = vector<VS>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int,int>;
using VVS = vector<vector<string>>;
using USS = unordered_set<string>;
using iMatrix=VVI;
#define REP(i,begin,end) for(int i=begin;i<end;i++)

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};



