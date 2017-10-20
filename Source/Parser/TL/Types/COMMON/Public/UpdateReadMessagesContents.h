#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateReadMessagesContents : public TLBaseObject
{
public:
	UpdateReadMessagesContents();
	UpdateReadMessagesContents(TArray<int32> messages, int32 pts, int32 pts_count);

	~UpdateReadMessagesContents();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<int32>  Getmessages() const
	{
		 return this->messages;
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
	TArray<int32> messages;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
