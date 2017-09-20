#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/MessageMedia.h"
#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdateShortSentMessage : public TLBaseObject
{
public:
	UpdateShortSentMessage();
	UpdateShortSentMessage(bool out, int32 id, int32 pts, int32 pts_count, FDateTime date, PRIVATE::MessageMedia* media, TArray<PRIVATE::MessageEntity*> entities);

	~UpdateShortSentMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool out;
	 int32 id;
	 int32 pts;
	 int32 pts_count;
	 FDateTime date;
	 PRIVATE::MessageMedia* media;
	 TArray<PRIVATE::MessageEntity*> entities;
};
} //end namespace block
