#pragma once
#include "Engine.h"

#include "../../../Types/Private/SentCodeType.h"

//begin namespace block
namespace AUTH
{
class SentCodeTypeFlashCall : public PRIVATE::SentCodeType
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
