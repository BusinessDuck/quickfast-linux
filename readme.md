# QuickFAST / FIX Adapted for streaming protocol (linux)

![](http://t11.deviantart.net/eaC0D_paozUQ9r0ExsQxBy_AYrQ=/300x200/filters:fixed_height(100,100):origin()/pre09/8a51/th/pre/f/2013/206/1/9/simple_linux_logo_by_dablim-d5k4ghu.png) ![](https://www.ociweb.com/files/1414/3024/2447/logo-circle.png)

## Dependencies

 * [Xerces-C++ 3.1.4](http://xerces.apache.org/xerces-c/) 
 * [Boost 1.62.0](http://www.boost.org/)
 * [MPC](http://www.ociweb.com/products/mpc)

## Installation 
Tested on ubuntu 14.04 with version of the library populated in deps
#### Step 1: Prepare you environment to compilation process
Install the compilation instruments and dependencies, follow command:
```sh
$ sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev build-essential libbz2-dev libboost-all-dev libxml2 
```
Create working directory and move dependencies to created folder.
Download dependencies archives in tar.gz (follow links in Dependencies section), save sources to directory and run command for move to the destination folder.
```sh
$ mkdir ~/quickfast
$ mv xerces-c*.tar.gz boost_*.tar.gz MPC*.tar.gz quickfast*.tar.gz ~/quickfast
```
Unpack the sources
```sh
$ cd ~/quickfast
$ tar -xvzf *.tar.gz
$ rm -rf ./*.tar.gz
```
### Step 2: Building Dependencies
>Is just a quick guide, more information may be found on source sites.
>Warning! sudo may be needed for running the command below
>Do not forget replace path to library correctly

#### Compile Xerces-c
```sh
$ cd ~/quickfast/xerces-c
$ ./configure && make
```

#### Compile Boost

```sh
$ cd ~/quickfast/boost_1_62
$ ./bootstrap.sh --prefix=/usr/local/lib
$./b2 --layout=versioned
$./b2 install
```
### Step 3: Setup customizing
Edit ~/quickfast/setup.sh and set you paths to components to variables
```sh
export QUICKFAST_ROOT=`pwd`

export MPC_ROOT=~/quickfast/MPC/

export BOOST_ROOT=/usr/local/lib
export BOOST_CFG=
export BOOST_ROOT_LIB=/usr/local/lib
export BOOST_STATIC_LIB_PREFIX=
export BOOST_VERSION=boost-1_62_0
export BOOST_TEST_CHECKPOINT=
export XERCES_ROOT=~/quickfast/xerces-c
export XERCES_LIBPATH=$XERCES_ROOT/src/.libs
export XERCES_LIBNAME=libxerces-c-3.1
export XERCES_INCLUDE=$XERCES_ROOT/src

export PATH=$QUICKFAST_ROOT/bin:$MPC_ROOT:$PATH
export LD_LIBRARY_PATH=$XERCES_LIBPATH:$QUICKFAST_ROOT/lib:$BOOST_ROOT_LIB:$LD_LIBRARY_PATH
```
Apply variables to scope
```sh
$ . ./setup.sh
```

Add execute permissions to file (check path, before run the command)
```sh
$ chmod +x ~/quickfast/MPC/mwc.pl
```
Generate Makefile
```sh
./m.sh
```
Replace generated file ~/quickfast/quickfast/src/MakeFile.QuickFAST by this
```sh
#----------------------------------------------------------------------------
#       Macros
#----------------------------------------------------------------------------
CFG = Release

ifeq ($(CFG), Release)
CC            = gcc
CXX           = g++
LD            = $(CXX) $(CCFLAGS) $(CPPFLAGS)
AR            = ar
PICFLAGS      = -fPIC
CPPFLAGS      = $(PICFLAGS) $(GENFLAGS) -DUSING_PCH -D_REENTRANT -I"$(BOOST_ROOT)/include/$(BOOST_VERSION)" -I"$(BOOST_ROOT)/." -I"$(XERCES_ROOT)/src" -I"../src" -DXML_USE_PTHREADS
OBJEXT        = .o
OUTPUT_OPTION = -o "$@"
COMPILE.c     = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc    = $(CXX) $(CCFLAGS) $(CPPFLAGS) -c
LDFLAGS       = -L"." -L"/usr/local/lib" -L"$(XERCES_LIBPATH)" -L"$(BOOST_ROOT_LIB)"
CCC           = $(CXX)
MAKEFILE      = Makefile.QuickFAST
DEPENDENCIES  = .depend.$(MAKEFILE)
LTARGETDIR    = ../lib/
CAT           = cat
MV            = mv -f
RM            = rm -rf
CP            = cp -p
NUL           = /dev/null
MKDIR         = mkdir -p
TESTDIRSTART  = test -d
TESTDIREND    = ||
TOUCH         = touch
EXEEXT        = 
LIBPREFIX     = lib
LIBSUFFIX     = 
GENFLAGS      = -O -O3
LDLIBS        = -l"xerces-c" -l"$(BOOST_STATIC_LIB_PREFIX)boost_thread$(BOOST_CFG)" -l"$(BOOST_STATIC_LIB_PREFIX)boost_system$(BOOST_CFG)" -l"$(BOOST_STATIC_LIB_PREFIX)boost_filesystem$(BOOST_CFG)" -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread
OBJS          = Common/QuickFASTPch$(OBJEXT) Application/DecoderConnection$(OBJEXT) Application/DNDecoderConnectionImpl$(OBJEXT) Application/CommandArgParser$(OBJEXT) Codecs/SegmentBody$(OBJEXT) Codecs/MulticastDecoder$(OBJEXT) Codecs/PresenceMap$(OBJEXT) Codecs/DictionaryIndexer$(OBJEXT) Codecs/FieldOpDefault$(OBJEXT) Codecs/DataSourceBuffer$(OBJEXT) Codecs/FieldInstructionByteVector$(OBJEXT) Codecs/BasePacketAssembler$(OBJEXT) Codecs/FastEncodedHeaderAnalyzer$(OBJEXT) Codecs/FieldInstructionGroup$(OBJEXT) Codecs/StreamingAssembler$(OBJEXT) Codecs/Decoder$(OBJEXT) Codecs/FieldOpTail$(OBJEXT) Codecs/SingleMessageConsumer$(OBJEXT) Codecs/GenericMessageBuilder$(OBJEXT) Codecs/FieldInstructionUtf8$(OBJEXT) Codecs/DataSourceStream$(OBJEXT) Codecs/Context$(OBJEXT) Codecs/DataSourceBufferedStream$(OBJEXT) Codecs/PacketSequencingAssembler$(OBJEXT) Codecs/MessagePerPacketAssembler$(OBJEXT) Codecs/Encoder$(OBJEXT) Codecs/FieldInstruction$(OBJEXT) Codecs/FieldInstructionSequence$(OBJEXT) Codecs/FieldInstructionBlob$(OBJEXT) Codecs/FieldInstructionAscii$(OBJEXT) Codecs/Template$(OBJEXT) Codecs/FieldOpConstant$(OBJEXT) Codecs/FieldOpIncrement$(OBJEXT) Codecs/FixedSizeHeaderAnalyzer$(OBJEXT) Codecs/DataSource$(OBJEXT) Codecs/FieldInstructionDecimal$(OBJEXT) Codecs/FieldOpCopy$(OBJEXT) Codecs/DataSourceString$(OBJEXT) Codecs/FieldInstructionTemplateRef$(OBJEXT) Codecs/FieldOpDelta$(OBJEXT) Codecs/SchemaElement$(OBJEXT) Codecs/TemplateRegistry$(OBJEXT) Codecs/XMLTemplateParser$(OBJEXT) Codecs/FieldOp$(OBJEXT) Common/dllmain$(OBJEXT) Common/Decimal$(OBJEXT) Common/BitMap$(OBJEXT) Common/WorkingBuffer$(OBJEXT) Common/Profiler$(OBJEXT) Common/Types$(OBJEXT) Communication/AsynchSender$(OBJEXT) Communication/AsioService$(OBJEXT) Communication/FileSender$(OBJEXT) Communication/MulticastReceiverHandle$(OBJEXT) Communication/PCapReader$(OBJEXT) Communication/AsynchFileSender$(OBJEXT) Messages/MessageAccessor$(OBJEXT) Messages/FieldDecimal$(OBJEXT) Messages/FieldUInt32$(OBJEXT) Messages/FieldGroup$(OBJEXT) Messages/FieldUtf8$(OBJEXT) Messages/FieldUInt64$(OBJEXT) Messages/FieldUInt16$(OBJEXT) Messages/FieldInt32$(OBJEXT) Messages/FieldIdentity$(OBJEXT) Messages/FieldAscii$(OBJEXT) Messages/MessageFormatter$(OBJEXT) Messages/FieldSequence$(OBJEXT) Messages/FieldInt16$(OBJEXT) Messages/FieldSet$(OBJEXT) Messages/Message$(OBJEXT) Messages/FieldByteVector$(OBJEXT) Messages/FieldUInt8$(OBJEXT) Messages/FieldString$(OBJEXT) Messages/MessageBuilder$(OBJEXT) Messages/Field$(OBJEXT) Messages/FieldInt64$(OBJEXT) Messages/FieldInt8$(OBJEXT)
AREXT         = .a
LIB           = $(LTARGETDIR)$(LIBPREFIX)QuickFAST$(LIBSUFFIX)$(AREXT)
SOEXT         = .so
SHTARGETDIR   = ../lib/
SHLIB         = $(SHTARGETDIR)$(LIBPREFIX)QuickFAST$(LIBSUFFIX)$(SOEXT)
SHFLAGS       = -shared
SRC           = Common/QuickFASTPch.cpp Application/DecoderConnection.cpp Application/DNDecoderConnectionImpl.cpp Application/CommandArgParser.cpp Codecs/SegmentBody.cpp Codecs/MulticastDecoder.cpp Codecs/PresenceMap.cpp Codecs/DictionaryIndexer.cpp Codecs/FieldOpDefault.cpp Codecs/DataSourceBuffer.cpp Codecs/FieldInstructionByteVector.cpp Codecs/BasePacketAssembler.cpp Codecs/FastEncodedHeaderAnalyzer.cpp Codecs/FieldInstructionGroup.cpp Codecs/StreamingAssembler.cpp Codecs/Decoder.cpp Codecs/FieldOpTail.cpp Codecs/SingleMessageConsumer.cpp Codecs/GenericMessageBuilder.cpp Codecs/FieldInstructionUtf8.cpp Codecs/DataSourceStream.cpp Codecs/Context.cpp Codecs/DataSourceBufferedStream.cpp Codecs/PacketSequencingAssembler.cpp Codecs/MessagePerPacketAssembler.cpp Codecs/Encoder.cpp Codecs/FieldInstruction.cpp Codecs/FieldInstructionSequence.cpp Codecs/FieldInstructionBlob.cpp Codecs/FieldInstructionAscii.cpp Codecs/Template.cpp Codecs/FieldOpConstant.cpp Codecs/FieldOpIncrement.cpp Codecs/FixedSizeHeaderAnalyzer.cpp Codecs/DataSource.cpp Codecs/FieldInstructionDecimal.cpp Codecs/FieldOpCopy.cpp Codecs/DataSourceString.cpp Codecs/FieldInstructionTemplateRef.cpp Codecs/FieldOpDelta.cpp Codecs/SchemaElement.cpp Codecs/TemplateRegistry.cpp Codecs/XMLTemplateParser.cpp Codecs/FieldOp.cpp Common/dllmain.cpp Common/Decimal.cpp Common/BitMap.cpp Common/WorkingBuffer.cpp Common/Profiler.cpp Common/Types.cpp Communication/AsynchSender.cpp Communication/AsioService.cpp Communication/FileSender.cpp Communication/MulticastReceiverHandle.cpp Communication/PCapReader.cpp Communication/AsynchFileSender.cpp Messages/MessageAccessor.cpp Messages/FieldDecimal.cpp Messages/FieldUInt32.cpp Messages/FieldGroup.cpp Messages/FieldUtf8.cpp Messages/FieldUInt64.cpp Messages/FieldUInt16.cpp Messages/FieldInt32.cpp Messages/FieldIdentity.cpp Messages/FieldAscii.cpp Messages/MessageFormatter.cpp Messages/FieldSequence.cpp Messages/FieldInt16.cpp Messages/FieldSet.cpp Messages/Message.cpp Messages/FieldByteVector.cpp Messages/FieldUInt8.cpp Messages/FieldString.cpp Messages/MessageBuilder.cpp Messages/Field.cpp Messages/FieldInt64.cpp Messages/FieldInt8.cpp
LINK.cc       = $(LD) $(LDFLAGS)
DYNAMICFLAGS  = -DQUICKFAST_BUILD_DLL
EXPORTFLAGS   = $(DYNAMICFLAGS)
DEPLIBS       = $(foreach lib, "xerces-c" "$(BOOST_STATIC_LIB_PREFIX)boost_thread$(BOOST_CFG)" "$(BOOST_STATIC_LIB_PREFIX)boost_system$(BOOST_CFG)" $(BOOST_STATIC_LIB_PREFIX)boost_filesystem$(BOOST_CFG), $(foreach libpath, . /usr/local/lib $(XERCES_ROOT)/lib, $(wildcard $(libpath)/lib$(lib).a)))
endif
ifeq ($(CFG), Debug)
CC            = gcc
CXX           = g++
LD            = $(CXX) $(CCFLAGS) $(CPPFLAGS)
AR            = ar
PICFLAGS      = -fPIC
CPPFLAGS      = $(PICFLAGS) $(GENFLAGS) -DUSING_PCH -D_REENTRANT -I"$(BOOST_ROOT)/include/$(BOOST_VERSION)" -I"$(BOOST_ROOT)/." -I"$(XERCES_ROOT)/src" -I"../src" -DXML_USE_PTHREADS
OBJEXT        = .o
OUTPUT_OPTION = -o "$@"
COMPILE.c     = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc    = $(CXX) $(CCFLAGS) $(CPPFLAGS) -c
LDFLAGS       = -L"." -L"/usr/local/lib" -L"$(XERCES_ROOT)/lib"
CCC           = $(CXX)
MAKEFILE      = Makefile.QuickFAST
DEPENDENCIES  = .depend.$(MAKEFILE)
LTARGETDIR    = ../lib/
CAT           = cat
MV            = mv -f
RM            = rm -rf
CP            = cp -p
NUL           = /dev/null
MKDIR         = mkdir -p
TESTDIRSTART  = test -d
TESTDIREND    = ||
TOUCH         = touch
EXEEXT        = 
LIBPREFIX     = lib
LIBSUFFIX     = d
GENFLAGS      = -g
LDLIBS        = -l"xerces-c" -l"$(BOOST_STATIC_LIB_PREFIX)boost_thread$(BOOST_CFG)" -l"$(BOOST_STATIC_LIB_PREFIX)boost_system$(BOOST_CFG)" -l"$(BOOST_STATIC_LIB_PREFIX)boost_filesystem$(BOOST_CFG)" -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread
OBJS          = Common/QuickFASTPch$(OBJEXT) Application/DecoderConnection$(OBJEXT) Application/DNDecoderConnectionImpl$(OBJEXT) Application/CommandArgParser$(OBJEXT) Codecs/SegmentBody$(OBJEXT) Codecs/MulticastDecoder$(OBJEXT) Codecs/PresenceMap$(OBJEXT) Codecs/DictionaryIndexer$(OBJEXT) Codecs/FieldOpDefault$(OBJEXT) Codecs/DataSourceBuffer$(OBJEXT) Codecs/FieldInstructionByteVector$(OBJEXT) Codecs/BasePacketAssembler$(OBJEXT) Codecs/FastEncodedHeaderAnalyzer$(OBJEXT) Codecs/FieldInstructionGroup$(OBJEXT) Codecs/StreamingAssembler$(OBJEXT) Codecs/Decoder$(OBJEXT) Codecs/FieldOpTail$(OBJEXT) Codecs/SingleMessageConsumer$(OBJEXT) Codecs/GenericMessageBuilder$(OBJEXT) Codecs/FieldInstructionUtf8$(OBJEXT) Codecs/DataSourceStream$(OBJEXT) Codecs/Context$(OBJEXT) Codecs/DataSourceBufferedStream$(OBJEXT) Codecs/PacketSequencingAssembler$(OBJEXT) Codecs/MessagePerPacketAssembler$(OBJEXT) Codecs/Encoder$(OBJEXT) Codecs/FieldInstruction$(OBJEXT) Codecs/FieldInstructionSequence$(OBJEXT) Codecs/FieldInstructionBlob$(OBJEXT) Codecs/FieldInstructionAscii$(OBJEXT) Codecs/Template$(OBJEXT) Codecs/FieldOpConstant$(OBJEXT) Codecs/FieldOpIncrement$(OBJEXT) Codecs/FixedSizeHeaderAnalyzer$(OBJEXT) Codecs/DataSource$(OBJEXT) Codecs/FieldInstructionDecimal$(OBJEXT) Codecs/FieldOpCopy$(OBJEXT) Codecs/DataSourceString$(OBJEXT) Codecs/FieldInstructionTemplateRef$(OBJEXT) Codecs/FieldOpDelta$(OBJEXT) Codecs/SchemaElement$(OBJEXT) Codecs/TemplateRegistry$(OBJEXT) Codecs/XMLTemplateParser$(OBJEXT) Codecs/FieldOp$(OBJEXT) Common/dllmain$(OBJEXT) Common/Decimal$(OBJEXT) Common/BitMap$(OBJEXT) Common/WorkingBuffer$(OBJEXT) Common/Profiler$(OBJEXT) Common/Types$(OBJEXT) Communication/AsynchSender$(OBJEXT) Communication/AsioService$(OBJEXT) Communication/FileSender$(OBJEXT) Communication/MulticastReceiverHandle$(OBJEXT) Communication/PCapReader$(OBJEXT) Communication/AsynchFileSender$(OBJEXT) Messages/MessageAccessor$(OBJEXT) Messages/FieldDecimal$(OBJEXT) Messages/FieldUInt32$(OBJEXT) Messages/FieldGroup$(OBJEXT) Messages/FieldUtf8$(OBJEXT) Messages/FieldUInt64$(OBJEXT) Messages/FieldUInt16$(OBJEXT) Messages/FieldInt32$(OBJEXT) Messages/FieldIdentity$(OBJEXT) Messages/FieldAscii$(OBJEXT) Messages/MessageFormatter$(OBJEXT) Messages/FieldSequence$(OBJEXT) Messages/FieldInt16$(OBJEXT) Messages/FieldSet$(OBJEXT) Messages/Message$(OBJEXT) Messages/FieldByteVector$(OBJEXT) Messages/FieldUInt8$(OBJEXT) Messages/FieldString$(OBJEXT) Messages/MessageBuilder$(OBJEXT) Messages/Field$(OBJEXT) Messages/FieldInt64$(OBJEXT) Messages/FieldInt8$(OBJEXT)
AREXT         = .a
LIB           = $(LTARGETDIR)$(LIBPREFIX)QuickFAST$(LIBSUFFIX)$(AREXT)
SOEXT         = .so
SHTARGETDIR   = ../lib/
SHLIB         = $(SHTARGETDIR)$(LIBPREFIX)QuickFAST$(LIBSUFFIX)$(SOEXT)
SHFLAGS       = -shared
SRC           = Common/QuickFASTPch.cpp Application/DecoderConnection.cpp Application/DNDecoderConnectionImpl.cpp Application/CommandArgParser.cpp Codecs/SegmentBody.cpp Codecs/MulticastDecoder.cpp Codecs/PresenceMap.cpp Codecs/DictionaryIndexer.cpp Codecs/FieldOpDefault.cpp Codecs/DataSourceBuffer.cpp Codecs/FieldInstructionByteVector.cpp Codecs/BasePacketAssembler.cpp Codecs/FastEncodedHeaderAnalyzer.cpp Codecs/FieldInstructionGroup.cpp Codecs/StreamingAssembler.cpp Codecs/Decoder.cpp Codecs/FieldOpTail.cpp Codecs/SingleMessageConsumer.cpp Codecs/GenericMessageBuilder.cpp Codecs/FieldInstructionUtf8.cpp Codecs/DataSourceStream.cpp Codecs/Context.cpp Codecs/DataSourceBufferedStream.cpp Codecs/PacketSequencingAssembler.cpp Codecs/MessagePerPacketAssembler.cpp Codecs/Encoder.cpp Codecs/FieldInstruction.cpp Codecs/FieldInstructionSequence.cpp Codecs/FieldInstructionBlob.cpp Codecs/FieldInstructionAscii.cpp Codecs/Template.cpp Codecs/FieldOpConstant.cpp Codecs/FieldOpIncrement.cpp Codecs/FixedSizeHeaderAnalyzer.cpp Codecs/DataSource.cpp Codecs/FieldInstructionDecimal.cpp Codecs/FieldOpCopy.cpp Codecs/DataSourceString.cpp Codecs/FieldInstructionTemplateRef.cpp Codecs/FieldOpDelta.cpp Codecs/SchemaElement.cpp Codecs/TemplateRegistry.cpp Codecs/XMLTemplateParser.cpp Codecs/FieldOp.cpp Common/dllmain.cpp Common/Decimal.cpp Common/BitMap.cpp Common/WorkingBuffer.cpp Common/Profiler.cpp Common/Types.cpp Communication/AsynchSender.cpp Communication/AsioService.cpp Communication/FileSender.cpp Communication/MulticastReceiverHandle.cpp Communication/PCapReader.cpp Communication/AsynchFileSender.cpp Messages/MessageAccessor.cpp Messages/FieldDecimal.cpp Messages/FieldUInt32.cpp Messages/FieldGroup.cpp Messages/FieldUtf8.cpp Messages/FieldUInt64.cpp Messages/FieldUInt16.cpp Messages/FieldInt32.cpp Messages/FieldIdentity.cpp Messages/FieldAscii.cpp Messages/MessageFormatter.cpp Messages/FieldSequence.cpp Messages/FieldInt16.cpp Messages/FieldSet.cpp Messages/Message.cpp Messages/FieldByteVector.cpp Messages/FieldUInt8.cpp Messages/FieldString.cpp Messages/MessageBuilder.cpp Messages/Field.cpp Messages/FieldInt64.cpp Messages/FieldInt8.cpp
LINK.cc       = $(LD) $(LDFLAGS)
DYNAMICFLAGS  = -DQUICKFAST_BUILD_DLL
EXPORTFLAGS   = $(DYNAMICFLAGS)
DEPLIBS       = $(foreach lib, "xerces-c" "$(BOOST_STATIC_LIB_PREFIX)boost_thread$(BOOST_CFG)" "$(BOOST_STATIC_LIB_PREFIX)boost_system$(BOOST_CFG)" $(BOOST_STATIC_LIB_PREFIX)boost_filesystem$(BOOST_CFG), $(foreach libpath, . /usr/local/lib $(XERCES_ROOT)/lib, $(wildcard $(libpath)/lib$(lib).a)))
endif

#----------------------------------------------------------------------------
#       Local targets
#----------------------------------------------------------------------------

all: $(SHLIB)

$(SHLIB): $(OBJS) $(DEPLIBS)
	@$(TESTDIRSTART) "$(SHTARGETDIR)" $(TESTDIREND) $(MKDIR) "$(SHTARGETDIR)"
	$(LINK.cc) $(SHFLAGS) $(OBJS) $(LDLIBS) $(OUTPUT_OPTION)

$(LIB): $(OBJS)
	@$(TESTDIRSTART) "$(LTARGETDIR)" $(TESTDIREND) $(MKDIR) "$(LTARGETDIR)"
	$(AR) $(ARFLAGS) $(LIB) $(OBJS)

generated: $(GENERATED_DIRTY)
	@-:

Common/QuickFASTPch$(OBJEXT): Common/QuickFASTPch.cpp
	$(COMPILE.cc) -o Common/QuickFASTPch.h.gch $(EXPORTFLAGS) Common/QuickFASTPch.cpp
	@$(CP) Common/QuickFASTPch.h.gch Common/QuickFASTPch$(OBJEXT)

Application/DecoderConnection$(OBJEXT): Application/DecoderConnection.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Application/DecoderConnection.cpp

Application/DNDecoderConnectionImpl$(OBJEXT): Application/DNDecoderConnectionImpl.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Application/DNDecoderConnectionImpl.cpp

Application/CommandArgParser$(OBJEXT): Application/CommandArgParser.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Application/CommandArgParser.cpp

Codecs/SegmentBody$(OBJEXT): Codecs/SegmentBody.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/SegmentBody.cpp

Codecs/MulticastDecoder$(OBJEXT): Codecs/MulticastDecoder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/MulticastDecoder.cpp

Codecs/PresenceMap$(OBJEXT): Codecs/PresenceMap.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/PresenceMap.cpp

Codecs/DictionaryIndexer$(OBJEXT): Codecs/DictionaryIndexer.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/DictionaryIndexer.cpp

Codecs/FieldOpDefault$(OBJEXT): Codecs/FieldOpDefault.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldOpDefault.cpp

Codecs/DataSourceBuffer$(OBJEXT): Codecs/DataSourceBuffer.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/DataSourceBuffer.cpp

Codecs/FieldInstructionByteVector$(OBJEXT): Codecs/FieldInstructionByteVector.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionByteVector.cpp

Codecs/BasePacketAssembler$(OBJEXT): Codecs/BasePacketAssembler.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/BasePacketAssembler.cpp

Codecs/FastEncodedHeaderAnalyzer$(OBJEXT): Codecs/FastEncodedHeaderAnalyzer.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FastEncodedHeaderAnalyzer.cpp

Codecs/FieldInstructionGroup$(OBJEXT): Codecs/FieldInstructionGroup.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionGroup.cpp

Codecs/StreamingAssembler$(OBJEXT): Codecs/StreamingAssembler.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/StreamingAssembler.cpp

Codecs/Decoder$(OBJEXT): Codecs/Decoder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/Decoder.cpp

Codecs/FieldOpTail$(OBJEXT): Codecs/FieldOpTail.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldOpTail.cpp

Codecs/SingleMessageConsumer$(OBJEXT): Codecs/SingleMessageConsumer.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/SingleMessageConsumer.cpp

Codecs/GenericMessageBuilder$(OBJEXT): Codecs/GenericMessageBuilder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/GenericMessageBuilder.cpp

Codecs/FieldInstructionUtf8$(OBJEXT): Codecs/FieldInstructionUtf8.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionUtf8.cpp

Codecs/DataSourceStream$(OBJEXT): Codecs/DataSourceStream.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/DataSourceStream.cpp

Codecs/Context$(OBJEXT): Codecs/Context.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/Context.cpp

Codecs/DataSourceBufferedStream$(OBJEXT): Codecs/DataSourceBufferedStream.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/DataSourceBufferedStream.cpp

Codecs/PacketSequencingAssembler$(OBJEXT): Codecs/PacketSequencingAssembler.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/PacketSequencingAssembler.cpp

Codecs/MessagePerPacketAssembler$(OBJEXT): Codecs/MessagePerPacketAssembler.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/MessagePerPacketAssembler.cpp

Codecs/Encoder$(OBJEXT): Codecs/Encoder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/Encoder.cpp

Codecs/FieldInstruction$(OBJEXT): Codecs/FieldInstruction.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstruction.cpp

Codecs/FieldInstructionSequence$(OBJEXT): Codecs/FieldInstructionSequence.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionSequence.cpp

Codecs/FieldInstructionBlob$(OBJEXT): Codecs/FieldInstructionBlob.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionBlob.cpp

Codecs/FieldInstructionAscii$(OBJEXT): Codecs/FieldInstructionAscii.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionAscii.cpp

Codecs/Template$(OBJEXT): Codecs/Template.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/Template.cpp

Codecs/FieldOpConstant$(OBJEXT): Codecs/FieldOpConstant.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldOpConstant.cpp

Codecs/FieldOpIncrement$(OBJEXT): Codecs/FieldOpIncrement.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldOpIncrement.cpp

Codecs/FixedSizeHeaderAnalyzer$(OBJEXT): Codecs/FixedSizeHeaderAnalyzer.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FixedSizeHeaderAnalyzer.cpp

Codecs/DataSource$(OBJEXT): Codecs/DataSource.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/DataSource.cpp

Codecs/FieldInstructionDecimal$(OBJEXT): Codecs/FieldInstructionDecimal.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionDecimal.cpp

Codecs/FieldOpCopy$(OBJEXT): Codecs/FieldOpCopy.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldOpCopy.cpp

Codecs/DataSourceString$(OBJEXT): Codecs/DataSourceString.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/DataSourceString.cpp

Codecs/FieldInstructionTemplateRef$(OBJEXT): Codecs/FieldInstructionTemplateRef.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldInstructionTemplateRef.cpp

Codecs/FieldOpDelta$(OBJEXT): Codecs/FieldOpDelta.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldOpDelta.cpp

Codecs/SchemaElement$(OBJEXT): Codecs/SchemaElement.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/SchemaElement.cpp

Codecs/TemplateRegistry$(OBJEXT): Codecs/TemplateRegistry.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/TemplateRegistry.cpp

Codecs/XMLTemplateParser$(OBJEXT): Codecs/XMLTemplateParser.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/XMLTemplateParser.cpp

Codecs/FieldOp$(OBJEXT): Codecs/FieldOp.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Codecs/FieldOp.cpp

Common/dllmain$(OBJEXT): Common/dllmain.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Common/dllmain.cpp

Common/Decimal$(OBJEXT): Common/Decimal.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Common/Decimal.cpp

Common/BitMap$(OBJEXT): Common/BitMap.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Common/BitMap.cpp

Common/WorkingBuffer$(OBJEXT): Common/WorkingBuffer.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Common/WorkingBuffer.cpp

Common/Profiler$(OBJEXT): Common/Profiler.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Common/Profiler.cpp

Common/Types$(OBJEXT): Common/Types.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Common/Types.cpp

Communication/AsynchSender$(OBJEXT): Communication/AsynchSender.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Communication/AsynchSender.cpp

Communication/AsioService$(OBJEXT): Communication/AsioService.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Communication/AsioService.cpp

Communication/FileSender$(OBJEXT): Communication/FileSender.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Communication/FileSender.cpp

Communication/MulticastReceiverHandle$(OBJEXT): Communication/MulticastReceiverHandle.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Communication/MulticastReceiverHandle.cpp

Communication/PCapReader$(OBJEXT): Communication/PCapReader.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Communication/PCapReader.cpp

Communication/AsynchFileSender$(OBJEXT): Communication/AsynchFileSender.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Communication/AsynchFileSender.cpp

Messages/MessageAccessor$(OBJEXT): Messages/MessageAccessor.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/MessageAccessor.cpp

Messages/FieldDecimal$(OBJEXT): Messages/FieldDecimal.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldDecimal.cpp

Messages/FieldUInt32$(OBJEXT): Messages/FieldUInt32.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldUInt32.cpp

Messages/FieldGroup$(OBJEXT): Messages/FieldGroup.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldGroup.cpp

Messages/FieldUtf8$(OBJEXT): Messages/FieldUtf8.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldUtf8.cpp

Messages/FieldUInt64$(OBJEXT): Messages/FieldUInt64.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldUInt64.cpp

Messages/FieldUInt16$(OBJEXT): Messages/FieldUInt16.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldUInt16.cpp

Messages/FieldInt32$(OBJEXT): Messages/FieldInt32.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldInt32.cpp

Messages/FieldIdentity$(OBJEXT): Messages/FieldIdentity.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldIdentity.cpp

Messages/FieldAscii$(OBJEXT): Messages/FieldAscii.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldAscii.cpp

Messages/MessageFormatter$(OBJEXT): Messages/MessageFormatter.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/MessageFormatter.cpp

Messages/FieldSequence$(OBJEXT): Messages/FieldSequence.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldSequence.cpp

Messages/FieldInt16$(OBJEXT): Messages/FieldInt16.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldInt16.cpp

Messages/FieldSet$(OBJEXT): Messages/FieldSet.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldSet.cpp

Messages/Message$(OBJEXT): Messages/Message.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/Message.cpp

Messages/FieldByteVector$(OBJEXT): Messages/FieldByteVector.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldByteVector.cpp

Messages/FieldUInt8$(OBJEXT): Messages/FieldUInt8.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldUInt8.cpp

Messages/FieldString$(OBJEXT): Messages/FieldString.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldString.cpp

Messages/MessageBuilder$(OBJEXT): Messages/MessageBuilder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/MessageBuilder.cpp

Messages/Field$(OBJEXT): Messages/Field.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/Field.cpp

Messages/FieldInt64$(OBJEXT): Messages/FieldInt64.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldInt64.cpp

Messages/FieldInt8$(OBJEXT): Messages/FieldInt8.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Messages/FieldInt8.cpp

clean:
	-$(RM) $(OBJS)
	-$(RM) Common/QuickFASTPch.h.gch

realclean: clean
	-$(RM) $(SHLIB) $(LIB)

check-syntax:
	$(COMPILE.cc) $(EXPORTFLAGS) -Wall -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

#----------------------------------------------------------------------------
#       Dependencies
#----------------------------------------------------------------------------


depend:
	-$(MPC_ROOT)/depgen.pl  $(CFLAGS) $(CCFLAGS) $(CPPFLAGS) -f $(DEPENDENCIES) $(SRC) 2> $(NUL)

-include $(DEPENDENCIES)
```

Run the make in ~/quickfast/quickfast/
```sh
$ ./make
```

check the lib.so file in ~/quickfast/quickfast/libs





