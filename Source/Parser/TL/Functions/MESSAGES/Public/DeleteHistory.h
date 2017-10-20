#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/AffectedHistory.h"

//begin namespace block
namespace MESSAGES
{
class DeleteHistory : public TLBaseObject
{
public:
	DeleteHistory();
	DeleteHistory(bool just_clear, TLBaseObject* peer, int32 max_id);

	~DeleteHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetJustClear() const
	{
		 return this->just_clear;
	}

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	int32 GetMaxId() const
	{
		 return this->max_id;
	}

	MESSAGES::AffectedHistory* GetResult() const
	{
		 return this->result;
	}

private:
	bool just_clear;
	 TLBaseObject* peer;
	 int32 max_id;
	MESSAGES::AffectedHistory* result;
};
} //end namespace block
