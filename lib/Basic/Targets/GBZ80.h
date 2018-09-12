//===--- Z80.h - Declare Z80 target feature support -------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares Z80 TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_GBZ80_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_GBZ80_H

#include "Targets.h"
#include "clang/Basic/TargetInfo.h"
#include "llvm/Support/Compiler.h"

namespace clang {
namespace targets {

// GBZ80 Target
class LLVM_LIBRARY_VISIBILITY GBZ80TargetInfo : public TargetInfo {
public:
  explicit GBZ80TargetInfo(const llvm::Triple &Triple, const TargetOptions &)
    : TargetInfo(Triple) {
    TLSSupported = false;
    PointerWidth = 16;
    PointerAlign = 8;
    IntWidth = 8; // 16?
    IntAlign = 8;
    LongWidth = 16;
    LongAlign = 8;
    LongLongWidth = 32;
    LongLongAlign = 8;
    SuitableAlign = 8;
    DefaultAlignForAttributeAligned = 8;
    HalfWidth = 16;
    HalfAlign = 8;
    FloatWidth = 32;
    FloatAlign = 8;
    DoubleWidth = 32;
    DoubleAlign = 8;
    DoubleFormat = &llvm::APFloat::IEEEsingle();
    LongDoubleWidth = 32;
    LongDoubleAlign = 8;
    LongDoubleFormat = &llvm::APFloat::IEEEsingle();
    SizeType = UnsignedLong;
    PtrDiffType = SignedLong;
    IntPtrType = SignedLong;
    Char16Type = UnsignedLong;
    WCharType = SignedLong;
    WIntType = SignedLong;
    Char32Type = UnsignedLong;
    SigAtomicType = SignedChar;

    BoolAlign = 8;
    MinGlobalAlign = 8;
    UseBitFieldTypeAlignment = false;

    resetDataLayout("e-p:16:8-i8:8-i16:8-i32:8-i64:8-f32:8-f64:8-n8-a:8");
    //resetDataLayout("e-m:o-S8-p:16:8-p1:8:8-i16:8-i32:8-a:8-n8:16"); Z80
  }

  ArrayRef<Builtin::Info> getTargetBuiltins() const final { return None; }

  BuiltinVaListKind getBuiltinVaListKind() const override {
    return TargetInfo::VoidPtrBuiltinVaList;
  };

  const char *getClobbers() const override;

  bool validateAsmConstraint(const char *&Name,
    TargetInfo::ConstraintInfo &Info) const override;

  IntType getIntTypeByWidth(unsigned BitWidth,
    bool IsSigned) const final;

  IntType getLeastIntTypeByWidth(unsigned BitWidth,
    bool IsSigned) const final;

protected:
  std::string CPU;
private:
  bool setCPU(const std::string &Name) override;
  //bool
  //  initFeatureMap(llvm::StringMap<bool> &Features, DiagnosticsEngine &Diags,
  //                 StringRef CPU,
  //                 const std::vector<std::string> &FeaturesVec) const override;
  ArrayRef<const char *> getGCCRegNames() const override;
  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override {
    return None;
  }
  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;
};

} // namespace targets
} // namespace clang

#endif // LLVM_CLANG_LIB_BASIC_TARGETS_GBZ80_H
