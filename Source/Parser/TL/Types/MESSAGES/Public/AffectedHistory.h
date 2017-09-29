#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class AffectedHistory : public TLBaseObject
{
public:
	AffectedHistory();
	AffectedHistory(int32 pts, int32 pts_count, int32 offset);

	~AffectedHistory();
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

	int32 Getoffset() const
	{
		 return this->offset;
	}

private:
	int32 pts;
	 int32 pts_count;
	 int32 offset;
};
} //end namespace block
