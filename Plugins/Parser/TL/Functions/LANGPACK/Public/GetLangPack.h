#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackDifference.h"

//begin namespace block
namespace LANGPACK
{
class GetLangPack : public TLBaseObject
{
public:
	GetLangPack();
	GetLangPack(FString lang_code);

	~GetLangPack();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString lang_code;
	COMMON::LangPackDifference* result;
};
} //end namespace block
