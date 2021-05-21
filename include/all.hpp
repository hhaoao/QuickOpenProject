// Workaround for a boost/mingw bug.
// This must occur before the inclusion of the boost/process.hpp header.
// Taken from https://github.com/boostorg/process/issues/96
#ifndef __kernel_entry
    #define __kernel_entry
#endif

#include <boost/process.hpp>


namespace bp = boost::process;

