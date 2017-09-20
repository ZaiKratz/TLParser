#include "../Public/UpdatePinnedMessage.h"


//begin namespace block
namespace CHANNELS
{

UpdatePinnedMessage::UpdatePinnedMessage()
{
	this->_ConstructorID = 1391275431;
	this->_ContentRelated = true;
}

UpdatePinnedMessage::UpdatePinnedMessage(bool silent, COMMON::InputChannel* channel, int32 id)
{
	this->_ConstructorID = 1391275431;
	this->_ContentRelated = true;
	this->silent = silent;
	this->channel = channel;
	this->id = id;
}
void UpdatePinnedMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!silent)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->channel->OnSend(Writer);
	Writer.WriteInt(this->id);
}


void UpdatePinnedMessage::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
UpdatePinnedMessage::~UpdatePinnedMessage()
{

}
}//end namespace block
