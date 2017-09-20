#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class LangPackString : public TLBaseObject
{
public:
	LangPackString();
	LangPackString(FString key, FString value);

	~LangPackString();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString key;
	 FString value;
};
} //end namespace block
