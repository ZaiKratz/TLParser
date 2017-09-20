#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageFwdHeader : public TLBaseObject
{
public:
	MessageFwdHeader();
	MessageFwdHeader(int32 from_id, FDateTime date, int32 channel_id, int32 channel_post, FString post_author);

	~MessageFwdHeader();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 from_id;
	 FDateTime date;
	 int32 channel_id;
	 int32 channel_post;
	 FString post_author;
};
} //end namespace block
