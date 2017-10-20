#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/AffectedMessages.h"

//begin namespace block
namespace MESSAGES
{
class ReadHistory : public TLBaseObject
{
public:
	ReadHistory();
	ReadHistory(TLBaseObject* peer, int32 max_id);

	~ReadHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	int32 GetMaxId() const
	{
		 return this->max_id;
	}

	MESSAGES::AffectedMessages* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	 int32 max_id;
	MESSAGES::AffectedMessages* result;
};
} //end namespace block
