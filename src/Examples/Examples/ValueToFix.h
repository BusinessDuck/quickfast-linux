// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#ifdef _MSC_VER
# pragma once
#endif
#ifndef VALUETOFIX_H
#define VALUETOFIX_H
#include <Messages/ValueMessageBuilder.h>

namespace QuickFAST{
  namespace Examples{

    /// @brief A message consumer that attempts to produce a human readable version
    /// of a message that has been decoded by QuickFAST.
    class ValueToFix : public Messages::ValueMessageBuilder
    {
    public:
      /// @brief Construct given a ostream to which to write the interpreted results.
      ValueToFix(std::ostream & out, const char * recordSeparator = "\n");
      virtual ~ValueToFix();

      /// @brief set the level of log messages that we are interested in.
      /// @param level is the first level that will *NOT* be displayed.
      void setLogLevel(Common::Logger::LogLevel level);

      ////////////////////////////
      // Implement ValueMessageBuilder
      virtual const std::string & getApplicationType()const;
      virtual const std::string & getApplicationTypeNs()const;
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int64 value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uint64 value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int32 value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uint32 value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int16 value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uint16 value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int8 value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uchar value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const Decimal& value);
      virtual void addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const unsigned char * value, size_t length);
      virtual Messages::ValueMessageBuilder & startMessage(
        const std::string & applicationType,
        const std::string & applicationTypeNamespace,
        size_t size);
      virtual bool endMessage(Messages::ValueMessageBuilder & messageBuilder);
      virtual bool ignoreMessage(Messages::ValueMessageBuilder & messageBuilder);
      virtual Messages::ValueMessageBuilder & startSequence(
        Messages::FieldIdentityCPtr & identity,
        const std::string & applicationType,
        const std::string & applicationTypeNamespace,
        size_t fieldCount,
        Messages::FieldIdentityCPtr & lengthIdentity,
        size_t length);
      virtual void endSequence(
        Messages::FieldIdentityCPtr & identity,
        Messages::ValueMessageBuilder & sequenceBuilder);
      virtual Messages::ValueMessageBuilder & startSequenceEntry(
        const std::string & applicationType,
        const std::string & applicationTypeNamespace,
        size_t size) ;
      virtual void endSequenceEntry(Messages::ValueMessageBuilder & entry);
      virtual Messages::ValueMessageBuilder & startGroup(
        Messages::FieldIdentityCPtr & identity,
        const std::string & applicationType,
        const std::string & applicationTypeNamespace,
        size_t size);
      virtual void endGroup(
        Messages::FieldIdentityCPtr & identity,
        Messages::ValueMessageBuilder & groupBuilder);

      ///////////////////
      // Implement Logger
      virtual bool wantLog(unsigned short level);
      virtual bool logMessage(unsigned short level, const std::string & logMessage);
      virtual bool reportDecodingError(const std::string & errorMessage);
      virtual bool reportCommunicationError(const std::string & errorMessage);

    private:
      std::ostream & out_;
      const char * recordSeparator_;
      Common::Logger::LogLevel logLevel_;
      std::string applicationType_;
      std::string applicationTypeNamespace_;
    };
  }
}
#endif /* VALUETOFIX_H */
