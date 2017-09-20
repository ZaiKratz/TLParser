#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class LangPackLanguage : public TLBaseObject
{
public:
	LangPackLanguage();
	LangPackLanguage(FString name, FString native_name, FString lang_code);

	~LangPackLanguage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString name;
	 FString native_name;
	 FString lang_code;
};
} //end namespace block
