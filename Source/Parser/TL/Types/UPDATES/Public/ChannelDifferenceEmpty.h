#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Updates/Public/ChannelDifference.h"

//begin namespace block
namespace UPDATES
{
class ChannelDifferenceEmpty : public TLBaseObject
{
public:
	ChannelDifferenceEmpty();
	ChannelDifferenceEmpty(bool final, int32 pts, int32 timeout);

	~ChannelDifferenceEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getfinal() const
	{
		 return this->final;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 Gettimeout() const
	{
		 return this->timeout;
	}

private:
	bool final;
	 int32 pts;
	 int32 timeout;
};
} //end namespace block
