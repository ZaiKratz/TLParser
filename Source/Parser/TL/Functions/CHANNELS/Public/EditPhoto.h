#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/InputChatPhoto.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class EditPhoto : public TLBaseObject
{
public:
	EditPhoto();
	EditPhoto(COMMON::InputChannel* channel, COMMON::InputChatPhoto* photo);

	~EditPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	COMMON::InputChatPhoto*  Getphoto() const
	{
		 return this->photo;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 COMMON::InputChatPhoto* photo;
	COMMON::Updates* result;
};
} //end namespace block
