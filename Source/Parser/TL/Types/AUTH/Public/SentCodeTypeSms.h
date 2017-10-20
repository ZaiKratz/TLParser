#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class SentCodeTypeSms : public TLBaseObject
{
public:
	SentCodeTypeSms();
	SentCodeTypeSms(int32 length);

	~SentCodeTypeSms();
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
