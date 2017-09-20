#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackString.h"

//begin namespace block
namespace COMMON
{
class LangPackStringDeleted : public TLBaseObject
{
public:
	LangPackStringDeleted();
	LangPackStringDeleted(FString key);

	~LangPackStringDeleted();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString key;
};
} //end namespace block
