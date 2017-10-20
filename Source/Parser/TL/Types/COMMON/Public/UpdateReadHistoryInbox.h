#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateReadHistoryInbox : public TLBaseObject
{
public:
	UpdateReadHistoryInbox();
	UpdateReadHistoryInbox(TLBaseObject* peer, int32 max_id, int32 pts, int32 pts_count);

	~UpdateReadHistoryInbox();
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

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsCount() const
	{
		 return this->pts_count;
	}

private:
	TLBaseObject* peer;
	 int32 max_id;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
