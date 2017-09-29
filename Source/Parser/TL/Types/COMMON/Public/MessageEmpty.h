#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"

//begin namespace block
namespace COMMON
{
class MessageEmpty : public TLBaseObject
{
public:
	MessageEmpty();
	MessageEmpty(int32 id);

	~MessageEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

private:
	int32 id;
};
} //end namespace block
