#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class Search : public TLBaseObject
{
public:
	Search();
	Search(TLBaseObject* peer, FString q, COMMON::InputUser* from_id, TLBaseObject* filter, FDateTime min_date, FDateTime max_date, int32 offset_id, int32 add_offset, int32 limit, int32 max_id, int32 min_id);

	~Search();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	FString Getq() const
	{
		 return this->q;
	}

	COMMON::InputUser*  GetFromId() const
	{
		 return this->from_id;
	}

	TLBaseObject*  Getfilter() const
	{
		 return this->filter;
	}

	FDateTime GetMinDate() const
	{
		 return this->min_date;
	}

	FDateTime GetMaxDate() const
	{
		 return this->max_date;
	}

	int32 GetOffsetId() const
	{
		 return this->offset_id;
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
	 FString q;
	 COMMON::InputUser* from_id;
	 TLBaseObject* filter;
	 FDateTime min_date;
	 FDateTime max_date;
	 int32 offset_id;
	 int32 add_offset;
	 int32 limit;
	 int32 max_id;
	 int32 min_id;
	MESSAGES::Messages* result;
};
} //end namespace block
