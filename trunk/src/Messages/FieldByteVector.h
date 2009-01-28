// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#ifdef _MSC_VER
# pragma once
#endif
#ifndef FIELDBYTEVECTOR_H
#define FIELDBYTEVECTOR_H
#include "Field.h"
namespace QuickFAST{
  namespace Messages{
    /// @brief A field containing arbitrary binary data
    ///
    /// In the XML template file this field is described as &lt;byteVector>
    class QuickFAST_Export FieldByteVector : public Field{
      /// @brief Construct the field from a value in a std::string
      /// @param value the value to be stored in the field
      explicit FieldByteVector(const std::string & value);

      /// @brief Construct the field from a value in a std::string
      /// @param buffer the start of the value to be stored in the field
      /// @param length how many bytes are in the value
      FieldByteVector(const uchar * buffer, size_t length);
      /// @brief Construct a NULL field (not an empty field)
      FieldByteVector();

    public:
      /// @brief Construct the field from a value in a std::string
      /// @param file is set to point to the created field
      /// @param value the value to be stored in the field
      static FieldCPtr create(const std::string & value);
      /// @brief Construct the field from a value in byte buffer
      /// @param file is set to point to the created field
      /// @param buffer the start of the value to be stored in the field
      /// @param length how many bytes (not characters) are in the value
      static FieldCPtr create(const uchar * buffer, size_t length);
      /// @brief Construct a NULL field (not an empty string)
      /// @param file is set to point to the created field
      static FieldCPtr createNull();

      /// @brief a typical virtual destructor.
      virtual ~FieldByteVector();

      /// @brief Assign a value to the field
      /// @param value the value to be stored in the field
      void setValue(const std::string & value);

      /// @brief Assign a value to the field
      /// @param buffer the start of the value to be stored in the field
      /// @param length how many characters are in the value
      void setValue(const uchar * buffer, size_t length);

      // implement selected virtual methods from Field
      virtual Field::FieldType getType()const;
      virtual const std::string & toByteVector() const;
      virtual bool isString() const;
      virtual const std::string & toString() const;
    private:
      std::string value_;
    };
  }
}
#endif // FIELDBYTEVECTOR_H
