#pragma once
#include "Engine.h"

#include "../../../Types/Private/SentCodeType.h"

//begin namespace block
namespace AUTH
{
class SentCodeTypeApp : public PRIVATE::SentCodeType
{
public:
	SentCodeTypeApp();
	SentCodeTypeApp(int32 length);

	~SentCodeTypeApp();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 length;
};
} //end namespace block
