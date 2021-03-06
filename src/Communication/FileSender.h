// Copyright (c) 2011, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
//
#ifndef FILESENDER_H
#define FILESENDER_H
#include <Common/QuickFAST_Export.h>
#include "FileSender_fwd.h"
#include <Communication/Sender.h>
namespace QuickFAST
{
  namespace Communication
  {
    /// @brief Simple implementaton of the Sender interface.  Writes the data to a file.
    class FileSender: public Sender
    {
    public:
      /// @brief construct
      /// @param recycler to take care of empty buffers
      /// @param fileName is the name of the file to be written
      /// @param binary controls end-of-line handling on Windows.  Ignored on other platforms.
      FileSender(
        BufferRecycler & recycler,
        const char * fileName,
        bool binary = false);

      virtual ~FileSender();
      // Override Sender method
      virtual void open();
      // Override Sender method
      virtual void send(LinkedBuffer * buffer);
      // Override Sender method
      virtual void close();

    private:
      std::string fileName_;
      bool binary_;
      FILE * file_;
    };
  }
}
#endif // FILESENDER_H
