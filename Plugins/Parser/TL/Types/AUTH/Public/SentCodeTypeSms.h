#pragma once
#include "Engine.h"

#include "../../../Types/Private/SentCodeType.h"

//begin namespace block
namespace AUTH
{
class SentCodeTypeSms : public PRIVATE::SentCodeType
{
public:
	SentCodeTypeSms();
	SentCodeTypeSms(int32 length);

	~SentCodeTypeSms();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 length;
};
} //end namespace block
