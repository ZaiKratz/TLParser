#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class SentCodeTypeCall : public TLBaseObject
{
public:
	SentCodeTypeCall();
	SentCodeTypeCall(int32 length);

	~SentCodeTypeCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getlength() const
	{
		 return this->length;
	}

private:
	int32 length;
};
} //end namespace block
