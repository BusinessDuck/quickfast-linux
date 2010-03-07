// Copyright (c) 2009, 2010 Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#pragma once

#include "DNMessageDeliverer.h"
#include <DotNet/ImplBuilderBase.h>

#pragma unmanaged
#include <Messages/ValueMessageBuilder.h>
#include <Messages/FieldIdentity_fwd.h>
#pragma managed

namespace QuickFAST
{
  namespace DotNet
  {
    class ImplSequence;
    class ImplFieldSetBuilder;

    class ImplSequenceBuilder : public ImplBuilderBase
    {
    public:
      ImplSequenceBuilder(DNMessageDeliverer ^ deliverer);
      ~ImplSequenceBuilder();
      void initialize(
        Messages::FieldIdentityCPtr & lengthIdentity,
        size_t length
        );

      ImplSequence * endSequence();

      //////////////////////////
      // Implement ValueMessageBuilder
      virtual Messages::ValueMessageBuilder & startSequenceEntry(
        const std::string & applicationType,
        const std::string & applicationTypeNamespace,
        size_t size) ;
      virtual void endSequenceEntry(Messages::ValueMessageBuilder & entry);

    private:
      ImplSequence * sequence_;
      boost::scoped_ptr<ImplFieldSetBuilder> sequenceEntryBuilder_;
    };

  }
}
