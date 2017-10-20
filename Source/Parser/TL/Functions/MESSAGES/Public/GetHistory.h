#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class GetHistory : public TLBaseObject
{
public:
	GetHistory();
	GetHistory(TLBaseObject* peer, int32 offset_id, FDateTime offset_date, int32 add_offset, int32 limit, int32 max_id, int32 min_id);

	~GetHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	int32 GetOffsetId() const
	{
		 return this->offset_id;
	}

	FDateTime GetOffsetDate() const
	{
		 return this->offset_date;
	}

	int32 GetAddOffset() const
	{
		 return this->add_offset;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	int32 GetMaxId() const
	{
		 return this->max_id;
	}

	int32 GetMinId() const
	{
		 return this->min_id;
	}

	MESSAGES::Messages* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	 int32 offset_id;
	 FDateTime offset_date;
	 int32 add_offset;
	 int32 limit;
	 int32 max_id;
	 int32 min_id;
	MESSAGES::Messages* result;
};
} //end namespace block
