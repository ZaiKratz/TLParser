#include "../Public/ToggleInvites.h"


//begin namespace block
namespace CHANNELS
{

ToggleInvites::ToggleInvites()
{
	this->_ConstructorID = 127098953;
	this->_ContentRelated = true;
}

ToggleInvites::ToggleInvites(COMMON::InputChannel* channel, bool enabled)
{
	this->_ConstructorID = 127098953;
	this->_ContentRelated = true;
	this->channel = channel;
	this->enabled = enabled;
}
void ToggleInvites::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.WriteBool(this->enabled);
}


void ToggleInvites::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
ToggleInvites::~ToggleInvites()
{

}
}//end namespace block