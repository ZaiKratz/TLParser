#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackLanguage.h"

//begin namespace block
namespace LANGPACK
{
class GetLanguages : public TLBaseObject
{
public:
	GetLanguages();
	~GetLanguages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::LangPackLanguage*> result;
};
} //end namespace block
