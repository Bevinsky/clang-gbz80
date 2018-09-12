//===--- Z80.cpp - Implement Z80 target feature support -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements Z80 TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "GBZ80.h"
#include "llvm/ADT/StringSwitch.h"

using namespace clang;
using namespace clang::targets;

bool GBZ80TargetInfo::setCPU(const std::string &Name) {
    // TODO: verify something here
    return true;
}

ArrayRef<const char *> GBZ80TargetInfo::getGCCRegNames() const {
    static const char * const GCCRegNames[] = {
      "A", "B", "C", "D", "E", "H", "L", "SP"
    };
    return llvm::makeArrayRef(GCCRegNames);
}

void GBZ80TargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
}

const char * clang::targets::GBZ80TargetInfo::getClobbers() const
{
  return "";
}

bool clang::targets::GBZ80TargetInfo::validateAsmConstraint(const char *&Name, TargetInfo::ConstraintInfo &Info) const
{
  return false;
}

clang::TargetInfo::IntType clang::targets::GBZ80TargetInfo::getIntTypeByWidth(unsigned BitWidth, bool IsSigned) const
{
  // AVR prefers int for 16-bit integers.
  return BitWidth == 16 ? (IsSigned ? SignedInt : UnsignedInt)
    : TargetInfo::getIntTypeByWidth(BitWidth, IsSigned);
}

clang::TargetInfo::IntType clang::targets::GBZ80TargetInfo::getLeastIntTypeByWidth(unsigned BitWidth, bool IsSigned) const
{
  // AVR uses int for int_least16_t and int_fast16_t.
  return BitWidth == 16
    ? (IsSigned ? SignedInt : UnsignedInt)
    : TargetInfo::getLeastIntTypeByWidth(BitWidth, IsSigned);
}
