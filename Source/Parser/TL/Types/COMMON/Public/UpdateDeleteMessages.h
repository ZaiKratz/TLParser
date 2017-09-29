#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateDeleteMessages : public PRIVATE::Update
{
public:
	UpdateDeleteMessages();
	UpdateDeleteMessages(TArray<int32> messages, int32 pts, int32 pts_count);

	~UpdateDeleteMessages();
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
