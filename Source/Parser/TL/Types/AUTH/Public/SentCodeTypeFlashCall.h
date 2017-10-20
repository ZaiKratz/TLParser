#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class SentCodeTypeFlashCall : public TLBaseObject
{
public:
	SentCodeTypeFlashCall();
	SentCodeTypeFlashCall(FString pattern);

	~SentCodeTypeFlashCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getpattern() const
	{
		 return this->pattern;
	}

private:
	FString pattern;
};
} //end namespace block
