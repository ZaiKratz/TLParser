#pragma once
#include "Engine.h"

#include "../../../Types/Private/SentCodeType.h"

//begin namespace block
namespace AUTH
{
class SentCodeTypeCall : public PRIVATE::SentCodeType
{
public:
	SentCodeTypeCall();
	SentCodeTypeCall(int32 length);

	~SentCodeTypeCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 length;
};
} //end namespace block
