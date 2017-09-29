#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace UPDATES
{
class State : public TLBaseObject
{
public:
	State();
	State(int32 pts, int32 qts, FDateTime date, int32 seq, int32 unread_count);

	~State();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 Getqts() const
	{
		 return this->qts;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 Getseq() const
	{
		 return this->seq;
	}

	int32 GetUnreadCount() const
	{
		 return this->unread_count;
	}

private:
	int32 pts;
	 int32 qts;
	 FDateTime date;
	 int32 seq;
	 int32 unread_count;
};
} //end namespace block
