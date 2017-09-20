#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackString.h"

//begin namespace block
namespace COMMON
{
class LangPackDifference : public TLBaseObject
{
public:
	LangPackDifference();
	LangPackDifference(FString lang_code, int32 from_version, int32 version, TArray<COMMON::LangPackString*> strings);

	~LangPackDifference();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString lang_code;
	 int32 from_version;
	 int32 version;
	 TArray<COMMON::LangPackString*> strings;
};
} //end namespace block
