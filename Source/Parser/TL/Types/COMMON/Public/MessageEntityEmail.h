#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageEntityEmail : public TLBaseObject
{
public:
	MessageEntityEmail();
	MessageEntityEmail(int32 offset, int32 length);

	~MessageEntityEmail();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getoffset() const
	{
		 return this->offset;
	}

	int32 Getlength() const
	{
		 return this->length;
	}

private:
	int32 offset;
	 int32 length;
};
} //end namespace block
