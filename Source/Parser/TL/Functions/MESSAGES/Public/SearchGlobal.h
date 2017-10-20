#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class SearchGlobal : public TLBaseObject
{
public:
	SearchGlobal();
	SearchGlobal(FString q, FDateTime offset_date, TLBaseObject* offset_peer, int32 offset_id, int32 limit);

	~SearchGlobal();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getq() const
	{
		 return this->q;
	}

	FDateTime GetOffsetDate() const
	{
		 return this->offset_date;
	}

	TLBaseObject*  GetOffsetPeer() const
	{
		 return this->offset_peer;
	}

	int32 GetOffsetId() const
	{
		 return this->offset_id;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	MESSAGES::Messages* GetResult() const
	{
		 return this->result;
	}

private:
	FString q;
	 FDateTime offset_date;
	 TLBaseObject* offset_peer;
	 int32 offset_id;
	 int32 limit;
	MESSAGES::Messages* result;
};
} //end namespace block
