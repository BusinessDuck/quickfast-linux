// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#ifdef _MSC_VER
# pragma once
#endif
#ifndef GROUP_H
#define GROUP_H
#include "Group_fwd.h"
#include <Common/QuickFAST_Export.h>
#include <Messages/FieldSet.h>
namespace QuickFAST{
  namespace Messages{
    /// @todo: consider typedef FieldSet Group
#if 0
    class Group : public FieldSet
    {
    public:
      Group()
      {
      }

      /// @brief a typical virtual destructor.
      virtual ~Group()
      {
      }
    };
#endif
  }
}

#endif // GROUP_H
