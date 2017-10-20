#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Dialogs.h"

//begin namespace block
namespace MESSAGES
{
class GetDialogs : public TLBaseObject
{
public:
	GetDialogs();
	GetDialogs(bool exclude_pinned, FDateTime offset_date, int32 offset_id, TLBaseObject* offset_peer, int32 limit);

	~GetDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetExcludePinned() const
	{
		 return this->exclude_pinned;
	}

	FDateTime GetOffsetDate() const
	{
		 return this->offset_date;
	}

	int32 GetOffsetId() const
	{
		 return this->offset_id;
	}

	TLBaseObject*  GetOffsetPeer() const
	{
		 return this->offset_peer;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	MESSAGES::Dialogs* GetResult() const
	{
		 return this->result;
	}

private:
	bool exclude_pinned;
	 FDateTime offset_date;
	 int32 offset_id;
	 TLBaseObject* offset_peer;
	 int32 limit;
	MESSAGES::Dialogs* result;
};
} //end namespace block
