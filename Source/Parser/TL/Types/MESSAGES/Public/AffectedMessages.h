#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class AffectedMessages : public TLBaseObject
{
public:
	AffectedMessages();
	AffectedMessages(int32 pts, int32 pts_count);

	~AffectedMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsCount() const
	{
		 return this->pts_count;
	}

private:
	int32 pts;
	 int32 pts_count;
};
} //end namespace block
