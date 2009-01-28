// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#ifdef _MSC_VER
# pragma once
#endif
#ifndef FIELDGROUP_H
#define FIELDGROUP_H
#include <Messages/Field.h>
#include <Messages/FieldSet_fwd.h>
namespace QuickFAST{
  namespace Messages{
    /// @brief A field containing a subgroup of fields
    ///
    /// In the XML template file this field is described as &lt;group>
    class QuickFAST_Export FieldGroup : public Field{
      /// @brief construct given a group as the value of the field
      explicit FieldGroup(Messages::GroupCPtr group);
    public:
      static FieldCPtr create(Messages::GroupCPtr group);

      /// @brief a typical virtual destructor.
      virtual ~FieldGroup();

      // implement selected virtual methods from Field
      virtual Field::FieldType getType()const;
      virtual const Messages::GroupCPtr & toGroup() const;
    private:
      Messages::GroupCPtr group_;
    };
  }
}
#endif // FIELDINT64_H
