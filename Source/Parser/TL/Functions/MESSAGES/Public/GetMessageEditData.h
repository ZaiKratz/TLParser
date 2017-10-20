#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/MessageEditData.h"

//begin namespace block
namespace MESSAGES
{
class GetMessageEditData : public TLBaseObject
{
public:
	GetMessageEditData();
	GetMessageEditData(TLBaseObject* peer, int32 id);

	~GetMessageEditData();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	MESSAGES::MessageEditData* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	 int32 id;
	MESSAGES::MessageEditData* result;
};
} //end namespace block
