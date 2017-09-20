#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateReadMessagesContents : public PRIVATE::Update
{
public:
	UpdateReadMessagesContents();
	UpdateReadMessagesContents(TArray<int32> messages, int32 pts, int32 pts_count);

	~UpdateReadMessagesContents();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<int32> messages;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
